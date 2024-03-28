#include <iostream>
#include <cmath>
#include <string>
#include <random>
#include <fstream>
#include <sstream>

using namespace std;

// D�finition de la structure Livre
struct Livre {
    string titre;            // Titre du livre
    int anneeEdition;        // Ann�e de publication du livre
    int nbPages;             // Nombre de pages du livre
    double prixAchat;        // Prix d'achat du livre
    double prixVente;        // Prix de vente du livre
    int nbCopiesAchete;      // Nombre de copies achet�es du livre
    int nbCopiesVendues;     // Nombre de copies vendues du livre
};

// Fonction pour d�terminer si un livre est un bon vendeur
bool estBonVendeur(const Livre& livre) {
    // Calcul de la diff�rence entre les revenus de vente et les co�ts d'achat
    // Si cette diff�rence est sup�rieure ou �gale � 10000, le livre est consid�r� comme un bon vendeur
    return (livre.prixVente * livre.nbCopiesVendues) - (livre.prixAchat * livre.nbCopiesAchete) >= 10000.0;
}

// D�finition de la structure Point
struct Point {
    char identifiant;   // Identifiant du point
    double x;           // Coordonn�e x du point
    double y;           // Coordonn�e y du point
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
            int choix; // Variable pour stocker le num�ro du mois saisi par l'utilisateur
            // Tableau des noms des mois
            const string mois[12] = { "janvier", "fevrier", "mars", "avril", "mai", "juin",
                                     "juillet", "aout", "septembre", "octobre", "novembre", "decembre" };
            // Tableau du nombre de jours dans chaque mois
            const int jours[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

            cout << "Entrer le numero d'un mois : " << endl; // Demande � l'utilisateur de saisir un num�ro de mois
            cin >> choix; // Lecture du num�ro de mois saisi par l'utilisateur

            if (choix >= 1 && choix <= 12) { // V�rifie si le num�ro de mois est valide (entre 1 et 12)
                // Affiche le nombre de jours dans le mois correspondant au num�ro saisi par l'utilisateur
                cout << "Nombre de jours de " << mois[choix - 1] << " : " << jours[choix - 1] << "." << endl;
            }
            else {
                // Affiche un message d'erreur si le num�ro de mois est invalide
                cout << "Numero de mois invalide. Veuillez entrer un numero entre 1 et 12." << endl;
            }
            break;
        }

        case 2: {
            int x = 2;
            // Boucle pour calculer les puissances de 2 tant que le r�sultat est inf�rieur ou �gal � 32000
            for (int i = 0; pow(x, i) <= 32000; i++)
            {
                // Affiche les puissances de 2 pour les indices pairs
                if (i % 2 == 0)
                {
                    cout << x << "^" << i << " = " << pow(x, i) << endl;
                }
            }
            cout << "******************" << endl;
            // Boucle pour calculer les puissances de 2 tant que le r�sultat est inf�rieur ou �gal � 32000
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
            int tabSave[5]; // D�claration d'un tableau de 5 entiers
            int nb, min, max;
            float moyenne = 0;
            // Boucle pour saisir les nombres et les stocker dans le tableau
            for (int i = 0; i < 5; i++)
            {
                cout << "Saisir le nombre " << i + 1 << ": " << endl;
                cin >> nb;
                tabSave[i] = nb;
                moyenne += nb; // Ajout du nombre pour calculer la moyenne
                // V�rification du minimum
                if (i == 0 || nb < min) {
                    min = nb;
                }
                // V�rification du maximum
                if (i == 0 || nb > max) {
                    max = nb;
                }
            }
            moyenne /= 5; // Calcul de la moyenne
            // Affichage des r�sultats
            cout << "La moyenne est : " << moyenne << endl;
            cout << "Le min est: " << min << endl;
            cout << "Le max est: " << max << endl;

            break;
        }


        case 4: {
            // Parcours de tous les nombres de 50 � 100 inclus
            for (int x = 50; x <= 100; x++)
            {
                bool Primer = true; // Variable pour indiquer si le nombre est premier, initialement vrai
                // Boucle pour v�rifier si le nombre est premier
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

            // Calcul de l'imp�t en fonction du revenu et des tranches d'imposition
            if (revenu <= tranche1)
            {
                impot = revenu * taxe1; // Si le revenu est inf�rieur ou �gal � la premi�re tranche, appliquer le taux de taxe1
            }
            else {
                impot = tranche1 * taxe1 + (revenu - tranche1) * taxe2; // Sinon, appliquer le taux de taxe2 sur le montant au-dessus de la premi�re tranche
            }
            // Gestion d'un revenu n�gatif qui arrete le programme
            if (revenu < 0) {
                cout << "Le revenu ne peut pas etre negatif." << endl;
                break;
            }
            cout << "L'impot a payer est de : " << impot << endl;
            break;
        }


        case 8: {
            int nb; 
            bool trouve = false; // Variable pour indiquer si le nombre a �t� trouv�
            random_device rd; // Initialisation du g�n�rateur de nombres al�atoires
            mt19937 gen(rd()); // Initialisation du g�n�rateur 
            uniform_int_distribution<int> dist(0, 50); // Distribution uniforme pour g�n�rer des nombres entre 0 et 50
            int aleatoire = dist(gen); // G�n�ration du nombre al�atoire

            cout << "Entrez un nombre: "; 
            // Boucle pour s'assurer que l'entr�e de l'utilisateur est un nombre
            while (!(cin >> nb)) {
                cin.clear(); // Efface l'erreur de cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore le reste de la ligne erron�e
                cout << "Entrez un nombre valide: "; // l'utilisateur doit saisir un nombre valide
            }
            do {
                // Comparaison du nombre saisi par l'utilisateur avec le nombre al�atoire
                if (nb < aleatoire) {
                    cout << "Nombre inferieur, reessayez: "; // Si le nombre est inf�rieur, demande � l'utilisateur de r�essayer
                    cin >> nb;
                }
                else if (nb > aleatoire) {
                    cout << "Nombre superieur, reessayez: "; // Si le nombre est sup�rieur, demande � l'utilisateur de r�essayer
                    cin >> nb;
                }
                else {
                    trouve = true; // Si les nombres correspondent, d�finir trouve � true et afficher un message de r�ussite
                    cout << "Bravo, vous avez trouve le bon nombre !" << endl;
                }
            } while (!trouve); // R�p�ter tant que le nombre n'a pas �t� trouv�
            break;
        }

        case 11: {
            string anneeStr; // Variable pour stocker l'ann�e saisie par l'utilisateur sous forme de cha�ne de caract�res
            cout << "Entrez une annee : ";
            cin >> anneeStr; // Demande � l'utilisateur de saisir une ann�e

            int annee;
            stringstream(anneeStr) >> annee; // Convertit la cha�ne de caract�res en entier

            ifstream fichier("Livres.dat"); // Ouverture du fichier contenant les informations sur les livres

            if (!fichier) { // V�rifie si le fichier a �t� ouvert avec succ�s
                cout << "Erreur: Impossible d'ouvrir le fichier Livres.dat" << endl;
                return 1; // Retourne une valeur d'erreur
            }

            string ligneActuelle, titreLivre; // Variables pour stocker les lignes lues du fichier et le titre du livre
            bool trouve = false; // Variable pour indiquer si des livres ont �t� trouv�s pour l'ann�e sp�cifi�e

            // Parcours du fichier ligne par ligne
            while (getline(fichier, titreLivre)) {
                getline(fichier, ligneActuelle); // Lecture de la ligne suivante pour obtenir les d�tails du livre
                stringstream ss(ligneActuelle); // Cr�ation d'un stringstream � partir de la ligne lue pour extraire les donn�es

                int anneeEdition;
                ss >> anneeEdition; // Extraction de l'ann�e de publication du livre

                // V�rifie si l'ann�e de publication correspond � l'ann�e sp�cifi�e par l'utilisateur
                if (anneeEdition == annee) {
                    Livre livre; // Cr�ation d'un objet Livre pour stocker les d�tails du livre
                    livre.titre = titreLivre; // Attribution du titre du livre
                    livre.anneeEdition = anneeEdition; // Attribution de l'ann�e de publication

                    // Extraction des autres d�tails du livre depuis le stringstream
                    ss >> livre.nbPages >> livre.prixAchat >> livre.prixVente >> livre.nbCopiesAchete >> livre.nbCopiesVendues;

                    // V�rifie si le livre est un bon vendeur en appelant la fonction estBonVendeur
                    if (estBonVendeur(livre)) {
                        if (!trouve) {
                            cout << "Livres publies en " << annee << " : " << endl;
                            trouve = true; // Indique qu'un livre a �t� trouv� pour l'ann�e saisi
                        }
                        cout << " - " << livre.titre << endl; // Affiche le titre du livre
                    }
                }
            }

            if (!trouve) {
                cout << "Aucun bon vendeur trouve pour l'annee " << annee << endl; // Affiche un message si aucun bon vendeur n'a �t� trouv�
            }

            fichier.close(); // Fermeture du fichier
            break; 
        }

        case 13: {
            ifstream fichier("Polygone.dat"); // Ouverture du fichier contenant les points du polygone

            if (!fichier) { // V�rifie si le fichier a �t� ouvert avec succ�s
                cout << "Erreur: Impossible d'ouvrir le fichier Polygone.dat" << endl;
                return 1; // Retourne une valeur d'erreur
            }

            const int MAX_POINTS = 26; // D�finition de la taille maximale du tableau de points
            Point points[MAX_POINTS]; // D�claration d'un tableau de points
            int cpt = 0; // Compteur de points

            char identifiant; // Variable pour stocker l'identifiant du point
            double x, y; // Variables pour stocker les coordonn�es x et y du point

            // Lecture des points � partir du fichier et stockage dans le tableau de points
            while (fichier >> identifiant >> x >> y) {
                points[cpt++] = { identifiant, x, y }; // Ajoute le point au tableau et incr�mente le compteur
            }

            fichier.close(); // Fermeture du fichier

            double perimetre = 0.0; // Initialisation du p�rim�tre � 0

            // Calcul du p�rim�tre en parcourant tous les points du polygone
            for (int i = 0; i < cpt - 1; ++i) {
                perimetre += distance(points[i], points[i + 1]); // Ajoute la distance entre chaque paire de points cons�cutifs
            }

            // Ajoute la distance entre le dernier point et le premier point pour fermer le polygone
            perimetre += distance(points[cpt - 1], points[0]);

            // Affichage du p�rim�tre calcul�
            cout << "Le p�rim�tre du polygone est : " << perimetre << endl;
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
