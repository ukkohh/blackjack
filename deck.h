#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cctype>

using namespace std;

// Korttipakka luodaan kahdesta osasta "maasta" (mark) ja "arvosta" (point)

struct Card {
    string mark;
    string point;
};

class Deck {
public:
    const string Mark[4] = { "Pata ", "Hertta ", "Risti ", "Ruutu " };
    const string Point[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

private:
    Card card[52];
    static int num;

// Määritellään funktiot pakan sekoitamiseen ja jakamiseen

public:
    Deck();
    void randomDeck();
    Card& dealDeck();
};


#endif // DECK_H
