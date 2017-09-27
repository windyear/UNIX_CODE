/* version 1 of cp ,which uses read and write fuction with tunable buffer sizeof

usage: cp1 src dest

author: windyear
date: 2017-09-18 */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFFERSIZE 4096
#define COPYMODE 0644

void oops(char * , char *);

void main(int ac, char * av[]){
    int in_fd, out_fd, n_chars;
    char buf[BUFFERSIZE];
    # print the information about how to use this program
    if(ac != 3){
        fprintf(stderr, "Usage: %s source destination\n", *av);
    }
    if((in_fd = open(av[1], O_REONLY)) == -1){
        oops("Cannot open ", av[1]);
    }
    if((out_fd = open(av[2], O_WRONLY)) == -1){
        oops("Cannot open", av[2]);
    }
    while((n_chars = read(in_fd, buf, BUFFERSIZE)) > 0){
        if(write(out_fd, buf, BUFFERSIZE) != n_chars){
            oops("Write error to", av[2]);
        }
    }
    if(n_chars == -1){
        oops("Read error from", av[1]);
    }
    
    if( close(in_fd) == -1 || close(out_fd) == -1){
        oops("Error clsing files", "");
    }
    
}

void oops(char * s1, char * s2){
    
}