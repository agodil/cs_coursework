/*
 * TerminalPlayer.h
 *
 *  Created on: May 6, 2019
 *      Author: student
 */

#ifndef TERMINALPLAYER_H_
#define TERMINALPLAYER_H_

#include "Player.h"

class TerminalPlayer: public Player {
public:
	/**
	 * constructor
	 */
	TerminalPlayer(std::string name);

	/**
	 * destructor
	 */
	virtual ~TerminalPlayer();

	/**
	 * Play a card. If the player receives a joker then this player is going first
	 */
	const Card playCard(const Card opponentCard);
};

#endif /* TERMINALPLAYER_H_ */
