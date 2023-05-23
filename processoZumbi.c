#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int exitdofilho = 0;
void trata(int a ) {
    exitdofilho = a;
}

int main (void){
    signal (SIGUSR1, trata);
    signal (SIGUSR2, trata);

    pause ();
    if(fork() == 0)
       exit(0);
    pause();
    wait(NULL);
    pause();
    exit(0);

}



