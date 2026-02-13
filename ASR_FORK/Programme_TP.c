#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ESPACE " "


typedef struct Date_De_Naissance{
    char Nom_Prenom[50];
    int jour;
    int mois;
    int annee;
} dateN;


int main(){

    dateN *DDN_User_1 = malloc(sizeof(dateN));

    strcpy(DDN_User_1->Nom_Prenom, "Jean Marc");
    DDN_User_1->annee = 2004;
    DDN_User_1->jour = 2;
    DDN_User_1->mois = 3;

    dateN DDN_User_2;

    strcpy(DDN_User_2.Nom_Prenom, "Jeanne Marcelle");
    DDN_User_2.annee = 2005;
    DDN_User_2.jour = 5;
    DDN_User_2.mois = 11;
    
    printf("DDN de %s : %d/%d/%d\n",DDN_User_1->Nom_Prenom , DDN_User_1->jour, DDN_User_1->mois, DDN_User_1->annee);
    printf("DDN de %s : %d/%d/%d\n",DDN_User_2.Nom_Prenom , DDN_User_2.jour, DDN_User_2.mois, DDN_User_2.annee);

    free(DDN_User_1);
    return 0;

}
