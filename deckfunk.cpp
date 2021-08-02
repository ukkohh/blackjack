#include "deck.h"

int Deck::num=0;

// Luo pakan

Deck::Deck() {
    for (int i=0;i<52;i++) {
        card[i].mark = Mark[i%4];
        card[i].point = Point[i%13];
    }
}

// Sekoitaa pakan

void Deck::randomDeck() {
    srand((unsigned int)time(0));
    for (int i=0;i<52;i++) {
        Card temp;
        temp = card[i];
        int r = rand()%52;
        card[i] = card[r];
        card[r] = temp;
    }
}

// Jakaa kortin ja huolehtii, että kortteja on jäljellä

Card& Deck::dealDeck()
{
    if (num<52)
        return card[num++];
    else
        cout<<"Kortit loppuivat.\n";
    exit(EXIT_FAILURE);
}
