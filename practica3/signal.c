#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int run;
void printHelloWorld(int sigNum){
    printf("Recibi la se;al: %d\n",sigNum);
}
void printAntikill(int sigNum){
    printf("Jajaja no me puedes matar %d\n",sigNum);
}
void terminawhile(int sigNum){
    run = run + 1;
}

int main() {
    signal(12,printHelloWorld);
    signal(2,printAntikill);
    signal(10, terminawhile);
    run = 1;
    while(run == 1){
        printf("Trabajando\n");
        sleep(1);
    }
    printf("Termine de trabajar\n");
    printf("Adios\n");
    return 0;
}
