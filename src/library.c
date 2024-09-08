// library.c
#include <stdio.h>
#include <string.h>
#include "library.h"

// Global variables
char titles[MAX_BOOKS][MAX_TITLE_LENGTH];
char authors[MAX_BOOKS][MAX_AUTHOR_LENGTH];
float prices[MAX_BOOKS];
int quantities[MAX_BOOKS];
int bookCount = 0;

// Function implementations
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Le stock est plein. Impossible d'ajouter plus de livres.\n");
        return;
    }

    printf("Entrez le titre du livre : ");
    if (scanf(" %[^\n]", titles[bookCount]) != 1) {
        printf("Erreur de saisie du titre.\n");
        return;
    }
    
    printf("Entrez l'auteur du livre : ");
    if (scanf(" %[^\n]", authors[bookCount]) != 1) {
        printf("Erreur de saisie de l'auteur.\n");
        return;
    }

    printf("Entrez le prix du livre : ");
    if (scanf("%f", &prices[bookCount]) != 1 || prices[bookCount] < 0) {
        printf("Erreur de saisie du prix. Assurez-vous d'entrer un nombre positif.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Entrez la quantité en stock : ");
    if (scanf("%d", &quantities[bookCount]) != 1 || quantities[bookCount] < 0) {
        printf("Erreur de saisie de la quantité. Assurez-vous d'entrer un nombre entier positif.\n");
        while (getchar() != '\n');
        return;
    }

    bookCount++;
    printf("Livre ajouté avec succès.\n");
}

void displayBooks() {
    if (bookCount == 0) {
        printf("Aucun livre en stock.\n");
        return;
    }

    printf("Livres disponibles :\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d. Titre: %s, Auteur: %s, Prix: %.2f€, Quantité: %d\n",
               i + 1, titles[i], authors[i], prices[i], quantities[i]);
    }
}

void searchBook() {
    char searchTitle[MAX_TITLE_LENGTH];
    printf("Entrez le titre du livre à rechercher : ");
    if (scanf(" %[^\n]", searchTitle) != 1) {
        printf("Erreur de saisie du titre.\n");
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(titles[i], searchTitle) == 0) {
            printf("Livre trouvé :\n");
            printf("Titre: %s, Auteur: %s, Prix: %.2f€, Quantité: %d\n",
                   titles[i], authors[i], prices[i], quantities[i]);
            return;
        }
    }

    printf("Livre non trouvé.\n");
}

void updateQuantity() {
    char updateTitle[MAX_TITLE_LENGTH];
    printf("Entrez le titre du livre à mettre à jour : ");
    if (scanf(" %[^\n]", updateTitle) != 1) {
        printf("Erreur de saisie du titre.\n");
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(titles[i], updateTitle) == 0) {
            printf("Entrez la nouvelle quantité : ");
            if (scanf("%d", &quantities[i]) != 1 || quantities[i] < 0) {
                printf("Erreur de saisie de la quantité. Assurez-vous d'entrer un nombre entier positif.\n");
                return;
            }
            printf("Quantité mise à jour avec succès.\n");
            return;
        }
    }

    printf("Livre non trouvé.\n");
}

void deleteBook() {
    char deleteTitle[MAX_TITLE_LENGTH];
    printf("Entrez le titre du livre à supprimer : ");
    if (scanf(" %[^\n]", deleteTitle) != 1) {
        printf("Erreur de saisie du titre.\n");
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(titles[i], deleteTitle) == 0) {
            for (int j = i; j < bookCount - 1; j++) {
                strcpy(titles[j], titles[j + 1]);
                strcpy(authors[j], authors[j + 1]);
                prices[j] = prices[j + 1];
                quantities[j] = quantities[j + 1];
            }
            bookCount--;
            printf("Livre supprimé avec succès.\n");
            return;
        }
    }

    printf("Livre non trouvé.\n");
}

void displayTotalBooks() {
    int total = 0;
    for (int i = 0; i < bookCount; i++) {
        total += quantities[i];
    }
    printf("Nombre total de livres en stock : %d\n", total);
}
