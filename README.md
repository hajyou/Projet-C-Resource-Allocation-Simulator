Programme en C qui manipule les vecteurs/matrices classiques de gestion de ressources
(**EXIST, CURRENT, AVAILABLE, REQUEST, MAXREQUEST**) et simule l’exécution des processus
afin de vérifier si l’état est **sûr** et/ou de détecter un **interblocage**.

> Rappels Formules :
- `AVAILABLE = EXIST - somme_colonnes(CURRENT)`
- `MAXREQUEST = CURRENT + REQUEST`
- (équivalent : `REQUEST = MAXREQUEST - CURRENT`)

## Fonctionnalités
- Saisie interactive :
  - nombre de processus `P`
  - nombre de ressources `R`
  - vecteur `EXIST`
  - matrice `CURRENT`
  - matrice `REQUEST`
- Calcul automatique :
  - `AVAILABLE`
  - `MAXREQUEST`
- Simulation :
  - Un processus `Pi` peut terminer si `REQUEST[:,i] <= AVAILABLE`
  - Quand il termine, il “libère” ses ressources : `AVAILABLE += CURRENT[:,i]`
- Résultat final :
  - **Aucun interblocage** si tous les processus peuvent terminer
  - **Interblocage détecté** sinon (liste des processus bloqués)

## Exemple (idée)
Le programme affiche les tableaux/matrices sous forme lisible et montre l’évolution de `AVAILABLE`
à chaque processus terminé.

## Compilation & Exécution

### Linux / macOS
```bash
gcc -Wall -pedantic programme_vecteurs.c -o Programme
./Programme
