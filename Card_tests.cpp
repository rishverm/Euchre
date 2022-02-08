// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Card.h"
#include "unit_test_framework.h"
#include <iostream>

using namespace std;
TEST(test_card_ctor) {
    Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(Card::RANK_ACE, c.get_rank());
    ASSERT_EQUAL(Card::SUIT_HEARTS, c.get_suit());

    Card c2(Card::RANK_SEVEN, Card::SUIT_CLUBS);
    ASSERT_EQUAL(Card::RANK_SEVEN, c2.get_rank());
    ASSERT_EQUAL(Card::SUIT_CLUBS, c2.get_suit());

    Card c3(Card::RANK_TWO, Card::SUIT_SPADES);
    ASSERT_EQUAL(Card::RANK_TWO, c3.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, c3.get_suit());

    Card c4(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(Card::RANK_ACE, c4.get_rank());
    ASSERT_EQUAL(Card::SUIT_DIAMONDS, c4.get_suit());
}


TEST(test_card_default_constructor) {
    Card a;
    ASSERT_EQUAL(Card::RANK_TWO, a.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, a.get_suit());
}




TEST(test_card_get_rank) {
    Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(Card::RANK_ACE, c.get_rank());

    Card c2(Card::RANK_SEVEN, Card::SUIT_CLUBS);
    ASSERT_EQUAL(Card::RANK_SEVEN, c2.get_rank());

    Card c3(Card::RANK_TWO, Card::SUIT_SPADES);
    ASSERT_EQUAL(Card::RANK_TWO, c3.get_rank());

    Card c4(Card::RANK_FOUR, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(Card::RANK_FOUR, c4.get_rank());

    Card a;
    ASSERT_EQUAL(Card::RANK_TWO, a.get_rank());
}




TEST(test_card_get_suit1) {
    Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(Card::SUIT_HEARTS, c.get_suit());

    Card c2(Card::RANK_SEVEN, Card::SUIT_CLUBS);
    ASSERT_EQUAL(Card::SUIT_CLUBS, c2.get_suit());

    Card c3(Card::RANK_TWO, Card::SUIT_SPADES);
    ASSERT_EQUAL(Card::SUIT_SPADES, c3.get_suit());

    Card c4(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(Card::SUIT_DIAMONDS, c4.get_suit());

    Card a;
    ASSERT_EQUAL(Card::SUIT_SPADES, a.get_suit());
}




TEST(test_card_getsuit_parameter1) {
    Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(Card::SUIT_HEARTS, c.get_suit(Card::SUIT_HEARTS));

    Card c2(Card::RANK_SEVEN, Card::SUIT_CLUBS);
    ASSERT_EQUAL(Card::SUIT_CLUBS, c2.get_suit(Card::SUIT_CLUBS));

    Card c3(Card::RANK_TWO, Card::SUIT_SPADES);
    ASSERT_EQUAL(Card::SUIT_SPADES, c3.get_suit(Card::SUIT_SPADES));

    Card c4(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(Card::SUIT_DIAMONDS, c4.get_suit(Card::SUIT_DIAMONDS));

    Card a;
    ASSERT_EQUAL(Card::SUIT_SPADES, a.get_suit(Card::SUIT_SPADES));
}






TEST(test_is_face1) {
    Card a;
    ASSERT_FALSE(a.is_face());

    Card c(Card::RANK_ACE, Card::SUIT_CLUBS);
    ASSERT_TRUE(c.is_face());

    Card c2(Card::RANK_KING, Card::SUIT_DIAMONDS);
    ASSERT_TRUE(c2.is_face());

    Card c3(Card::RANK_QUEEN, Card::SUIT_SPADES);
    ASSERT_TRUE(c3.is_face());

    Card c4(Card::RANK_JACK, Card::SUIT_HEARTS);
    ASSERT_TRUE(c4.is_face());

    Card c5(Card::RANK_SEVEN, Card::SUIT_CLUBS);
    ASSERT_FALSE(c5.is_face());
}




TEST(test_is_right_bower1) {
    Card c(Card::RANK_JACK, Card::SUIT_SPADES);
    ASSERT_TRUE(c.is_right_bower(Card::SUIT_SPADES));
    ASSERT_FALSE(c.is_right_bower(Card::SUIT_HEARTS));
    ASSERT_FALSE(c.is_right_bower(Card::SUIT_DIAMONDS));
    ASSERT_FALSE(c.is_right_bower(Card::SUIT_CLUBS));

    Card c2(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_FALSE(c2.is_right_bower(Card::SUIT_SPADES));
    ASSERT_FALSE(c2.is_right_bower(Card::SUIT_HEARTS));
    ASSERT_FALSE(c2.is_right_bower(Card::SUIT_DIAMONDS));
    ASSERT_TRUE(c2.is_right_bower(Card::SUIT_CLUBS));

    Card c3(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    ASSERT_FALSE(c3.is_right_bower(Card::SUIT_SPADES));
    ASSERT_FALSE(c3.is_right_bower(Card::SUIT_HEARTS));
    ASSERT_TRUE(c3.is_right_bower(Card::SUIT_DIAMONDS));
    ASSERT_FALSE(c3.is_right_bower(Card::SUIT_CLUBS));

    Card c4(Card::RANK_JACK, Card::SUIT_HEARTS);
    ASSERT_FALSE(c4.is_right_bower(Card::SUIT_SPADES));
    ASSERT_TRUE(c4.is_right_bower(Card::SUIT_HEARTS));
    ASSERT_FALSE(c4.is_right_bower(Card::SUIT_DIAMONDS));
    ASSERT_FALSE(c4.is_right_bower(Card::SUIT_CLUBS));
}



TEST(test_is_left_bower1) {
    Card c(Card::RANK_JACK, Card::SUIT_SPADES);
    ASSERT_FALSE(c.is_left_bower(Card::SUIT_SPADES));
    ASSERT_FALSE(c.is_left_bower(Card::SUIT_HEARTS));
    ASSERT_FALSE(c.is_left_bower(Card::SUIT_DIAMONDS));
    ASSERT_TRUE(c.is_left_bower(Card::SUIT_CLUBS));

    Card c2(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_TRUE(c2.is_left_bower(Card::SUIT_SPADES));
    ASSERT_FALSE(c2.is_left_bower(Card::SUIT_HEARTS));
    ASSERT_FALSE(c2.is_left_bower(Card::SUIT_DIAMONDS));
    ASSERT_FALSE(c2.is_left_bower(Card::SUIT_CLUBS));

    Card c3(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    ASSERT_FALSE(c3.is_left_bower(Card::SUIT_SPADES));
    ASSERT_TRUE(c3.is_left_bower(Card::SUIT_HEARTS));
    ASSERT_FALSE(c3.is_left_bower(Card::SUIT_DIAMONDS));
    ASSERT_FALSE(c3.is_left_bower(Card::SUIT_CLUBS));

    Card c4(Card::RANK_JACK, Card::SUIT_HEARTS);
    ASSERT_FALSE(c4.is_left_bower(Card::SUIT_SPADES));
    ASSERT_FALSE(c4.is_left_bower(Card::SUIT_HEARTS));
    ASSERT_TRUE(c4.is_left_bower(Card::SUIT_DIAMONDS));
    ASSERT_FALSE(c4.is_left_bower(Card::SUIT_CLUBS));
}




TEST(test_is_trump1) {
    Card c(Card::RANK_JACK, Card::SUIT_SPADES);
    ASSERT_TRUE(c.is_trump(Card::SUIT_SPADES));
    ASSERT_FALSE(c.is_trump(Card::SUIT_HEARTS));
    ASSERT_FALSE(c.is_trump(Card::SUIT_DIAMONDS));
    ASSERT_TRUE(c.is_trump(Card::SUIT_CLUBS));

    Card c2(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_TRUE(c2.is_trump(Card::SUIT_SPADES));
    ASSERT_FALSE(c2.is_trump(Card::SUIT_HEARTS));
    ASSERT_FALSE(c2.is_trump(Card::SUIT_DIAMONDS));
    ASSERT_TRUE(c2.is_trump(Card::SUIT_CLUBS));

    Card c3(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    ASSERT_FALSE(c3.is_trump(Card::SUIT_SPADES));
    ASSERT_TRUE(c3.is_trump(Card::SUIT_HEARTS));
    ASSERT_TRUE(c3.is_trump(Card::SUIT_DIAMONDS));
    ASSERT_FALSE(c3.is_trump(Card::SUIT_CLUBS));

    Card c4(Card::RANK_JACK, Card::SUIT_HEARTS);
    ASSERT_FALSE(c4.is_trump(Card::SUIT_SPADES));
    ASSERT_TRUE(c4.is_trump(Card::SUIT_HEARTS));
    ASSERT_TRUE(c4.is_trump(Card::SUIT_DIAMONDS));
    ASSERT_FALSE(c4.is_trump(Card::SUIT_CLUBS));
}





TEST(test_operatorlessthan1) {
    Card c(Card::RANK_JACK, Card::SUIT_SPADES);
    Card d(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_TRUE(operator<(c, d));

    Card c2(Card::RANK_KING, Card::SUIT_SPADES);
    Card d2(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    ASSERT_FALSE(operator<(c2, d2));

    Card c3(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card d3(Card::RANK_TWO, Card::SUIT_DIAMONDS);
    ASSERT_FALSE(operator<(c3, d3));

    Card c4(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d4(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    ASSERT_TRUE(operator<(c4, d4));

    Card c5(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d5(Card::RANK_ACE, Card::SUIT_SPADES);
    ASSERT_TRUE(operator<(c5, d5));

    Card c6(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d6(Card::RANK_TWO, Card::SUIT_SPADES);
    ASSERT_FALSE(operator<(c6, d6));
}





TEST(test_operatorlessthanequalto1) {
    Card c(Card::RANK_JACK, Card::SUIT_SPADES);
    Card d(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_TRUE(operator<=(c, d));

    Card c2(Card::RANK_KING, Card::SUIT_SPADES);
    Card d2(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    ASSERT_FALSE(operator<=(c2, d2));

    Card c3(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card d3(Card::RANK_TWO, Card::SUIT_DIAMONDS);
    ASSERT_FALSE(operator<=(c3, d3));

    Card c4(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d4(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    ASSERT_TRUE(operator<=(c4, d4));

    Card c5(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d5(Card::RANK_ACE, Card::SUIT_SPADES);
    ASSERT_TRUE(operator<=(c5, d5));

    Card c6(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d6(Card::RANK_TWO, Card::SUIT_SPADES);
    ASSERT_TRUE(operator<=(c6, d6));
}





TEST(test_operatorgreaterthan1) {
    Card c(Card::RANK_JACK, Card::SUIT_SPADES);
    Card d(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_TRUE(operator>(d, c));

    Card c2(Card::RANK_KING, Card::SUIT_SPADES);
    Card d2(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    ASSERT_FALSE(operator>(d2, c2));

    Card c3(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card d3(Card::RANK_TWO, Card::SUIT_DIAMONDS);
    ASSERT_FALSE(operator>(d3, c3));

    Card c4(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d4(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    ASSERT_TRUE(operator>(d4, c4));

    Card c5(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d5(Card::RANK_ACE, Card::SUIT_SPADES);
    ASSERT_TRUE(operator>(d5, c5));

    Card c6(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d6(Card::RANK_TWO, Card::SUIT_SPADES);
    ASSERT_FALSE(operator>(d6, c6));
}




TEST(test_operatorgreaterthanequalto1) {
    Card c(Card::RANK_JACK, Card::SUIT_SPADES);
    Card d(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_TRUE(operator>=(d, c));

    Card c2(Card::RANK_KING, Card::SUIT_SPADES);
    Card d2(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    ASSERT_FALSE(operator>=(d2, c2));

    Card c3(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card d3(Card::RANK_TWO, Card::SUIT_DIAMONDS);
    ASSERT_FALSE(operator>=(d3, c3));

    Card c4(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d4(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    ASSERT_TRUE(operator>=(d4, c4));

    Card c5(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d5(Card::RANK_ACE, Card::SUIT_SPADES);
    ASSERT_TRUE(operator>=(d5, c5));

    Card c6(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d6(Card::RANK_TWO, Card::SUIT_SPADES);
    ASSERT_TRUE(operator>=(d6, c6));
}




TEST(test_operatorequalto1) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d(Card::RANK_TWO, Card::SUIT_SPADES);
    ASSERT_TRUE(operator==(c, d));

    Card c2(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d2(Card::RANK_TWO, Card::SUIT_HEARTS);
    ASSERT_FALSE(operator==(c2, d2));

    Card c3(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d3(Card::RANK_THREE, Card::SUIT_SPADES);
    ASSERT_FALSE(operator==(c3, d3));
}




TEST(test_operatornotequalto1) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d(Card::RANK_TWO, Card::SUIT_SPADES);
    ASSERT_FALSE(operator!=(c, d));

    Card c2(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d2(Card::RANK_TWO, Card::SUIT_HEARTS);
    ASSERT_TRUE(operator!=(c2, d2));

    Card c3(Card::RANK_TWO, Card::SUIT_SPADES);
    Card d3(Card::RANK_THREE, Card::SUIT_SPADES);
    ASSERT_TRUE(operator!=(c3, d3));
}





TEST(test_Suit_next1) {
    Card c(Card::RANK_TWO, Card::SUIT_SPADES);
    ASSERT_EQUAL(Suit_next(c.get_suit()), Card::SUIT_CLUBS);
    ASSERT_NOT_EQUAL(Suit_next(c.get_suit()), Card::SUIT_SPADES);
    ASSERT_NOT_EQUAL(Suit_next(c.get_suit()), Card::SUIT_HEARTS);
    ASSERT_NOT_EQUAL(Suit_next(c.get_suit()), Card::SUIT_DIAMONDS);

    Card c2(Card::RANK_ACE, Card::SUIT_CLUBS);
    ASSERT_NOT_EQUAL(Suit_next(c2.get_suit()), Card::SUIT_CLUBS);
    ASSERT_EQUAL(Suit_next(c2.get_suit()), Card::SUIT_SPADES);
    ASSERT_NOT_EQUAL(Suit_next(c2.get_suit()), Card::SUIT_HEARTS);
    ASSERT_NOT_EQUAL(Suit_next(c2.get_suit()), Card::SUIT_DIAMONDS);

    Card c3(Card::RANK_SEVEN, Card::SUIT_DIAMONDS);
    ASSERT_NOT_EQUAL(Suit_next(c3.get_suit()), Card::SUIT_CLUBS);
    ASSERT_NOT_EQUAL(Suit_next(c3.get_suit()), Card::SUIT_SPADES);
    ASSERT_EQUAL(Suit_next(c3.get_suit()), Card::SUIT_HEARTS);
    ASSERT_NOT_EQUAL(Suit_next(c3.get_suit()), Card::SUIT_DIAMONDS);

    Card c4(Card::RANK_THREE, Card::SUIT_HEARTS);
    ASSERT_NOT_EQUAL(Suit_next(c4.get_suit()), Card::SUIT_CLUBS);
    ASSERT_NOT_EQUAL(Suit_next(c4.get_suit()), Card::SUIT_SPADES);
    ASSERT_NOT_EQUAL(Suit_next(c4.get_suit()), Card::SUIT_HEARTS);
    ASSERT_EQUAL(Suit_next(c4.get_suit()), Card::SUIT_DIAMONDS);

}




TEST(test_operatorstring1 ) {
    Card c(Card::RANK_JACK, Card::SUIT_SPADES);
    ostringstream d = ostringstream();
    d << c;
    ASSERT_TRUE(d.str() == "Jack of Spades");

    Card c2(Card::RANK_ACE, Card::SUIT_CLUBS);
    ostringstream d2 = ostringstream();
    d2 << c2;
    ASSERT_TRUE(d2.str() == "Ace of Clubs");


    Card c3(Card::RANK_TWO, Card::SUIT_DIAMONDS);
    ostringstream d3 = ostringstream();
    d3 << c3;
    ASSERT_TRUE(d3.str() == "Two of Diamonds");


    Card c4(Card::RANK_SEVEN, Card::SUIT_HEARTS);
    ostringstream d4 = ostringstream();
    d4 << c4;
    ASSERT_TRUE(d4.str() == "Seven of Hearts");

}


TEST(test_Card_less1) {
    Card a(Card::RANK_THREE, Card::SUIT_DIAMONDS);
    Card b(Card::RANK_TWO, Card::SUIT_DIAMONDS);
    ASSERT_FALSE(Card_less(a, b, Card::SUIT_HEARTS));


    Card a2(Card::RANK_THREE, Card::SUIT_HEARTS);
    Card b2(Card::RANK_TWO, Card::SUIT_DIAMONDS);
    ASSERT_TRUE(Card_less(a2, b2, Card::SUIT_DIAMONDS));



    Card a3(Card::RANK_TWO, Card::SUIT_DIAMONDS);
    Card b3(Card::RANK_THREE, Card::SUIT_HEARTS);
    ASSERT_TRUE(Card_less(a3, b3, Card::SUIT_CLUBS));


    Card a4(Card::RANK_ACE, Card::SUIT_CLUBS);
    Card b4(Card::RANK_TWO, Card::SUIT_SPADES);
    ASSERT_TRUE(Card_less(a4, b4, Card::SUIT_SPADES));


}




TEST(test_Card_lessled1) {
    Card a(Card::RANK_THREE, Card::SUIT_DIAMONDS);
    Card b(Card::RANK_TWO, Card::SUIT_DIAMONDS);
    ASSERT_FALSE(Card_less(a, b, a, Card::SUIT_DIAMONDS));


    Card a2(Card::RANK_THREE, Card::SUIT_HEARTS);
    Card b2(Card::RANK_TWO, Card::SUIT_DIAMONDS);
    ASSERT_TRUE(Card_less(a2, b2, a2, Card::SUIT_DIAMONDS));



    Card a3(Card::RANK_TWO, Card::SUIT_DIAMONDS);
    Card b3(Card::RANK_THREE, Card::SUIT_HEARTS);
    ASSERT_FALSE(Card_less(a3, b3, b3, Card::SUIT_DIAMONDS));



    Card a4(Card::RANK_ACE, Card::SUIT_CLUBS);
    Card b4(Card::RANK_TWO, Card::SUIT_SPADES);
    ASSERT_TRUE(Card_less(a4, b4, b4, Card::SUIT_SPADES));



    Card a5(Card::RANK_TWO, Card::SUIT_DIAMONDS);
    Card b5(Card::RANK_THREE, Card::SUIT_HEARTS);
    ASSERT_TRUE(Card_less(a5, b5, a5, Card::SUIT_HEARTS));


}

// Add more test cases here

TEST_MAIN()
