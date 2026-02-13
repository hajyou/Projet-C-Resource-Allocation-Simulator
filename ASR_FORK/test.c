#include <stdio.h>
#include <stdlib.h>

// a = &b
// *a = 2 (la valeur 2 est affecté à b)


void Remplissage_matrice(int x, int y,int** m){
    printf("Remplissage en cours ...\n");

    for(int k = 0; k < x; k++){
        for (int j = 0; j < y; j++){
            m[k][j] = 1;
        }
    }
}

void affichage_matrice(int x,int y,int** m){
    for(int l = 0; l < x; l++){
        for (int s = 0; s < y; s++){
            printf("%d",m[s][l]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void){

    int x = 3;
    int y = 3;

    int** m;

    m = (int**)malloc(x * sizeof(int*));
    for (int i = 0;i < x; i++){
        m[i] = (int*)malloc(y * sizeof(int));
    }

    printf("Allocation réussi ...\n");

    Remplissage_matrice(x,y,m);

    affichage_matrice(x,y,m);
    
    m[1][1] = 2;

    affichage_matrice(x,y,m);

    m[1][1] = 5;

    affichage_matrice(x,y,m);
    
    return 0;
}