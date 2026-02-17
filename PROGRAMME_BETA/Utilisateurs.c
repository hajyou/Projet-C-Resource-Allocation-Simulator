#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "Utilisateurs.h"

//fonction de verification de nom ou prenom
static int VerifString(const char* MOT){
    if (MOT == NULL || strlen(MOT) == 0){
        return 0;
    }
    for (int i = 0; MOT[i]; i++){
        if (!isalpha((unsigned char)MOT[i])){
            return 0;
        }
    }
    return 1;
}

char* getNom(user* List_Users,int u){
    return List_Users[u].Nom;
}

char* getPrenom(user* List_Users,int u){
    return List_Users[u].Prenom;
    //return &(List_Users[u])->Nom;
    //return x->y reviens a faire *(x).y
    //return (Adresse de x + 1 reviens a décaler d'une case)
}

char* getAdresse(user* List_Users,int u){
    return List_Users[u].Adresse;
}

int getDDN_jour(user* List_Users,int u){
    return List_Users[u].Date_De_Naissance.jour;
}

int getDDN_mois(user* List_Users,int u){
    return List_Users[u].Date_De_Naissance.mois;
}
int getDDN_annee(user* List_Users,int u){
    return List_Users[u].Date_De_Naissance.annee;
}

time_t getDerniere_Connexion(user* List_Users, int u){
    return List_Users[u].Derniere_Connexion;
}

int setNom(user* List_Users,int u,const char* NouveauNom){
    if (!VerifString(NouveauNom))
    {
        return 1;
    }
    else {
        strncpy(List_Users[u].Nom, NouveauNom,sizeof(List_Users[u].Nom) - 1);
        List_Users[u].Nom[sizeof(List_Users[u].Nom) - 1] = '\0';
        return 0;
    }
}

int setPrenom(user* List_Users,int u,const char* NouveauPrenom){
    if (!VerifString(NouveauPrenom)){
        return 1;
    }

    else{
        strncpy(List_Users[u].Prenom, NouveauPrenom, sizeof(List_Users[u].Prenom) - 1);
        List_Users[u].Prenom[sizeof(List_Users[u].Prenom) - 1] = '\0';
        return 0;
    }
    
}

int setAdresse(user* List_Users,int u,const char* NouvelleAdresse){
    if (!VerifString(NouvelleAdresse)){
        return 1;
    }
    else{
        strncpy(List_Users[u].Adresse, NouvelleAdresse, sizeof(List_Users[u].Adresse) - 1);
        List_Users[u].Adresse[sizeof(List_Users[u].Adresse) - 1] = '\0';
        return 0;
    }
    
}

void setDDN_jour(user* List_Users,int u,int NouveauJourDeDDN){
    List_Users[u].Date_De_Naissance.jour = NouveauJourDeDDN;
}

void setDDN_mois(user* List_Users,int u, int NouveauMoisDeDDN){
    List_Users[u].Date_De_Naissance.mois = NouveauMoisDeDDN;
}

void setDDN_annee(user* List_Users,int u, int NouvelleAnneeDeDDN){
    List_Users[u].Date_De_Naissance.annee = NouvelleAnneeDeDDN;
}

void setDerniere_Connexion(user* List_Users, int u, time_t newnow){
    List_Users[u].Derniere_Connexion = newnow;
}