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
    /** 
    int age_de_la_personne;
    printf("Quel age as-tu ? \n>");
    age_de_la_personne = get();
    printf("Tu as %d ans.\n", age_de_la_personne);
    
    pointeur();
    **/
    erreur(get());
    return 0;
}
