// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <cassert>
#include <iostream>
#include <string>
#include "Card.h"
using namespace std;
// add any necessary #include or using directives here

// rank and suit names -- do not remove these
constexpr const char* const Card::RANK_TWO;
constexpr const char* const Card::RANK_THREE;
constexpr const char* const Card::RANK_FOUR;
constexpr const char* const Card::RANK_FIVE;
constexpr const char* const Card::RANK_SIX;
constexpr const char* const Card::RANK_SEVEN;
constexpr const char* const Card::RANK_EIGHT;
constexpr const char* const Card::RANK_NINE;
constexpr const char* const Card::RANK_TEN;
constexpr const char* const Card::RANK_JACK;
constexpr const char* const Card::RANK_QUEEN;
constexpr const char* const Card::RANK_KING;
constexpr const char* const Card::RANK_ACE;

constexpr const char* const Card::SUIT_SPADES;
constexpr const char* const Card::SUIT_HEARTS;
constexpr const char* const Card::SUIT_CLUBS;
constexpr const char* const Card::SUIT_DIAMONDS;

// add your code below
Card::Card(const string& rank_in, const string& suit_in) {
    rank = rank_in;
    suit = suit_in;
}


Card::Card() :rank(RANK_TWO), suit(SUIT_SPADES) {
    rank = RANK_TWO;
    suit = SUIT_SPADES;
}



string Card::get_rank() const {
	return rank;
}


string Card::get_suit() const {
	return suit;
}
/*if ((trump == SUIT_DIAMONDS) && (suit == SUIT_HEARTS) && (rank == RANK_JACK)) {
    return SUIT_DIAMONDS;
}
else if ((trump == SUIT_HEARTS) && (suit == SUIT_DIAMONDS) && (rank == RANK_JACK)) {
    return SUIT_HEARTS;
}
else if ((trump == SUIT_CLUBS) && (suit == SUIT_SPADES) && (rank == RANK_JACK)) {
    return SUIT_CLUBS;
}
else if ((trump == SUIT_SPADES) && (suit == SUIT_CLUBS) && (rank == RANK_JACK)) {
    return SUIT_SPADES;
}
 */
string Card::get_suit(const string& trump) const {
    if (Card::is_left_bower(trump)) {
        return trump;
    }
    else {
        return suit;
    }
}


bool Card::is_face() const {
    if (rank == RANK_JACK || rank == RANK_QUEEN) {
        return true;
    }
    else if (rank == RANK_KING || rank == RANK_ACE) {
        return true;
    }
    else {
        return false;
    }
}


bool Card::is_right_bower(const string& trump) const {
    if ((rank == RANK_JACK) && (suit == trump)) {
        return true;
    }
    else {
        return false;
    }
}


bool Card::is_left_bower(const string& trump) const {
    if ((rank == RANK_JACK) && Suit_next(suit) == trump) {
        return true;
    }
    else {
        return false;
    }
}

bool Card::is_trump(const string& trump) const {
    if (suit == trump) {
        return true;
    }
    else if (Card::is_left_bower(trump)) {
        return true;
    }
    else {
        return false;
    }
}


bool operator<(const Card& lhs, const Card& rhs) {
    int lhsValue = 0;
    int rhsValue = 0;
    if (lhs.get_rank() != rhs.get_rank()) {
    
        for (int i = 0; i < NUM_RANKS; ++i) {
            if (RANK_NAMES_BY_WEIGHT[i] == lhs.get_rank()) {
                lhsValue = i;
            }
            if (RANK_NAMES_BY_WEIGHT[i] == rhs.get_rank()) {
                rhsValue = i;
            }
        }
        if (lhsValue < rhsValue) {
            return true;
        }
        else {
            return false;
        }
    }
    
    else {
        for (int i = 0; i < NUM_SUITS; ++i) {
            if (SUIT_NAMES_BY_WEIGHT[i] == lhs.get_suit()) {
                lhsValue = i;
            }
            if (SUIT_NAMES_BY_WEIGHT[i] == rhs.get_suit()) {
                rhsValue = i;
            }
        }
        if (lhsValue < rhsValue) {
            return true;
        }
        else {
            return false;
        }
    }
    
}

bool operator<=(const Card& lhs, const Card& rhs) {
    int lhsValue = 0;
    int rhsValue = 0;
    if (lhs.get_rank() != rhs.get_rank()) {
    
        for (int i = 0; i < NUM_RANKS; ++i) {
            if (RANK_NAMES_BY_WEIGHT[i] == lhs.get_rank()) {
                lhsValue = i;
            }
            if (RANK_NAMES_BY_WEIGHT[i] == rhs.get_rank()) {
                rhsValue = i;
            }
        }
        if (lhsValue <= rhsValue) {
            return true;
        }
        else {
            return false;
        }
    }
    
    else {
        for (int i = 0; i < NUM_SUITS; ++i) {
            if (SUIT_NAMES_BY_WEIGHT[i] == lhs.get_suit()) {
                lhsValue = i;
            }
            if (SUIT_NAMES_BY_WEIGHT[i] == rhs.get_suit()) {
                rhsValue = i;
            }
        }
        if (lhsValue <= rhsValue) {
            return true;
        }
        else {
            return false;
        }
    }
    
	return 0;

}

bool operator>(const Card& lhs, const Card& rhs) {
    int lhsValue = 0;
    int rhsValue = 0;
    if (lhs.get_rank() != rhs.get_rank()) {
    
        for (int i = 0; i < NUM_RANKS; ++i) {
            if (RANK_NAMES_BY_WEIGHT[i] == lhs.get_rank()) {
                lhsValue = i;
            }
            if (RANK_NAMES_BY_WEIGHT[i] == rhs.get_rank()) {
                rhsValue = i;
            }
        }
        if (lhsValue > rhsValue) {
            return true;
        }
        else {
            return false;
        }
    }
    
    else {
        for (int i = 0; i < NUM_SUITS; ++i) {
            if (SUIT_NAMES_BY_WEIGHT[i] == lhs.get_suit()) {
                lhsValue = i;
            }
            if (SUIT_NAMES_BY_WEIGHT[i] == rhs.get_suit()) {
                rhsValue = i;
            }
        }
        if (lhsValue > rhsValue) {
            return true;
        }
        else {
            return false;
        }
    }

}

bool operator>=(const Card& lhs, const Card& rhs) {
    int lhsValue = 0;
    int rhsValue = 0;
    if (lhs.get_rank() != rhs.get_rank()) {
    
        for (int i = 0; i < NUM_RANKS; ++i) {
            if (RANK_NAMES_BY_WEIGHT[i] == lhs.get_rank()) {
                lhsValue = i;
            }
            if (RANK_NAMES_BY_WEIGHT[i] == rhs.get_rank()) {
                rhsValue = i;
            }
        }
        if (lhsValue >= rhsValue) {
            return true;
        }
        else {
            return false;
        }
    }
    
    else {
        for (int i = 0; i < NUM_SUITS; ++i) {
            if (SUIT_NAMES_BY_WEIGHT[i] == lhs.get_suit()) {
                lhsValue = i;
            }
            if (SUIT_NAMES_BY_WEIGHT[i] == rhs.get_suit()) {
                rhsValue = i;
            }
        }
        if (lhsValue >= rhsValue) {
            return true;
        }
        else {
            return false;
        }
    }

}

bool operator==(const Card& lhs, const Card& rhs) {
    if ((lhs.get_rank() == rhs.get_rank()) && (lhs.get_suit() == rhs.get_suit())) {
        return true;
    }
    else {
        return false;
    }

}

bool operator!=(const Card& lhs, const Card& rhs) {
    if ((lhs.get_rank() == rhs.get_rank()) && (lhs.get_suit() == rhs.get_suit())) {
        return false;
    }
    else {
        return true;
    }

}

string Suit_next(const string& suit) {
    if (suit == Card::SUIT_DIAMONDS) {
        return Card::SUIT_HEARTS;
    }
    else if (suit == Card::SUIT_HEARTS) {
        return Card::SUIT_DIAMONDS;
    }
    else if (suit == Card::SUIT_CLUBS) {
        return Card::SUIT_SPADES;
    }
    else {
        return Card::SUIT_CLUBS;
    }
	
}

ostream& operator<<(ostream& os, const Card& card) {
    string rank = card.get_rank();
    string suit = card.get_suit();
    os << rank << " of " << suit;
	return os;
    
}

bool Card_less(const Card& a, const Card& b, const std::string& trump) {
    //a is trump, b isn't
    //b is trump, a isn't
    //both trump: compare ranks
    //neither trump, same suit: compare ranks
    //neither trump, different suit, different rank: compare ranks
    //neither trump, different suits, same rank: compare suit weight
    
    if (a.is_right_bower(trump)) {
        return false;
    }
    
    if (b.is_right_bower(trump)) {
        return true;
    }
    
    if (a.is_left_bower(trump)) {
        return false;
    }
    
    if (b.is_left_bower(trump)) {
        return true;
    }
    
    //a or b or both are trump
    if (a.get_suit() == trump || b.get_suit() == trump) {
        if (a.get_suit(trump) == trump && b.get_suit(trump) != trump) {
            return false;
            //a is not less than b
        }
        else if (b.get_suit(trump) == trump && a.get_suit(trump) != trump) {
            return true;
            //a is less than b
        }
        else if (b.get_suit(trump) == trump && a.get_suit(trump) == trump) {
            bool lessThan = operator<(a, b);
            if (lessThan) {
                return true;
            }
            else {
                return false;
            }

        }
    }

    //neither a nor b trump
    bool lessThan = operator<(a, b);
    if (lessThan) {
        return true;
    }
    
    else {
        return false;
    }
}

//trump suit > led suit > non-trump && non-led suit
bool Card_less(const Card& a, const Card& b, const Card& led_card,
	const std::string& trump) {
    string ledSuit = led_card.get_suit();
    
    if ((a.get_suit() == ledSuit) || (b.get_suit() == ledSuit)) {
    if (a.get_suit() == ledSuit && b.get_suit() != ledSuit) {
        return false;
        //a is not less than b
    }
    else if (b.get_suit() == ledSuit && a.get_suit() != ledSuit) {
        return true;
        //a is less than b
    }
    else if (b.get_suit() == ledSuit && a.get_suit() == ledSuit) {
        return Card_less(a, b, trump);

    }
    }


    else if (a.get_suit(trump) == trump || b.get_suit(trump) == trump) {
        return Card_less(a, b, trump);
            
    }
        /*
        if (a.get_suit() == trump && b.get_suit() != trump) {
            return false;
            //a is not less than b
        }
        else if (b.get_suit() == trump && a.get_suit() != trump) {
            return true;
            //a is less than b
        }
        else if (b.get_suit() == trump && a.get_suit() == trump) {
            bool lessThan = operator<(a, b);
            if (lessThan) {
                return true;
            }
            else {
                return false;
            }

        }
    }
     */
    //a is led, b is led
    //a is is led, b is not led or trump
    
    
    

    //neither a nor b trump
    bool lessThan = operator<(a, b);
    if (lessThan) {
        return true;
    }
    
    else {
        return false;
    }
    
}



// NOTE: We HIGHLY recommend you check out the operator overloading
// tutorial in the project spec (see the appendices) before implementing
// the following operator overload functions:
//   operator<<
//   operator<
//   operator<=
//   operator>
//   operator>=
//   operator==
//   operator!=
