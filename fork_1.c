#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/** 
Photo du shémas de fork dans le cahier jaune
*/

int main(int argc, char *argv[]){
    int res1 = -1;
    int res2 = -1;
    int res3 = -1;

    res1 = fork();
    res2 = fork();

    if (res1 > 0){
        res3 = fork();
    }

    fprintf(stdout, "%d de père %d se termine\n", getpid(), getppid());
    fprintf(stdout, "[%d, %d, %d]\n", res1 , res2, res3);

    return EXIT_SUCCESS;
}