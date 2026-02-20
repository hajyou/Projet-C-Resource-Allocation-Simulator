# Resource Allocation Simulateur  

Programme en C simulant la gestion de ressources entre plusieurs processus.  
Le projet implémente les concepts classiques vus en systèmes d’exploitation :

- EXIST
- CURRENT
- AVAILABLE
- REQUEST
- MAXREQUEST

Il permet de simuler l’exécution des processus et de détecter un éventuel interblocage.

---

## 📚 Concepts implémentés

Rappels théoriques :

- `AVAILABLE = EXIST - somme_colonnes(CURRENT)`
- `MAXREQUEST = CURRENT + REQUEST`
- Un processus peut terminer si :  
  `REQUEST[:,i] <= AVAILABLE`

Si un processus termine :
- Il libère ses ressources
- AVAILABLE est mis à jour

Si aucun processus ne peut progresser → interblocage détecté.

---

## ⚙️ Technologies utilisées

- Langage C
- Allocation dynamique mémoire (`malloc`, `free`)
- Manipulation de matrices dynamiques
- Simulation d’état sûr

---

## 🚀 Compilation & Exécution

### Linux / macOS

```bash
gcc -Wall -pedantic programme_vecteurs.c -o simulateur
./simulator
```

### Windows (MinGW)

```bash
gcc -Wall -pedantic programme_vecteurs.c -o simulateur.exe
simulateur.exe
```

---

## 📥 Entrées utilisateur

Le programme demande :

- Nombre de processus
- Nombre de ressources
- Vecteur EXIST
- Matrice CURRENT
- Matrice REQUEST

---

## 📌 Fonctionnalités

- Calcul automatique de AVAILABLE
- Calcul automatique de MAXREQUEST
- Simulation dynamique des processus
- Affichage des matrices formatées
- Détection d’interblocage
- Libération propre de la mémoire

---

## 🧠 Finalité du projet

Ce projet illustre :

- La gestion de ressources en systèmes d’exploitation
- La détection d’interblocage
- La manipulation de matrices dynamiques en C
- La gestion mémoire manuelle

---

## 👤 Auteur

HAJRI Youssef  
Étudiant en Informatique
