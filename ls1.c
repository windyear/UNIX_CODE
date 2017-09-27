/* author: windyear
   date: 2017/7/14
   this a a program to module the function of ls
*/
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

void DoLs(char []);

int main(int ac, char * av[]){
    if(ac == 1){
        DoLs(".");
    }
    else{
        while(ac--){
            printf("%s:\n",*++av);
            DoLs(*av);
        }
    }
}

void DoLs(char dirname[]){
    DIR * dir_ptr;
    struct dirent * direntp;
    
    if((dir_ptr = opendir(dirname)) == NULL){
        fprintf(stderr, "ls1: cannot open %s\n", dirname);
    }
    else{
        while((direntp = readdir(dir_ptr)) != NULL){
            printf("%s\n", direntp->d_name);
        }
        closedir(dir_ptr);
    }
}