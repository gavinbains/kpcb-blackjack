#include <iostream>
#include "Hand.h"
#include "Card.h"

using namespace std;

void startGame();
void playerTurn(Hand&, Hand&);
void dealerTurn(Hand&, Hand&);
void playAgain();

/**
 * Driver for program
 * @return 0 to indicate successful run!
 */
int main() {
    // Start the game!
    startGame();
    return 0;
}

/** 
 * Sets up hand and plays the game
 * 
 */
void startGame() {
    // Sets up your hand and dealer's hand
    Hand playerHand("player"); 
    Hand dealerHand("dealer");

    // Shows your hand, and dealers shown card
    cout << "Your cards: " + playerHand.displayTwoCards() << endl;
    cout << "Dealer's card: " + dealerHand.displayOneCard() << endl;
    cout << "--------------------------" << endl;

    // Calls playerTurn function to begin play
    playerTurn(playerHand, dealerHand);

    // Displays final scores
    cout << "You had: " + to_string(playerHand.getTotalScore()) + " | Dealer had: " + to_string(dealerHand.getTotalScore()) << endl << endl;

    // calls playAgain function to give user option to play the game again
    playAgain();
}

/** 
 * Runs player hand, prompts to hit or stay and checks for win/bust
 * When player's turn is over, it calls the dealer's turn
 *
 * @param Hand& playerHand player's hand containing the player's cards passed by reference
 * @param Hand& dealerHand dealer's hand containing the dealer's cards passed by reference
 * 
 */
void playerTurn(Hand& playerHand, Hand& dealerHand) {
    // Checks if the player or dealer has a natural blackjack
    if(playerHand.getTotalScore() == 21 && playerHand.getCardAmount() == 2) {
        if(dealerHand.getTotalScore() == 21) {
            cout << "Both blackjacks! It's a tie!" << endl;
        } 
        else {
            cout << "Blackjack! You win!" << endl;
        }
    } 
    else if(playerHand.getTotalScore() < 21) {
        /* 
        The player does not have a natural black jack, give the player the 
        option to hit or stay with their current hand 
        */
        string hitOrStay;
        //Ask the player for their move until they make a valid choice
        while(true) { 
            cout << "Your score is: " + to_string(playerHand.getTotalScore()) + ". hit or stay?" << endl;
            cin >> hitOrStay;
            
            // Check for hit or stay
            if((hitOrStay == "h") | (hitOrStay == "hit")) {
                playerHand.hit(); // Deal player a card
                playerTurn(playerHand, dealerHand); 
                break;
            } 
            else if((hitOrStay == "s") | (hitOrStay == "stay")) {
                // Start dealer's turn if player chooses to stay
                dealerTurn(playerHand, dealerHand); 
                break;
            }
            else { // Remind player to choose
                cout << "Please enter either 'h' or 'hit' to hit or 's' or 'stay' to stay" << endl;
            }
        }
    } 
    else if(playerHand.getTotalScore() > 21) {  // Case for when player loses
        cout << "You went bust. Dealer wins." << endl;
    } 
    else { // Case when player ends turn without losing 
        // Display player's current score
        cout << "You got 21! Starting dealer's turn..." << endl;
        dealerTurn(playerHand, dealerHand); // Start dealer's turn
    }
}

/** 
 * Runs dealer's hand
 * 
 * @param Hand& playerHand player's hand containing the player's cards passed by reference
 * @param Hand& dealerHand dealer's hand containing the dealer's cards passed by reference
 * 
 */
void dealerTurn(Hand& playerHand, Hand& dealerHand) {
    // Check if Dealer has a natural blackjack
    if(dealerHand.getTotalScore() == 21 && dealerHand.getCardAmount() == 2) {
        cout << "Blackjack. Dealer wins." << endl;
    } // Else check if the dealer lost
    else if(dealerHand.getTotalScore() > 21) {
        cout << "Dealer went bust. You win!" << endl;
    } // Else determine whether dealer has won
    else if(dealerHand.getTotalScore() >= 17) {
        if(playerHand.getTotalScore() > dealerHand.getTotalScore()) {
            cout << "You win!" << endl;
        } 
        else {
            cout << "Dealer wins." << endl;
        }
    } 
    else { // Dealer keep's hitting until win/loss
        dealerHand.hit();
        dealerTurn(playerHand, dealerHand);
    }
}

/** 
 * Starts a new game or exits based on user's response
 *
 */
void playAgain() {
    string answer;
    cout << "==========================" << endl;
    while(true) { 
        // Ask player if they would like to play again
        cout << "Would you like to play again? (y/n)" << endl;
        cin >> answer;
        // Handle response
        if((answer == "y") | (answer == "yes")) {
            startGame(); // Start a new game if the player chooses 'y'
            break;
        } 
        else if((answer == "n") | (answer == "no")) { 
            // End game 
            cout << "Thanks for playing!" << endl << endl;
            break;
        }
        else { // Remind player to make a valid choice
            cout << "Please enter either 'y' for yes or 'n' for no" << endl;
        }
    }
}