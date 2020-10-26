/*
 * Player.h
 *
 *  Created on: Nov 11, 2014
 *      Author: williamhooper
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>

#include "Card.h"

#define MAX_HAND_SIZE 3

/**
 * Abstract Player class
 */
class Player {
public:
	/**
	 * Deconstructor
	 */
	virtual ~Player() {
	}

	/**
	 * Play a card. If the player receives a joker then this player is going first
	 */
	virtual const Card playCard(const Card opponentCard) = 0;

	/**
	 * Receive a card from the dealer
	 */
	void receiveCard(const Card c) {
		hand.push_back(c);
	}

	/**
	 * Add points to the score
	 */
	void addScore(unsigned s) {
		score += s;
	}

	/**
	 * Get the score
	 */
	int getScore() const {
		return score;
	}

	/**
	 * Return true if the player has cards in the hand
	 */
	bool hasCards() const {
		return (hand.size() != 0);
	}

	/**
	 * Receive the cards played from the previous round. This member function would
	 * be used by a computer player that may need to 'see' what cards were played.
	 */
	void cardsPlayed(const Card card1, const Card card2) {
	}

	/**
	 * Output the player's name
	 */
	friend std::ostream& operator <<(std::ostream& out, const Player& p);

protected:
	/**
	 * Constructor. Since this is an abstract class we do not want anyone instantiating
	 * a player class so we make it protected.
	 */
	Player(std::string name) :
			score(0), name(name), hand(0) {
	}

	int score;
	std::string name;
	std::vector<Card> hand;
};

#endif /* PLAYER_H_ */
