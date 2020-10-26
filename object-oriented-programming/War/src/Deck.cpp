/*
 * Deck.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: student
 */

#include "Deck.h"
#include <vector>
#include <stdexcept>
#include <random>
#include <algorithm>

using namespace std;

/*
 * constructor
 */
Deck::Deck() {
	/*
	 * add cards to vector
	 */
	for (int i = 1; i < 14; i++) {
		for (int j = 0; j < 4; j++) {
			cardDeck.push_back(Card(Card::Suit(j), Card::Rank(i)));
		}
	}
	nextCard = 0;
}

/*
 * destructor
 */
Deck::~Deck() {

}

/*
 * shuffle deck
 * reset nextCard
 */
void Deck::shuffle() {
	random_device rd;
	std::shuffle(cardDeck.begin(), cardDeck.end(), default_random_engine(rd()));
	nextCard = 0;
}

/*
 * tests if all cards drawn
 */
bool Deck::isEmpty() const {
	return nextCard == MaxCards;
}

/*
 * returns the next card in the deck
 * increments nextCard
 */
const Card Deck::draw() {
	if (isEmpty()) {
		throw out_of_range("");
	}
	nextCard++;
	return cardDeck[nextCard - 1];
}
