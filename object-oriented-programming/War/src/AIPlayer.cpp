/*
 * AIPlayer.cpp
 *
 *  Created on: May 20, 2019
 *      Author: student
 */

#include "AIPlayer.h"
#include <stdexcept>
#include <algorithm>
#include <vector>

using namespace std;

AIPlayer::AIPlayer(string name) : Player(name) {
	// init array values
	for (int i = 0; i < 14; i++) {
		knownCards[i] = 0;
	}
}

AIPlayer::~AIPlayer() {
	// empty
}

const Card AIPlayer::playCard(const Card opponentCard) {
	// check if player has cards
	if (!hasCards())
		throw logic_error("");


	sort(hand.begin(), hand.end());

	// init index to zero
	unsigned cardInd = 0;
	if (opponentCard.isJoker()) {
		// first

		// denominator for calculating probabilities
		int unknownCardCount = 52-knownCardsSum()-hand.size();

		// vector to keep track of probabilities
		vector<vector<double>> probabilitySets;

		/*
		 * calculate probabilities for each card
		 */
		for (unsigned int i = 0; i < hand.size(); i++) {
			/*
			 * calculate number of unknown cards less than hand[i]
			 */
			int cardsLessThanCard = 4 * (hand[i].getCardRank() - 1); 	// total number of cards less than hand[i]
			// subtract number of played cards less than hand[i]
			for (int j = 1; j < hand[i].getCardRank(); j++) {
				cardsLessThanCard -= knownCards[j];
			}
			// subtract number of cards in hand less than hand[i]
			for (unsigned int j = 0; j < hand.size(); j++) {
				if (hand[j] < hand[i]) {
					cardsLessThanCard--;
				}
			}

			/*
			 * calculate number of unknown cards equal to hand[i]
			 */
			int cardsEqualToCard = 4;									// total number of cards equal to hand[i]
			cardsEqualToCard -= knownCards[hand[i].getCardRank()];		// subtract number of played cards equal to hand[i]
			// subtract number of cards in hand equal to hand[i]
			for (unsigned int j = 0; j < hand.size(); j++) {
				if (hand[j] == hand[i]) {
					cardsEqualToCard--;
				}
			}

			/*
			 * probabilities
			 */
			double probWin = cardsLessThanCard*1.0/unknownCardCount;
			double probPush = cardsEqualToCard*1.0/unknownCardCount;
			double probLose = 1.0 - probWin - probPush;

			vector<double> probabilities;
			probabilities.push_back(probWin);
			probabilities.push_back(probPush);
			probabilities.push_back(probLose);

			probabilitySets.push_back(probabilities);
		}

		/*
		 * process cards
		 */
		for (unsigned int i = 0; i < hand.size(); i++) {
			// select card based on probability
			bool a = probabilitySets[i][0] - probabilitySets[cardInd][0] >= 0.25;
			if ( a ) {
				cardInd = i;
			}
		}

	} else {
		// second
		cardInd = 0;
		/*
		 * find smallest card greater than opponentCard
		 */
		for (int i = hand.size() - 1; i >= 0; i--) {
			if (opponentCard < hand[i]) {
				cardInd = i;
			}
		}
	}

	Card c = hand[cardInd];
	hand.erase(hand.begin() + cardInd);

	return c;
}

void AIPlayer::cardsPlayed(const Card card1, const Card card2) {
	knownCards[card1.getCardRank()]++;
	knownCards[card2.getCardRank()]++;
}

int AIPlayer::knownCardsSum() const {
	int sum = 0;
	for (int i = 1; i < 14; i++) {
		sum += knownCards[i];
	}
	return sum;
}
