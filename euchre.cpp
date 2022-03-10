//Project UID 1d9f47bfc76643019cfbf037641defe1
#include "Player.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "Pack.h"
#include "Card.h"
#include "euchre.h"
using namespace std;










class Game {
private:
    Player* players[4];
    string shuffle;

    Pack* pack;
    int score[2];
    string team[2];
    int hand;

public:
    
    

    Game(int* argc, char* argv[]) {
        int ind = 0;
        for (int i = 4; i < *argc; i += 2) {
            players[ind] = Player_factory(argv[i], (argv[i + 1]));
            ++ind;
        }
        shuffle = argv[2];

        ifstream fin;
        fin.open(argv[2]);
        Pack gamePack(fin);
        pack = &gamePack;
        score[0] = 0;
        score[1] = 0;
        hand = 1;
        team[0] = players[0]->get_name() + " and " + players[2]->get_name();
        team[1] = players[1]->get_name() + " and " + players[3]->get_name();
    }


    static string cardType(Card& card) {
        return card.get_rank() + " of " + card.get_suit();
    }

    void deal_player(Player* player, int number) {
        for (int i = 0; i < number; i++) {
            player->add_card(pack->deal_one());
        }
    }
    
    void deal(Player * dealer) {
        
        //dealer + 1 = 3 cards
        deal_player(players[(dealer_index(hand) + 1) % 4], 3);
        //dealer + 2 = 2 cards
        deal_player(players[(dealer_index(hand) + 2) % 4], 2);
        //dealer + 3 = 3 cards
        deal_player(players[(dealer_index(hand) + 3) % 4], 3);
        //dealer = 2 cards
        deal_player(players[(dealer_index(hand) + 4) % 4], 2);
        
        //dealer + 1 = 2 cards
        deal_player(players[(dealer_index(hand) + 1) % 4], 2);
        //dealer + 2 = 3 cards
        deal_player(players[(dealer_index(hand) + 2) % 4], 3);
        //dealer + 3 = 2 cards
        deal_player(players[(dealer_index(hand) + 3) % 4], 2);
        //dealer = 3 cards
        deal_player(players[(dealer_index(hand) + 4) % 4], 3);
        
        
    }
    
    int dealer_index(int hand) {
        return hand % 4;
        //if hand = 0, player 0 deals
        //if hand = 1, player 1 deals
        // ...
        //if hand = 4, player 0 deals
    }

    void setUpTable() {
        if (shuffle == "shuffle") {
            pack->shuffle();
        }
        
        deal(players[dealer_index(hand)]);
        //WE MIGHT NEED TO ITERATE HAND HERE
        
        cout << "Hand " << hand << endl;
        cout << players[dealer_index(hand)]->get_name() << " deals" << endl;
    }

    void makingTrump();

    void trickTaking();

    void scoring();

    Player* getPlayer0() {
        return players[0];
    }

    Player* getPlayer1() {
        return players[1];
    }

    Player* getPlayer2() {
        return players[2];
    }

    Player* getPlayer3() {
        return players[3];
    }

    string getShuffle() {
        return shuffle;
    }


    Pack* getPack() {
        return pack;
    }

    int* getScore() {
        
        ++hand;
        return score;
    }

    string* getTeam() {
        return team;
    }



};

int main(int argc, char* argv[]) {
    if (argc != 12) {
        cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
            << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
            << "NAME4 TYPE4" << endl;
        return 1;
    }
    if (atoi(argv[3]) > 100 || atoi(argv[3]) < 1) {
        cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
            << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
            << "NAME4 TYPE4" << endl;
        return 1;
    }
    if (strcmp(argv[2], "shuffle") != 0) {
        if (strcmp(argv[2], "noshuffle") != 0) {
            cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
                << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
                << "NAME4 TYPE4" << endl;
            return 1;
        }
    }
    if (strcmp(argv[5], "Human") != 0) {
        if (strcmp(argv[5], "Simple") != 0) {
            cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
                << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
                << "NAME4 TYPE4" << endl;
            return 1;
        }

    }
    if (strcmp(argv[7], "Human") != 0) {
        if (strcmp(argv[7], "Simple") != 0) {
            cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
                << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
                << "NAME4 TYPE4" << endl;
            return 1;
        }

    }
    if (strcmp(argv[9], "Human") != 0) {
        if (strcmp(argv[9], "Simple") != 0) {
            cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
                << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
                << "NAME4 TYPE4" << endl;
            return 1;
        }

    }
    if (strcmp(argv[11], "Human") != 0) {
        if (strcmp(argv[11], "Simple") != 0) {
            cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
                << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
                << "NAME4 TYPE4" << endl;
            return 1;
        }

    }
    ifstream file;
    file.open(argv[1]);
    if (!file.is_open()) {
        cout << "Error opening " << argv[1] << endl;
    }
    
    for (int i = 0; i < argc; ++i) {
        cout << argv[i] << " ";
    }
    
    Game* x = new Game(&argc, argv);
    cout << x->deal_player(, 3);
    

}


/*
    Game* x = new Game(&argc, argv);
    if (x->getShuffle() == "shuffle") {
        x->getPack()->shuffle();
    }

    x->getPlayer1()->
*/


