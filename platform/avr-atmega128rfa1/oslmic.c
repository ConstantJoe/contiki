/*******************************************************************************
 * Copyright (c) 2014-2015 IBM Corporation.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *    IBM Zurich Research Lab - initial API, implementation and documentation
 *******************************************************************************/

#include "lmic.h"

// RUNTIME STATE
static struct {
    osjob_t* scheduledjobs;
    osjob_t* runnablejobs;
} OS;

static struct ctimer c_timer;

void os_init () {

    memset(&OS, 0x00, sizeof(OS));

    lmic_hal_init();

    radio_init();

    LMIC_init();
}

ostime_t os_getTime () {
    return hal_ticks();
}

static u1_t unlinkjob (osjob_t** pnext, osjob_t* job) {
    for( ; *pnext; pnext = &((*pnext)->next)) {
        if(*pnext == job) { // unlink
            *pnext = job->next;
            return 1;
        }
    }
    return 0;
}

// clear scheduled job
void os_clearCallback (osjob_t* job) {
    hal_disableIRQs();
    unlinkjob(&OS.scheduledjobs, job) || unlinkjob(&OS.runnablejobs, job);
    hal_enableIRQs();
}

// schedule immediately runnable job
void os_setCallback (osjob_t* job, osjobcb_t cb) {
    job->func = cb;
    job->next = NULL;

    job->func(job);
}

// schedule timed job
void os_setTimedCallback (osjob_t* job, ostime_t time, osjobcb_t cb) {
    ctimer_set(&c_timer, time, (void (*)(void *)) cb, job);
}