#include "Board.h"


/**
 * Kuvab laua ekraanile
*/
void Board::joonistaLaud() {
    for (int i = 0; i < 3; ++i) { // Iga rea kaupa
        cout << " ";
        for (int j = 0; j < 3; ++j) { // Kuvame iga sümboli
            cout << manguLaud[i][j];
            if (j < 2) { // Kui me ei ole lõpus, kuvame laua osa
                cout << " ║ ";
            }
        }
        cout << "\n";
        if (i < 2) { // Kui me ei ole lõpus, kuvame laua osa
            cout << "═══╬═══╬═══\n";
        }
    }
    cout << endl;
}

/**
 * Lisab mangija sümboli antud lahtrisse ja tagastab true.
 * Kui lahtris on juba sümbol, siis tagastab false.
*/
bool Board::lisaKaik(char lahter, Mangija mangija) {
    for (int i = 0; i < 3; ++i) { // Iga rea seast
        for (int j = 0; j < 3; ++j) { // Iga elemendi seast
            if ((manguLaud[i][j] != 'X' || manguLaud[i][j] != 'O') && manguLaud[i][j] == lahter){ // Kui on tegu vaba elemendiga ja element on see mida otsime siis...
                manguLaud[i][j] = mangija.getSymbol(); // Asendame selle mängija sümboliga
                return true; // Ja tagastame true, sest käik on leitud
            }
        }
    }
    return false; // Kui käiku ei leitud, tagastame false
}

/**
 * Kontrollib igas rea, veerus ja diagonaalis, kas antud mangija on võitnud.
 * Tagastab true, kui mangija on võitnud. Muidu tagastab false.
*/
bool Board::kontrolliVoit(Mangija mangija) {
    for (int i = 0; i < 3; ++i) { // Vaatame igat veergu ja rida
        if ((manguLaud[i][0] == manguLaud[i][1] && manguLaud[i][1] == manguLaud[i][2] && mangija.getSymbol() == manguLaud[i][0]) ||
            (manguLaud[0][i] == manguLaud[1][i] && manguLaud[1][i] == manguLaud[2][i] && mangija.getSymbol() == manguLaud[0][i])) {
            // Kui leidub veerg või rida, kus iga lahter on mangija sümboliga, siis tagstame true
            return true;
        }
    }


    if (((manguLaud[0][0] == manguLaud[1][1] && manguLaud[1][1] == manguLaud[2][2]) ||
         (manguLaud[0][2] == manguLaud[1][1] && manguLaud[1][1] == manguLaud[2][0])) &&
        (mangija.getSymbol() == manguLaud[1][1])) {
        // Vaatame, kas vähemalt ühes diagonaalis on kõik sümbolid sama ja kas see sisaldab mangija sümbolit
        return true;
    }


    return false; // Kui keegi ei ole võitnud, tagastame false.
}

/**
 * Kui leidub lahter, kus ei ole sümbolit, siis tagastab false. Muidu tagstab true.
*/
bool Board::onLaudTäis() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) { // Vaatame igat lahtrit
            if (manguLaud[i][j] != 'X' && manguLaud[i][j] != 'O') {
                return false; // Kui leiame lahtri, kus ei ole mängija sümbol, siis tagstame false
            }
        }
    }
    return true; // Kui kõik lahtrid on täis, tagastame true
}

Mangija::Mangija(char symbol) {
    this->symbol = symbol;
}

char Mangija::getSymbol() {
    return symbol;
}

/**
 * Tagastab suvaliselt valitud käigu, mida arvuti mängib.
*/
char Mangija::arvutiKaik(Board board) {
    char* käigud{board.getKäigud()}; // Vaatame kõiki sobivaid käike
    int i{0};
    while (käigud[i] != 'L') { // Käigud lõppu on lisatud 'L' ehk Lõpp
        i++; // Loeme üle mitu käiku on olemas
    }
    
    srand(std::time(0)); // Kasutame seediks aega
    int kaik = std::rand() % (i); // Genereerime suvalise numbri
    return käigud[kaik]; // Tagastame valitud käigu
}


/**
 * Tagastab kõik võimalikud käigud, ehk kõik lahtrid, kus ei ole kellegi sümbolit.
 * Lisab lõppu 'L'
*/
char* Board::getKäigud() {
    char* käigud{new char[10]};
    int indeks{0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) { // Vaatame iga lahtri korral
            char ruut = manguLaud[i][j];
            if (isdigit(ruut)) { // Kas tegu on numbriga
                käigud[indeks] = ruut; // Kui tegu on numbriga, siis lisame selle sobivate käikude sekka
                indeks++; // Ja lähme järgmise elemendi juurde
            }
        }
    }
    käigud[indeks] = 'L'; // Kõige lõppu lisame 'L' ehk Lõpp, et hiljem vaadates teame täpselt, kus käigud lõpevad
    return käigud; // Tagastame leitud käigud
}