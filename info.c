/**
 * Author: Andrew Gilpatrick
 * Assignment: Lab 9
 * Date: 11/3/2025
 * info.c
 */
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <sys/sysinfo.h>


int main(int argc, char* argv[])
{
    // current time of day in NS
    struct timespec ts;
    int result;
    result = clock_gettime(CLOCK_REALTIME, &ts);
    if (result == 0){
        printf("Seconds: %ld\n", ts.tv_sec);
        printf("Nanoseconds: %ld\n", ts.tv_nsec);
        long long total_ns = (long long)ts.tv_sec * 1000000000LL + ts.tv_nsec; // convert s to ns and add for total time in NS
        printf("Clock realtime NS: ");
        printf("%lld ", total_ns);
        printf("\n");
    }
    else {
        perror("error getting realtime");
    }

    //system info
    struct utsname system_info;

    if(uname(&system_info) == -1){
        perror("uname");
        return 1;
    }

    printf("Operating System: %s\n", system_info.sysname);
    printf("System Release: %s\n", system_info.release);
    printf("System Version: %s\n", system_info.version);

    char hostname[100];
    if (gethostname(hostname, sizeof(hostname)) == 0){
        printf("Hostname: %s\n", hostname);
    } else {
        perror("gethostname");
    }


    // cpu
    long available_processors = get_nprocs();
    long configured_processors = get_nprocs_conf();
    printf("Processors:\n");
    printf("Available Processors: %ld\n", available_processors);
    printf("Configured Processors: %ld\n", configured_processors);

    //memory
    long totalMem;
    long notUse;
    long pageSize;
    pageSize = sysconf(_SC_PAGE_SIZE);
    totalMem = sysconf(_SC_PHYS_PAGES); // Total Memory
    notUse = sysconf(_SC_AVPHYS_PAGES); //physical memory pages not in use by system
    printf("Total Physical Memory: %ld\n", totalMem);
    printf("Total Free Memory: %ld\n", notUse);
    printf("Page Size: %ld Bytes\n", pageSize);

   

}