#ifndef TIC_TAC_TOE_BOARD_H
#define TIC_TAC_TOE_BOARD_H
#include "iostream"

using namespace std;

class Mangija{
private:
    char symbol;

public:
    Mangija(char);
    char getSymbol();
};


class Board {

private:
    char manguLaud[3][3] {
            {'1','2','3'},
            {'4','5','6'},
            {'7','8','9'}
    };

public:
    void joonistaLaud();
    bool lisaKaik(char, Mangija);
    bool kontrolliVoit(Mangija);

};



#endif
