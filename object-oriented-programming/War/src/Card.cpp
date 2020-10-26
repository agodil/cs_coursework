/*
 * Card.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: student
 */

#include "Card.h"
#include <iostream>
#include <string>

using namespace std;

/*
 * constructor
 */
Card::Card(Suit s, Rank r) {
	cardSuit = s;
	cardRank = r;
}

/*
 * construct joker
 */
Card::Card() {
	cardRank = Joker;
	cardSuit = Spades;
}

/*
 * << operator
 */
std::ostream& operator <<(std::ostream& os, const Card& c) {
	// output joker
	if (c.isJoker()) {
		return os << "Joker";
	}
	// output in format
	return os << rankNames[c.cardRank] + " of " + suitNames[c.cardSuit];
}

/*
 * == operator
 * compare rank
 */
bool operator ==(const Card &lhs, const Card &rhs) {
	return lhs.cardRank == rhs.cardRank;
}

/*
 * < operator
 * compare rank
 */
bool operator <(const Card &lhs, const Card &rhs) {
	return lhs.cardRank < rhs.cardRank;
}
