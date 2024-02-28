#include <iostream>

enum class colors {
    BLUE, GREEN, RED, YELLOW, BLACK
};

enum class cardNames {
    ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, REVERSE, DRAW2, SKIP, DRAW4, WILD
};

/* the card names for this are just for the player, cards with special abilities will have a value less than 0 for example 
reverse will have a -1, draw2 -2, skip -3, draw4 -4, wild -5. Also for card colors the basic colors will be not be changed
but if a black card is played i plan for it to be made that the player then chooses a temporary color that can be played
ontop of said color*/
struct Card {
    cardNames name;
    colors color;
    int value;
};

struct Deck {
    //108 cards in the deck 
    Card arrCards[108];

    /*this will setup the cards so that we have all the cards which should be 9 number cards of each color with 1 zero
    2 of each specialty card, 4 black wild cards and 4 black draw 4 cards */
    void setupCards() {
        //this will tikk up on card creation, as long as its put in =)
        int cardsCreated = 0;

        for (int i = (int)colors::BLUE; i <= (int)colors::YELLOW; i++) {
            //there is only one 0 card for each color so that is here
            Card c;
            c.color = (colors)i;
            c.name = (cardNames)0;
            c.value = 0;
            
            // this is putting the cards into the deck, like a real deck of cards with an order
            int index
            arrCards[index] = 

            //this is going to give us 2 of every number card for each color and 2 of each specialty card
            for (int j = 0; j < 2; j++) {
                for (int k = (int)cardNames::ONE; k <= (int)cardNames::SKIP; k++) {
                    Card c;
                    c.color = (colors)i;
                    c.name = (cardNames)k;

                    // assigning the specialty cards with values less than 0
                    switch (c.name) {
                        case cardNames::REVERSE:
                            c.value = -1;
                            break;
                        case cardNames::DRAW2:
                            c.value = -2;
                            break;
                        case cardNames::SKIP:
                            c.value = -3;
                            break;
                        default:
                            c.value = (int)c.name;
                    }
                    std::cout << (int)c.color << "  " << (int)c.name << " " << (int)c.value << "\n";
                }
            }
        }

        // this will create 4 of each Black card (wild and draw4s)
        for (int i = (int)cardNames::DRAW4; i <= (int)cardNames::WILD; i++) {
            for(int k = 0; k < 4; k++) {
                Card c;
                c.color = (colors)((int)colors::BLACK);
                c.name = (cardNames)i;

                if (c.name == cardNames::DRAW4) {
                    c.value = -4;
                }
                else if (c.name == cardNames::WILD) {
                    c.value = -5;
                }
                else {
                    std::cout << "ERROR:: WILD//DRAW4";
                }
                std::cout << (int)c.color << " " << (int)c.name << " " << (int)c.value << "\n";
            }
        }
    }
};


int main() {
    Deck deck1;
    deck1.setupCards();

    return 0;
};