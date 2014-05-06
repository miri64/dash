# Introduction
* what is dash?
* what is POSIX?
* POSIX-wrapping in RIOT
* newlib and msp430-libc

# Main problems
* POSIX-API function implemention
* http://pubs.opengroup.org/onlinepubs/9699919799/

## Subtasks
* identify needed functions [done]
* devide functions between us
    * provide maybe needed RIOT functionality (files, environment, …)

## Subtask1: how to address ...

## Subtask2: how to address ...

# Timeline
* Until May 11th: Try to compile it, identify missing functions and types
* Until May 18th: distribute tasks (maybe define sub-milestones for next milestone)
* Until June 29th: implement functionality

# Killing threads
* Two prerequisites: Scheduler needs to know thread has been killed,
  memory needs to be freed
## Scheduler
* See core/sched.c sched_task_exit()
* Set scheduler entry for thread PID to NULL
* Decrease num_tasks
* Set status to STOPPED (maybe introduce new status KILLED?)
* active_thread = NULL
## Memory
* Implement a process pool that statically allocates memory for MAXNUM
  processes
* new threads get first free memory block assigned to them
* when a thread is killed: mark memory block as free
* free blocks can be used by new threads
