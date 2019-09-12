# KPCB Blackjack

Blackjack project for the KPCB Fellowship

## Getting Started

These instructions will get you a copy of the project up and running on your
local machine for development and testing purposes. See deployment for notes
on how to deploy the project on a live system.

### Prerequisites

Pull the game from the repo with the following command:

```
git clone https://github.com/gbains8172/Blackjack.git
```

You need to have g++ installed in your environment or have a method of
compiling and running C++ code on your terminal.

g++ comes native on most \*nix systems but in case you don't have it simply run:

```
sudo apt-get update
sudo apt-get install g++
```
For windows, the following guides are useful to follow:

If you would like to use Cygwin:
```
http://www1.cmc.edu/pages/faculty/alee/g++/g++.html
```

if you would like to use MinGW
```
http://www.mingw.org/wiki/Getting_Started
```

### Compiling

cd into the fetched directory

```
cd Blackjack/
```

And run the Makefile

```
make
```

This should result in new object files called `Card.o` and `Hand.o` along with
an executable called `blackjack`

## Running the Game

To start playing the game, run:

```
./blackjack
```

## Rules of the Game

The game starts off with the player(s) and dealer all being dealt two cards each.

The game will then proceed with the player's turn. Here is where the player can
decide whether to hit or stay.

Hit = get a new card

Stay = pass and move to next turn

After the player is done with his/her turn and if they haven't lost yet, the
turn continues to the dealer's turn.

The dealer will hit until it wins or goes bust.

The aim of the game is for the player to get as close to 21 without going over.
The player will win if the dealer goes bust or if both player and dealer have
21, the game results in a tie.

## Design Choices

C++ is my go-to language for terminal based games. The control it provides and
the lack of heavy overhead when compared to Java and other languages along with
easy input/output through command line made it the best choice for this program.

I feel that one of the most important things when building any product is clean,
object-oriented, and modular code that is well documented. For blackjack, it was
the best decision to create objects for the game and keep the code as modular
and reusable as possible so that anyone can pick up the project and keep building
on top of it.

The softness of Aces required the most testing to make sure that I was able
to handle them well. I tested these with the following edge cases:
  1. Dealt 2 Aces off the bat
  2. Dealt 1 Ace and a 9 initially, and then hitting to receive a Face card
  3. Dealt 1 Ace and a 3 initially, and then hitting to receive a Face card, and then getting another Ace

## Built With

* [Random](http://www.cplusplus.com/reference/random/) - Modern random number
generation with variable distributions

## Contributing

If you have any contributions, such as implementing multiplayer capabilities or
tweaks to the code, feel free to send me a message.
I'd be happy to have contributors!

## Authors

* **Gavin Bains** - [Github](https://github.com/gbains8172) - [LinkedIn](https://linkedin.com/in/bainsgavin)

Will append this if contributions are made by the community!


## Acknowledgments

* Massive shout out to KPCB for compelling me to do this project it was
definitely a lot of fun.
