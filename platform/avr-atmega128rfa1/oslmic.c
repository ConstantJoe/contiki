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

#include "dev/rs232.h"
#include <stdio.h>

// RUNTIME STATE
static struct {
    osjob_t* scheduledjobs;
    osjob_t* runnablejobs;
} OS;

#define CTIMERS_SIZE_OF_POOL 10

static struct ctimer c_timers[CTIMERS_SIZE_OF_POOL];

//static ctimer_holder c_timers[10];

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
    /*hal_disableIRQs();*/
    unlinkjob(&OS.scheduledjobs, job) || unlinkjob(&OS.runnablejobs, job); //TODO: is this needed?
    /*hal_enableIRQs();*/
}

// schedule immediately runnable job
void os_setCallback (osjob_t* job, osjobcb_t cb) {
    job->func = cb;
    job->next = NULL;

    job->func(job);
}

// schedule timed job
void os_setTimedCallback (osjob_t* job, ostime_t time, osjobcb_t cb) {
    
    //currently its waiting "time" amount of time
    //instead it should waiting "time" - current time amount of time
    //set a callback using one of the pool of timers
    int i;
    for(i=0;i<CTIMERS_SIZE_OF_POOL;i++){
        if(ctimer_expired(&c_timers[i])){
            ostime_t ctime = os_getTime();

            ostime_t t;
            if(ctime > time){
                t = 0;
            } else{
                t = time - ctime;
            }
            
            ctimer_set(&c_timers[i], t, (void (*)(void *)) cb, job);
            return;
        }
    }
}