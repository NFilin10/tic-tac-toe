#include "Board.h"

void Board::joonistaLaud() {
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << manguLaud[i][j];
            if (j < 2) {
                cout << " ║ ";
            }
        }
        cout << "\n";
        if (i < 2) {
            cout << "═══╬═══╬═══\n";
        }
    }
    cout << endl;
}

bool Board::lisaKaik(char lahter, Mangija mangija) {
    for (int i = 0; i < 3; ++i) { // Iga rea seast
        for (int j = 0; j < 3; ++j) { // Iga elemendi seast
            if ((manguLaud[i][j] != 'X' || manguLaud[i][j] != '0') && manguLaud[i][j] == lahter){ // Kui on tegu vaba elemendiga ja element on see mida otsime siis...
                manguLaud[i][j] = mangija.getSymbol(); // Asendame selle mängija sümboliga
                return true; // Ja tagastame true, sest käik on leitud
            }
        }
    }
    return false; // Kui käiku ei leitud, tagastame false
}

bool Board::kontrolliVoit(Mangija mangija) {
    for (int i = 0; i < 3; ++i) {
        if ((manguLaud[i][0] == manguLaud[i][1] && manguLaud[i][1] == manguLaud[i][2]) ||
            (manguLaud[0][i] == manguLaud[1][i] && manguLaud[1][i] == manguLaud[2][i])) {
            cout << mangija.getSymbol() << " võitis";
            return true;
        }
    }

    if ((manguLaud[0][0] == manguLaud[1][1] && manguLaud[1][1] == manguLaud[2][2]) ||
        (manguLaud[0][2] == manguLaud[1][1] && manguLaud[1][1] == manguLaud[2][0])) {
        cout << mangija.getSymbol() << " võitis";
        return true;
    }

    if(manguLaud[0][0] != '1' && manguLaud[0][1] != '2' && manguLaud[0][2] != '3' &&
    manguLaud[1][0] != '4' && manguLaud[1][1] != '5' && manguLaud[1][2] != '6' &&
    manguLaud[2][0] != '7' && manguLaud[2][1] != '8' && manguLaud[2][2] != '9'){
        cout << "Viik" << endl;
        return true;
    }

    return false;


}


Mangija::Mangija(char symbol) {
    this->symbol = symbol;
}

char Mangija::getSymbol() {
    return symbol;
}

int Mangija::arvutiKaik() {
    srand(std::time(0));
    int kaik = std::rand() % 9 + 1;
    return kaik;
}
//board.joonistaLaud();