#include <iostream>
#include <ctime>    
#include <chrono>
#include <unistd.h>
#include <thread>
#include "puissance4.h"
using namespace std;

int main(int argc, char const *argv[])
{
    system("cls");
    srand(time(NULL));
    
    system("cls");
    
    int piece = rand() % 2; 
    cout << "--------------------------------------------" << endl << endl;
    cout << "La piece est : " << piece << endl;
    if(piece == 0) cout << "Ce sera l'ordinateur qui jouera le premier" << endl;
    else cout << "Ce sera le joueur qui jouera le premier" << endl;
    cout << endl;
    cout << "--------------------------------------------" << endl << endl;
    cout << "Entrez une hauteur : ";
    int h = 1;
    cin >> h;
    Puissance4 partie(h);
    system("cls");
    cout << "------------ LA PARTIE COMMENCE ------------" << endl << endl;
    if(piece == 0){
        while(true){

            int bestMove = 0;
            partie.JeuOrdi(bestMove, 1);
            system("cls");

            cout << "--------------------------------------------" << endl << endl;
            partie.jouer(bestMove,1);
            cout << "L'ordinateur a joue en " << bestMove << endl << endl;
            partie.affichage();
            cout << endl;
            cout << "--------------------------------------------" << endl << endl;

            if(partie.victoire(1) == true){
                cout << "L'ordinateur a gagne !" << endl;
                break;
            }
            if(partie.plein() == true){
                cout << "Match nul !" << endl;
                break;
            }

            int j;
            cout << "A vous de jouer ! (0-6) : ";
            cin >> j;
            partie.jouer(j,-1);
            system("cls");
            cout << "--------------------------------------------" << endl << endl;
            cout << "Vous avez joue en " << j << endl << endl;
            partie.affichage();
            cout << endl;
            cout << "--------------------------------------------" << endl << endl;

            if(partie.victoire(-1) == true){
                cout << "Vous avez gagne !" << endl;
                break;
            }
            if(partie.plein() == true){
                cout << "Match nul !" << endl;
                break;
            }

        }
    }
    else if(piece == 1){
        while(true){

            int j;
            cout << "A vous de jouer ! (0-6) : ";
            cin >> j;
            partie.jouer(j,-1);
            system("cls");
            cout << "--------------------------------------------" << endl << endl;
            cout << "Vous avez joue en " << j << endl << endl;
            partie.affichage();
            cout << endl;
            cout << "--------------------------------------------" << endl << endl;
            
            if(partie.victoire(-1) == true){
                cout << "Vous avez gagne !" << endl;
                break;
            }
            if(partie.plein() == true){
                cout << "Match nul !" << endl;
                break;
            }

            int bestMove;
            partie.JeuOrdi(bestMove, 1);
            system("cls");
            cout << "--------------------------------------------" << endl << endl;
            cout << "L'ordinateur a joue en " << bestMove << endl << endl;
            partie.jouer(bestMove,1);
            partie.affichage();
            cout << endl;
            cout << "--------------------------------------------" << endl << endl;

            if(partie.victoire(1) == true){
                cout << "L'ordinateur a gagne !" << endl;
                break;
            }
            if(partie.plein() == true){
                cout << "Match nul !" << endl;
                break;
            }

        }
    }

}
