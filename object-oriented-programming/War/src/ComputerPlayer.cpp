/*
 * ComputerPlayer.cpp
 *
 *  Created on: May 14, 2019
 *      Author: student
 */

#include "ComputerPlayer.h"
#include <stdexcept>
#include <random>
#include <limits>
#include <ctime>

using namespace std;

ComputerPlayer::ComputerPlayer(string name) :
		Player(name) {
	// TODO Auto-generated constructor stub

}

ComputerPlayer::~ComputerPlayer() {
	// TODO Auto-generated destructor stub
}

/**
 * play random card, throw exception if hand empty
 */
const Card ComputerPlayer::playCard(const Card opponentCard) {
	// check if player has cards
	if (!hasCards())
		throw logic_error("");

	/*
	 * get card selection
	 */
	random_device rd;
	default_random_engine dre(rd());
	uniform_int_distribution<int> dist(0, hand.size() - 1);
	int cardInd = dist(dre);
	Card c = hand[cardInd];
	hand.erase(hand.begin() + cardInd);

	return c;
}

///**
// * output name
// */
//std::ostream& operator <<(std::ostream& out, const Player& p) {
//	return out << p.name;
//}
