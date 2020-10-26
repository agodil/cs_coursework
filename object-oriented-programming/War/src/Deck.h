/*
 * Deck.h
 *
 *  Created on: Nov 11, 2014
 *      Author: williamhooper
 */

#ifndef DECK_H_
#define DECK_H_

#include <vector>

#include "Card.h"

#define MaxCards 52

/**
 * The Deck class holds a deck of 52 cards. Cards are not removed
 * from the Deck.
 */
class Deck {
public:
	/**
	 * Constructor and destructor
	 */
	Deck();
	virtual ~Deck();

	/**
	 * Shuffle the deck and reset the next available card to the beginning of the deck
	 */
	void shuffle();

	/**
	 * Return true if the deck is empty (next available card is past the end of the deck)
	 */
	bool isEmpty() const;

	/**
	 * Draw a card from the deck. If someone attempts to draw a card when the deck is
	 * empty then throw an out-of-range exception.
	 */
	const Card draw();

private:
	unsigned nextCard;
	std::vector<Card> cardDeck;
};

#endif /* DECK_H_ */
