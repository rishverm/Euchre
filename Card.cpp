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

}


Card::Card() :rank(RANK_TWO), suit(SUIT_SPADES) {

}



string Card::get_rank() const {
	return "";
}


string Card::get_suit() const {
	return "";
}

string Card::get_suit(const string& trump) const {
	return "";
}


bool Card::is_face() const {
	return 0;
}


bool Card::is_right_bower(const string& trump) const {
	return 0;
}


bool Card::is_left_bower(const string& trump) const {
	return 0;
}



bool Card::is_trump(const string& trump) const {
	return 0;
}


bool operator<(const Card& lhs, const Card& rhs) {
	return 0;
	
}

bool operator<=(const Card& lhs, const Card& rhs) {
	return 0;

}

bool operator>(const Card& lhs, const Card& rhs) {
	return 0;

}

bool operator>=(const Card& lhs, const Card& rhs) {
	return 0;

}

bool operator==(const Card& lhs, const Card& rhs) {
	return 0;

}

bool operator!=(const Card& lhs, const Card& rhs) {
	return 0;

}

string Suit_next(const string& suit) {
	return "";
	
}

ostream& operator<<(ostream& os, const Card& card) {
	return os;
}

bool Card_less(const Card& a, const Card& b, const std::string& trump) {

	return 0;
}

bool Card_less(const Card& a, const Card& b, const Card& led_card,
	const std::string& trump) {
	return 0;
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
