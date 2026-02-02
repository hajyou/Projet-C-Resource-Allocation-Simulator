#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    
    int ancestor_pid = getppid();
    int res1 = -1;

    res1 = fork();

    if(res1 > 0){
        fprintf(stdout, "%dvient de créer un fils %d\n", getpid(), res1);
    }
    else{
        fprintf(stdout, "%d vient d'etre créer par %d\n", getpid(), getppid());
        fprintf(stdout, "son grand-père est %d\n", ancestor_pid);
    }
    return EXIT_SUCCESS;
}