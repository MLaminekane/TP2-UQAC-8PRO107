#include <iostream>
#include <cmath>
#include <string>
#include <random>
#include <fstream>
#include <sstream>

using namespace std;

struct Livre {
    string titre;
    int anneeEdition;
    int nbPages;
    double prixAchat;
    double prixVente;
    int nbCopiesAchete;
    int nbCopiesVendues;
};

bool estBonVendeur(const Livre& livre) {
    return (livre.prixVente * livre.nbCopiesVendues) - (livre.prixAchat * livre.nbCopiesAchete) >= 10000.0;
}

struct Point {
    char identifiant;
    double x;
    double y;
};

double distance(const Point& p1, const Point& p2) {
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
            int choix;
            cout << "Entrer le numero d'un mois : " << endl;
            cin >> choix;
            switch (choix)
            {
            case 1: {
                cout << "Nombre de jours de janvier : 31." << endl;
                break;
            }
            case 2: {
                cout << "Nombre de jours de fevrier : 28, mais 29 pour les annees bissextiles." << endl;
                break;
            }
            case 3: {
                cout << "Nombre de jours de mars : 31." << endl;
                break;
            }
            case 4: {
                cout << "Nombre de jours d'avril : 30." << endl;
                break;
            }
            case 5: {
                cout << "Nombre de jours de mai : 31." << endl;
                break;
            }
            case 6: {
                cout << "Nombre de jours de juin : 30." << endl;
                break;
            }
            case 7: {
                cout << "Nombre de jours de juillet : 31." << endl;
                break;
            }
            case 8: {
                cout << "Nombre de jours d'août : 31." << endl;
                break;
            }
            case 9: {
                cout << "Nombre de jours de septembre : 30." << endl;
                break;
            }
            case 10: {
                cout << "Nombre de jours d'octobre : 31." << endl;
                break;
            }
            case 11: {
                cout << "Nombre de jours de novembre : 30." << endl;
                break;
            }
            case 12: {
                cout << "Nombre de jours de decembre : 31." << endl;
                break;
            }
            default: {
                cout << "Numero de mois invalide. Veuillez entrer un numero entre 1 et 12." << endl;
                break;
            }
            }
        }

        case 2: {
            int x = 2;
            for (int i = 0; pow(x, i) <= 32000; i++)
            {
                if (i % 2 == 0)
                {
                    cout << x << "^" << i << " = " << pow(x, i) << endl;
                }
            }
            cout << "******************" << endl;
            for (int i = 0; pow(x, i) <= 32000; i++)
            {
                if (i % 2 != 0) {
                    cout << x << "^" << i << " = " << pow(x, i) << endl;
                }
            }
            break;
        }

        case 3: {
            int tabSave[5];
            int nb, min, max;
            float moyenne = 0;
            for (int i = 0; i < 5; i++)
            {
                cout << "Saisir le nombre " << i + 1 << ": " << endl;
                cin >> nb;
                tabSave[i] = nb;
                moyenne += nb;
                if (i == 0 || nb < min) {
                    min = nb;
                }
                if (i == 0 || nb > max) {
                    max = nb;
                }
            }
            moyenne /= 5;
            cout << "La moyenne est : " << moyenne << endl;
            cout << "Le min est: " << min << endl;
            cout << "Le max est: " << max << endl;

            break;
        }

        case 4: {
            for (int x = 50; x <= 100; x++)
            {
                bool Primer = true;
                for (int i = 2; i * i <= x; i++)
                {
                    if (x % i == 0)
                    {
                        Primer = false;
                        break;
                    }
                }
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
            if (revenu <= tranche1)
            {
                impot = revenu * taxe1;
            }
            else {
                impot = tranche1 * taxe1 + (revenu - tranche1) * taxe2;
            }
            cout << "L'impot a payer est de : " << impot << endl;
        }

        case 8: {
            int nb;
            bool trouve = false;
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> dist(0, 50);
            int aleatoire = dist(gen);
            cout << "Entrez un nombre: ";
            while (!(cin >> nb)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrez un nombre valide: ";
            }
            do {
                if (nb < aleatoire) {
                    cout << "Nombre inferieur, reessayez: ";
                    cin >> nb;
                }
                else if (nb > aleatoire) {
                    cout << "Nombre superieur, reessayez: ";
                    cin >> nb;
                }
                else {
                    trouve = true;
                    cout << "Bravo, vous avez trouve le bon nombre !" << endl;
                }
            } while (!trouve);
            break;
        }

        case 11: {
              string anneeStr;
              cout << "Entrez une annee : ";
              cin >> anneeStr;
              int annee;
              stringstream(anneeStr) >> annee; 
              ifstream fichier("Livres.dat");
              if (!fichier) {
                  cout << "Erreur: Impossible d'ouvrir le fichier Livres.txt" << endl;
                  return 1;
              }
              string ligneActuelle, titreLivre;
              bool trouve = false;
              while (getline(fichier, titreLivre)) {
                  getline(fichier, ligneActuelle);
                  stringstream ss(ligneActuelle);
                  int anneeEdition;
                  ss >> anneeEdition;
                  if (anneeEdition == annee) {
                      Livre livre;
                      livre.titre = titreLivre;
                      livre.anneeEdition = anneeEdition;
                      ss >> livre.nbPages >> livre.prixAchat >> livre.prixVente >> livre.nbCopiesAchete >> livre.nbCopiesVendues;
                      if (estBonVendeur(livre)) {
                          if (!trouve) {
                              cout << "Livres publies en " << annee << " : " << endl;
                              trouve = true;
                          }
                          cout << " - " << livre.titre << endl;
                      }
                  }
              }
              if (!trouve) {
                  cout << "Aucun bon vendeur trouve pour l'annee " << annee << endl;
              }
              fichier.close();
              break;
        }

        case 13: {
            ifstream fichier("Polygone.dat");
            if (!fichier) {
                cerr << "Erreur: Impossible d'ouvrir le fichier Polygone.txt" << endl;
                return 1;
            }

            const int MAX_POINTS = 26;
            Point points[MAX_POINTS];
            int cpt = 0;

            char identifiant;
            double x, y;
            while (fichier >> identifiant >> x >> y) {
                points[cpt++] = { identifiant, x, y };
            }
            fichier.close();
            double perimetre = 0.0;
            for (int i = 0; i < cpt - 1; ++i) {
                perimetre += distance(points[i], points[i + 1]);
            }
            perimetre += distance(points[cpt - 1], points[0]);
            cout << "Le perimetre du polygone est : " << perimetre << endl;
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
