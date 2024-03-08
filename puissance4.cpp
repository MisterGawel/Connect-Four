#include "puissance4.h"
#include <iostream>

using namespace std;
//  cd /c/Users/gaela/OneDrive/Documents/Informatique/S3/ALGORITHMIQUE_AVANCEE/TP5/

Puissance4::Puissance4(int h) {                             // Constructeur
    for (int i = 0; i < 6; i++) {                           // Initialisation du tableau       
        for (int j = 0; j < 7; j++) {                       
            T[i][j] = 0;                                    // 0 = case vide
        }
    }
    for (int i = 0; i < 7; i++) {
        Col[i] = -1;                                        // Initialisation du tableau des colonnes à -1
    }
    this->hmax = h;                                         // Initialisation de la profondeur
}


void Puissance4::affichage() {                              // Affichage du tableau
    cout << endl;
    for (int i = 5; i >= 0; i--) {                          // Parcours du tableau
        cout << i << " | ";
        for (int j = 0; j < 7; j++) {
            if (T[i][j] == 0) {                             // 0 = case vide
                cout << ". ";
            }
            if (T[i][j] == 1) {                             // 1 = case occupée par l'ordinateur        
                cout << "O ";                                   
            }
            if (T[i][j] == -1) {                            // -1 = case occupée par le joueur
                cout << "X ";
            }
        }
        cout << "| " << endl;
    }
    cout << "  -----------------" << endl;
    cout << "    0 1 2 3 4 5 6" << endl << endl;
}


void Puissance4::jouer(int j, int joueur) {                 // Fonction pour jouer
    while(j > 6 || j < 0){                                  // Vérification de la validité de la colonne
        cout << "Veuillez entrer un numero de colonne valide : ";
        cin >> j;                                           // Saisie de la colonne si elle n'est pas valide
    }
    if(joueur == -1){
        while(Col[j] == 5){                                 // Vérification de la validité de la colonne
            cout << "Veuillez entrer un numero de colonne valide : ";
            cin >> j;                                       // Saisie de la colonne si elle n'est pas valide
        }
    }
    if(Col[j] < 5 && T[Col[j] + 1][j] == 0){                // Vérification de la validité de la ligne
        Col[j] = Col[j] + 1;                                // Incrémentation de la ligne
        T[Col[j]][j] = joueur;                              // Affectation de la case
    }
    else return;
}


void Puissance4::dejouer(int j) {                           // Fonction pour déjouer
    T[Col[j]][j] = 0;                                       // Affectation de la case à 0
    Col[j] = Col[j] - 1;                                    // Décrémentation de la ligne
}


bool Puissance4::coup_gagnant(int joueur, int &bestMove) {   // Fonction pour vérifier si le coup est gagnant
    for (int i = 0; i < 7; ++i) {
        if (Col[i] < 5) {                                   // Vérification de la validité de la ligne
            jouer(i, joueur);                               // Jouer le coup
            if (gagnant_colonne(i, joueur) || gagnant_ligne(Col[i], joueur) || gagnant_diagonale(joueur)) {
                bestMove = i;                               // Affectation du meilleur coup si le coup est gagnant
                dejouer(i);                                 // Déjouer le coup
                return true;                                // Retourne vrai si le coup est gagnant
            }
            dejouer(i);                                     // Déjouer le coup
        }
    }
    return false;                                           // Retourne faux si le coup n'est pas gagnant
}


bool Puissance4::gagnant_colonne(int col, int joueur) {     // Fonction pour vérifier si le coup est gagnant en colonne
    int l = Col[col];                                       // Récupération de la ligne
    if (l >= 3) {                                           // Vérification de la validité de la ligne
        return (T[l][col] == joueur &&                      // Retourne vrai si le coup est gagnant dans la colonne
                T[l - 1][col] == joueur &&                      
                T[l - 2][col] == joueur &&
                T[l - 3][col] == joueur);
    }
    return false;
}


bool Puissance4::gagnant_ligne(int l, int joueur) {         // Fonction pour vérifier si le coup est gagnant en ligne
    if (l < 0 || l >= 6) {                                  // Vérification de la validité de la ligne
        return false;               
    }
    for (int col = 0; col <= 7 - 4; ++col) {                // Parcours du tableau
        if (T[l][col] == joueur &&                         
            T[l][col + 1] == joueur &&                          
            T[l][col + 2] == joueur &&
            T[l][col + 3] == joueur) {
            return true;                                    // Retourne vrai si le coup est gagnant dans la ligne
        }
    }
    return false;
}


bool Puissance4::gagnant_diagonale(int joueur) {            // Fonction pour vérifier si le coup est gagnant en diagonale
    for (int l = 0; l <= 2; ++l) {                          
        for (int col = 0; col <= 3; ++col) {                
            if (T[l][col] == joueur &&                      
                T[l + 1][col + 1] == joueur &&
                T[l + 2][col + 2] == joueur &&
                T[l + 3][col + 3] == joueur) {
                return true;                                // Retourne vrai si le coup est gagnant en diagonale gauche
            }
        }
    }

    for (int l = 3; l <= 5; ++l) {      
        for (int col = 0; col <= 3; ++col) {
            if (T[l][col] == joueur &&
                T[l - 1][col + 1] == joueur &&
                T[l - 2][col + 2] == joueur &&
                T[l - 3][col + 3] == joueur) {
                return true;                                // Retourne vrai si le coup est gagnant en diagonale droite  
            }
        }
    }

    return false;
}


bool Puissance4::plein() {                                  // Fonction pour vérifier si le tableau est plein
    for (int i = 0; i < 7; i++) {
        if (Col[i] != 5) {
            return false;
        }
    }
    return true;
}


bool Puissance4::plein_col(int j) {                         // Fonction pour vérifier si la colonne est pleine
    if(Col[j] == 5) return true;                            
    else return false;
}


int Puissance4::JeuOrdi(int &bestMove, int niveau) {        // Fonction pour que l'ordinateur joue
    int arg = 99999;
    int joueur = 1;

    if (plein()) return 0;

    if (coup_gagnant(joueur, bestMove)) return +1000;

    if (niveau == this->hmax) {
        int S = 0;
        for (int j = 0; j < 7; j++) {
            if (!plein_col(j)) {
                jouer(j, joueur);
                S = S + evaluation(joueur, j);
                dejouer(j);
            }
        }
        return S;
    }
    int val = -1000;
    for (int j = 0; j < 7; j++) {
        if (!plein_col(j)) {
            jouer(j, joueur);
            int res = JeuHumain(arg, niveau + 1);
            dejouer(j);
            if (res > val) {
                val = res;
                bestMove = j;
            }
        }
    }
    return val;
}


int Puissance4::JeuHumain(int &bestMove, int niveau) {      // Fonction pour que le joueur joue
    int arg = -99999;
    int joueur = -1;

    if (plein()) return 0;

    if (coup_gagnant(joueur, bestMove)) return -1000;

    if (niveau == this->hmax) {
        int S = 0;
        for (int j = 0; j < 7; j++) {
            if (!plein_col(j)) {
                jouer(j, joueur);
                S = S + evaluation(joueur, j);
                dejouer(j);
            }
        }
        return S;
    }
    int val = +1000;
    for (int j = 0; j < 7; j++) {
        if (!plein_col(j)) {
            jouer(j, joueur);
            int res = JeuOrdi(arg, niveau + 1);
            dejouer(j);
            if (res < val) {
                val = res;
                bestMove = j;
            }
        }
    }
    return val;
}


int Puissance4::evaluation(int joueur, int j) {             // Fonction pour évaluer le coup
    return direction1(joueur, j) + direction2(joueur, j) + direction3(joueur, j) + direction4(joueur, j);
}


int Puissance4::direction1(int joueur, int j) {             // Fonction pour évaluer le coup en verticale bas                
    int S = 0;                                              // S = score
    int i = Col[j];                                         // i = ligne    
    int k = 0;                                              // k = compteur
    while (i < 6 && k < 4) {                                // Vérification de la validité de la ligne et du compteur
        if (T[i][j] == joueur) {                            
            S = S + 5;                                      // Incrémentation du score
        } else if (T[i][j] == -joueur) {                     
            break;
        } else {
            S = S + 0;
        }
        i = i + 1;                                          // Incrémentation de la ligne
        k = k + 1;                                          // Incrémentation du compteur
    }
    return S;                                               // Retourne le score
}


int Puissance4::direction2(int joueur, int j) {             // Fonction pour évaluer le coup en verticale haut           
    int S = 0;                                             
    int i = Col[j];
    int k = 0;
    while (i >= 0 && k < 4) {                               // Vérification de la validité de la ligne et du compteur
        if (T[i][j] == joueur) {
            S = S + 1;                                      // Incrémentation du score
        } else if (T[i][j] == -joueur) {
            S = S - 1;
        } else {
            S = S + 0;
        }
        i = i - 1;
        k = k + 1;
    }
    return S;
}


int Puissance4::direction3(int joueur, int j) {             // Fonction pour évaluer le coup en diagonale gauche bas                      
    int S = 0;
    int i = Col[j];
    int k = 0;
    while (i < 6 && j < 7 && k < 4) {                       // Vérification de la validité de la ligne, de la colonne et du compteur
        if (T[i][j] == joueur) {                            
            S = S + 1;                                      // Incrémentation du score
        } else if (T[i][j] == -joueur) {
            S = S - 1;
        } else {
            S = S + 0;
        }
        i = i + 1;
        j = j + 1;
        k = k + 1;
    }
    return S;
}


int Puissance4::direction4(int joueur, int j) {             // Fonction pour évaluer le coup en diagonale droite bas           
    int S = 0;
    int i = Col[j];
    int k = 0;
    while (i >= 0 && j >= 0 && k < 4) {                     // Vérification de la validité de la ligne, de la colonne et du compteur
        if (T[i][j] == joueur) {    
            S = S + 1;                                      // Incrémentation du score
        } else if (T[i][j] == -joueur) {
            S = S - 1;
        } else {
            S = S + 0;
        }
        i = i - 1;
        j = j - 1;
        k = k + 1;
    }
    return S;
}


bool Puissance4::victoire(int joueur) {                     // Fonction pour vérifier si le joueur a gagné
    if(gagnant_diagonale(joueur)) return true;
    for(int i = 0; i < 6; i++){
        if(gagnant_ligne(i, joueur)) return true;
    }
    for(int i = 0; i < 7; i++){
        if(gagnant_colonne(i, joueur)) return true;
    }
    return false;
}

