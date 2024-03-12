#include <iostream>
#include "deck.h"

//holds the hand rules
struct Hand {
    std::deque<Card> baseHand;

    // this will play the card chosen 
    void playCard() {

    }
    void drawCard() {

    }
};

// this will be where the rules of the deck and cards played.
struct Table {
    Deck deck;
        deck.setupCards();
        deck.shuffle();

    int numPlayers() {
        //this is where the numplayers function is
        return 3;
    }
    
    

    void gaming(int numPlayers) {
        bool gameover;
        while(!gameover) {
            for (int i = 0; i < numPlayers; i++)


        }
    }

};

int main() {
    Table table;
    int numPlayers = table.numPlayers();
    table.gaming(numPlayers);

    return 0;
};