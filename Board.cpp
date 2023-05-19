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
            cout << manguLaud[i][j] << ":" << lahter << endl;
            if ((manguLaud[i][j] != 'X' || manguLaud[i][j] != 'O') && manguLaud[i][j] == lahter){ // Kui on tegu vaba elemendiga ja element on see mida otsime siis...
                manguLaud[i][j] = mangija.getSymbol(); // Asendame selle mängija sümboliga
                return true; // Ja tagastame true, sest käik on leitud
            }
        }
    }
    return false; // Kui käiku ei leitud, tagastame false
}

bool Board::kontrolliVoit(Mangija mangija) {
    for (int i = 0; i < 3; ++i) {
        if ((manguLaud[i][0] == manguLaud[i][1] && manguLaud[i][1] == manguLaud[i][2] && mangija.getSymbol() == manguLaud[i][0]) ||
            (manguLaud[0][i] == manguLaud[1][i] && manguLaud[1][i] == manguLaud[2][i] && mangija.getSymbol() == manguLaud[0][i])) {
            //cout << mangija.getSymbol() << " võitis FIRST";
            return true;
        }
    }

    if (((manguLaud[0][0] == manguLaud[1][1] && manguLaud[1][1] == manguLaud[2][2]) ||
         (manguLaud[0][2] == manguLaud[1][1] && manguLaud[1][1] == manguLaud[2][0])) &&
        (mangija.getSymbol() == manguLaud[1][1])) {
        //cout << mangija.getSymbol() << " võitis";
        return true;
    }


    return false;
}


bool Board::onLaudTäis() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (manguLaud[i][j] != 'X' && manguLaud[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}



Mangija::Mangija(char symbol) {
    this->symbol = symbol;
}

char Mangija::getSymbol() {
    return symbol;
}

char Mangija::arvutiKaik(Board board) {
    char* käigud{board.getKäigud()};
    int i{0};
    while (käigud[i] != 'L') {
        i++;
    }
    
    srand(std::time(0));
    int kaik = std::rand() % (i - 1);
    cout << käigud[kaik] << " :" << endl;
    return käigud[kaik];
}

char* Board::getKäigud() {
    char* käigud{new char[10]};
    int indeks{0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char ruut = manguLaud[i][j];
            if (isdigit(ruut)) {
                käigud[indeks++] = ruut; 
            }
        }
    }
    käigud[indeks] = 'L';
    return käigud;
}

//board.joonistaLaud();