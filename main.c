#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 11

void longeurMot(int *, char[]);
void demanderMot(char[], char[]);
void ecrirePendu(int);
void ecrireMot(char[], char[]);
void lireLettre(int *, char[], char[]);
void comptageVie(int, int *, int *);

int main()
{
//Algorithme Jeu du pendu

//BUT : Permettre a des joueurs de jouer au jeu du pendu dans une console
//ENTREE : Le mot secret puis des lettres pour deviner ce premier
//SORTIE : La victoire ou la defaite des joueurs

    char s_mot[MAX], c_lettre, s_mot2[MAX];
    int etat=0, n_vie=0, n_k=0;

    demanderMot(s_mot, s_mot2);

    while (etat == 0){

        ecrirePendu(n_vie);
        ecrireMot(s_mot, s_mot2);
        lireLettre(&n_k, s_mot, s_mot2);
        comptageVie(n_k, &n_vie, &etat);
    }
    printf("Le mot etait %s \n", s_mot);
    return 0;
}
//MAIN
//On y execute cinq fonctions

void longeurMot(int *n_i, char s_mot[MAX]){
    *n_i=strlen(s_mot);
}
//On defini la fonction pour compter le nombre de caracteres dans le mot

void demanderMot(char s_mot[MAX], char s_mot2[MAX]){
    int n_i, n_j;
    do {
        printf("Ecrire un mot avec un maximum de %d caracteres \n", MAX-1);
        scanf("%s", s_mot);
    }while (strlen(s_mot) > MAX-1);

    longeurMot(&n_i, s_mot);

    for (n_j=0;n_j < n_i;n_j++) {
        s_mot2[n_j] = s_mot[n_j];
    }
}
//On defini une fonction pour demander un mot d'un maximum  de characteres MAX
//ET
//On y execute la fonction de nombre de caracteres

void ecrirePendu(int n_vie){
    system("cls"); //On efface l'ecran pour pouvoir afficher la potence relatif au nombre de vie

    switch (n_vie)
            {
            case 1 :
                printf("\n\n\n\n\n\n____\n\n");
                break;
            case 2 :
                printf("\n |\n");
                printf(" |\n");
                printf(" |\n");
                printf(" |\n");
                printf(" |\n");
                printf("_|__\n\n");
                break;
            case 3 :
                printf("____________\n");
                printf(" |\n");
                printf(" |\n");
                printf(" |\n");
                printf(" |\n");
                printf(" |\n");
                printf("_|__\n\n");
                break;
            case 4 :
                printf("____________\n");
                printf(" |       |\n");
                printf(" |\n");
                printf(" |\n");
                printf(" |\n");
                printf(" |\n");
                printf("_|__\n\n");
                break;
            case 5 :
                printf("____________\n");
                printf(" |       |\n");
                printf(" |       O\n");
                printf(" |\n");
                printf(" |\n");
                printf(" |\n");
                printf("_|__\n\n");
                break;
            case 6 :
                printf("____________\n");
                printf(" |       |\n");
                printf(" |       O\n");
                printf(" |       |\n");
                printf(" |\n");
                printf(" |\n");
                printf("_|__\n\n");
                break;
            case 7 :
                printf("____________\n");
                printf(" |       |\n");
                printf(" |       O\n");
                printf(" |      /|\n");
                printf(" |\n");
                printf(" |\n");
                printf("_|__\n\n");
                break;
            case 8 :
                printf("____________\n");
                printf(" |       |\n");
                printf(" |       O\n");
                printf(" |      /|\\\n");
                printf(" |\n");
                printf(" |\n");
                printf("_|__\n\n");
                break;
            case 9
             :
                printf("____________\n");
                printf(" |       |\n");
                printf(" |       O\n");
                printf(" |      /|\\\n");
                printf(" |      /\n");
                printf(" |\n");
                printf("_|__\n\n");
                break;
            case 10
             :
                printf("____________\n");
                printf(" |       |\n");
                printf(" |       O\n");
                printf(" |      /|\\\n");
                printf(" |      / \\\n");
                printf(" |\n");
                printf("_|__\n\n");
                break;
            }
//On defini une fonction pour construire la potence par rapport au nombre de vie
}

void ecrireMot(char s_mot[MAX], char s_mot2[MAX]){

    int n_k, n_j, n_i;
    char c_lettre;

    longeurMot(&n_i, s_mot);

    n_k=0;
    for (n_j=0;n_j < n_i;n_j++) {
        c_lettre = s_mot2[n_j];
        if (c_lettre == '*') {
            printf("%c ", s_mot[n_j]);
        }else{
            printf("_ ");
            n_k++;
        }
    }
    if (n_k <= 0) {
        printf("\n\nBravo c'est gagne !!!\n");
        exit(0);
    }
}
//On defini une fonction pour afficher le mot au fur et a mesure sur la console

void lireLettre(int *n_k, char s_mot[MAX], char s_mot2[MAX]){

    int n_j, n_i;
    char c_lettre;

    longeurMot(&n_i, s_mot);

    printf("\nDonne une lettre\n");
    scanf(" %c", &c_lettre);
    *n_k=0;
    for (n_j=0;n_j < n_i;n_j++) {
        if (c_lettre == s_mot2[n_j]) {
            s_mot2[n_j]='*';
            *n_k=1;
        }
    }
}
//On defini une fonction pour verifier la lettre entree

void comptageVie(int n_k, int *n_vie, int *etat){
    if (n_k == 0) {
        *n_vie=*n_vie+1;

        if (*n_vie == 11) {
            *etat=1;
        }
    }
}
//On defini une fonction pour compter le nombre de vie
