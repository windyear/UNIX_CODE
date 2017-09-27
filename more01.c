/*author: windyear
  date: 2017/07/08
  Features: imitate the features of the instruction more
*/
#include <stdio.h>

#define PAGELEN 24
#define LINELEN 512

void Domore(FILE * fp);
int Seemore();

int main(int ac, char * av[]){
    FILE * fp;
    if(ac == 1){
        Domore(stdin);
    }
    else{
        while(--ac){
            if((fp=fopen(*++av,"r"))!=NULL){
                Domore(fp);
                fclose(fp);
            }
            else
                exit(1);
        }
    }
    return 0;
}

void Domore(FILE * fp){
    char line[LINELEN];
    int Seemore();
    int num_of_lines=0;
    while(fgets(line, LINELEN, fp){
        if(num_of_lines == PAGELEN){
            reply = Seemore();
            if(!reply){
                break;
            }
            num_of_lines = reply - 1;
        }
        if(fputs(line, stdout) == EOF){
            exit(1);
        }
        num_of_lines++;
    }
}

int Seemore(){
    char c;
    printf("\033[7m more?\033[m");
    while((c = getchar()) != EOF){
        if(c == 'q')
            return 0;
        if(c == ' ')
            return PAGELEN;
        if(c == '\n')
            return 1;
    }
    return 0;
}