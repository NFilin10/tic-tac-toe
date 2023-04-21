#include <iostream>
#include "Board.h"
#include <string>

using namespace std;

int main() {
    Board board;
    char symbol1;
    char symbol2;
    cout << "Vali sümbol millega mangima hakkad: ";
    cin >> symbol1;



    if (symbol1 == 'X'){
        symbol2 = '0';
    }

    else{
        symbol2 = 'X';
    }

    Mangija mangija1(symbol1);
    Mangija mangija2(symbol2);

    string mangija1Valik;
    string mangija2Valik;

    bool voit = false;

    char kumbGamemode;
    cout << "Kas mängid arvuti või teise mängija vastu [a/m]: ";
    cin >> kumbGamemode;

    board.joonistaLaud();

    switch (kumbGamemode)
    {
    case 'a':
        while (!voit) {
            bool moveMade1 = false;
            while (!moveMade1) { // Nii kaua kui mängija ei ole sobivat käiku teinud, kordame seda
                cout << "Mängija1 sisesta lahter: ";
                cin >> mangija1Valik;

                if (mangija1Valik.size() == 1) {
                    char mangija1ValikC = mangija1Valik.c_str()[0];
                    moveMade1 = board.lisaKaik(mangija1ValikC, mangija1);
                }

                if (moveMade1) {
                    board.joonistaLaud();
                } else {
                    cout << "Lahter " << mangija1Valik << " ei sobi." << endl;
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
        break;
    case 'm':
        while (!voit){
            bool moveMade1 = false;
            while (!moveMade1) {
                cout << "Mängija1 sisesta lahter: ";
                cin >> mangija1Valik;

                if (mangija1Valik.size() == 1) {
                    char mangija1ValikC = mangija1Valik.c_str()[0];
                    moveMade1 = board.lisaKaik(mangija1ValikC, mangija1);
                }

                if (moveMade1) {
                    board.joonistaLaud();
                } else {
                    cout << "Lahter " << mangija1Valik << " ei sobi." << endl;
                }
            }
            if (board.kontrolliVoit(mangija1)) break;



            bool moveMade2 = false;
            while (!moveMade2) {
                cout << "Mängija2 sisesta lahter: ";
                cin >> mangija2Valik;

                if (mangija2Valik.size() == 1) {
                    char mangija2ValikC = mangija2Valik.c_str()[0];
                    moveMade2 = board.lisaKaik(mangija2ValikC, mangija2);
                }

                if (moveMade2) {
                    board.joonistaLaud();
                } else {
                    cout << "Lahter " << mangija2Valik << " ei sobi." << endl;
                }
            }
            voit = board.kontrolliVoit(mangija2);
        }
        break;
    default:
        break;
    }
}
