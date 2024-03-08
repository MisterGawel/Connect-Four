#ifndef PUISSANCE4_H
#define PUISSANCE4_H

class Puissance4 {

public:
    int T[6][7];
    int Col[7];
    int hmax; // la profondeur a partir de laquelle l’etat du jeu est 
              // évaluée par une fonction d’évaluation a concevoir
    Puissance4(int h);
    void affichage();
    void jouer(int j,int joueur);
    void dejouer(int j);
    bool coup_gagnant(int joueur, int &bestMove);
    int JeuOrdi(int & bestMove, int niveau);
    int evaluation(int joueur, int j);
    int JeuHumain(int & bestMove, int niveau);
    bool gagnant_colonne(int col, int joueur);
    bool gagnant_ligne(int row, int joueur);
    bool gagnant_diagonale(int joueur);
    bool plein();
    bool plein_col(int j);
    bool victoire(int joueur);
    int direction1(int joueur, int j);
    int direction2(int joueur, int j);
    int direction3(int joueur, int j);
    int direction4(int joueur, int j);
    void reinitialiser();
};

#endif 