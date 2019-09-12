#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
    
private: // Private local variables
    int suit; // Suit of card
    int number; // Number on card

public:
    // Constructor: Sets up card suit, number, & value
    Card(int s, int n);
    Card();

    // Returns the actual suit name
    std::string getSuit();

    // Returns face cards and regular numbers
    std::string getNumber();

    // Turns number into correct blackjack value
    int getValue();
};

#endif