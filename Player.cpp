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
#include <vector>
#include <iostream>
using namespace std;

class Simple : public Player {
private:
    string name;
    vector<Card> hand;
    
public:
    Simple(const string name_in) {
        name = name_in;
    }
    
    const std::string & get_name() {
        return name;
    }
    
    void add_card(const Card &c) {
        hand.push_back(c);
    }
    
    bool make_trump(const Card &upcard, bool is_dealer,
                    int round, std::string &order_up_suit) {
        int numFaceCardsUpCard = 0;
        if (round == 1) {
            for (unsigned int i = 0; i < hand.size(); ++ i) {
                if (hand[i].is_face() && hand[i].is_trump(upcard.get_suit())) {
                    ++numFaceCardsUpCard;
                }
                
            }
            if (numFaceCardsUpCard >= 2) {
                order_up_suit = upcard.get_suit();
                return true;
            }
            else {
                return false;
            }
        }
        
        else if (round == 2 && !is_dealer) {
            for (unsigned int i = 0; i < hand.size(); ++ i) {
                if (hand[i].is_face() && hand[i].is_trump(Suit_next(upcard.get_suit()))) {
                    ++numFaceCardsUpCard;
                }
            }
            if (numFaceCardsUpCard >= 1) {
                order_up_suit = Suit_next(upcard.get_suit());
                return true;
            }
            else {
                return false;
            }
        }
        
        //if round == 2 && is_dealer
        else {
            order_up_suit = upcard.get_suit();
            return true;
        }
        
        //in round two, look at same color suite: only need one face card of same color suite
    }
    
    void add_and_discard(const Card& upcard) {
        add_card(upcard);
        Card min= hand[0];
        vector <Card>:: iterator it;
        it = hand.begin();
        int iter = 0;
        int minIndex = 0;
        for (it = hand.begin()+1; it != hand.end(); ++it) {
            iter++;
            if (Card_less(hand[iter], min, upcard.get_suit())) {
                min= hand[iter];
                minIndex = iter;
            }
        }
        hand.erase(hand.begin()+minIndex);
    }
    
    
    Card lead_card(const std::string& trump) {
        Card cardMax = hand[0];
        int iterator = 0;
        for (unsigned int card = 1; card < hand.size(); card++) {
            if (Card_less(cardMax, hand[card], trump)) {
                cardMax = hand[card];
                iterator = card;
            }
        }
        hand.erase(hand.begin()+iterator);
        return cardMax;
       

    }
    
    Card play_card(const Card& led_card, const std::string& trump) {
        Card cardMax = hand[0];
        Card cardMin = hand[0];
        int iterator = 0;
        bool hasLed = false;
        for (unsigned int card = 0; card < hand.size(); card++) {
            if (hand[card].get_suit() == led_card.get_suit()) {
                hasLed = true;
                break;
            }
        }
        if (hasLed) {
            for (unsigned int card = 1; card < hand.size(); card++) {
                if (Card_less(cardMax, hand[card], led_card.get_suit())) {
                    cardMax = hand[card];
                    iterator = card;
                }
            }
            hand.erase(hand.begin() + iterator);
            return cardMax;
        }
        else {
            for (unsigned int card = 1; card < hand.size(); card++) {
                if (Card_less(hand[card], cardMin,led_card, trump)) {
                    cardMin = hand[card];
                    iterator = card;
                }
            }
            hand.erase(hand.begin() + iterator);
            return cardMin;
        }
        

    }
};

class Human : public Player {
private:
    string name;
    vector<Card> hand;
    
public:
    Human(const string name_in) {
        name = name_in;
    }
    
    const std::string & get_name() {
        return name;
    }
    
    void add_card(const Card &c) {
        hand.push_back(c);
    }
    
    bool make_trump(const Card &upcard, bool is_dealer,
                    int round, std::string &order_up_suit);
    
    void add_and_discard(const Card &upcard);
    
    Card lead_card(const std::string &trump);
    
    Card play_card(const Card &led_card, const std::string &trump);
    
};


Player * Player_factory(const std::string &name, const std::string &strategy) {
    // We need to check the value of strategy and return
      // the corresponding player type.
    if (strategy == "Simple") {
        //return new Simple(name);
    }
    else if (strategy == "Human") {
        //return new Human(name);
    }
      // Invalid strategy if we get here
      //assert(false);
      
    return nullptr;
}

std::ostream & operator<<(std::ostream &os, const Player &p) {
   return os;
}

