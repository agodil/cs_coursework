/*
 * TerminalPlayer.cpp
 *
 *  Created on: May 6, 2019
 *      Author: student
 */

#include "TerminalPlayer.h"
#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

/**
 Get unsigned int from user input
 **/
unsigned get_index_from_input(string input_message,
		string invalid_input_message, unsigned lower, unsigned upper) {

	unsigned input_value = 0;

	/**
	 keep collecting input until valid input
	 **/
	while (true) {
		cout << input_message;
		cin >> input_value;
		if (cin && input_value >= lower && input_value < upper) {
			// break if unsigned is found
			break;
		} else if (cin.fail()
				|| (input_value < lower || input_value >= upper)) {
			// bad input
			cout << invalid_input_message << '\n';

			// clear data in cin
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} else {
			// other stream state
			throw runtime_error("cin is eof or bad");
		}
	}
	// clear data in cin
	cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return input_value;
}

/**
 * constructor
 * use parent constructor
 */
TerminalPlayer::TerminalPlayer(string name) :
		Player(name) {

}

/**
 * destructor
 */
TerminalPlayer::~TerminalPlayer() {

}

/**
 * play card
 * throw exception if hand is empty
 */
const Card TerminalPlayer::playCard(const Card opponentCard) {
	// check if player has cards
	if (!hasCards())
		throw logic_error("");

	cout << '\n';
	/*
	 * inform the player as first or second
	 */
	if (opponentCard.isJoker()) {
		cout << name << ": You are first." << endl;
	} else {
		// output opponent's card
		cout << name << ": You are second.\nOpponent has played "
				<< opponentCard << endl;
	}

	cout << "Play a card" << endl;
	cout << "Hand:" << endl;
	/*
	 * output hand cards
	 */
	for (unsigned int i = 0; i < hand.size(); i++) {
		cout << i << ": " << hand[i] << endl;
	}

	cout << '\n';

	/*
	 * get card selection from player
	 */
	unsigned cardInd;
	cardInd = get_index_from_input("Enter card number: ", "Invalid number", 0,
			hand.size());
	Card c = hand[cardInd];
	cout << '\n';

	hand.erase(hand.begin() + cardInd);

	return c;
}

/**
 * output name
 */
std::ostream& operator <<(std::ostream& out, const Player& p) {
	return out << p.name;
}
