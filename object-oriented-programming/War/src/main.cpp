/*
 * main.cpp
 *
 *  Created on: Apr 30, 2019
 *      Author: student
 */
#include <iostream>
#include <stdexcept>
#include <random>
#include <ctime>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "TerminalPlayer.h"
#include "ComputerPlayer.h"
#include "AIPlayer.h"

using namespace std;

int main() {

	// players
	AIPlayer aPlayer("AI Player");
	TerminalPlayer bPlayer("Terminal Player");

	Player& player1 = aPlayer;
	Player& player2 = bPlayer;

	// init deck
	Deck deck;
	deck.shuffle();

	// joker for first player
	Card joker;

	// pick first and second players
	random_device rd;
	default_random_engine dre(rd());
	uniform_int_distribution<int> dist(0, 1);
	bool player1First = dist(dre) == 1;

	// deal initial three cards
	for (int i = 0; i < 3; i++) {

		player1.receiveCard(deck.draw());

		player2.receiveCard(deck.draw());
	}

	/*
	 * turns
	 * play while there are cards
	 */
	while (player1.hasCards() && player2.hasCards()) {

		Card player1Card, player2Card;

		/*
		 * play cards
		 */
		if (player1First) {

			player1Card = player1.playCard(joker);
			cout << player1 << " has played " << player1Card << endl;

			player2Card = player2.playCard(player1Card);
			cout << player2 << " has played " << player2Card << endl;

		} else {

			player2Card = player2.playCard(joker);
			cout << player2 << " has played " << player2Card << endl;

			player1Card = player1.playCard(player2Card);
			cout << player1 << " has played " << player1Card << endl;

		}

		cout << '\n';

		// compare cards
		if (player1Card == player2Card) {

			player1.addScore(1);

			player2.addScore(1);

			cout << "push" << endl;

		} else if (player1Card < player2Card) {
			// player2 win
			player2.addScore(2);

			cout << player2 << " won round" << endl;

			player1First = false;
		} else {
			// player1 win
			player1.addScore(2);

			cout << player1 << " won round" << endl;

			player1First = true;
		}

		cout << "-----------------------------------\n";

		// inform players of cards played
		player1.cardsPlayed(player1Card, player2Card);
		player2.cardsPlayed(player1Card, player2Card);

		// each player draw card
		if (!deck.isEmpty()) {

			player1.receiveCard(deck.draw());

			player2.receiveCard(deck.draw());
		}
	}

	cout << player1 << ": " << player1.getScore() << endl;
	cout << player2 << ": " << player2.getScore() << endl;

	// identify player with higher score
	if (player1.getScore() > player2.getScore()) {

		cout << player1 << " won game" << endl;

	} else if (player1.getScore() < player2.getScore()) {

		cout << player2 << " won game" << endl;

	} else {

		cout << "tie" << endl;
	}

	return 0;

}
