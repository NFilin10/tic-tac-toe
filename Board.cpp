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
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if ((manguLaud[i][j] != 'X' || manguLaud[i][j] != '0') && manguLaud[i][j] == lahter){
                manguLaud[i][j] = mangija.getSymbol();
                return true;

            }
        }
    }
    cout << "See lahter on juba valitud" << endl;
    return false;
}

bool Board::kontrolliVoit(Mangija mangija) {
    for (int i = 0; i < 3; ++i) {
        if ((manguLaud[i][0] == manguLaud[i][1] && manguLaud[i][1] == manguLaud[i][2]) ||
            (manguLaud[0][i] == manguLaud[1][i] && manguLaud[1][i] == manguLaud[2][i])) {
            cout << mangija.getSymbol() << " voitis";
            return true;
        }
    }

    if ((manguLaud[0][0] == manguLaud[1][1] && manguLaud[1][1] == manguLaud[2][2]) ||
        (manguLaud[0][2] == manguLaud[1][1] && manguLaud[1][1] == manguLaud[2][0])) {
        cout << mangija.getSymbol() << " voitis";
        return true;
    }

    if(manguLaud[0][0] != '1' && manguLaud[0][1] != '2' && manguLaud[0][2] != '3' &&
    manguLaud[1][0] != '4' && manguLaud[1][1] != '5' && manguLaud[1][2] != '6' &&
    manguLaud[2][0] != '7' && manguLaud[2][1] != '8' && manguLaud[2][2] != '9'){
        cout << "Its a tie" << endl;
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
