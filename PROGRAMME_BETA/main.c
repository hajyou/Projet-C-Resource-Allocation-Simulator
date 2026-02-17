#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Utilisateurs.h"

user* Allocation_Memoire_Users(int n) {
    user* List_Users = malloc(n * sizeof(user));
    return List_Users;
}

int main(void) {

    int n = 1; // un seul utilisateur
    int indice_dernier_utilisateur = n - 1;

    DDN Date_De_Naissance_USER1 = {
        .jour = 11,
        .mois = 11,
        .annee = 2003
    };

    time_t now = time(NULL);

    user User1 = {
        .Date_De_Naissance = Date_De_Naissance_USER1,
        .Derniere_Connexion = now
    };

    strcpy(User1.Nom, "HAJRI");
    strcpy(User1.Prenom, "Youssef");
    strcpy(User1.Adresse, "42 Rue Carnot, Poitiers");

    user* List_Utilisateurs = Allocation_Memoire_Users(n);

    List_Utilisateurs[0] = User1;

    printf("Nom : %s\n", List_Utilisateurs[0].Nom);
    printf("Prenom : %s\n", List_Utilisateurs[0].Prenom);
    printf("Adresse : %s\n", List_Utilisateurs[0].Adresse);
    printf("Naissance : %d/%d/%d\n",
           List_Utilisateurs[0].Date_De_Naissance.jour,
           List_Utilisateurs[0].Date_De_Naissance.mois,
           List_Utilisateurs[0].Date_De_Naissance.annee);
    
    if (setNom(List_Utilisateurs, indice_dernier_utilisateur, "TESTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT")){
        printf("Erreur\n");
    }

    
    printf("Nom : %s\n", List_Utilisateurs[0].Nom);
    printf("Prenom : %s\n", List_Utilisateurs[0].Prenom);
    printf("Adresse : %s\n", List_Utilisateurs[0].Adresse);
    printf("Naissance : %d/%d/%d\n",List_Utilisateurs[0].Date_De_Naissance.jour,List_Utilisateurs[0].Date_De_Naissance.mois,List_Utilisateurs[0].Date_De_Naissance.annee);

    free(List_Utilisateurs);
    return 0;
}