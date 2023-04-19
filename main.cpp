#include <iostream>
#include "Board.h"


using namespace std;


int main() {
    Board board;
    char symbol1;
    char symbol2;
    cout << "Vali sümbol millega mangima hakkad" << endl;
    cin >> symbol1;



    if (symbol1 == 'X'){
        symbol2 = '0';
    }

    else{
        symbol2 = 'X';
    }

    Mangija mangija1(symbol1);
    Mangija mangija2(symbol2);

    board.joonistaLaud();

    char mangija1Valik;
    char mangija2Valik;

    bool voit = false;

//mängija vs mängija
/*
    while (!voit){
        bool moveMade1 = false;
        while (!moveMade1) {
            cout << "Mängija1 sisesta lahter" << endl;
            cin >> mangija1Valik;

            moveMade1 = board.lisaKaik(mangija1Valik, mangija1);
            if (moveMade1) {
                board.joonistaLaud();
            }
        }
        if (board.kontrolliVoit(mangija1)) break;



        bool moveMade2 = false;
        while (!moveMade2) {
            cout << "Mängija2 sisesta lahter" << endl;
            cin >> mangija2Valik;
            moveMade2 = board.lisaKaik(mangija2Valik, mangija2);
            if (moveMade2) {
                board.joonistaLaud();
            }
        }
        voit = board.kontrolliVoit(mangija2);
    }
    */

//Mängija vs arvuti
    while (!voit){
        bool moveMade1 = false;
        while (!moveMade1) {
            cout << "Mängija1 sisesta lahter" << endl;
            cin >> mangija1Valik;

            moveMade1 = board.lisaKaik(mangija1Valik, mangija1);
            if (moveMade1) {
                board.joonistaLaud();
            }
        }
        if (board.kontrolliVoit(mangija1)) break;



        bool moveMade2 = false;
        cout << "Arvuti käib" << endl;
        while (!moveMade2) {
            int arvutiKaik = mangija2.arvutiKaik();
            char arvutiKaik1 = arvutiKaik + '0';

            moveMade2 = board.lisaKaik(arvutiKaik1, mangija2);
            if (moveMade2) {
                board.joonistaLaud();
            }
        }
        voit = board.kontrolliVoit(mangija2);
    }
}
