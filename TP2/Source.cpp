#include <iostream>
#include <cmath>
#include <string>
#include <random>
#include <fstream>
#include <sstream>

using namespace std;

// Définition de la structure Livre
struct Livre {
    string titre;            // Titre du livre
    int anneeEdition;        // Année de publication du livre
    int nbPages;             // Nombre de pages du livre
    double prixAchat;        // Prix d'achat du livre
    double prixVente;        // Prix de vente du livre
    int nbCopiesAchete;      // Nombre de copies achetées du livre
    int nbCopiesVendues;     // Nombre de copies vendues du livre
};

// Fonction pour déterminer si un livre est un bon vendeur
bool estBonVendeur(const Livre& livre) {
    // Calcul de la différence entre les revenus de vente et les coûts d'achat
    // Si cette différence est supérieure ou égale à 10000, le livre est considéré comme un bon vendeur
    return (livre.prixVente * livre.nbCopiesVendues) - (livre.prixAchat * livre.nbCopiesAchete) >= 10000.0;
}

// Définition de la structure Point
struct Point {
    char identifiant;   // Identifiant du point
    double x;           // Coordonnée x du point
    double y;           // Coordonnée y du point
};

// Fonction pour calculer la distance entre deux points
double distance(const Point& p1, const Point& p2) {
    // Utilisation de la formule
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}



void afficherMenu() {
    cout << "=== Menu TP2 ===" << endl;
    cout << "1. Exercice 1 : Afficher le nombre de jours d'un mois" << endl;
    cout << "2. Exercice 2 : Affiche tous les puissances de 2 comprises entre 1 et 32,000" << endl;
    cout << "3. Exercice 3 : Affiche la moyenne, le min et max de 5 nombres contenu dans un tableau " << endl ;
    cout << "4. Exercice 4 : Les nombres premiers entre 50 et 100" << endl;
    cout << "5. Exercice 5 : L'impot a payer"<< endl;
    cout << "8. Exercice 8 : Jeu de nombre" << endl;
    cout << "11. Exercice 11: Librairie" << endl;
    cout << "13. Exercice 13: Perimetre polygone" << endl;
    cout << "0. Quitter" << endl;
}

int main() {
    int choix;
    do {
        afficherMenu();
        cout << "--------------------------------------------------------" << endl;
        cout << "Entrez le numero d'un exercice (0 pour quitter) : ";
        cin >> choix;

        switch (choix) {

        case 1: {
            int choix; // Variable pour stocker le numéro du mois saisi par l'utilisateur
            // Tableau des noms des mois
            const string mois[12] = { "janvier", "fevrier", "mars", "avril", "mai", "juin",
                                     "juillet", "aout", "septembre", "octobre", "novembre", "decembre" };
            // Tableau du nombre de jours dans chaque mois
            const int jours[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

            cout << "Entrer le numero d'un mois : " << endl; // Demande à l'utilisateur de saisir un numéro de mois
            cin >> choix; // Lecture du numéro de mois saisi par l'utilisateur

            if (choix >= 1 && choix <= 12) { // Vérifie si le numéro de mois est valide (entre 1 et 12)
                // Affiche le nombre de jours dans le mois correspondant au numéro saisi par l'utilisateur
                cout << "Nombre de jours de " << mois[choix - 1] << " : " << jours[choix - 1] << "." << endl;
            }
            else {
                // Affiche un message d'erreur si le numéro de mois est invalide
                cout << "Numero de mois invalide. Veuillez entrer un numero entre 1 et 12." << endl;
            }
            break;
        }

        case 2: {
            int x = 2;
            // Boucle pour calculer les puissances de 2 tant que le résultat est inférieur ou égal à 32000
            for (int i = 0; pow(x, i) <= 32000; i++)
            {
                // Affiche les puissances de 2 pour les indices pairs
                if (i % 2 == 0)
                {
                    cout << x << "^" << i << " = " << pow(x, i) << endl;
                }
            }
            cout << "******************" << endl;
            // Boucle pour calculer les puissances de 2 tant que le résultat est inférieur ou égal à 32000
            for (int i = 0; pow(x, i) <= 32000; i++)
            {
                // Affiche les puissances de 2 pour les indices impairs
                if (i % 2 != 0) {
                    cout << x << "^" << i << " = " << pow(x, i) << endl;
                }
            }
            break;
        }

        case 3: {
            int tabSave[5]; // Déclaration d'un tableau de 5 entiers
            int nb, min, max;
            float moyenne = 0;
            // Boucle pour saisir les nombres et les stocker dans le tableau
            for (int i = 0; i < 5; i++)
            {
                cout << "Saisir le nombre " << i + 1 << ": " << endl;
                cin >> nb;
                tabSave[i] = nb;
                moyenne += nb; // Ajout du nombre pour calculer la moyenne
                // Vérification du minimum
                if (i == 0 || nb < min) {
                    min = nb;
                }
                // Vérification du maximum
                if (i == 0 || nb > max) {
                    max = nb;
                }
            }
            moyenne /= 5; // Calcul de la moyenne
            // Affichage des résultats
            cout << "La moyenne est : " << moyenne << endl;
            cout << "Le min est: " << min << endl;
            cout << "Le max est: " << max << endl;

            break;
        }


        case 4: {
            // Parcours de tous les nombres de 50 à 100 inclus
            for (int x = 50; x <= 100; x++)
            {
                bool Primer = true; // Variable pour indiquer si le nombre est premier, initialement vrai
                // Boucle pour vérifier si le nombre est premier
                for (int i = 2; i * i <= x; i++)
                {
                    if (x % i == 0) // Si le nombre est divisible par i, il n'est pas premier
                    {
                        Primer = false;
                        break;
                    }
                }
                // Si le nombre est premier, l'afficher
                if (Primer) {
                    cout << "Les nombres sont: " << x << endl;
                }
            }
            break;
        }

        case 5: {
            double impot, revenu, tranche1 = 10000, taxe1 = 0.05, taxe2 = 0.15;
            cout << "Entrez votre revenu annuel : ";
            cin >> revenu;

            // Calcul de l'impôt en fonction du revenu et des tranches d'imposition
            if (revenu <= tranche1)
            {
                impot = revenu * taxe1; // Si le revenu est inférieur ou égal à la première tranche, appliquer le taux de taxe1
            }
            else {
                impot = tranche1 * taxe1 + (revenu - tranche1) * taxe2; // Sinon, appliquer le taux de taxe2 sur le montant au-dessus de la première tranche
            }
            // Gestion d'un revenu négatif qui arrete le programme
            if (revenu < 0) {
                cout << "Le revenu ne peut pas etre negatif." << endl;
                break;
            }
            cout << "L'impot a payer est de : " << impot << endl;
            break;
        }


        case 8: {
            int nb; 
            bool trouve = false; // Variable pour indiquer si le nombre a été trouvé
            random_device rd; // Initialisation du générateur de nombres aléatoires
            mt19937 gen(rd()); // Initialisation du générateur 
            uniform_int_distribution<int> dist(0, 50); // Distribution uniforme pour générer des nombres entre 0 et 50
            int aleatoire = dist(gen); // Génération du nombre aléatoire

            cout << "Entrez un nombre: "; 
            // Boucle pour s'assurer que l'entrée de l'utilisateur est un nombre
            while (!(cin >> nb)) {
                cin.clear(); // Efface l'erreur de cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore le reste de la ligne erronée
                cout << "Entrez un nombre valide: "; // l'utilisateur doit saisir un nombre valide
            }
            do {
                // Comparaison du nombre saisi par l'utilisateur avec le nombre aléatoire
                if (nb < aleatoire) {
                    cout << "Nombre inferieur, reessayez: "; // Si le nombre est inférieur, demande à l'utilisateur de réessayer
                    cin >> nb;
                }
                else if (nb > aleatoire) {
                    cout << "Nombre superieur, reessayez: "; // Si le nombre est supérieur, demande à l'utilisateur de réessayer
                    cin >> nb;
                }
                else {
                    trouve = true; // Si les nombres correspondent, définir trouve à true et afficher un message de réussite
                    cout << "Bravo, vous avez trouve le bon nombre !" << endl;
                }
            } while (!trouve); // Répéter tant que le nombre n'a pas été trouvé
            break;
        }

        case 11: {
            string anneeStr; // Variable pour stocker l'année saisie par l'utilisateur sous forme de chaîne de caractères
            cout << "Entrez une annee : ";
            cin >> anneeStr; // Demande à l'utilisateur de saisir une année

            int annee;
            stringstream(anneeStr) >> annee; // Convertit la chaîne de caractères en entier

            ifstream fichier("Livres.dat"); // Ouverture du fichier contenant les informations sur les livres

            if (!fichier) { // Vérifie si le fichier a été ouvert avec succès
                cout << "Erreur: Impossible d'ouvrir le fichier Livres.dat" << endl;
                return 1; // Retourne une valeur d'erreur
            }

            string ligneActuelle, titreLivre; // Variables pour stocker les lignes lues du fichier et le titre du livre
            bool trouve = false; // Variable pour indiquer si des livres ont été trouvés pour l'année spécifiée

            // Parcours du fichier ligne par ligne
            while (getline(fichier, titreLivre)) {
                getline(fichier, ligneActuelle); // Lecture de la ligne suivante pour obtenir les détails du livre
                stringstream ss(ligneActuelle); // Création d'un stringstream à partir de la ligne lue pour extraire les données

                int anneeEdition;
                ss >> anneeEdition; // Extraction de l'année de publication du livre

                // Vérifie si l'année de publication correspond à l'année spécifiée par l'utilisateur
                if (anneeEdition == annee) {
                    Livre livre; // Création d'un objet Livre pour stocker les détails du livre
                    livre.titre = titreLivre; // Attribution du titre du livre
                    livre.anneeEdition = anneeEdition; // Attribution de l'année de publication

                    // Extraction des autres détails du livre depuis le stringstream
                    ss >> livre.nbPages >> livre.prixAchat >> livre.prixVente >> livre.nbCopiesAchete >> livre.nbCopiesVendues;

                    // Vérifie si le livre est un bon vendeur en appelant la fonction estBonVendeur
                    if (estBonVendeur(livre)) {
                        if (!trouve) {
                            cout << "Livres publies en " << annee << " : " << endl;
                            trouve = true; // Indique qu'un livre a été trouvé pour l'année saisi
                        }
                        cout << " - " << livre.titre << endl; // Affiche le titre du livre
                    }
                }
            }

            if (!trouve) {
                cout << "Aucun bon vendeur trouve pour l'annee " << annee << endl; // Affiche un message si aucun bon vendeur n'a été trouvé
            }

            fichier.close(); // Fermeture du fichier
            break; 
        }

        case 13: {
            ifstream fichier("Polygone.dat"); // Ouverture du fichier contenant les points du polygone

            if (!fichier) { // Vérifie si le fichier a été ouvert avec succès
                cout << "Erreur: Impossible d'ouvrir le fichier Polygone.dat" << endl;
                return 1; // Retourne une valeur d'erreur
            }

            const int MAX_POINTS = 26; // Définition de la taille maximale du tableau de points
            Point points[MAX_POINTS]; // Déclaration d'un tableau de points
            int cpt = 0; // Compteur de points

            char identifiant; // Variable pour stocker l'identifiant du point
            double x, y; // Variables pour stocker les coordonnées x et y du point

            // Lecture des points à partir du fichier et stockage dans le tableau de points
            while (fichier >> identifiant >> x >> y) {
                points[cpt++] = { identifiant, x, y }; // Ajoute le point au tableau et incrémente le compteur
            }

            fichier.close(); // Fermeture du fichier

            double perimetre = 0.0; // Initialisation du périmètre à 0

            // Calcul du périmètre en parcourant tous les points du polygone
            for (int i = 0; i < cpt - 1; ++i) {
                perimetre += distance(points[i], points[i + 1]); // Ajoute la distance entre chaque paire de points consécutifs
            }

            // Ajoute la distance entre le dernier point et le premier point pour fermer le polygone
            perimetre += distance(points[cpt - 1], points[0]);

            // Affichage du périmètre calculé
            cout << "Le périmètre du polygone est : " << perimetre << endl;
            break; 
        }


        case 0: {
            cout << "Au revoir !" << endl;
            break;
        }
        default: {
            cout << "Choix invalide. Veuillez entrer un numero entre 1 et 13 ( 0 pour quitter )." << endl;
            break;
        }
        }
    } while (choix != 0);

    return 0;
}
