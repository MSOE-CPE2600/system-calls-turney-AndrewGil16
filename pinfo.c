/**
 * Author: Andrew Gilpatrick
 * Assignment: Lab 9
 * Date: 11/3/2025
 * pinfo.c
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <errno.h>
int main(int argc, char* argv[]) {
    const char* policy_name(int policy) {
        switch (policy) {
            case SCHED_OTHER:   return "SCHED_OTHER";
            case SCHED_FIFO:    return "SCHED_FIFO";
            case SCHED_RR:      return "SCHED_RR";
            case SCHED_BATCH:   return "SCHED_BATCH";
            case SCHED_IDLE:    return "SCHED_IDLE";
    #ifdef SCHED_DEADLINE
        case SCHED_DEADLINE:return "SCHED_DEADLINE";
    #endif
        default: return "UNKNOWN";
    }
}

    pid_t current_pid;
    int which = PRIO_PROCESS; //represents priority of single process
    int priority;
    if (argc > 1){
        current_pid = atoi(argv[1]);
        errno = 0;
        priority = getpriority(which, current_pid);
        if(priority == -1 && errno != 0){
            perror("Priority Failed");
            printf("Error # %d\n", errno);
            exit(0);
        }
        int policy = sched_getscheduler(current_pid);
        printf("Current PID: %d\n", current_pid);
        printf("Priority: %d\n", priority);
        printf("POLICY: %s\n", policy_name(policy));
    }
    else{
        current_pid = getpid();
        priority = getpriority(which, current_pid);
        int policy = sched_getscheduler(current_pid);
        printf("Current PID: %d\n",current_pid);
        printf("Priority: %d\n", priority);
        printf("Scheduling Method: %d\n", policy);
        
    }
}