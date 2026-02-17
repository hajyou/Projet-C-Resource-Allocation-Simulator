#ifndef UTILISATEURS_H
#define UTILISATEURS_H

typedef struct Date_De_Naissance{

    int jour;
    int mois;
    int annee;

}DDN;

typedef struct Utilisateur{

    char Nom[255];
    char Prenom[255];

    DDN Date_De_Naissance;
    char Adresse[255];

    time_t Derniere_Connexion;

}user;

char* getNom(user* List_Users,int u);

char* getPrenom(user* List_Users,int u);

char* getAdresse(user* List_Users,int u);

int getDDN_jour(user* List_Users,int u);

int getDDN_mois(user* List_Users,int u);

int getDDN_annee(user* List_Users,int u);

time_t getDerniere_Connexion(user* List_Users, int u);

int setNom(user* List_Users,int u,const char* NouveauNom);

int setPrenom(user* List_Users,int u,const char* NouveauPrenom);

int setAdresse(user* List_Users,int u,const char* NouvelleAdresse);

void setDDN_jour(user* List_Users,int u,int NouveauJourDeDDN);

void setDDN_mois(user* List_Users,int u, int NouveauMoisDeDDN);

void setDDN_annee(user* List_Users,int u, int NouvelleAnneeDeDDN);

void setDerniere_Connexion(user* List_Users, int u, time_t newnow);

#endif