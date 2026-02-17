#include <stdio.h>
#include <stdlib.h>

int main(void){

    int Lignes;
    int Colonnes;

    Lignes = 5;
    Colonnes = 3;

    int *tab = (int*)malloc(Lignes * Colonnes * sizeof(int));
    if (!tab){
        return 1;
    } 

    // On vas remplir le tableau de valeurs contigue pour ensuite effectuer des tests cela m'aidera a mieux comprendre les différentes
    // Matrice de taille 2

    for (int i = 0; i < Colonnes * Lignes; i++){
        tab[i] = i;
    }

    for (int i = 0; i < Colonnes * Lignes; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");

    // si je veux modifier tab[i][j] dans mon exemple tab[4][1] pour le 13 je fait tab[i * Colonnes + j]
    printf("\nje veux print le 13\n");
    printf("%d \n", tab[4 * Colonnes + 1]);

    return 0;
}