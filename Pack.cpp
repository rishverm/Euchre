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
            
            cards[(6 * i) + (j - 7)] = Card(RANK_NAMES_BY_WEIGHT[j], SUIT_NAMES_BY_WEIGHT[i]);
           // i = 0: 0, 1, 2, 3, 4, 5,
            //i = 1: 6, 7, 8, 9, 10, 11
           // i = 2: 12, 13, 14, 15, 16, 17
           // i = 3: 18, 19, 20, 21, 22, 23
            
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
    return;
}

bool Pack::empty() const {
    if (next == 23) {
        return true;
    }
    else {
        return false;
    }
}
