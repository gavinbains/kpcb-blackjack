# Set up compiler and necessary flags for compilations
CXX = g++
CPPFLAGS = -g -Wall -std=c++11

all: blackjack

# Compile the executable blackjack game
blackjack: Card.o Hand.o blackjack.cpp
	$(CXX) $(CPPFLAGS) Card.o Hand.o blackjack.cpp -o blackjack

# Compile the Card class into an object file
Card.o: Card.h Card.cpp
	$(CXX) $(CPPFLAGS) Card.cpp -c -o Card.o

# Compile Hand class into an object file
Hand.o: Hand.h Hand.cpp
	$(CXX) $(CPPFLAGS) Hand.cpp -c -o Hand.o

# Handle cleaning the directory
.PHONY: clean

clean: 
	rm Hand.o
	rm Card.o
	rm blackjack 
	
	              
