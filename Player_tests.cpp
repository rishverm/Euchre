// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Player.h"
#include "unit_test_framework.h"

#include <iostream>

using namespace std;

//test constructors
TEST(test_player_player_factory_basic) {
    // Create a Human player
    Player * marcus = Player_factory("Marcus", "Human");

    // Print the player using the stream insertion operator
    ostringstream oss1;
    oss1 << * marcus;

    // Verify that the output is the player's name
    ASSERT_EQUAL(oss1.str(), "Marcus");
    
    Player * maury = Player_factory("Maury", "Simple");

    // Print the player using the stream insertion operator
    ostringstream oss2;
    oss2 << * marcus;

    // Verify that the output is the player's name
    ASSERT_EQUAL(oss2.str(), "Maury");

    // Create a Simple player
    Player * mert = Player_factory("Mert", "Simple");

    // Print the player using the stream insertion operator
    ostringstream oss3;
    oss3 << * mert;
    ASSERT_EQUAL(oss3.str(), "Mert");

    // Clean up players that were created using Player_factory()
    delete maury;
    delete mert;
    delete marcus;
}


//Test get_name
TEST(test_player_get_name_basic) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}

TEST(test_player_get_name_2) {
  // Create a player and verify that get_name() returns the player's name
  Player * Gandolf = Player_factory("Gandolf", "Human");
  ASSERT_EQUAL(Gandolf->get_name(), "Gandolf");
    
  delete Gandolf;
}

//test add_card, make_trump
TEST(test_player_make_trump_basic) {
    // Player's hand
    Player * gollum = Player_factory("Gollum", "Simple");
    gollum->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    gollum->add_card(Card(Card::RANK_EIGHT, Card::SUIT_SPADES));
    gollum->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    gollum->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    gollum->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));

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
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_SPADES);

    delete gollum;
}

TEST(test_player_make_trump_edgecase_1) {
    //no cards of same suite as trump
    // Player's hand
    Player * merry = Player_factory("Merry", "Simple");
    merry->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    merry->add_card(Card(Card::RANK_EIGHT, Card::SUIT_SPADES));
    merry->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    merry->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    merry->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));

    // Player makes trump
    Card nine_diamonds(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    string trump;
    bool orderup = merry->make_trump(
      nine_diamonds,    // Upcard
      false,           // Bob is also the dealer
      2,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_FALSE(orderup);

    delete merry;
}


TEST(test_player_make_trump_edgecase_2) {
    //cards of same suite as trump, but no face cards of same suite as trump
    // Player's hand
    Player * merry = Player_factory("Merry", "Simple");
    merry->add_card(Card(Card::RANK_TWO, Card::SUIT_CLUBS));
    merry->add_card(Card(Card::RANK_EIGHT, Card::SUIT_CLUBS));
    merry->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    merry->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    merry->add_card(Card(Card::RANK_ACE, Card::SUIT_DIAMONDS));

    // Player makes trump
    Card six_clubs(Card::RANK_SIX, Card::SUIT_CLUBS);
    string trump;
    bool orderup = merry->make_trump(
      six_clubs,    // Upcard
      false,           // Bob is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_FALSE(orderup);

    delete merry;
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
    
    bob->add_and_discard(Card(Card::RANK_NINE, Card::SUIT_HEARTS) // upcard
      );

      // Bob leads
    Card card_led = bob->lead_card(Card::SUIT_HEARTS);

      // Verify the card Bob selected to lead
    Card ace_clubs(Card::RANK_ACE, Card::SUIT_CLUBS);
    ASSERT_EQUAL(card_led, ace_clubs); //check led card

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
    
    bob->add_and_discard(Card(Card::RANK_NINE, Card::SUIT_HEARTS) // upcard
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

      // Bob leads
    Card card_led = bob->lead_card(Card::SUIT_HEARTS);

      // Verify the card Bob selected to lead
    Card nine_hearts(Card::RANK_NINE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(card_led, nine_hearts); //check led card

    delete bob;
}

TEST(test_player_lead_card_edgecase_6) {
    //test with 1 card, pick up non-trump
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
      // Bob adds a card to his hand and discards one card
    
    bob->add_and_discard(Card(Card::RANK_NINE, Card::SUIT_SPADES) // upcard
      );

      // Bob leads
    Card card_led = bob->lead_card(Card::SUIT_HEARTS);

      // Verify the card Bob selected to lead
    Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    ASSERT_EQUAL(card_led, nine_spades); //check led card

    delete bob;
}

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
    "Hearts"        // Trump suit
    );

    // Verify the card Bob played
    ASSERT_EQUAL(card_played, Card(Card::RANK_ACE, Card::SUIT_SPADES));
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
    "Hearts"  // Trump suit
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
    "Hearts"    // Trump suit
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
    "Hearts"    // Trump suit
    );

    ASSERT_EQUAL(card_played, Card(Card::RANK_JACK, Card::SUIT_SPADES));
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
