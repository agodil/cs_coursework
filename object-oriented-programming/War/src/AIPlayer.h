/*
 * AIPlayer.h
 *
 *  Created on: May 20, 2019
 *      Author: student
 */

#ifndef AIPLAYER_H_
#define AIPLAYER_H_

#include "Player.h"

class AIPlayer: public Player {
public:
	/**
	 * constructor
	 */
	AIPlayer(std::string name);
	/**
	 * destructor
	 */
	virtual ~AIPlayer();
	/**
	 * plays a card
	 */
	const Card playCard(const Card opponentCard);
	/**
	 * informs player of cards played
	 */
	void cardsPlayed(const Card card1, const Card card2);
private:
	/**
	 * returns number of cards played
	 */
	int knownCardsSum() const;

	// array to represent played cards
	int knownCards[14];
};

#endif /* AIPLAYER_H_ */
