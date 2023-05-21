#include <iostream>
#include "Board.h"
#include <string>

using namespace std;

int main() {
    int score1 = 0;
    int score2 = 0;
    int round = 1;

    char symbol1;
    char symbol2;
    cout << "Vali sümbol millega mängima hakkad:\n1. X\n2. O" << endl;
    cin >> symbol1;

    if (symbol1 == '1') {
        symbol1 = 'X';
        symbol2 = 'O';
    } else {
        symbol2 = 'X';
        symbol1 = 'O';
    }

    Mangija mangija1(symbol1);
    Mangija mangija2(symbol2);

    string mangija1Valik;
    string mangija2Valik;

    bool voit = false;
    bool viik = false;

    char kumbGamemode;
    cout << "Kas mängid arvuti või teise mängija vastu [a/m]: ";
    cin >> kumbGamemode;

    bool playAgain = true;

    while (playAgain) {
        Board board;
        board.joonistaLaud();
        switch (kumbGamemode) {
            case 'a':
                while (!voit && !viik) {
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
                    if (board.onLaudTäis()) {
                        viik = true;
                        break;
                    }

                    bool moveMade2 = false;
                    cout << "Arvuti käib" << endl;
                    while (!moveMade2) {
                        moveMade2 = board.lisaKaik(mangija2.arvutiKaik(board), mangija2);
                        if (moveMade2) {
                            board.joonistaLaud();
                        }
                    }

                    if (board.kontrolliVoit(mangija2)) {
                        viik = false;
                        break;
                    }
                    if (board.onLaudTäis()) {
                        viik = true;
                        break;
                    }
                }
                break;
            case 'm':
                while (!voit && !viik) {
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
                    if (board.onLaudTäis()) {
                        viik = true;
                        break;
                    }

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

                    if (board.kontrolliVoit(mangija2)) break;
                    if (board.onLaudTäis()) {
                        viik = true;
                        break;
                    }
                }
                break;
            default:
                break;
        }
        round++;

        // Update the scores based on the result of the round
        if (board.kontrolliVoit(mangija1)) {
            cout << "Mängija 1 võitis vooru!" << endl;
            score1++;
        } else if (board.kontrolliVoit(mangija2)) {
            cout << "Mängija 2 võitis vooru!" << endl;
            score2++;
        } else if (viik) {
            cout << "Viik!" << endl;
            viik = false;
        }

        // Display the current scores
        cout << "Kokkuvõttes:" << endl;
        cout << "Mängija 1: " << score1 << " punkti" << endl;
        cout << "Mängija 2: " << score2 << " punkti" << endl;

        // Ask the players if they want to play another round
        char playAgainChoice;
        cout << "Kas soovite veel ühe vooru mängida? (j/e): ";
        cin >> playAgainChoice;
        playAgain = (playAgainChoice == 'j' || playAgainChoice == 'J');
    }
    return 0;
}
