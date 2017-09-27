/* author: windyear
   date: 2017-7-12
   This is a program can list the current users in the unix operation system
*/
#include <stdio.h>
#include <utmp.h>
#include <unistd.h>
#include <fcntl.h>

#define SHOWHOST

int main(int ac, char * ar[]){
    utmp current_record; //use to save the record which is read from the utmp files
    int record_len;
    int utmpfd; //描述文件的句柄
    record_len == sizeof(current_record):
    if(utmpfd = open(UTMP_FILE, O_RDONLY) == -1){
        perror(UTMP_FILE);
    }
    while(read(utmpfd, &current_record, record_len) == record_len){
        ShowInfo(&current_record);
    }
    close(utmpfd);
    return 0;
}

void ShowInfo(struct utmp * utmp_recordbuf){
    printf("%-8.8s", utmp_recordbuf->ut_name);
    printf(“ ”);
    printf("%-8.8s", utmp_recordbuf->ut_line);
    printf(“ ”);
    printf("%-8.8s", utmp_recordbuf->ut_time);
    printf(“ ”);
    #ifdef SHOWHOST
    printf("%-8.8s", utmp_recordbuf->ut_host);
    printf(“ ”);
    #endif
    printf("\n");
}