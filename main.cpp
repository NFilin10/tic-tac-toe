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
    
    // Mängija valib sümboli
    cout << "Vali sümbol millega mängima hakkad:\n1. X\n2. O" << endl;
    cin >> symbol1;

    if (symbol1 == '1') { // Määrame sümbolid valiku järgi
        symbol1 = 'X';
        symbol2 = 'O';
    } else {
        symbol2 = 'X';
        symbol1 = 'O';
    }

    // Loome mängijad
    Mangija mangija1(symbol1);
    Mangija mangija2(symbol2);

    string mangija1Valik;
    string mangija2Valik;

    bool voit = false;
    bool viik = false;

    // Mängija valib, kas ta tahab mängida arvuti või teise mängija vastu
    char kumbGamemode;
    cout << "Kas mängid arvuti või teise mängija vastu [a/m]: ";
    cin >> kumbGamemode;
    while (kumbGamemode != 'a' && kumbGamemode != 'm') { // Kui mängija ei vali sobiva gamemodei, siis sunnib tal uuesti valida
        cout << "Valik '" << kumbGamemode << "' ei eksisteeri." << endl;
        cout << "Kas mängid arvuti või teise mängija vastu [a/m]: ";
        cin >> kumbGamemode;
    }

    bool playAgain = true;

    bool käik1 = true;
    bool algasKäik1 = false;

    while (playAgain) { // Peamine mängu loop
        Board board; // Loome uue laua
        board.joonistaLaud(); // Väljastame laua
        voit = false;
        viik = false;
        // Käikude vahetus
        käik1 = !algasKäik1; // Esimese käigu saab see, kes käis teisena eelmine mäng
        algasKäik1 = käik1; // Jätame meelde, kumb käib esimesena
        switch (kumbGamemode) {
            case 'a': // Arvuti vastu mängimine
                while (!voit && !viik) { // Kui keegi ei ole võitnud ja meil ei ole viik, siis mäng käib edasi
                    for (int i = 0; i < 2; i++) { // Üks käik mõlema mängija jaoks
                        bool moveMade1 = false;
                        bool moveMade2 = false;
                        if (käik1) { // Kui esimene mängija käib
                            while (!moveMade1) { // Kordama nii kaua, kuni mängija teeb sobiva käigu
                                cout << "Mängija1 sisesta lahter: ";
                                cin >> mangija1Valik; // Mängija valib, mis lahtrisse ta tahab märki lisada

                                if (mangija1Valik.size() == 1) { // Kui mängija sisestas mingit sorti märgi
                                    char mangija1ValikC = mangija1Valik.c_str()[0]; // Loome char tüüpi muutuja selle märgiga
                                    moveMade1 = board.lisaKaik(mangija1ValikC, mangija1); // Ja proovime käiku lisada
                                }

                                if (moveMade1) { // Kui käik sobis
                                    board.joonistaLaud(); // Siis joonistame laua
                                } else { // Muidu väljastame, et käik ei sobinud ja laseme mängijal uue käigu teha.
                                    cout << "Lahter " << mangija1Valik << " ei sobi." << endl;
                                }
                            }

                            // Peale igat käiku kontrollime, kas keegi võitis või kas meil on viik
                            if (board.kontrolliVoit(mangija1)) {
                                viik = false;
                                voit = true;
                                break;
                            }

                            if (board.onLaudTäis()) {
                                viik = true;
                                break;
                            }

                            käik1 = !käik1; // Nüüd on teise mängija käik
                        } else { // Kui arvuti käib
                            cout << "Arvuti käib" << endl;
                            while (!moveMade2) { // Igaks juhuks on while loop, et vältida probleeme, mille peale meie ei tulnud. Ei tohiks olla suurt mõju programmi kiirusele, kuna arvuti valib käigu ainult sobivate käikude seast.
                                moveMade2 = board.lisaKaik(mangija2.arvutiKaik(board), mangija2); // Arvuti valib käigu ja proovib seda mängida
                                if (moveMade2) { // Kui mängimine õnnestus, väljastame laua.
                                    board.joonistaLaud();
                                }
                            }

                            // Peale igat käiku kontrollime, kas keegi võitis või kas meil on viik
                            if (board.kontrolliVoit(mangija2)) {
                                viik = false;
                                voit = true;
                                break;
                            }
                            if (board.onLaudTäis()) {
                                viik = true;
                                break;
                            }
                            käik1 = !käik1; // Nüüd on esimese mängija käik
                        }
                    }
                }
                break;
            case 'm': // Kahe mängija vahel mängimine
                while (!voit && !viik) { // Kui keegi ei ole võitnud ja meil ei ole viik, siis mäng käib edasi
                    for (int i = 0; i < 2; i++) { // Üks käik mõlema mängija jaoks
                        bool moveMade1 = false;
                        bool moveMade2 = false;
                        if (käik1) { // Kui esimene mängija käib
                            while (!moveMade1) { // Kordama nii kaua, kuni mängija teeb sobiva käigu
                                cout << "Mängija1 sisesta lahter: ";
                                cin >> mangija1Valik; // Mängija valib, mis lahtrisse ta tahab märki lisada

                                if (mangija1Valik.size() == 1) { // Kui mängija sisestas mingit sorti märgi
                                    char mangija1ValikC = mangija1Valik.c_str()[0]; // Loome char tüüpi muutuja selle märgiga
                                    moveMade1 = board.lisaKaik(mangija1ValikC, mangija1); // Ja proovime käiku lisada
                                }

                                if (moveMade1) { // Kui käik sobis
                                    board.joonistaLaud(); // Siis joonistame laua
                                } else { // Muidu väljastame, et käik ei sobinud ja laseme mängijal uue käigu teha.
                                    cout << "Lahter " << mangija1Valik << " ei sobi." << endl;
                                }
                            }

                            // Peale igat käiku kontrollime, kas keegi võitis või kas meil on viik
                            if (board.kontrolliVoit(mangija1)) {
                                viik = false;
                                voit = true;
                                break;
                            }

                            if (board.onLaudTäis()) {
                                viik = true;
                                break;
                            }

                            käik1 = !käik1; // Nüüd on teise mängija käik
                        } else { // Kui teine mängija käib
                            while (!moveMade2) { // Kordama nii kaua, kuni mängija teeb sobiva käigu
                                cout << "Mängija2 sisesta lahter: ";
                                cin >> mangija2Valik; // Mängija valib, mis lahtrisse ta tahab märki lisada

                                if (mangija2Valik.size() == 1) { // Kui mängija sisestas mingit sorti märgi
                                    char mangija2ValikC = mangija2Valik.c_str()[0]; // Loome char tüüpi muutuja selle märgiga
                                    moveMade2 = board.lisaKaik(mangija2ValikC, mangija2); // Ja proovime käiku lisada
                                }

                                if (moveMade2) { // Kui käik sobis
                                    board.joonistaLaud(); // Siis joonistame laua
                                } else { // Muidu väljastame, et käik ei sobinud ja laseme mängijal uue käigu teha.
                                    cout << "Lahter " << mangija2Valik << " ei sobi." << endl;
                                }
                            }

                            // Peale igat käiku kontrollime, kas keegi võitis või kas meil on viik
                            if (board.kontrolliVoit(mangija2)) {
                                viik = false;
                                voit = true;
                                break;
                            }

                            if (board.onLaudTäis()) {
                                viik = true;
                                break;
                            }

                            käik1 = !käik1; // Nüüd on esimese mängija käik
                        }
                    }
                }
                break;
            default:
                break;
        }
        round++; // Mäng on läbi, lisame roundi

        // Uuendame punkte, kui keegi võitis ja väljastame mängu seisu
        if (board.kontrolliVoit(mangija1)) {
            cout << "Mängija 1 võitis vooru!" << endl;
            score1++;
        } else if (board.kontrolliVoit(mangija2)) {
            cout << "Mängija 2 võitis vooru!" << endl;
            score2++;
        } else if (viik) {
            cout << "Viik!" << endl;
        }

        // Väljastab punktid
        cout << "Kokkuvõttes:" << endl;
        cout << "Mängija 1: " << score1 << " punkti" << endl;
        cout << "Mängija 2: " << score2 << " punkti" << endl;

        // Küsib, kas mängija tahab uuesti mängida
        char playAgainChoice;
        cout << "Kas soovite veel ühe vooru mängida? (j/e): ";
        cin >> playAgainChoice;
        playAgain = (playAgainChoice == 'j' || playAgainChoice == 'J');
    }
    return 0;
}
