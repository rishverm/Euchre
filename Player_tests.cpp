// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Player.h"
#include "unit_test_framework.h"

#include <iostream>

using namespace std;

//Test get_name, Player_factory
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

//MAKE TRUMP TESTS
//round == 1 && is_dealer, 0 face cards X
//round == 1 && is_dealer, 1 face card X
//round == 1 && is_dealer, 2 face cards X
//round == 1 && is_dealer, 3 face cards X

//round == 1 && !is_dealer, 0 face cards X
//round == 1 && !is_dealer, 1 face card X
//round == 1 && !is_dealer, 2 face cards X
//round == 1 && !is_dealer, 3 face cards X

//round == 2 && is_dealer, 0 face cards
//round == 2 && is_dealer, 1 face card
//round == 2 && is_dealer, 2 face cards
//round == 2 && is_dealer, 3 face cards

//round == 2 && !is_dealer, 0 face cards
//round == 2 && !is_dealer, 1 face card
//round == 2 && !is_dealer, 2 face cards
//round == 2 && !is_dealer, 3 face cards


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

    delete gollum;
}

TEST(test_player_make_trump_2) {
    // Player's hand
    Player * smeagol = Player_factory("Smeagol", "Simple");
    smeagol->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    smeagol->add_card(Card(Card::RANK_THREE, Card::SUIT_SPADES));
    smeagol->add_card(Card(Card::RANK_FOUR, Card::SUIT_SPADES));
    smeagol->add_card(Card(Card::RANK_FIVE, Card::SUIT_SPADES));
    smeagol->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));

    // Player makes trump
    Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    string trump;
    bool orderup = smeagol->make_trump(
      nine_spades,    // Upcard
      true,           // Player is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_FALSE(orderup);

    delete smeagol;
}

TEST(test_player_make_trump_3) {
    // Player's hand
    Player * legolas = Player_factory("Legolas", "Simple");
    legolas->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    legolas->add_card(Card(Card::RANK_THREE, Card::SUIT_SPADES));
    legolas->add_card(Card(Card::RANK_FOUR, Card::SUIT_SPADES));
    legolas->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    legolas->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));

    // Player makes trump
    Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    string trump;
    bool orderup = legolas->make_trump(
      nine_spades,    // Upcard
      true,           // Player is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_SPADES);
    
    delete legolas;
}

TEST(test_player_make_trump_4) {
    // Player's hand
    Player * pippin = Player_factory("Pippin", "Simple");
    pippin->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    pippin->add_card(Card(Card::RANK_EIGHT, Card::SUIT_SPADES));
    pippin->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    pippin->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    pippin->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));

    // Player makes trump
    Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    string trump;
    bool orderup = pippin->make_trump(
      nine_spades,    // Upcard
      true,           // Player is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_SPADES);

    delete pippin;
}

TEST(test_player_make_trump_5) {
    // Player's hand
    Player * aragorn = Player_factory("Aragorn", "Simple");
    aragorn->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    aragorn->add_card(Card(Card::RANK_EIGHT, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_FOUR, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    aragorn->add_card(Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS));

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

TEST(test_player_make_trump_6) {
    // Player's hand
    Player * arwen = Player_factory("Arwen", "Simple");
    arwen->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    arwen->add_card(Card(Card::RANK_EIGHT, Card::SUIT_SPADES));
    arwen->add_card(Card(Card::RANK_FOUR, Card::SUIT_SPADES));
    arwen->add_card(Card(Card::RANK_FIVE, Card::SUIT_SPADES));
    arwen->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));

    // Player makes trump
    Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    string trump;
    bool orderup = arwen->make_trump(
      nine_spades,    // Upcard
      false,           // Player is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_FALSE(orderup);
    
    delete arwen;
}


TEST(test_player_make_trump_7) {
    // Player's hand
    Player * merry = Player_factory("Merry", "Simple");
    merry->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    merry->add_card(Card(Card::RANK_EIGHT, Card::SUIT_SPADES));
    merry->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    merry->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    merry->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));

    // Player makes trump
    Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    string trump;
    bool orderup = merry->make_trump(
      nine_spades,    // Upcard
      false,           // Player is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_SPADES);
    
    delete merry;
}

TEST(test_player_make_trump_8) {
    // Player's hand
    Player * boromir = Player_factory("Merry", "Simple");
    boromir->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    boromir->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));
    boromir->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    boromir->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    boromir->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));

    // Player makes trump
    Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    string trump;
    bool orderup = boromir->make_trump(
      nine_spades,    // Upcard
      false,           // Player is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_SPADES);
    
    delete boromir;
}

TEST(test_player_make_trump_1_0) {
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
      2,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_FALSE(orderup);

    delete gollum;
}

TEST(test_player_make_trump_2) {
    // Player's hand
    Player * smeagol = Player_factory("Smeagol", "Simple");
    smeagol->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    smeagol->add_card(Card(Card::RANK_THREE, Card::SUIT_SPADES));
    smeagol->add_card(Card(Card::RANK_FOUR, Card::SUIT_SPADES));
    smeagol->add_card(Card(Card::RANK_FIVE, Card::SUIT_SPADES));
    smeagol->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));

    // Player makes trump
    Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    string trump;
    bool orderup = smeagol->make_trump(
      nine_spades,    // Upcard
      true,           // Player is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_FALSE(orderup);

    delete smeagol;
}

TEST(test_player_make_trump_3) {
    // Player's hand
    Player * legolas = Player_factory("Legolas", "Simple");
    legolas->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    legolas->add_card(Card(Card::RANK_THREE, Card::SUIT_SPADES));
    legolas->add_card(Card(Card::RANK_FOUR, Card::SUIT_SPADES));
    legolas->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    legolas->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));

    // Player makes trump
    Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    string trump;
    bool orderup = legolas->make_trump(
      nine_spades,    // Upcard
      true,           // Player is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_SPADES);
    
    delete legolas;
}

TEST(test_player_make_trump_4) {
    // Player's hand
    Player * pippin = Player_factory("Pippin", "Simple");
    pippin->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    pippin->add_card(Card(Card::RANK_EIGHT, Card::SUIT_SPADES));
    pippin->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    pippin->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    pippin->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));

    // Player makes trump
    Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    string trump;
    bool orderup = pippin->make_trump(
      nine_spades,    // Upcard
      true,           // Player is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_SPADES);

    delete pippin;
}

TEST(test_player_make_trump_5) {
    // Player's hand
    Player * aragorn = Player_factory("Aragorn", "Simple");
    aragorn->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    aragorn->add_card(Card(Card::RANK_EIGHT, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_FOUR, Card::SUIT_SPADES));
    aragorn->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    aragorn->add_card(Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS));

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

TEST(test_player_make_trump_6) {
    // Player's hand
    Player * arwen = Player_factory("Arwen", "Simple");
    arwen->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    arwen->add_card(Card(Card::RANK_EIGHT, Card::SUIT_SPADES));
    arwen->add_card(Card(Card::RANK_FOUR, Card::SUIT_SPADES));
    arwen->add_card(Card(Card::RANK_FIVE, Card::SUIT_SPADES));
    arwen->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));

    // Player makes trump
    Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    string trump;
    bool orderup = arwen->make_trump(
      nine_spades,    // Upcard
      false,           // Player is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_FALSE(orderup);
    
    delete arwen;
}


TEST(test_player_make_trump_7) {
    // Player's hand
    Player * merry = Player_factory("Merry", "Simple");
    merry->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    merry->add_card(Card(Card::RANK_EIGHT, Card::SUIT_SPADES));
    merry->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    merry->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    merry->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));

    // Player makes trump
    Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    string trump;
    bool orderup = merry->make_trump(
      nine_spades,    // Upcard
      false,           // Player is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_SPADES);
    
    delete merry;
}

TEST(test_player_make_trump_8) {
    // Player's hand
    Player * boromir = Player_factory("Merry", "Simple");
    boromir->add_card(Card(Card::RANK_TWO, Card::SUIT_SPADES));
    boromir->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));
    boromir->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    boromir->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    boromir->add_card(Card(Card::RANK_QUEEN, Card::SUIT_SPADES));

    // Player makes trump
    Card nine_spades(Card::RANK_NINE, Card::SUIT_SPADES);
    string trump;
    bool orderup = boromir->make_trump(
      nine_spades,    // Upcard
      false,           // Player is also the dealer
      1,              // First round
      trump           // Suit ordered up (if any)
    );

    // Verify Player's order up and trump suit
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_SPADES);
    
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
    
    bob->add_and_discard(Card(Card::RANK_NINE, Card::SUIT_HEARTS) // upcard
      );
      // Bob leads
    Card card_led = bob->lead_card(Card::SUIT_HEARTS); //trump suit

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
    Card card_led = bob->lead_card(Card::SUIT_SPADES); //trump suit
    //bob leads with the highest non-trump card
      // Verify the card Bob selected to lead
    Card nine_spades(Card::RANK_NINE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(card_led, nine_spades); //check led card

    delete bob;
}
//Simple Players will lead the highest non-trump card in their hand (this ordering
//considers the trump suit). If their hand is all trump cards, they lead the highest.
TEST(test_player_lead_card_edgecase_7) {
    //test with 1 card, pick up non-trump
    
    // Bob's hand
    Player * bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
      // Bob adds a card to his hand and discards one card
    
    // Bob will discard the lowest card in his hand,
    bob->add_and_discard(Card(Card::RANK_NINE, Card::SUIT_SPADES) // upcard
      );

      // Bob leads
    Card card_led = bob->lead_card(Card::SUIT_SPADES); //trump suit
    //bob leads with the highest non-trump card
    
      // Bob will lead with
    Card nine_hearts(Card::RANK_NINE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(card_led, nine_hearts); //check led card

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
    "Spades"        // Trump suit
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
