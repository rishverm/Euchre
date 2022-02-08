// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Card.h"
#include "unit_test_framework.h"
#include <iostream>

using namespace std;


TEST(test_card_ctor) {
    Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(Card::RANK_ACE, c.get_rank());
    ASSERT_EQUAL(Card::SUIT_HEARTS, c.get_suit());
}

//create more constructor tests

TEST(test_card_default_constructor) {
    Card a;
    ASSERT_EQUAL(Card::RANK_TWO, a.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, a.get_suit());
}

TEST(test_card_get_rank) {
    
}

// Add more test cases here

TEST_MAIN()
