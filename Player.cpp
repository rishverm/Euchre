//
//  Project UID 1d9f47bfc76643019cfbf037641defe1
//  Player.cpp
//  p3-euchre
//
//  Created by Jenna Elwing on 2/7/22.
//

#include <stdio.h>
#include <string>
#include "Card.h"
#include "Player.h"

const std::string playerName = "name";
const std::string & get_name() {
    
    return playerName;
}

void add_card(const Card &c) {
    return;
}

bool make_trump(const Card &upcard, bool is_dealer,
                int round, std::string &order_up_suit) {
    return 0;
}

void add_and_discard(const Card &upcard) {
    return;
}

Card lead_card(const std::string &trump) {
    return Card();
}

Card play_card(const Card &led_card, const std::string &trump) {
    return Card();
}

Player * Player_factory(const std::string &name, const std::string &strategy) {
    // We need to check the value of strategy and return
      // the corresponding player type.
      if (strategy == "Simple") {
        // The "new" keyword dynamically allocates an object.
        //return new SimplePlayer(name);
      }
      // Repeat for each other type of Player
      
      // Invalid strategy if we get here
      //assert(false);
      
    return nullptr;
}

std::ostream & operator<<(std::ostream &os, const Player &p) {
    return os;
}

