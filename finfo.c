/**
 * Author: Andrew Gilpatrick
 * Assignment: Lab 9
 * Date: 11/3/2025
 * finfo.c
 */
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>
int main(int argc, char* argv[])
{
    struct stat statbuf;
    char fileName[100];
    printf("enter file name\n");
    scanf("%99s",fileName);

    if (stat(fileName, &statbuf) == -1) {
        perror("Error");
        exit(1);            
    }

    stat(fileName,&statbuf);
    printf("File size: %ld bytes\n", statbuf.st_size);
    printf("Last Modified: %s\n", ctime(&statbuf.st_mtime));

    if (S_ISREG(statbuf.st_mode)){
        printf("File type: Regular file\n");
    }
    else if (S_ISDIR(statbuf.st_mode)){
        printf("File type: Directory\n");
    }
    else if (S_ISLNK(statbuf.st_mode)){
        printf("File type: Symbolic link\n");
    }
    else if (S_ISCHR(statbuf.st_mode)){
        printf("File type: Character device\n");
    }
    else if (S_ISBLK(statbuf.st_mode)){
        printf("File type: Block device\n");
    }
    else if (S_ISFIFO(statbuf.st_mode)){
        printf("File type: FIFO / pipe\n");
    }
    else if (S_ISSOCK(statbuf.st_mode)){
        printf("File type: Socket\n");
    }
    else{
        printf("File type: Unknown\n");
    }

    printf("User:  %c%c%c\n",
       (statbuf.st_mode & S_IRUSR) ? 'r' : '-',
       (statbuf.st_mode & S_IWUSR) ? 'w' : '-',
       (statbuf.st_mode & S_IXUSR) ? 'x' : '-');

    printf("Group: %c%c%c\n",
       (statbuf.st_mode & S_IRGRP) ? 'r' : '-',
       (statbuf.st_mode & S_IWGRP) ? 'w' : '-',
       (statbuf.st_mode & S_IXGRP) ? 'x' : '-');

    printf("Other: %c%c%c\n",
       (statbuf.st_mode & S_IROTH) ? 'r' : '-',
       (statbuf.st_mode & S_IWOTH) ? 'w' : '-',
       (statbuf.st_mode & S_IXOTH) ? 'x' : '-');

    printf("User ID (OWNER): %d\n", statbuf.st_uid);  // user ID (owner)
    printf("Group Owner: %d\n", statbuf.st_gid);  // group ID (group owner)
       
}