// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Player.h"
#include "unit_test_framework.h"

#include <iostream>

using namespace std;

//Test get_name, Player_factory
TEST(test_player_get_name_1) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    

  // Create a player and verify that get_name() returns the player's name
  Player * Gandolf = Player_factory("Gandolf", "Human");
  ASSERT_EQUAL(Gandolf->get_name(), "Gandolf");

  // Create a player and verify that get_name() returns the player's name
  Player * empty = Player_factory("", "Human");
  ASSERT_EQUAL(empty->get_name(), "");
    
    delete alice;
    delete Gandolf;
}

//MAKE TRUMP TESTS
//round == 1 && is_dealer, 0 face cards X
//round == 1 && is_dealer, 1 face card X
//round == 1 && is_dealer, 2 face cards X
//round == 1 && is_dealer, 3 face cards X

//round == 1 && !is_dealer, 0 face cards X
//round == 1 && !is_dealer, 1 face card X
//round == 1 && !is_dealer, 2 face cards X
//round == 1 && !is_dealer, 3 face cards X




//test add_card, make_trump
TEST(test_player_make_trump_1) {
    // Player's hand
    Player * gollum = Player_factory("Gollum", "Simple");
    gollum->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    gollum->add_card(Card(Card::RANK_THREE, Card::SUIT_SPADES));
    gollum->add_card(Card(Card::RANK_FOUR, Card::SUIT_SPADES));
    gollum->add_card(Card(Card::RANK_FIVE, Card::SUIT_SPADES));
    gollum->add_card(Card(Card::RANK_SIX, Card::SUIT_SPADES));

    // Player makes trump
    Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    string trump;
    bool orderup = gollum->make_trump(
      nine_spades,    // Upcard
      true,           // Gollum is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_FALSE(orderup);

    

    // Player's hand
    Player * chicken = Player_factory("Chicken", "Simple");
    chicken->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    chicken->add_card(Card(Card::RANK_THREE, Card::SUIT_SPADES));
    chicken->add_card(Card(Card::RANK_FOUR, Card::SUIT_SPADES));
    chicken->add_card(Card(Card::RANK_FIVE, Card::SUIT_SPADES));
    chicken->add_card(Card(Card::RANK_SIX, Card::SUIT_SPADES));

    // Player makes trump
    Card jack_spades(Card::RANK_JACK, Card::SUIT_SPADES);
    //string trump;
    bool orderupchicken = chicken->make_trump(
      jack_spades,    // Upcard
      true,           // Gollum is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_FALSE(orderupchicken);

    
    
    // Player's hand
    Player * turkey = Player_factory("Turkey", "Simple");
    turkey->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    // Player makes trump
    //Card jack_spades(Card::RANK_JACK, Card::SUIT_SPADES);
    //string trump;
    bool orderupturkey = turkey->make_trump(
      jack_spades,    // Upcard
      true,           // Gollum is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_FALSE(orderupturkey);

    

    // Player's hand
    Player * smeagol = Player_factory("Smeagol", "Simple");
    smeagol->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    smeagol->add_card(Card(Card::RANK_THREE, Card::SUIT_SPADES));
    smeagol->add_card(Card(Card::RANK_FOUR, Card::SUIT_SPADES));
    smeagol->add_card(Card(Card::RANK_FIVE, Card::SUIT_SPADES));
    smeagol->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));

    // Player makes trump
    //Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    //string trump;
    bool orderup2 = smeagol->make_trump(
      nine_spades,    // Upcard
      true,           // Player is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_FALSE(orderup2);

    



    // Player's hand
    Player * legolas = Player_factory("Legolas", "Simple");
    legolas->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    legolas->add_card(Card(Card::RANK_THREE, Card::SUIT_SPADES));
    legolas->add_card(Card(Card::RANK_FOUR, Card::SUIT_SPADES));
    legolas->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    legolas->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));

    // Player makes trump
    //Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    //string trump;
    bool orderup3 = legolas->make_trump(
      nine_spades,    // Upcard
      true,           // Player is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_TRUE(orderup3);
    ASSERT_EQUAL(trump, Card::SUIT_SPADES);
    
    

    // Player's hand
    Player * pippin = Player_factory("Pippin", "Simple");
    pippin->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    pippin->add_card(Card(Card::RANK_EIGHT, Card::SUIT_SPADES));
    pippin->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    pippin->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    pippin->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));

    // Player makes trump
    //Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    //string trump;
    bool orderup4 = pippin->make_trump(
      nine_spades,    // Upcard
      true,           // Player is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_TRUE(orderup4);
    ASSERT_EQUAL(trump, Card::SUIT_SPADES);

    

    // Player's hand
    Player * aragorn = Player_factory("Aragorn", "Simple");
    aragorn->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    aragorn->add_card(Card(Card::RANK_EIGHT, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_FOUR, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    aragorn->add_card(Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS));

    // Player makes trump
    //Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    //string trump;
    bool orderup5 = aragorn->make_trump(
      nine_spades,    // Upcard
      false,           // Player is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_FALSE(orderup5);
    
    

    // Player's hand
    Player * arwen = Player_factory("Arwen", "Simple");
    arwen->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    arwen->add_card(Card(Card::RANK_EIGHT, Card::SUIT_SPADES));
    arwen->add_card(Card(Card::RANK_FOUR, Card::SUIT_SPADES));
    arwen->add_card(Card(Card::RANK_FIVE, Card::SUIT_SPADES));
    arwen->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));

    // Player makes trump
    //Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    //string trump;
    bool orderup6 = arwen->make_trump(
      nine_spades,    // Upcard
      false,           // Player is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_FALSE(orderup6);
    
    

    // Player's hand
    Player * merry = Player_factory("Merry", "Simple");
    merry->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    merry->add_card(Card(Card::RANK_EIGHT, Card::SUIT_SPADES));
    merry->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    merry->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    merry->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));

    // Player makes trump
    //Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    //string trump;
    bool orderup7 = merry->make_trump(
      nine_spades,    // Upcard
      false,           // Player is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_TRUE(orderup7);
    ASSERT_EQUAL(trump, Card::SUIT_SPADES);
    
    

    // Player's hand
    Player * boromir = Player_factory("Merry", "Simple");
    boromir->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    boromir->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));
    boromir->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    boromir->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    boromir->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));

    // Player makes trump
    //Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    //string trump;
    bool orderup8 = boromir->make_trump(
      nine_spades,    // Upcard
      false,           // Player is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_TRUE(orderup8);
    ASSERT_EQUAL(trump, Card::SUIT_SPADES);
    
    


//round == 2 && is_dealer, 0 face cards

    // Player's hand
    Player * gollum2 = Player_factory("Gollum", "Simple");
    gollum2->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    gollum2->add_card(Card(Card::RANK_THREE, Card::SUIT_SPADES));
    gollum2->add_card(Card(Card::RANK_FOUR, Card::SUIT_SPADES));
    gollum2->add_card(Card(Card::RANK_FIVE, Card::SUIT_SPADES));
    gollum2->add_card(Card(Card::RANK_SIX, Card::SUIT_SPADES));

    // Player makes trump
    //Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    //string trump;
    bool orderup9 = gollum2->make_trump(
      nine_spades,    // Upcard
      true,           // Gollum is also the dealer
      2,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_TRUE(orderup9);
    ASSERT_EQUAL(trump, Card::SUIT_CLUBS);

    


//round == 2 && is_dealer, 1 face card

    // Player's hand
    Player * smeagol2 = Player_factory("Smeagol", "Simple");
    smeagol2->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    smeagol2->add_card(Card(Card::RANK_THREE, Card::SUIT_SPADES));
    smeagol2->add_card(Card(Card::RANK_FOUR, Card::SUIT_SPADES));
    smeagol2->add_card(Card(Card::RANK_FIVE, Card::SUIT_SPADES));
    smeagol2->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));

    // Player makes trump
    Card nine_clubs(Card::RANK_NINE, Card::SUIT_CLUBS);
    //string trump;
    bool orderup0 = smeagol2->make_trump(
      nine_clubs,    // Upcard
      true,           // Player is also the dealer
      2,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_TRUE(orderup0);
    ASSERT_EQUAL(trump, Card::SUIT_SPADES);

    delete smeagol2;
    delete gollum;
    delete gollum2;
    delete boromir;
    delete merry;
    delete arwen;
    delete aragorn;
    delete pippin;
    delete legolas;
    delete smeagol;
    delete turkey;
    delete chicken;
    
}

//round == 2 && is_dealer, 2 face cards
TEST(test_player_make_trump_3_2) {
    // Player's hand
    Player * legolas = Player_factory("Legolas", "Simple");
    legolas->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    legolas->add_card(Card(Card::RANK_THREE, Card::SUIT_SPADES));
    legolas->add_card(Card(Card::RANK_FOUR, Card::SUIT_SPADES));
    legolas->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    legolas->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));

    // Player makes trump
    Card nine_hearts(Card::RANK_NINE, Card::SUIT_HEARTS);
    string trump;
    bool orderup = legolas->make_trump(
      nine_hearts,    // Upcard
      true,           // Player is also the dealer
      2,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_DIAMONDS);
    
    delete legolas;
}

//round == 2 && is_dealer, 3 face cards
TEST(test_player_make_trump_4_2) {
    // Player's hand
    Player * pippin = Player_factory("Pippin", "Simple");
    pippin->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    pippin->add_card(Card(Card::RANK_EIGHT, Card::SUIT_SPADES));
    pippin->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    pippin->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    pippin->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));

    // Player makes trump
    Card nine_diamonds(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    string trump;
    bool orderup = pippin->make_trump(
      nine_diamonds,    // Upcard
      true,           // Player is also the dealer
      2,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_HEARTS);

    delete pippin;
}

TEST(test_player_make_trump_for_loop_1) {
    Player * aragorn = Player_factory("Aragorn", "Simple");
    aragorn->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    
    // Player makes trump
    Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    string trump;
    bool orderup = aragorn->make_trump(
      nine_spades,    // Upcard
      false,           // Player is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_SPADES);
    
    
    delete aragorn;
}

TEST(test_player_make_trump_for_loop_2) {
    Player * aragorn = Player_factory("Aragorn", "Simple");
    aragorn->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    
    // Player makes trump
    Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    string trump;
    bool orderup = aragorn->make_trump(
      nine_spades,    // Upcard
      false,           // Player is also the dealer
      2,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_CLUBS);
    
    
    delete aragorn;
}

TEST(test_player_make_trump_for_loop_3) {
    Player * aragorn = Player_factory("Aragorn", "Simple");
    aragorn->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_THREE, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_FOUR, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_FIVE, Card::SUIT_SPADES));
    
    // Player makes trump
    Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    string trump;
    bool orderup = aragorn->make_trump(
      nine_spades,    // Upcard
      false,           // Player is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_FALSE(orderup);
    
    
    delete aragorn;
}

TEST(test_player_make_trump_for_loop_4) {
    Player * aragorn = Player_factory("Aragorn", "Simple");
    aragorn->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_THREE, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_FOUR, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_FIVE, Card::SUIT_SPADES));
    
    // Player makes trump
    Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    string trump;
    bool orderup = aragorn->make_trump(
      nine_spades,    // Upcard
      false,           // Player is also the dealer
      2,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_FALSE(orderup);
    
    
    delete aragorn;
}

TEST(test_player_make_trump_for_loop_5) {
    Player * aragorn = Player_factory("Aragorn", "Simple");
    aragorn->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    
    // Player makes trump
    Card nine_clubs(Card::RANK_NINE, Card::SUIT_CLUBS);
    string trump;
    bool orderup = aragorn->make_trump(
      nine_clubs,    // Upcard
      false,           // Player is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_FALSE(orderup);
    
    
    delete aragorn;
}

TEST(test_player_make_trump_for_loop_6) {
    Player * aragorn = Player_factory("Aragorn", "Simple");
    aragorn->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    aragorn->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    
    // Player makes trump
    Card nine_clubs(Card::RANK_NINE, Card::SUIT_CLUBS);
    string trump;
    bool orderup = aragorn->make_trump(
      nine_clubs,    // Upcard
      false,           // Player is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_CLUBS);
    
    
    delete aragorn;
}

TEST(test_player_make_trump_for_loop_7) {
    Player * aragorn = Player_factory("Aragorn", "Simple");
    aragorn->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    aragorn->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    
    // Player makes trump
    Card nine_clubs(Card::RANK_NINE, Card::SUIT_CLUBS);
    string trump;
    bool orderup = aragorn->make_trump(
      nine_clubs,    // Upcard
      false,           // Player is also the dealer
      2,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_SPADES);
    
    
    delete aragorn;
}

TEST(test_player_make_trump_for_loop_8) {
    Player * aragorn = Player_factory("Aragorn", "Simple");
    aragorn->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    aragorn->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    
    // Player makes trump
    Card nine_hearts(Card::RANK_NINE, Card::SUIT_HEARTS);
    string trump;
    bool orderup = aragorn->make_trump(
      nine_hearts,    // Upcard
      false,           // Player is also the dealer
      2,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_FALSE(orderup);
    
    
    
    
    
    Player * aragorn2 = Player_factory("Aragorn", "Simple");
    aragorn2->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    aragorn2->add_card(Card(Card::RANK_THREE, Card::SUIT_SPADES));
    aragorn2->add_card(Card(Card::RANK_FOUR, Card::SUIT_SPADES));
    aragorn2->add_card(Card(Card::RANK_FIVE, Card::SUIT_CLUBS));
    aragorn2->add_card(Card(Card::RANK_SIX, Card::SUIT_SPADES));
    
    // Player makes trump
    //Card nine_hearts(Card::RANK_NINE, Card::SUIT_HEARTS);
    //string trump;
    bool orderup2 = aragorn2->make_trump(
      nine_hearts,    // Upcard
      false,           // Player is also the dealer
      2,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_FALSE(orderup2);
    
    
    
    Player * aragorn3 = Player_factory("Aragorn", "Simple");
    aragorn3->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    aragorn3->add_card(Card(Card::RANK_THREE, Card::SUIT_SPADES));
    aragorn3->add_card(Card(Card::RANK_FOUR, Card::SUIT_SPADES));
    aragorn3->add_card(Card(Card::RANK_FIVE, Card::SUIT_CLUBS));
    
    // Player makes trump
    //Card nine_hearts(Card::RANK_NINE, Card::SUIT_HEARTS);
    //string trump;
    bool orderup3 = aragorn3->make_trump(
      nine_hearts,    // Upcard
      false,           // Player is also the dealer
      2,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_FALSE(orderup3);
    
    delete aragorn;
    delete aragorn2;
    delete aragorn3;
}


TEST(aragorn) {
   
    
    Player * aragorn4 = Player_factory("Aragorn", "Simple");
    aragorn4->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    aragorn4->add_card(Card(Card::RANK_THREE, Card::SUIT_SPADES));
    aragorn4->add_card(Card(Card::RANK_FOUR, Card::SUIT_SPADES));
    
    // Player makes trump
    Card nine_hearts(Card::RANK_NINE, Card::SUIT_HEARTS);
    string trump;
    bool orderup4 = aragorn4->make_trump(
      nine_hearts,    // Upcard
      false,           // Player is also the dealer
      2,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_FALSE(orderup4);
    
    
    
    Player * aragorn5 = Player_factory("Aragorn", "Simple");
    aragorn5->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    aragorn5->add_card(Card(Card::RANK_THREE, Card::SUIT_SPADES));
    
    // Player makes trump
    //Card nine_hearts(Card::RANK_NINE, Card::SUIT_HEARTS);
    //string trump;
    bool orderup5 = aragorn5->make_trump(
      nine_hearts,    // Upcard
      false,           // Player is also the dealer
      2,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_FALSE(orderup5);
    
    
    
    Player * aragorn6 = Player_factory("Aragorn", "Simple");
    aragorn6->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    
    // Player makes trump
    //Card nine_hearts(Card::RANK_NINE, Card::SUIT_HEARTS);
    //string trump;
    bool orderup6 = aragorn6->make_trump(
      nine_hearts,    // Upcard
      false,           // Player is also the dealer
      2,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_FALSE(orderup6);
    
    delete aragorn6;
    delete aragorn4;
    delete aragorn5;
}



//round == 2 && !is_dealer, 0 face cards
TEST(test_player_make_trump_5_2) {
    // Player's hand
    Player * aragorn = Player_factory("Aragorn", "Simple");
    aragorn->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    aragorn->add_card(Card(Card::RANK_EIGHT, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_FOUR, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    aragorn->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));

    // Player makes trump
    Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    string trump;
    bool orderup = aragorn->make_trump(
      nine_spades,    // Upcard
      false,           // Player is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_FALSE(orderup);
    
    delete aragorn;
}

//round == 2 && !is_dealer, 1 face card
TEST(test_player_make_trump_6_2) {
    // Player's hand
    Player * arwen = Player_factory("Arwen", "Simple");
    arwen->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    arwen->add_card(Card(Card::RANK_EIGHT, Card::SUIT_SPADES));
    arwen->add_card(Card(Card::RANK_FOUR, Card::SUIT_SPADES));
    arwen->add_card(Card(Card::RANK_FIVE, Card::SUIT_SPADES));
    arwen->add_card(Card(Card::RANK_QUEEN, Card::SUIT_CLUBS));

    // Player makes trump
    Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    string trump;
    bool orderup = arwen->make_trump(
      nine_spades,    // Upcard
      false,           // Player is also the dealer
      2,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_CLUBS);
    
    delete arwen;
}



//round == 2 && !is_dealer, 2 face cards
TEST(test_player_make_trump_7_2) {
    // Player's hand
    Player * merry = Player_factory("Merry", "Simple");
    merry->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    merry->add_card(Card(Card::RANK_EIGHT, Card::SUIT_SPADES));
    merry->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    merry->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    merry->add_card(Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS));

    // Player makes trump
    Card nine_hearts(Card::RANK_NINE, Card::SUIT_HEARTS);
    string trump;
    bool orderup = merry->make_trump(
      nine_hearts,    // Upcard
      false,           // Player is also the dealer
      2,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_DIAMONDS);
    
    delete merry;
}

//round == 2 && !is_dealer, 3 face cards
TEST(test_player_make_trump_8_2) {
    // Player's hand
    Player * boromir = Player_factory("Merry", "Simple");
    boromir->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    boromir->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));
    boromir->add_card(Card(Card::RANK_ACE, Card::SUIT_HEARTS));
    boromir->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    boromir->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));

    // Player makes trump
    Card nine_diamonds(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    string trump;
    bool orderup = boromir->make_trump(
      nine_diamonds,    // Upcard
      false,           // Player is also the dealer
      2,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_HEARTS);
    
    delete boromir;
}


//test lead_card, add_and_discard
TEST(test_player_lead_card_basic) {
    
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));
      // Bob adds a card to his hand and discards one card
    
    bob->add_and_discard(Card(Card::RANK_NINE, Card::SUIT_HEARTS) // upcard
      );

      // Bob leads
    Card card_led = bob->lead_card(Card::SUIT_HEARTS);

      // Verify the card Bob selected to lead
    Card ace_spades(Card::RANK_ACE, Card::SUIT_SPADES);
    ASSERT_EQUAL(card_led, ace_spades); //check led card

    delete bob;
}

//Note that at this point, the trump suit is the suit of the upcard

//they play the highest non-trump card in their hand. If they have only trump cards, they play the highest trump card in their hand.
TEST(test_player_lead_card_hand_size) {
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));
    
      // Bob adds a card to his hand and discards one card
    
    bob->add_and_discard(Card(Card::RANK_NINE, Card::SUIT_HEARTS) // upcard
      );

      // Bob leads
    Card card_led = bob->lead_card(Card::SUIT_HEARTS);

      // Verify the card Bob selected to lead
    Card ace_spades(Card::RANK_ACE, Card::SUIT_SPADES);
    ASSERT_EQUAL(card_led, ace_spades); //check led card

    
    
//they play the highest non-trump card in their hand. If they have only trump cards, they play the highest trump card in their hand.
    Player * bob2 = Player_factory("Bob", "Simple");
    bob2->add_card(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    bob2->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    bob2->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    bob2->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    //bob->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));
    
      // Bob adds a card to his hand and discards one card
    
    bob2->add_and_discard(Card(Card::RANK_NINE, Card::SUIT_HEARTS) // upcard
      );
    
    Card card_led2 = bob2->lead_card(Card::SUIT_HEARTS);
      // Bob leads
    //Card card_led = bob2->lead_card(Card::SUIT_HEARTS);

      // Verify the card Bob selected to lead
    Card king_spades(Card::RANK_KING, Card::SUIT_SPADES);
    ASSERT_EQUAL(card_led2, king_spades); //check led card

    
    
//they play the highest non-trump card in their hand. If they have only trump cards, they play the highest trump card in their hand.
    Player * bob3 = Player_factory("Bob", "Simple");
    bob3->add_card(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    bob3->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    bob3->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    //bob3->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    //bob->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));
    
      // Bob adds a card to his hand and discards one card
    
    bob3->add_and_discard(Card(Card::RANK_NINE, Card::SUIT_HEARTS) // upcard
      );
    
    Card card_led3 = bob3->lead_card(Card::SUIT_HEARTS);
      // Bob leads
    //Card card_led = bob2->lead_card(Card::SUIT_HEARTS);

      // Verify the card Bob selected to lead
    Card queen_spades(Card::RANK_QUEEN, Card::SUIT_SPADES);
    ASSERT_EQUAL(card_led3, queen_spades); //check led card

    delete bob3;
    delete bob2;
    delete bob;
}
TEST(test) {
    
//they play the highest non-trump card in their hand. If they have only trump cards, they play the highest trump card in their hand.
    Player * bob4 = Player_factory("Bob", "Simple");
    bob4->add_card(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    bob4->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    //bob4->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    //bob3->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    //bob->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));
    
      // Bob adds a card to his hand and discards one card
    
    bob4->add_and_discard(Card(Card::RANK_NINE, Card::SUIT_HEARTS) // upcard
      );
    
    Card card_led4 = bob4->lead_card(Card::SUIT_HEARTS);
      // Bob leads
    //Card card_led = bob2->lead_card(Card::SUIT_HEARTS);

      // Verify the card Bob selected to lead
    Card ten_spades(Card::RANK_TEN, Card::SUIT_SPADES);
    ASSERT_EQUAL(card_led4, ten_spades); //check led card

    
    
    Player * bob5 = Player_factory("Bob", "Simple");
    bob5->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    //bob5->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    //bob4->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    //bob3->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    //bob->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));
    
      // Bob adds a card to his hand and discards one card
    
    bob5->add_and_discard(Card(Card::RANK_NINE, Card::SUIT_HEARTS) // upcard
      );
    
    Card card_led5 = bob5->lead_card(Card::SUIT_HEARTS);
      // Bob leads
    //Card card_led = bob2->lead_card(Card::SUIT_HEARTS);

      // Verify the card Bob selected to lead
    Card nine_hearts(Card::RANK_NINE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(card_led5, nine_hearts); //check led card

    
    
    Player * bob6 = Player_factory("Bob", "Simple");
    bob6->add_card(Card(Card::RANK_EIGHT, Card::SUIT_HEARTS));
    //bob5->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    //bob4->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    //bob3->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    //bob->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));
    
      // Bob adds a card to his hand and discards one card
    
    bob6->add_and_discard(Card(Card::RANK_NINE, Card::SUIT_HEARTS) // upcard
      );
    
    Card card_led6 = bob6->lead_card(Card::SUIT_HEARTS);
      // Bob leads
    //Card card_led = bob2->lead_card(Card::SUIT_HEARTS);

      // Verify the card Bob selected to lead
    //Card nine_hearts(Card::RANK_NINE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(card_led6, nine_hearts); //check led card

    delete bob6;
    delete bob5;
    delete bob4;
    
}


TEST(test_player_lead_card_edgecase_1) {
    //with trump cards
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_HEARTS));
      // Bob adds a card to his hand and discards one card
    
    bob->add_and_discard(Card(Card::RANK_NINE, Card::SUIT_HEARTS) // upcard
      );

      // Bob leads
    Card card_led = bob->lead_card(Card::SUIT_HEARTS);

      // Verify the card Bob selected to lead
    Card king_spades(Card::RANK_KING, Card::SUIT_SPADES);
    ASSERT_EQUAL(card_led, king_spades); //check led card

    delete bob;
}

TEST(test_player_lead_card_edgecase_19) {
    //with trump cards
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
      // Bob adds a card to his hand and discards one card
    
    bob->add_and_discard(Card(Card::RANK_NINE, Card::SUIT_HEARTS) // upcard
      );

      // Bob leads
    Card card_led = bob->lead_card(Card::SUIT_HEARTS);

      // Verify the card Bob selected to lead
    Card nine_hearts(Card::RANK_NINE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(card_led, nine_hearts); //check led card

    delete bob;
}


TEST(test_player_lead_card_edgecase_2) {
    //all trump cards
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_HEARTS));
      // Bob adds a card to his hand and discards one card
    
    bob->add_and_discard(Card(Card::RANK_NINE, Card::SUIT_HEARTS) // upcard
      );

      // Bob leads
    Card card_led = bob->lead_card(Card::SUIT_HEARTS);

      // Verify the card Bob selected to lead
    Card ace_hearts(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(card_led, ace_hearts); //check led card

    delete bob;
}

TEST(test_player_lead_card_edgecase_3) {
    //all trumps except 1, discarded
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_TWO, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_HEARTS));
      // Bob adds a card to his hand and discards one card
    
    bob->add_and_discard(Card(Card::RANK_NINE, Card::SUIT_HEARTS) // upcard
      );

      // Bob leads
    Card card_led = bob->lead_card(Card::SUIT_HEARTS);

      // Verify the card Bob selected to lead
    Card ace_hearts(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(card_led, ace_hearts); //check led card

    delete bob;
}

TEST(test_player_lead_card_edgecase_4) {
    //all trumps except 1, discarded
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_HEARTS));
      // Bob adds a card to his hand and discards one card
    
    bob->add_and_discard(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS) // upcard
      );
    //bob will discard the ace of clubs

      // Bob leads
    Card card_led = bob->lead_card(Card::SUIT_HEARTS); //trump suit

      // Verify the card Bob selected to lead
    Card ace_hearts(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(card_led, ace_hearts); //check led card

    delete bob;
}

TEST(test_player_lead_card_edgecase_4_2) {
    //lead with right bower
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_HEARTS));
      // Bob adds a card to his hand and discards one card
    
    bob->add_and_discard(Card(Card::RANK_KING, Card::SUIT_HEARTS) // upcard
      );

      // Bob leads
    Card card_led = bob->lead_card(Card::SUIT_HEARTS);

      // Verify the card Bob selected to lead
    Card jack_hearts(Card::RANK_JACK, Card::SUIT_HEARTS);
    ASSERT_EQUAL(card_led, jack_hearts); //check led card

    delete bob;
}


TEST(test_player_lead_card_edgecase_5) {
    //test with 1 card, not trump
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
      // Bob adds a card to his hand and discards one card
    
    bob->add_and_discard(Card(Card::RANK_NINE, Card::SUIT_HEARTS) // upcard
      );
      // Bob leads
    Card card_led = bob->lead_card(Card::SUIT_HEARTS); //trump suit

      // Verify the card Bob selected to lead
    Card nine_hearts(Card::RANK_NINE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(card_led, nine_hearts); //check led card

    delete bob;
}

//When a Simple Player leads a trick, they play the highest non-trump card in their hand. If they have only trump cards, they play the highest trump card in their hand.
//D > C > H > S
TEST(test_player_lead_card_edgecase_6) {
    //lead with right bower
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    

      // Bob adds a card to his hand and discards one card
    
    bob->add_and_discard(Card(Card::RANK_TEN, Card::SUIT_HEARTS) // upcard
      );

      // Bob leads
    Card card_led = bob->lead_card(Card::SUIT_HEARTS);

      // Verify the card Bob selected to lead
    Card nine_diamonds(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(card_led, nine_diamonds); //check led card

    delete bob;
}

//When a Simple Player leads a trick, they play the highest non-trump card in their hand. If they have only trump cards, they play the highest trump card in their hand.
//D > C > H > S
TEST(test_player_lead_card_edgecase_7) {
    //lead with right bower
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    

      // Bob adds a card to his hand and discards one card
    
    bob->add_and_discard(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS) // upcard
      );

      // Bob leads
    Card card_led = bob->lead_card(Card::SUIT_DIAMONDS);

      // Verify the card Bob selected to lead
    Card nine_diamonds(Card::RANK_NINE, Card::SUIT_CLUBS);
    ASSERT_EQUAL(card_led, nine_diamonds); //check led card

    delete bob;
}

//left bower, rest are trump

TEST(test_player_lead_card_edgecase_8) {
    //lead with right bower
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_FOUR, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_SEVEN, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_EIGHT, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    

      // Bob adds a card to his hand and discards one card
    
    bob->add_and_discard(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS) // upcard
      );

      // Bob leads
    Card card_led = bob->lead_card(Card::SUIT_DIAMONDS);

      // Verify the card Bob selected to lead
    Card jack_hearts(Card::RANK_JACK, Card::SUIT_HEARTS);
    ASSERT_EQUAL(card_led, jack_hearts); //check led card

    delete bob;
}

//all face cards, all trump suit
TEST(test_player_lead_card_edgecase_9) {
    //lead with right bower
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS));
    

      // Bob adds a card to his hand and discards one card
    
    bob->add_and_discard(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS) // upcard
      );

      // Bob leads
    Card card_led = bob->lead_card(Card::SUIT_DIAMONDS);

      // Verify the card Bob selected to lead
    Card jack_hearts(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(card_led, jack_hearts); //check led card

    delete bob;
}

//left and right bower, rest are trump
TEST(test_player_lead_card_edgecase_10) {
    //lead with right bower
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS));
    

      // Bob adds a card to his hand and discards one card
    
    bob->add_and_discard(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS) // upcard
      );

      // Bob leads
    Card card_led = bob->lead_card(Card::SUIT_DIAMONDS);

      // Verify the card Bob selected to lead
    Card jack_hearts(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(card_led, jack_hearts); //check led card

    delete bob;
}

TEST(test_player_lead_card_edgecase_11) {
    //lead with right bower
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS));
    

      // Bob adds a card to his hand and discards one card
    
    bob->add_and_discard(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS) // upcard
      );

      // Bob leads
    Card card_led = bob->lead_card(Card::SUIT_DIAMONDS);

      // Verify the card Bob selected to lead
    Card jack_clubs(Card::RANK_JACK, Card::SUIT_HEARTS);
    ASSERT_EQUAL(card_led, jack_clubs); //check led card

    delete bob;
}

TEST(test_player_lead_card_edgecase_12) {
    //aces with right bower
    //When a Simple Player leads a trick, they play the highest non-trump card in their hand. If they have only trump cards, they play the highest trump card in their hand.
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));
    

      // Bob adds a card to his hand and discards one card
    
    bob->add_and_discard(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS) // upcard
      );

      // Bob leads
    Card card_led = bob->lead_card(Card::SUIT_DIAMONDS);

      // Verify the card Bob selected to lead
    Card ace_clubs(Card::RANK_ACE, Card::SUIT_CLUBS);
    ASSERT_EQUAL(card_led, ace_clubs); //check led card

    delete bob;
}

TEST(test_player_lead_card_edgecase_13) {
    //aces with left bower
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));
    

      // Bob adds a card to his hand and discards one card
    
    bob->add_and_discard(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS) // upcard
      );

      // Bob leads
    Card card_led = bob->lead_card(Card::SUIT_DIAMONDS);

      // Verify the card Bob selected to lead
    Card ace_clubs(Card::RANK_ACE, Card::SUIT_CLUBS);
    ASSERT_EQUAL(card_led, ace_clubs); //check led card

    delete bob;
}

//left and right bower,





//TEST PLAY CARD
//has led card suit (plays highest)

//test play_card
TEST(test_player_play_card_edgecase_1) {
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));

    // Bob plays a card
    Card ten_spades(Card::RANK_TEN, Card::SUIT_SPADES);
    Card card_played = bob->play_card(
    ten_spades,  // Ten of Spades is led
    "Spades"        // Trump suit
    );

    // Verify the card Bob played
    ASSERT_EQUAL(card_played, Card(Card::RANK_ACE, Card::SUIT_SPADES));
    
    
    Player * bob2 = Player_factory("Bob", "Simple");
    bob2->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    bob2->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    bob2->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    bob2->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    //bob2->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));

    // Bob plays a card
    //Card ten_spades(Card::RANK_TEN, Card::SUIT_SPADES);
    Card card_played2 = bob2->play_card(
    ten_spades,  // Ten of Spades is led
    "Spades"        // Trump suit
    );

    // Verify the card Bob played
    ASSERT_EQUAL(card_played2, Card(Card::RANK_KING, Card::SUIT_SPADES));
    
    
    Player * bob3 = Player_factory("Bob", "Simple");
    bob3->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    bob3->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    bob3->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    //bob3->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    //bob2->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));

    // Bob plays a card
    //Card ten_spades(Card::RANK_TEN, Card::SUIT_SPADES);
    Card card_played3 = bob3->play_card(
    ten_spades,  // Ten of Spades is led
    "Spades"        // Trump suit
    );

    // Verify the card Bob played
    ASSERT_EQUAL(card_played3, Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    
    
    Player * bob4 = Player_factory("Bob", "Simple");
    bob4->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    bob4->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    //bob4->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    //bob3->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    //bob2->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));

    // Bob plays a card
    //Card ten_spades(Card::RANK_TEN, Card::SUIT_SPADES);
    Card card_played4 = bob4->play_card(
    ten_spades,  // Ten of Spades is led
    "Spades"        // Trump suit
    );

    // Verify the card Bob played
    ASSERT_EQUAL(card_played4, Card(Card::RANK_TEN, Card::SUIT_SPADES));
    
    delete bob4;
    delete bob3;
    delete bob2;
    delete bob;
    
}

TEST(testing) {
    Player * bob5 = Player_factory("Bob", "Simple");
    bob5->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    //bob4->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    //bob4->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    //bob3->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    //bob2->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));


    // Bob plays a card
    Card ten_spades(Card::RANK_TEN, Card::SUIT_SPADES);
    Card card_played5 = bob5->play_card(
    ten_spades,  // Ten of Spades is led
    "Spades"        // Trump suit
    );

    // Verify the card Bob played
    ASSERT_EQUAL(card_played5, Card(Card::RANK_NINE, Card::SUIT_SPADES));
    
    
    Player * bob6 = Player_factory("Bob", "Simple");
    bob6->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    //bob4->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    //bob4->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    //bob3->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    //bob2->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));

    // Bob plays a card
    //Card ten_spades(Card::RANK_TEN, Card::SUIT_SPADES);
    Card card_played6 = bob6->play_card(
    ten_spades,  // Ten of Spades is led
    "Spades"        // Trump suit
    );

    // Verify the card Bob played
    ASSERT_EQUAL(card_played6, Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    
                 
    
    Player * bob7 = Player_factory("Bob", "Simple");
    bob7->add_card(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    //bob4->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    //bob4->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    //bob3->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    //bob2->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));

    // Bob plays a card
    //Card ten_spades(Card::RANK_TEN, Card::SUIT_SPADES);
    Card card_played7 = bob7->play_card(
    ten_spades,  // Ten of Spades is led
    "Spades"        // Trump suit
    );

    // Verify the card Bob played
    ASSERT_EQUAL(card_played7, Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    
    delete bob7;
    delete bob6;
    delete bob5;
    
}

TEST(test_player_play_card_edgecase_1_0) {
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));

    // Bob plays a card
    Card ten_spades(Card::RANK_TEN, Card::SUIT_SPADES);
    Card card_played = bob->play_card(
    ten_spades,  // Ten of Spades is led
    "Spades"        // Trump suit
    );

    // Verify the card Bob played
    ASSERT_EQUAL(card_played, Card(Card::RANK_NINE, Card::SUIT_SPADES));

    delete bob;
}

TEST(test_player_play_card_edgecase_1_1) {
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS));

    // Bob plays a card
    Card ten_diamonds(Card::RANK_TEN, Card::SUIT_DIAMONDS);
    Card card_played = bob->play_card(
    ten_diamonds,  // Ten of Spades is led
    "Diamonds"        // Trump suit
    );

    // Verify the card Bob played
    ASSERT_EQUAL(card_played, Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    delete bob;
}

TEST(test_player_play_card_edgecase_2) {
    // right bower
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));

    // Bob plays a card
    Card two_spades(Card::RANK_TWO, Card::SUIT_SPADES);
    Card card_played = bob->play_card(
    two_spades,  // Two of Spades is led
    "Spades"  // Trump suit
    );

    // Verify the card Bob played
    ASSERT_EQUAL(card_played, Card(Card::RANK_JACK, Card::SUIT_SPADES));
    delete bob;
}

TEST(test_player_play_card_edgecase_3) {
    // left bower
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));

    // Bob plays a card
    Card two_spades(Card::RANK_TWO, Card::SUIT_SPADES);
    Card card_played = bob->play_card(
    two_spades,  // Ten of Spades is led
    "Spades"    // Trump suit
    );

    ASSERT_EQUAL(card_played, Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    delete bob;
}

TEST(test_player_play_card_edgecase_4) {
    //left and right bower, ace
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));

    // Bob plays a card
    Card two_spades(Card::RANK_TWO, Card::SUIT_SPADES);
    Card card_played = bob->play_card(
    two_spades,  // Ten of Spades is led
    "Spades"    // Trump suit
    );

    ASSERT_EQUAL(card_played, Card(Card::RANK_JACK, Card::SUIT_SPADES));
    delete bob;
}

//they play the highest card that follows suit. Otherwise, they play the lowest card in their hand.
//doesn't have led card suit (plays lowest)
//doesn't have led card suit, but has trump (plays lowest)
TEST(test_player_play_card_edgecase_5) {
    //left and right bower, ace
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));

    // Bob plays a card
    Card two_diamonds(Card::RANK_TWO, Card::SUIT_DIAMONDS);
    Card card_played = bob->play_card(
    two_diamonds,  // two of diamonds is led
    "Hearts"    // Trump suit
    );

    ASSERT_EQUAL(card_played, Card(Card::RANK_NINE, Card::SUIT_SPADES));
    delete bob;
}

//they play the highest card that follows suit. Otherwise, they play the lowest card in their hand.
TEST(test_player_play_card_edgecase_5_1) {
    //left and right bower, ace
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_HEARTS));

    // Bob plays a card
    Card two_diamonds(Card::RANK_TWO, Card::SUIT_DIAMONDS);
    Card card_played = bob->play_card(
    two_diamonds,  // two of diamonds is led
    "Hearts"    // Trump suit
    );

    ASSERT_EQUAL(card_played, Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    delete bob;
}


//they play the highest card that follows suit. Otherwise, they play the lowest card in their hand.
//lead card is right bower
TEST(test_player_play_card_edgecase_5_2) {
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_HEARTS));

    // Bob plays a card
    Card jack_hearts(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card card_played = bob->play_card(
    jack_hearts,  // two of diamonds is led
    "Hearts"    // Trump suit
    );

    ASSERT_EQUAL(card_played, Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    delete bob;
}

//lead card is left bower, no cards follow suit
TEST(test_player_play_card_edgecase_5_3) {
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_EIGHT, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_DIAMONDS));

    // Bob plays a card
    Card jack_diamonds(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card card_played = bob->play_card(
    jack_diamonds,  // two of diamonds is led
    "Hearts"    // Trump suit
    );

    ASSERT_EQUAL(card_played, Card(Card::RANK_EIGHT, Card::SUIT_DIAMONDS));
    delete bob;
}

//lead card is left bower, cards DO follow suit
TEST(test_player_play_card_edgecase_5_4) {
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_EIGHT, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_HEARTS));

    // Bob plays a card
    Card jack_diamonds(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card card_played = bob->play_card(
    jack_diamonds,  // two of diamonds is led
    "Hearts"    // Trump suit
    );

    ASSERT_EQUAL(card_played, Card(Card::RANK_ACE, Card::SUIT_HEARTS));
    
//lead card is left bower

// Bob's hand
Player * bob2 = Player_factory("Bob", "Simple");
bob2->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
bob2->add_card(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
bob2->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
bob2->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
bob2->add_card(Card(Card::RANK_ACE, Card::SUIT_HEARTS));

// Bob plays a card
Card two_diamonds(Card::RANK_TWO, Card::SUIT_DIAMONDS);
Card card_played2 = bob2->play_card(
two_diamonds,  // two of diamonds is led
"Hearts"    // Trump suit
);

ASSERT_EQUAL(card_played2, Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    
    




//doesn't have led card suit, but has trump (plays lowest)

    
    // Bob's hand
    Player * bob3 = Player_factory("Bob", "Simple");
    bob3->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    bob3->add_card(Card(Card::RANK_EIGHT, Card::SUIT_SPADES));
    bob3->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    bob3->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    bob3->add_card(Card(Card::RANK_ACE, Card::SUIT_HEARTS));

    // Bob plays a card
    Card two_clubs(Card::RANK_TWO, Card::SUIT_CLUBS);
    Card card_played3 = bob3->play_card(
    two_clubs,  // Ten of Spades is led
    "Spades"    // Trump suit
    );

    ASSERT_EQUAL(card_played3, Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    delete bob3;
    delete bob;
    delete bob2;

}


TEST(test_player_play_card_edgecase_7) {
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_HEARTS));

    // Bob plays a card
    Card two_clubs(Card::RANK_TWO, Card::SUIT_CLUBS);
    Card card_played = bob->play_card(
    two_clubs,  // Ten of Spades is led
    "Spades"    // Trump suit
    );

    ASSERT_EQUAL(card_played, Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    delete bob;
}

TEST(test_insertion_operator) {
    Player * Janine = Player_factory("Janine", "Simple");
    ostringstream oss;
    oss << *Janine;
    ASSERT_EQUAL(oss.str(), "Janine");
    
    delete Janine;
}

TEST(test_insertion_operator_2) {
    Player * bob = Player_factory("", "Simple");
    ostringstream oss;
    oss << *bob;
    ASSERT_EQUAL(oss.str(), "");
    
    delete bob;
}



TEST_MAIN()
//what does add and discard do, how to test it
/*
TEST(test_player_add_and_discard_1) {
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));
      // Bob adds a card to his hand and discards one card
    
    bob->add_and_discard(Card(Card::RANK_NINE, Card::SUIT_HEARTS) // upcard
      );
    //ASSERT()
    delete bob;
}
//create a test where upcard is taken
*/
