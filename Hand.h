#ifndef HAND_H
#define HAND_H

#include "Card.h"

class Hand {

private: // Private local variables
// Stores first dealt card
    Card card1; 
    // Stores second dealt card
    Card card2; 
    // The new card when player calls for hit
    Card hitCard; 
    // Tracks number of cards dealt to Hand
    int cardsDealt; 
    // Tracks the total score of the Hand
    int totalScore; 
    // Number of Aces dealt to player that the play can switch from 11 to 1
    int numberOfAcesUsed; 
    // ID for owner of the Hand
    std::string handOwner;

public:
	// Constructor: Sets up cards and related methods
    Hand(std::string);// 
    Hand();

    // Creates a random card
    Card deal();

    // Returns the amount of cards in play
    int getCardAmount();

    // Adds new card to Hand & updates total score for a "hit"
    void hit();

    // Returns the total score of the Hand
    int getTotalScore();

    // Shows players dealt cards
    std::string displayTwoCards();

    // Displays the dealer's first card
    std::string displayOneCard();
};

#endif
