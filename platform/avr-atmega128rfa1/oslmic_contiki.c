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

//#include "serial.h"

// RUNTIME STATE
static struct {
    osjob_t* scheduledjobs;
    osjob_t* runnablejobs;
} OS;

static struct ctimer c_timer;

PROCESS(os_runloop, "LMIC event handler");

void os_init () {
    rs232_print(RS232_PORT_0, "In OS init\r\n");
    //DDRB |= (1 << PB2);
    //serial_puts((char *) "in os init\r\n");
    memset(&OS, 0x00, sizeof(OS));
    rs232_print(RS232_PORT_0, "memset fine\r\n");
    //serial_puts((char *) "memset fine\r\n");
    //lmic_hal_init();
    rs232_print(RS232_PORT_0, "hal fine\r\n");
    //serial_puts((char *) "hal fine\r\n");
    radio_init();
    rs232_print(RS232_PORT_0, "radio fine\r\n");
    //serial_puts((char *) "radio fine\r\n");
    LMIC_init();
    rs232_print(RS232_PORT_0, "lmic fine\r\n");
    //serial_puts((char *) "lmic fine\r\n");

    process_start(&os_runloop, NULL);

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
    osjob_t** pnext;
    hal_disableIRQs();
    // remove if job was already queued
    os_clearCallback(job);
    // fill-in job
    job->func = cb;
    job->next = NULL;
    // add to end of run queue
    for(pnext=&OS.runnablejobs; *pnext; pnext=&((*pnext)->next));
    *pnext = job;
    hal_enableIRQs();

    /* Wake up runloop process */
    process_poll(&os_runloop);
}

// schedule timed job
/*void os_setTimedCallback (osjob_t* job, ostime_t time, osjobcb_t cb) {
    osjob_t** pnext;
    hal_disableIRQs();
    // remove if job was already queued
    os_clearCallback(job);
    // fill-in job
    job->deadline = time;
    job->func = cb;
    job->next = NULL;
    // insert into schedule
    for(pnext=&OS.scheduledjobs; *pnext; pnext=&((*pnext)->next)) {
        if((*pnext)->deadline - time > 0) { // (cmp diff, not abs!)
            // enqueue before next element and stop
            job->next = *pnext;
            break;
        }
    }
    *pnext = job;
    hal_enableIRQs();

    // TODO: set event timer, that polls runloop when it expires.
}*/

/*void os_setTimedCallback(clock_time_t time, void(*f)(void *)) {
    ctimer_set(&c_timer, time, f, NULL);
}*/

void os_setTimedCallback (osjob_t* job, ostime_t time, osjobcb_t cb) {
        
    //convert ostime_t to clock_time_t

    //convert osjobcb_t to void(*f)(void *) (a callback to the function)

    // the above was the right idea, but it would be best not to change the function parameters as that would require a lot of changes to lmic.c
    ctimer_set(&c_timer, time, &cb, NULL);

    // what happens if two functions try to use the ctimer at once?
}
// execute jobs from timer and from run queue
/*void os_runloop () {
    while(1) {
        osjob_t* j = NULL;
        hal_disableIRQs();
        // check for runnable jobs
        if(OS.runnablejobs) {
            j = OS.runnablejobs;
            OS.runnablejobs = j->next;
        } else if(OS.scheduledjobs && hal_checkTimer(OS.scheduledjobs->deadline)) { // check for expired timed jobs
            j = OS.scheduledjobs;
            OS.scheduledjobs = j->next;
        } else { // nothing pending
            hal_sleep(); // wake by irq (timer already restarted)
        }
        hal_enableIRQs();
        if(j) { // run job callback
            j->func(j);
        }
    }
}*/

PROCESS_THREAD(os_runloop, ev, data)
{
  PROCESS_BEGIN();

  rs232_print(RS232_PORT_0, "In OS runloop\r\n");
  while(1) {
    rs232_print(RS232_PORT_0, "In OS runloop loop\r\n");
    //no jobs available, wait for poll
    PROCESS_YIELD();

    //run all queued jobs


    //Going to handle timed jobs differently - each timed job sets a callback timer, which calls them when expired.
    
    osjob_t* j = NULL;
    
    while(OS.runnablejobs) {
        hal_disableIRQs();
        
        j = OS.runnablejobs;
        OS.runnablejobs = j->next;        
    
        hal_enableIRQs();

        if(j) { // run job callback
            j->func(j);
        }    
    }    
  }
  PROCESS_END();
}