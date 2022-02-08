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
TEST(test_card_ctor2) {
    Card c(Card::RANK_SEVEN, Card::SUIT_CLUBS);
    ASSERT_EQUAL(Card::RANK_SEVEN, c.get_rank());
    ASSERT_EQUAL(Card::SUIT_CLUBS, c.get_suit());
}
TEST(test_card_ctor3) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    ASSERT_EQUAL(Card::RANK_TWO, c.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, c.get_suit());
}
TEST(test_card_ctor4) {
    Card c(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(Card::RANK_ACE, c.get_rank());
    ASSERT_EQUAL(Card::SUIT_DIAMONDS, c.get_suit());
}




TEST(test_card_default_constructor) {
    Card a;
    ASSERT_EQUAL(Card::RANK_TWO, a.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, a.get_suit());
}




TEST(test_card_get_rank) {
    Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(Card::RANK_ACE, c.get_rank());
}
TEST(test_card_get_rank2) {
    Card c(Card::RANK_SEVEN, Card::SUIT_CLUBS);
    ASSERT_EQUAL(Card::RANK_SEVEN, c.get_rank());
}
TEST(test_card_get_rank3) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    ASSERT_EQUAL(Card::RANK_TWO, c.get_rank());
}
TEST(test_card_get_rank4) {
    Card c(Card::RANK_FOUR, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(Card::RANK_FOUR, c.get_rank());
}
TEST(test_card_get_rank5) {
    Card a;
    ASSERT_EQUAL(Card::RANK_TWO, a.get_rank());
}




TEST(test_card_get_suit1) {
    Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(Card::SUIT_HEARTS, c.get_suit());
}
TEST(test_card_get_suit2) {
    Card c(Card::RANK_SEVEN, Card::SUIT_CLUBS);
    ASSERT_EQUAL(Card::SUIT_CLUBS, c.get_suit());
}
TEST(test_card_get_suit3) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    ASSERT_EQUAL(Card::SUIT_SPADES, c.get_suit());
}
TEST(test_card_get_suit4) {
    Card c(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(Card::SUIT_DIAMONDS, c.get_suit());
}
TEST(test_card_getsuit5) {
    Card a;
    ASSERT_EQUAL(Card::SUIT_SPADES, a.get_suit());
}




TEST(test_card_getsuit_parameter1) {
    Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(Card::SUIT_HEARTS, c.get_suit(Card::SUIT_HEARTS));
}
TEST(test_card_getsuit_parameter2) {
    Card c(Card::RANK_SEVEN, Card::SUIT_CLUBS);
    ASSERT_EQUAL(Card::SUIT_CLUBS, c.get_suit(Card::SUIT_CLUBS));
}
TEST(test_card_getsuit_parameter3) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    ASSERT_EQUAL(Card::SUIT_SPADES, c.get_suit(Card::SUIT_SPADES));
}
TEST(test_card_getsuit_parameter4) {
    Card c(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(Card::SUIT_DIAMONDS, c.get_suit(Card::SUIT_DIAMONDS));
}
TEST(test_card_getsuit_parameter5) {
    Card a;
    ASSERT_EQUAL(Card::SUIT_SPADES, a.get_suit(Card::SUIT_SPADES));
}






TEST(test_is_face1) {
    Card a;
    ASSERT_FALSE(a.is_face());
}
TEST(test_is_face2) {
    Card c(Card::RANK_ACE, Card::SUIT_CLUBS);
    ASSERT_TRUE(c.is_face());
}
TEST(test_is_face3) {
    Card c(Card::RANK_KING, Card::SUIT_DIAMONDS);
    ASSERT_TRUE(c.is_face());
}
TEST(test_is_face4) {
    Card c(Card::RANK_QUEEN, Card::SUIT_SPADES);
    ASSERT_TRUE(c.is_face());
}
TEST(test_is_face5) {
    Card c(Card::RANK_JACK, Card::SUIT_HEARTS);
    ASSERT_TRUE(c.is_face());
}
TEST(test_is_face6) {
    Card c(Card::RANK_SEVEN, Card::SUIT_CLUBS);
    ASSERT_FALSE(c.is_face());
}




TEST(test_is_right_bower1) {
    Card c(Card::RANK_JACK, Card::SUIT_SPADES);
    ASSERT_TRUE(c.is_right_bower(Card::SUIT_SPADES));
    ASSERT_FALSE(c.is_right_bower(Card::SUIT_HEARTS));
    ASSERT_FALSE(c.is_right_bower(Card::SUIT_DIAMONDS));
    ASSERT_FALSE(c.is_right_bower(Card::SUIT_CLUBS));
}
TEST(test_is_right_bower2) {
    Card c(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_FALSE(c.is_right_bower(Card::SUIT_SPADES));
    ASSERT_FALSE(c.is_right_bower(Card::SUIT_HEARTS));
    ASSERT_FALSE(c.is_right_bower(Card::SUIT_DIAMONDS));
    ASSERT_TRUE(c.is_right_bower(Card::SUIT_CLUBS));
}
TEST(test_is_right_bower3) {
    Card c(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    ASSERT_FALSE(c.is_right_bower(Card::SUIT_SPADES));
    ASSERT_FALSE(c.is_right_bower(Card::SUIT_HEARTS));
    ASSERT_TRUE(c.is_right_bower(Card::SUIT_DIAMONDS));
    ASSERT_FALSE(c.is_right_bower(Card::SUIT_CLUBS));
}
TEST(test_is_right_bower4) {
    Card c(Card::RANK_JACK, Card::SUIT_HEARTS);
    ASSERT_FALSE(c.is_right_bower(Card::SUIT_SPADES));
    ASSERT_TRUE(c.is_right_bower(Card::SUIT_HEARTS));
    ASSERT_FALSE(c.is_right_bower(Card::SUIT_DIAMONDS));
    ASSERT_FALSE(c.is_right_bower(Card::SUIT_CLUBS));
}



TEST(test_is_left_bower1) {
    Card c(Card::RANK_JACK, Card::SUIT_SPADES);
    ASSERT_FALSE(c.is_left_bower(Card::SUIT_SPADES));
    ASSERT_FALSE(c.is_left_bower(Card::SUIT_HEARTS));
    ASSERT_FALSE(c.is_left_bower(Card::SUIT_DIAMONDS));
    ASSERT_TRUE(c.is_left_bower(Card::SUIT_CLUBS));
}
TEST(test_is_left_bower2) {
    Card c(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_TRUE(c.is_left_bower(Card::SUIT_SPADES));
    ASSERT_FALSE(c.is_left_bower(Card::SUIT_HEARTS));
    ASSERT_FALSE(c.is_left_bower(Card::SUIT_DIAMONDS));
    ASSERT_FALSE(c.is_left_bower(Card::SUIT_CLUBS));
}
TEST(test_is_left_bower3) {
    Card c(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    ASSERT_FALSE(c.is_left_bower(Card::SUIT_SPADES));
    ASSERT_TRUE(c.is_left_bower(Card::SUIT_HEARTS));
    ASSERT_FALSE(c.is_left_bower(Card::SUIT_DIAMONDS));
    ASSERT_FALSE(c.is_left_bower(Card::SUIT_CLUBS));
}
TEST(test_is_left_bower4) {
    Card c(Card::RANK_JACK, Card::SUIT_HEARTS);
    ASSERT_FALSE(c.is_left_bower(Card::SUIT_SPADES));
    ASSERT_FALSE(c.is_left_bower(Card::SUIT_HEARTS));
    ASSERT_TRUE(c.is_left_bower(Card::SUIT_DIAMONDS));
    ASSERT_FALSE(c.is_left_bower(Card::SUIT_CLUBS));
}




TEST(test_is_trump1) {
    Card c(Card::RANK_JACK, Card::SUIT_SPADES);
    ASSERT_TRUE(c.is_trump(Card::SUIT_SPADES));
    ASSERT_FALSE(c.is_trump(Card::SUIT_HEARTS));
    ASSERT_FALSE(c.is_trump(Card::SUIT_DIAMONDS));
    ASSERT_FALSE(c.is_trump(Card::SUIT_CLUBS));
}
TEST(test_is_trump2) {
    Card c(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_FALSE(c.is_trump(Card::SUIT_SPADES));
    ASSERT_FALSE(c.is_trump(Card::SUIT_HEARTS));
    ASSERT_FALSE(c.is_trump(Card::SUIT_DIAMONDS));
    ASSERT_TRUE(c.is_trump(Card::SUIT_CLUBS));
}
TEST(test_is_trump3) {
    Card c(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    ASSERT_FALSE(c.is_trump(Card::SUIT_SPADES));
    ASSERT_FALSE(c.is_trump(Card::SUIT_HEARTS));
    ASSERT_TRUE(c.is_trump(Card::SUIT_DIAMONDS));
    ASSERT_FALSE(c.is_trump(Card::SUIT_CLUBS));
}
TEST(test_is_trump4) {
    Card c(Card::RANK_JACK, Card::SUIT_HEARTS);
    ASSERT_FALSE(c.is_trump(Card::SUIT_SPADES));
    ASSERT_TRUE(c.is_trump(Card::SUIT_HEARTS));
    ASSERT_FALSE(c.is_trump(Card::SUIT_DIAMONDS));
    ASSERT_FALSE(c.is_trump(Card::SUIT_CLUBS));
}





TEST(test_operatorlessthan1) {
    Card c(Card::RANK_JACK, Card::SUIT_SPADES);
    Card d(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_TRUE(operator<(c, d));
}
TEST(test_operatorlessthan2) {
    Card c(Card::RANK_KING, Card::SUIT_SPADES);
    Card d(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    ASSERT_TRUE(operator<(c, d));
}
TEST(test_operatorlessthan3) {
    Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card d(Card::RANK_TWO, Card::SUIT_DIAMONDS);
    ASSERT_TRUE(operator<(c, d));
}
TEST(test_operatorlessthan4) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    ASSERT_TRUE(operator<(c, d));
}
TEST(test_operatorlessthan5) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d(Card::RANK_ACE, Card::SUIT_SPADES);
    ASSERT_TRUE(operator<(c, d));
}
TEST(test_operatorlessthan6) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d(Card::RANK_TWO, Card::SUIT_SPADES);
    ASSERT_FALSE(operator<(c, d));
}





TEST(test_operatorlessthanequalto1) {
    Card c(Card::RANK_JACK, Card::SUIT_SPADES);
    Card d(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_TRUE(operator<=(c, d));
}
TEST(test_operatorlessthanequalto2) {
    Card c(Card::RANK_KING, Card::SUIT_SPADES);
    Card d(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    ASSERT_TRUE(operator<=(c, d));
}
TEST(test_operatorlessthanequalto3) {
    Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card d(Card::RANK_TWO, Card::SUIT_DIAMONDS);
    ASSERT_TRUE(operator<=(c, d));
}
TEST(test_operatorlessthanequalto4) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    ASSERT_TRUE(operator<=(c, d));
}
TEST(test_operatorlessthanequalto5) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d(Card::RANK_ACE, Card::SUIT_SPADES);
    ASSERT_TRUE(operator<=(c, d));
}
TEST(test_operatorlessthanequalto6) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d(Card::RANK_TWO, Card::SUIT_SPADES);
    ASSERT_TRUE(operator<=(c, d));
}





TEST(test_operatorgreaterthan1) {
    Card c(Card::RANK_JACK, Card::SUIT_SPADES);
    Card d(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_TRUE(operator>(d, c));
}
TEST(test_operatorgreaterthan2) {
    Card c(Card::RANK_KING, Card::SUIT_SPADES);
    Card d(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    ASSERT_TRUE(operator>(d, c));
}
TEST(test_operatorgreaterthan3) {
    Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card d(Card::RANK_TWO, Card::SUIT_DIAMONDS);
    ASSERT_TRUE(operator>(d, c));
}
TEST(test_operatorgreaterthan4) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    ASSERT_TRUE(operator>(d, c));
}
TEST(test_operatorgreaterthan5) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d(Card::RANK_ACE, Card::SUIT_SPADES);
    ASSERT_TRUE(operator>(d, c));
}
TEST(test_operatorgreaterthan6) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d(Card::RANK_TWO, Card::SUIT_SPADES);
    ASSERT_FALSE(operator>(d, c));
}




TEST(test_operatorgreaterthanequalto1) {
    Card c(Card::RANK_JACK, Card::SUIT_SPADES);
    Card d(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_TRUE(operator>=(d, c));
}
TEST(test_operatorgreaterthanequalto2) {
    Card c(Card::RANK_KING, Card::SUIT_SPADES);
    Card d(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    ASSERT_TRUE(operator>=(d, c));
}
TEST(test_operatorgreaterthanequalto3) {
    Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card d(Card::RANK_TWO, Card::SUIT_DIAMONDS);
    ASSERT_TRUE(operator>=(d, c));
}
TEST(test_operatorgreaterthanequalto4) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    ASSERT_TRUE(operator>=(d, c));
}
TEST(test_operatorgreaterthanequalto5) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d(Card::RANK_ACE, Card::SUIT_SPADES);
    ASSERT_TRUE(operator>=(d, c));
}
TEST(test_operatorgreaterthanequalto6) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d(Card::RANK_TWO, Card::SUIT_SPADES);
    ASSERT_TRUE(operator>=(d, c));
}




TEST(test_operatorequalto1) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d(Card::RANK_TWO, Card::SUIT_SPADES);
    ASSERT_TRUE(operator==(c, d));
}
TEST(test_operatorequalto2) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d(Card::RANK_TWO, Card::SUIT_HEARTS);
    ASSERT_FALSE(operator==(c, d));
}
TEST(test_operatorequalto3) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d(Card::RANK_THREE, Card::SUIT_SPADES);
    ASSERT_FALSE(operator==(c, d));
}




TEST(test_operatornotequalto1) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d(Card::RANK_TWO, Card::SUIT_SPADES);
    ASSERT_FALSE(operator!=(c, d));
}
TEST(test_operatornotequalto2) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d(Card::RANK_TWO, Card::SUIT_HEARTS);
    ASSERT_TRUE(operator!=(c, d));
}
TEST(test_operatornotequalto3) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d(Card::RANK_THREE, Card::SUIT_SPADES);
    ASSERT_TRUE(operator!=(c, d));
}





TEST(test_Suit_next1) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    ASSERT_EQUAL(Suit_next(c.get_suit()), Card::SUIT_CLUBS);
    ASSERT_NOT_EQUAL(Suit_next(c.get_suit()), Card::SUIT_SPADES);
    ASSERT_NOT_EQUAL(Suit_next(c.get_suit()), Card::SUIT_HEARTS);
    ASSERT_NOT_EQUAL(Suit_next(c.get_suit()), Card::SUIT_DIAMONDS);
}
TEST(test_Suit_next2) {
    Card c(Card::RANK_ACE, Card::SUIT_CLUBS);
    ASSERT_NOT_EQUAL(Suit_next(c.get_suit()), Card::SUIT_CLUBS);
    ASSERT_EQUAL(Suit_next(c.get_suit()), Card::SUIT_SPADES);
    ASSERT_NOT_EQUAL(Suit_next(c.get_suit()), Card::SUIT_HEARTS);
    ASSERT_NOT_EQUAL(Suit_next(c.get_suit()), Card::SUIT_DIAMONDS);

}
TEST(test_Suit_next3) {
    Card c(Card::RANK_SEVEN, Card::SUIT_DIAMONDS);
    ASSERT_NOT_EQUAL(Suit_next(c.get_suit()), Card::SUIT_CLUBS);
    ASSERT_NOT_EQUAL(Suit_next(c.get_suit()), Card::SUIT_SPADES);
    ASSERT_EQUAL(Suit_next(c.get_suit()), Card::SUIT_HEARTS);
    ASSERT_NOT_EQUAL(Suit_next(c.get_suit()), Card::SUIT_DIAMONDS);

}
TEST(test_Suit_next4) {
    Card c(Card::RANK_THREE, Card::SUIT_HEARTS);
    ASSERT_NOT_EQUAL(Suit_next(c.get_suit()), Card::SUIT_CLUBS);
    ASSERT_NOT_EQUAL(Suit_next(c.get_suit()), Card::SUIT_SPADES);
    ASSERT_NOT_EQUAL(Suit_next(c.get_suit()), Card::SUIT_HEARTS);
    ASSERT_EQUAL(Suit_next(c.get_suit()), Card::SUIT_DIAMONDS);

}




TEST(test_operatorstring1 ) {
    Card c(Card::RANK_JACK, Card::SUIT_SPADES);
    ostringstream d = ostringstream();
    d << c;
    ASSERT_TRUE(d.str() == "Jack of Spades");

}
TEST(test_operatorstring2) {
    Card c(Card::RANK_ACE, Card::SUIT_CLUBS);
    ostringstream d = ostringstream();
    d << c;
    ASSERT_TRUE(d.str() == "Ace of Clubs");

}
TEST(test_operatorstring3) {
    Card c(Card::RANK_TWO, Card::SUIT_DIAMONDS);
    ostringstream d = ostringstream();
    d << c;
    ASSERT_TRUE(d.str() == "Two of Diamonds");

}
TEST(test_operatorstring4) {
    Card c(Card::RANK_SEVEN, Card::SUIT_HEARTS);
    ostringstream d = ostringstream();
    d << c;
    ASSERT_TRUE(d.str() == "Seven of Hearts");

}


TEST(test_Card_less1) {
    Card a(Card::RANK_TWO, Card::SUIT_DIAMONDS);
    Card b(Card::RANK_TWO, Card::SUIT_DIAMONDS);

}
TEST(test_Card_less2) {



}
TEST(test_Card_less3) {



}
TEST(test_Card_less4) {



}

// Add more test cases here

TEST_MAIN()
