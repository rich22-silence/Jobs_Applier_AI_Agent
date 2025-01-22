#include <stdio.h>
#include <string.h>

#define MAX_LIVRES 100
#define MAX_TITRE 100
#define MAX_AUTEUR 100

// Définir la structure pour un livre
typedef struct {
    int numero;                // Numéro unique
    char titre[MAX_TITRE];     // Titre du livre
    char auteur[MAX_AUTEUR];   // Auteur du livre
    int annee;                 // Année de publication
} Livre;

// Fonction pour valider une chaîne non vide
int validerChaine(const char *chaine) {
    return chaine != NULL && strlen(chaine) > 0;
}

// Fonction pour valider une année
int validerAnnee(int annee) {
    return annee > 1500;
}

// Fonction pour saisir un livre
void ajouterLivre(Livre *livres, int *nbLivres) {
    if (*nbLivres >= MAX_LIVRES) {
        printf("Vous ne pouvez pas ajouter plus de %d livres.\n", MAX_LIVRES);
        return;
    }

    Livre nouveauLivre;

    printf("Entrez le numéro unique du livre : ");
    scanf("%d", &nouveauLivre.numero);

    printf("Entrez le titre du livre : ");
    scanf(" %[^\n]", nouveauLivre.titre);
    while (!validerChaine(nouveauLivre.titre)) {
        printf("Le titre ne peut pas être vide. Réessayez : ");
        scanf(" %[^\n]", nouveauLivre.titre);
    }

    printf("Entrez le nom de l'auteur : ");
    scanf(" %[^\n]", nouveauLivre.auteur);
    while (!validerChaine(nouveauLivre.auteur)) {
        printf("Le nom de l'auteur ne peut pas être vide. Réessayez : ");
        scanf(" %[^\n]", nouveauLivre.auteur);
    }

    printf("Entrez l'année de publication : ");
    scanf("%d", &nouveauLivre.annee);
    while (!validerAnnee(nouveauLivre.annee)) {
        printf("L'année doit être supérieure à 1500. Réessayez : ");
        scanf("%d", &nouveauLivre.annee);
    }

    livres[*nbLivres] = nouveauLivre;
    (*nbLivres)++;
    printf("Le livre a été ajouté avec succès !\n");
}

// Fonction pour afficher les livres
void afficherLivres(const Livre *livres, int nbLivres) {
    if (nbLivres == 0) {
        printf("Aucun livre enregistré.\n");
        return;
    }

    printf("\n=== Liste des Livres ===\n");
    for (int i = 0; i < nbLivres; i++) {
        printf("Livre %d :\n", i + 1);
        printf("  Numéro : %d\n", livres[i].numero);
        printf("  Titre : %s\n", livres[i].titre);
        printf("  Auteur : %s\n", livres[i].auteur);
        printf("  Année : %d\n", livres[i].annee);
    }
}

// Fonction principale
int main() {
    Livre livres[MAX_LIVRES];
    int nbLivres = 0;
    int choix;

    do {
        printf("\n=== Gestion des Livres ===\n");
        printf("1. Ajouter un Livre\n");
        printf("2. Afficher tous les Livres\n");
        printf("3. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterLivre(livres, &nbLivres);
                break;
            case 2:
                afficherLivres(livres, nbLivres);
                break;
            case 3:
                printf("Au revoir !\n");
                break;
            default:
                printf("Option invalide. Réessayez.\n");
        }
    } while (choix != 3);

    return 0;
}