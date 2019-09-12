#include "Hand.h"
#include "Card.h"
#include <iostream>
#include <cmath>
#include <random>

/**
 * Constructor: Sets up cards and calculates the initial total score
 * 
 * @param String that acts as flag identifying the owner of the card 
 * (implemented for future scalability)
 * 
 */
Hand::Hand(std::string whoseHand) {
    card1 = deal(); // Deal first card
    card2 = deal(); // Deal second card
    cardsDealt = 2; // Initialize total cards in hand to 2
    numberOfAcesUsed = 0; // This keeps track of Ace transitions from 11 to 1
    // Calculate total score of Hand
    totalScore = card1.getValue() + card2.getValue();
    // If Hand contains Ace, account for softness
    if((card1.getNumber() == "Ace") | (card2.getNumber() == "Ace")){
        // Set number of Aces;
        numberOfAcesUsed = 1;
        // In case the Ace causes the user to go over 21
        if(totalScore > 21){
            totalScore -= 10;
        }
    }
    // Set flag for who owns the hand
    handOwner = whoseHand; 
}

/**
 * Default barebones constructor for Hand
 * This is not used but is kept in the code
 * so that the compiler doesn't complain
 *
 */
Hand::Hand(){}

/** 
 * Creates a random card using the <random> library to generate better and more 
 * modern randomness than the traditional rand() function
 * 
 * @return Card that the player is dealt either as the initial hand or after 
 * they call for a hit
 * 
 */
Card Hand::deal() {
    // obtain a random number from hardware
    std::random_device rd; 
    // seed the generator
    std::mt19937 eng(rd()); 
    // define the range for card suit
    std::uniform_int_distribution<> randSuit(1, 4); 
    // define the range for card number
    std::uniform_int_distribution<> randNum(1, 13); 

    // Private local variables
    int s = floor(randSuit(eng));
    int n = floor(randNum(eng));
    
    return Card(s, n);
}

/**
 * Returns the amount of cards that a player has been dealt
 * 
 * @return Integer number of cards dealt to the players
 * 
 */
int Hand::getCardAmount() {
    return cardsDealt;
}

/**
 * Adds new card & updates total score when a player calls for a "hit"
 * 
 */
void Hand::hit() {
    // Create card using deal()
    Card hitCard = deal();
    // Update the total score of the hand and the number cards in the hand
    totalScore += hitCard.getValue();
    // Increment numberOfAcesUsed if Ace is dealt
    if(hitCard.getNumber() == "Ace"){
        ++numberOfAcesUsed;
    }
    // Handle the case where an Ace's value goes from 11 to 1
    while(totalScore > 21 && numberOfAcesUsed > 0){
        // Switch Ace from 11 to 1
        totalScore -= 10;
        // Mark Ace as used
        --numberOfAcesUsed;
    }
    // Increment the total cards dealt to the hand
    cardsDealt++;
    // Output results to screen
    if(handOwner == "dealer"){
        std::cout << "Dealer drew " + hitCard.getNumber() + " of " + hitCard.getSuit() << std::endl;
    }
    else{
        std::cout << "You were dealt " + hitCard.getNumber() + " of " + hitCard.getSuit() << std::endl;
    }
}

/**
 * Retrieves the total score of the cards in the current hand
 * 
 * @return Integer total score of the Hand
 */
int Hand::getTotalScore() {
    return totalScore;
}

/**
 * Shows players dealt cards
 * 
 * @return string of the cards in the player's hand.
 * 
 */
std::string Hand::displayTwoCards() {
    std::string x = card1.getNumber() + " of " + card1.getSuit();
    std::string y = card2.getNumber() + " of " + card2.getSuit();
    return x + ", " + y;
}

/**
 * Displays the dealer's first card
 * 
 * @return string of the card that the dealer initally reveals at start of play 
 * from the dealer's hand
 * 
 */
std::string Hand::displayOneCard() {
    std::string x = card1.getNumber() + " of " + card1.getSuit();
    return x;
}