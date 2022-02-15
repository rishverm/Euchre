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
#include <algorithm>
#include <cassert>

using namespace std;

class Simple : public Player {
private:
    std::string name;
    std::vector<Card> hand;
    
public:
    Simple();
    
    Simple(const std::string &name_in);
    
    virtual const std::string & get_name() const;
    
    virtual void add_card(const Card &c);
    
    virtual bool make_trump(const Card &upcard, bool is_dealer,
                            int round, std::string &order_up_suit) const;
    
    virtual void add_and_discard(const Card& upcard);
    
    virtual Card lead_card(const std::string& trump);
    
    virtual Card play_card(const Card& led_card, const std::string& trump);
    
};

Simple::Simple() {

}

Simple::Simple(const std::string &name_in) {
    name = name_in;
}

const std::string & Simple::get_name() const {
    return name;
}

void Simple::add_card(const Card &c) {
    hand.push_back(c);
}

bool Simple::make_trump(const Card &upcard, bool is_dealer,
                int round, std::string &order_up_suit) const {
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
        order_up_suit = Suit_next(upcard.get_suit());
        return true;
    }
    
    //in round two, look at same color suite: only need one face card of same color suite
}

void Simple::add_and_discard(const Card& upcard) {
    add_card(upcard);
    Card min = hand[0];
    std::vector <Card>:: iterator handLoop;
    handLoop = hand.begin();
    int minIndex = 0;
    int iter = 0;
    
    for (handLoop = hand.begin() + 1; handLoop != hand.end(); ++handLoop) {
        iter++;
        if (Card_less(hand[iter], min, upcard.get_suit())) {
            min = hand[iter];
            minIndex = iter;
        }
        
    }
    Card discardedCard = hand[minIndex];
    hand.erase(hand.begin()+minIndex);
}


Card Simple::lead_card(const std::string& trump) {
    Card cardMax = hand[0];
    int iterator = 0;
    bool allCardsAreTrump = true;
    for (unsigned int card = 1; card < hand.size(); card++) {
        if (!(hand[card].is_trump(trump))) {
            allCardsAreTrump = false;
            cardMax = hand[card];
            break;
        }
    }
    
    if (!allCardsAreTrump) {
        for (unsigned int card = 0; card < hand.size(); card++) {
            if (Card_less(cardMax, hand[card], trump) && !(hand[card].is_trump(trump))) {
                cardMax = hand[card];
                iterator = card;
            }
        }
    }
    
    //allCardsAreTrump
    else {
        for (unsigned int card = 1; card < hand.size(); card++) {
            if (Card_less(cardMax, hand[card], trump)) {
                cardMax = hand[card];
                iterator = card;
            }
        }
    }

    hand.erase(hand.begin()+iterator);
    return cardMax;
   

}

Card Simple::play_card(const Card& led_card, const std::string& trump) {
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

class Human : public Player {
private:
    std::string name;
    std::vector<Card> hand;
    
public:
    Human();
    
    Human(const std::string &name_in);
    
    virtual const std::string & get_name() const;
    
    virtual void add_card(const Card &c);
    
    virtual bool make_trump(const Card &upcard, bool is_dealer,
                            int round, std::string &order_up_suit) const;
    
    virtual void add_and_discard(const Card &upcard);
    
    virtual Card lead_card(const std::string &trump);
    
    virtual Card play_card(const Card &led_card, const std::string &trump);
    
};



Human::Human() {
}

Human::Human(const std::string &name_in) {
    name = name_in;
}

const std::string & Human::get_name() const{
    return name;
}

void Human::add_card(const Card &c) {
    sort(hand.begin(), hand.end());
    hand.push_back(c);
    return;
}

bool Human::make_trump(const Card &upcard, bool is_dealer,
                int round, std::string &order_up_suit) const {
    
    string suit;
    for (unsigned int card = 0; card < hand.size(); card++) {
        cout << "Human player " << get_name()
        << "'s hand: [" << card << "] "
        << hand[card].get_rank() << " of " << hand[card].get_suit() << endl;
    }
    cout << "Human player " << get_name() << ", please enter a suit or \"pass\":" << endl;
    if (suit == "pass") {
        return false;
    }
    else {
        order_up_suit = suit;
        return true;
    }
}

void Human::add_and_discard(const Card &upcard) {
    sort(hand.begin(), hand.end());
    int cardDiscardNum;
    for (unsigned int card = 0; card < hand.size(); card++) {
        cout << "Human player " << get_name()
            << "'s hand: [" << card << "] "
            << hand[card].get_rank() << " of " << hand[card].get_suit() << endl;
    }
    cout << "Discard upcard : [-1]" << endl;
    cout << "Human player " << get_name() << ", please select a card : " << endl;
    cin >> cardDiscardNum;
    if (cardDiscardNum != -1) {
        hand.erase(hand.begin() + cardDiscardNum);
        add_card(upcard);
    }
}

Card Human::lead_card(const std::string &trump) {
    sort(hand.begin(), hand.end());
    int cardLeadNum;
    for (unsigned int card = 0; card < hand.size(); card++) {
        cout << "Human player " << get_name()
            << "'s hand: [" << card << "] "
            << hand[card].get_rank() << " of " << hand[card].get_suit() << endl;
    }
    cout << "Human player " + get_name() + ", please select a card:" << endl;
    cin >> cardLeadNum;
    Card lead = hand[cardLeadNum];
    hand.erase(hand.begin() + cardLeadNum);
    return lead;
}

Card Human::play_card(const Card &led_card, const std::string &trump) {
    sort(hand.begin(), hand.end());
    int cardPlayNum;
    for (unsigned int card = 0; card < hand.size(); card++) {
        cout << "Human player " << get_name()
            << "'s hand: [" << card << "] "
            << hand[card].get_rank() << " of " << hand[card].get_suit() << endl;
    }
    cout << "Human player " + get_name() + ", please select a card:" << endl;
    cin >> cardPlayNum;
    Card play = hand[cardPlayNum];
    hand.erase(hand.begin() + cardPlayNum);
    return play;
}




Player * Player_factory(const std::string &name, const std::string &strategy) {
    // We need to check the value of strategy and return
      // the corresponding player type.
    if (strategy == "Simple") {
        return new Simple(name);
    }
    else if (strategy == "Human") {
        return new Human(name);
    }
    else {
      // Invalid strategy if we get here
        
      assert(false);
      return nullptr;
    }
      
    
}

std::ostream & operator<<(std::ostream &os, const Player &p) {
    os << p.get_name();
   return os;
}

