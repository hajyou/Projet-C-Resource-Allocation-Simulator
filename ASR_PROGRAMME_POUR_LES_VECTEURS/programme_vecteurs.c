#include <stdio.h>
#include <stdlib.h>

// formules importantes vues en cours de TD : (AVAIL = EXIST - CURRENT)  ET  (REQUEST = MAXREQUEST - CURRENT)
//
// Pour mieux retenir les concepts du cours j'associe chaque vecteur à une action. Par exemple
//
// REQUEST -> L'action de demander.
// CURRENT -> L'action de détenir.
// EXIST -> Quantités de ressources existantes
// AVAILABLE -> Ressources disponibles à l'instant I, car oui ... ce n'est pas parce que les ressources existent qu'elles sont disponibles
// MAXREQUEST -> Ce qu'il faut comme ressources pour qu'un processus x se termine et libère à son tour les ressources


//fonction d'affichage de tableau
void affichage_matrice1(int x, int* m){
    printf("      |");
    for(int i = 0; i < x ; i++){
        printf(" R%d  |", i);
    }
    printf("\n------+");
    for(int i = 0; i < x ; i++){
        printf("-----+");
    }
    printf("\nVAL   |");
    for(int i = 0; i < x ; i++){
        printf("  %d  |", m[i]);
    }
    printf("\n");
}


//fonction d'affichage de matrice taille 2
void affichage_matrice2(int x,int y,int** m){
    printf("      |");
    for(int j = 0; j < x; j++){
        printf(" R%d  |", j);
    }
    printf("\n------+");
    for(int j = 0; j < x; j++){
        printf("-----+");
    }
    printf("\n");

    for(int i = 0; i < y; i++){
        printf(" P%d   |", i);
        for(int j = 0; j < x; j++){
            printf("  %d  |", m[j][i]);
        }
        printf("\n");
    }
}


// affichage CURRENT avec étoiles pour un processus terminé
void affichage_matrice2_avec_etoiles(int x,int y,int** m,int processus_fini){
    printf("      |");
    for(int j = 0; j < x; j++){
        printf(" R%d  |", j);
    }
    printf("\n------+");
    for(int j = 0; j < x; j++){
        printf("-----+");
    }
    printf("\n");

    for(int i = 0; i < y; i++){
        printf(" P%d   |", i);
        for(int j = 0; j < x; j++){
            if(i == processus_fini)
                printf("  *  |");
            else
                printf("  %d  |", m[j][i]);
        }
        printf("\n");
    }
}


//fonction de calcul de somme de colonne de la matrice de taille 2 de CURRENT .. ça sera utile pour la suite
int* sommme_colonnes_de_current(int x, int y, int** matrice_du_current){
    int* l_sommme_colonnes_de_current = malloc(x * sizeof(int));

    for(int k = 0; k < x; k++){
        int l_tmp = 0;
        for(int h = 0; h < y; h++){
            l_tmp += matrice_du_current[k][h];
        }
        l_sommme_colonnes_de_current[k] = l_tmp;
    }
    return l_sommme_colonnes_de_current;
}


int main(void){

    int nbr_p; // Entier qui représente le nombre de processus
    int nbr_r; // Entier qui représente le nombre de ressources
    int tmp = 0; // Valeur temporaire qui va nous servir à remplir nos tableaux
    
    printf("Entrez le nombre de processus \n>>>");
    scanf("%d", &nbr_p);
    
    printf("\nEntrez le nombre de ressources \n>>>");
    scanf("%d", &nbr_r);

    printf("\n------------------------------------------------------------------------------");
    printf("\nVECTEUR EXIST (Le nombre d'instances par ressource)");
    printf("\n------------------------------------------------------------------------------");

    int* m_exist;
    m_exist = (int*)malloc(nbr_r*sizeof(int));

    
    for (int i = 0; i < nbr_r; i++){
        printf("\nCombien de quantités de R[%d] existantes ?\n>>>", i);
        scanf("%d", &tmp);
        m_exist[i] = tmp;
    }

    affichage_matrice1(nbr_r,m_exist);

    int** m_current;

    m_current = (int**)malloc(nbr_r * sizeof(int*)); 
    for(int j = 0; j < nbr_r; j++){
        m_current[j] = (int*)malloc(nbr_p * sizeof(int));
    }

    for(int l = 0; l < nbr_r; l++){
        for(int s = 0; s < nbr_p; s++){
            printf("\nCOMBIEN DE R[%d] POSSÈDE P[%d] \n>>>",l,s);
            scanf("%d", &tmp);
            m_current[l][s] = tmp;
        }
    }

    printf("\n------------------------------------------------------------------------------");
    printf("\nVECTEUR CURRENT (Quel processus détient combien de ressources à l'instant I)");
    printf("\n------------------------------------------------------------------------------\n");

    affichage_matrice2(nbr_r, nbr_p, m_current);

    printf("\n Si jamais vous vous êtes trompé, relancez le programme ... c'est la V1, je ferai une V2 avec la gestion d'erreurs\n");

    printf("\n------------------------------------------------------------------------------");
    printf("\nVECTEUR AVAILABLE");
    printf("\n------------------------------------------------------------------------------");

    int* m_available = (int*)malloc(nbr_r * sizeof(int));

    int* m_sommme_colonnes_de_current = sommme_colonnes_de_current(nbr_r,nbr_p,m_current);

    printf("\nVoici le tableau qui représente la somme des colonnes de CURRENT : \n");

    affichage_matrice1(nbr_r, m_sommme_colonnes_de_current);

    printf("\nCalcul en cours pour la matrice AVAILABLE ... \n");

    for(int p = 0; p < nbr_r; p++){
        m_available[p] = m_exist[p] - m_sommme_colonnes_de_current[p];
    }

    printf("\nVoici le tableau qui représente la matrice AVAILABLE : \n");

    affichage_matrice1(nbr_r, m_available);


// Maintenant que AVAILABLE / CURRENT / EXIST sont faits, il nous manque deux autres comme REQUEST ou encore MAXREQUEST.
// L’un des deux nous suffit pour deviner l’autre, rappelez-vous de la relation du début : (REQUEST = MAXREQUEST - CURRENT).
// Donc dans l’examen, on pourrait avoir aussi bien MAXREQUEST que REQUEST.
//
// Pour expliquer REQUEST avec mes mots, je dirais que c’est la matrice de gestion des processus, autrement dit ce qui montre
// l’évolution des processus au cours du temps. Durant ce laps de temps, chaque processus prend et redonne des ressources chacun
// à leur tour, c’est pour cela qu’on peut voir AVAILABLE évoluer au cours du temps aussi.
//
// Et pour finir, MAXREQUEST c’est les ressources qu’il faut à un processus pour qu’il puisse s’arrêter et rendre ce qu’il a utilisé.
//
// Autre notion également : l’interblocage. C’est-à-dire que l’on ne peut pas donner de ressources à un processus x, non pas parce
// qu’on ne veut pas, mais parce qu’il n’existe pas de ressources pour lui à l’instant I. Et peut-être que ce processus x détient
// pas mal de ressources dont d’autres ont besoin pour se terminer, donc interblocage… mais dans ce code je ne vais pas faire de
// détection d’interblocage, peut-être dans la V2 du programme.


    printf("\n------------------------------------------------------------------------------");
    printf("\nVECTEUR REQUEST");
    printf("\n------------------------------------------------------------------------------");

    int** m_request;

    m_request = (int**)malloc(nbr_r * sizeof(int*)); 
    for(int j = 0; j < nbr_r; j++){
        m_request[j] = (int*)malloc(nbr_p * sizeof(int));
    }

    for(int l = 0; l < nbr_r; l++){
        for(int s = 0; s < nbr_p; s++){
            printf("\nCOMBIEN DE R[%d] DEMANDE P[%d] \n>>>",l,s);
            scanf("%d", &tmp);
            m_request[l][s] = tmp;
        }
    }

    affichage_matrice2(nbr_r,nbr_p,m_request);

    printf("\n------------------------------------------------------------------------------");
    printf("\nVECTEUR MAXREQUEST");
    printf("\n------------------------------------------------------------------------------");

    tmp = 0;
    int** m_maxrequest = (int**)malloc(nbr_r * sizeof(int*));
    for(int f = 0; f < nbr_r; f ++){
        m_maxrequest[f] = (int*)malloc(nbr_p * sizeof(int));
    }
    
    printf("\nCalcul en cours pour la matrice MAXREQUEST ... \n");

    for(int k = 0; k < nbr_r; k++){
        for(int h = 0; h < nbr_p; h++){
            tmp = m_request[k][h] + m_current[k][h];
            m_maxrequest[k][h] = tmp;
            tmp = 0;
        }
    }

    affichage_matrice2(nbr_r,nbr_p,m_maxrequest);

    printf("\n------------------------------------------------------------------------------");
    printf("\nVERIFICATION D'ETAT (Simulation d'exécution des processus)");
    printf("\n------------------------------------------------------------------------------\n");

    int* processus_termine = malloc(nbr_p * sizeof(int));
    for(int i = 0; i < nbr_p; i++){
        processus_termine[i] = 0;
    }

    int progression_possible = 1;

    while(progression_possible){
        progression_possible = 0;

        for(int p = 0; p < nbr_p; p++){

            if(processus_termine[p] == 1)
                continue;

            int demande_satisfaite = 1;

            for(int r = 0; r < nbr_r; r++){
                if(m_request[r][p] > m_available[r]){
                    demande_satisfaite = 0;
                    break;
                }
            }

            if(demande_satisfaite == 1){

                printf("Le processus P%d peut se terminer. Il libère ses ressources.\n", p);

                printf("CURRENT après la fin de P%d :\n", p);
                affichage_matrice2_avec_etoiles(nbr_r, nbr_p, m_current, p);
                printf("\n");

                for(int r = 0; r < nbr_r; r++){
                    m_available[r] += m_current[r][p];
                }

                processus_termine[p] = 1;
                progression_possible = 1;

                printf("Nouveau AVAILABLE :\n");
                affichage_matrice1(nbr_r, m_available);
                printf("\n");
            }
        }
    }

    int interblocage = 0;
    for(int p = 0; p < nbr_p; p++){
        if(processus_termine[p] == 0){
            interblocage = 1;
            break;
        }
    }

    if(interblocage == 1){
        printf("\n*** INTERBLOCAGE DETECTE ***\n");
        printf("Les processus suivants ne peuvent pas se terminer : ");
        for(int p = 0; p < nbr_p; p++){
            if(processus_termine[p] == 0)
                printf("P%d ", p);
        }
        printf("\n");
    }
    else{
        printf("\nAUCUN INTERBLOCAGE : Tous les processus peuvent se terminer.\n");
    }

    free(processus_termine);


    // -------------------------------------------------------------------------
    //  LIBERATION MEMOIRE
    // -------------------------------------------------------------------------

    free(m_exist);
    free(m_available);
    free(m_sommme_colonnes_de_current);

    for(int i = 0; i < nbr_r; i++){
        free(m_current[i]);
    }
    free(m_current);

    for(int i = 0; i < nbr_r; i++){
        free(m_request[i]);
    }
    free(m_request);

    for(int i = 0; i < nbr_r; i++){
        free(m_maxrequest[i]);
    }
    free(m_maxrequest);

    return 0;
}
