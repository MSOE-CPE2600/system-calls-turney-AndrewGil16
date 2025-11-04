/**
 * Author: Andrew Gilpatrick
 * Assignment: Lab 9
 * Date: 11/3/2025
 * pmod.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <unistd.h>
#include <sys/resource.h>
#include <errno.h>
#include <time.h>
int main(int argc, char* argv[])
{
    struct timespec request;
    struct timespec remaining;
    request.tv_nsec = 1837272628;
    nice(-10);
    nanosleep(&request,&remaining);
    printf("goodbye\n");
    exit(0);
}