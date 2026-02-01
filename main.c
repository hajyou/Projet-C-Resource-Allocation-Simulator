#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int get() {
    int x;
    printf(">>>");
    scanf("%d", &x);
    return x;
}

int pointeur(){
    int a = 5;
    int *pointeur_sur_a = &a;

    printf("La valeur de a est : %d\n", a);
    printf("L'adresse de a est : %p\n", &a);
    printf("La valeur du pointeur est : %p\n", pointeur_sur_a);
    printf("La valeur pointée par le pointeur est : %d\n", *pointeur_sur_a);

    *pointeur_sur_a = 10;
    printf("Après modification, la valeur de a est : %d\n", a);

    return 0;
}

void erreur(int x){

    int *tab = malloc(x * sizeof(int));
    if (tab == NULL){
        fprintf(stderr, "Une erreur s'est produite : %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "l'allocation de memoire s'est bien passée \n");
    free(tab);
    tab = NULL;
}


int main() {
    int choix = 0;
    printf("entrez un chiffre pour tester la limite d'un allocation mémoire :\n");
    printf("* si votre os est en 32 bits par exemple la limite théorique est 2^32-1\n");
    printf("* une commande utile est 'uname -a' sous Linux pour connaître l'architecture de votre pc\n");
    printf("* pour stopper le programme entrez -1\n");
    while(choix != -1){
        choix = get();
        if (choix > 0){
            erreur(choix);
        }
        else if (choix == -1){
            printf("Arrét du programme ...\n");
        }
        else{
            printf("Entrée invalide, veuillez réessayer.\n");
        }
    }
    return 0;
}
