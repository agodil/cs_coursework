/*
 * ComputerPlayer.h
 *
 *  Created on: May 14, 2019
 *      Author: student
 */

#ifndef COMPUTERPLAYER_H_
#define COMPUTERPLAYER_H_

#include "Player.h"

class ComputerPlayer: public Player {
public:
	/**
	 * constructor
	 */
	ComputerPlayer(std::string name);
	/**
	 * destructor
	 */
	virtual ~ComputerPlayer();
	/**
	 * Play a random card
	 */
	const Card playCard(const Card opponentCard);
};

#endif /* COMPUTERPLAYER_H_ */
