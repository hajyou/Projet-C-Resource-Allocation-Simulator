#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char str[100];
   int i;
   printf("\n Entrez la chaîne à convertir en minuscule: ");
   fgets(str, sizeof(str), stdin);
   for (i = 0; str[i]!='\0'; i++) {
     /* si les caractères sont en majuscules, convertissez-les
        en minuscule en ajoutant 32 à leur valeur ASCII. */
      if(str[i] >= 'A' && str[i] <= 'Z') {
         str[i] = str[i] +32;
      }
   }
   printf("\n La chaîne en minuscule = %s", str);
   return 0;
}