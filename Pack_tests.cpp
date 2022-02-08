// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Pack.h"
#include "unit_test_framework.h"
#include <fstream>
#include <iostream>

using namespace std;

TEST(test_pack_default_ctor) {
    Pack pack;
    Card first = pack.deal_one();
    ASSERT_EQUAL(Card::RANK_NINE, first.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, first.get_suit());
}

TEST(test_pack_non_default_ctor) {
    const string filename = "pack.in";
    ifstream ifs(filename);
    ASSERT_TRUE(ifs.is_open());
    Pack pack(ifs);
    pack.deal_one();
    pack.deal_one();
    Card third_card = pack.deal_one();
    
    ASSERT_EQUAL(third_card, Card(Card::RANK_JACK, Card::SUIT_SPADES));
    ASSERT_EQUAL(Card::RANK_JACK, third_card.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, third_card.get_suit());
}
// Add more tests here

TEST_MAIN()
