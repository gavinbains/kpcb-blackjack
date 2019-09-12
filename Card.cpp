#include "Card.h"
#include <time.h>

/**
 * Constructor: Sets up card suit, number, & value
 *
 * @param Int s is the integer representation of the suit on the card
 * @param Int n is the number on the card
 *
 */
Card::Card(int s, int n){
    suit = s;
    number = n;
}

/**
 * Default barebones constructor for Card.
 * This is not used but is kept in the code
 * so that the compiler doesn't complain
 *
 */
Card::Card(){}

/**
 * Returns the actual suit name
 * 
 * @return String that represents the suit of the card
 *
 */
std::string Card::getSuit(){
    switch(suit) {
        case 1: // if int suit is 1, return Spades
            return "Spades";
        case 2: // if int suit is 2, return Hearts
            return "Hearts";
        case 3: // if int suit is 3, return Diamonds
            return "Diamonds";
        case 4: // if int suit is 4, return Clubs
            return "Clubs";
        default:
            // Will never happen
            srand(time(NULL)); //initialize the random seed
            std::string suitArray[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
            int randIndex = rand() % 4;
            // return random card suit
            return suitArray[randIndex];
    }
}

/**
 * Returns face cards and regular numbers
 * 
 * @return String that represents the number or face of the card
 *
 */
std::string Card::getNumber(){
    switch(number) {
        // Check if face card
        case 1: // If number is 1 return Ace
            return "Ace";
        case 11: // If number is 11 return Jack
            return "Jack";
        case 12: // If number is 12 return Queen
            return "Queen";
        case 13: // If number is 13 return King
            return "King";
        default: // Else return the number
            return std::to_string(number);
    }
}

/**
 * Turns number into correct blackjack value
 * 
 * @return The integer value of the card.
 *
 */
int Card::getValue(){
    if(number > 9) {
        // All cards above 9 are worth 10
        return 10;
    } 
    else if(number == 1) {
        // Ace is worth a soft 11 
        return 11;
    } 
    else {
        // Normal cards are taken at written value
        return number;
    }
}