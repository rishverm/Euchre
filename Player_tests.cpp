// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Player.h"
#include "unit_test_framework.h"

#include <iostream>

using namespace std;

TEST(test_player_get_name_basic) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}

TEST(test_player_get_name_2) {
  // Create a player and verify that get_name() returns the player's name
  Player * Gandolf = Player_factory("Gandolf", "Simple");
  ASSERT_EQUAL(Gandolf->get_name(), "Gandolf");
  delete Gandolf;
}

TEST(test_player_add_card_basic) {
    Card c(Card::RANK_QUEEN, Card::SUIT_DIAMONDS);
    
}

TEST(test_player_make_trump_basic) {
    
}

TEST(test_player_add_and_discard_basic) {
    
}

TEST(test_player_lead_card_basic) {
    
}

TEST(test_player_play_card_basic) {
    
}

TEST(test_player_player_factory_basic) {
    
}

// Add more tests here

TEST_MAIN()
