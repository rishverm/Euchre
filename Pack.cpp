//
//  Pack.cpp
//  p3-euchre
// <<<<<<< HEAD
//
//=======
//  Project UID 1d9f47bfc76643019cfbf037641defe1
//>>>>>>> dd2ef5fdd9a64faf69da152ed05911cd5f710d3e
//  Created by Jenna Elwing on 2/7/22.
//

#include <stdio.h>
#include <array>
#include <string>
// <<<<<<< HEAD
#include "Pack.h"

//=======
//>>>>>>> dd2ef5fdd9a64faf69da152ed05911cd5f710d3e


using namespace std;

Pack::Pack() {
    Pack::next = 0;
    for (int i = 0; i < NUM_SUITS; ++i) {
        for (int j = 7; j < NUM_RANKS; ++j) {
            int k = (6 * i) + (j - 7);
            cards[k] = Card(RANK_NAMES_BY_WEIGHT[j], SUIT_NAMES_BY_WEIGHT[i]);
        }
    }
}

Pack::Pack(std::istream& pack_input) {
    Pack::next = 0;
    string rank;
    string suit;
    string of;
    for (int i = 0; i < PACK_SIZE; ++i) {
        pack_input >> rank >> of >> suit;
        Card card = Card(rank, suit);
        cards[i] = card;
    }
}

Card Pack::deal_one() {
    Pack::next++;
    return Pack::cards[next - 1];
}

void Pack::reset() {
    next = 0;
    return;
}

void Pack::shuffle() {
    reset();
    for (int j = 0; j < 7; j++) {
        //create array for first half
        //create array for 2nd half
        //new for loop that assigns to cards (every other)

        const int half = PACK_SIZE / 2;
        std::array<Card, half> firstHalf;
        std::array<Card, half> secondHalf;

        //first half
        for (int i = 0; i < half; i++) {
            firstHalf[i] = cards[i];
        }

        //second half
        int iterator = 0;
        for (int i = half; i < PACK_SIZE; i++) {
            secondHalf[iterator] = cards[i];
            iterator++;
        }

        //new for loop that assigns to cards (every other)
        int counter = 0;
        for (int i = 0; i < half; i++) {
            cards[counter] = secondHalf[i];
            counter++;
            cards[counter] = firstHalf[i];
            counter++;
        }
    }
    return;
}

bool Pack::empty() const {
    if (next == 24) {
        return true;
    }
    else {
        return false;
    }
}

