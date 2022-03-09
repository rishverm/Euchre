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
    //should this be 24?
    Pack* pack;
    int score[2];
    string team[2];

public:

    Game(int argc, char* argv[]) {
        int ind = 0;
        for (int i = 4; i < argc; i += 2) {
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
        team[0] = players[0]->get_name() + " and " + players[2]->get_name();
        team[1] = players[1]->get_name() + " and " + players[3]->get_name();
    }


    //is this a good way to store and create the players array?
    static string cardType(Card& card) {
        return card.get_rank() + " of " + card.get_suit();
    }

    static void deal_player(Player* player, Pack& pack, int number) {
        for (int i = 0; i < number; i++) {
            player->add_card(pack.deal_one());
        }
    }

    void setUpTable();

    void makingTrump();

    void trickTaking();

    void scoring();

};


#include "Player.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "Pack.h"
#include "Card.h"
using namespace std;



class Game {
private:
    Player* players[4];
    string shuffle;
    //should this be 24?
    Pack* pack;
    int score[2];
    string team[2];

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
        team[0] = players[0]->get_name() + " and " + players[2]->get_name();
        team[1] = players[1]->get_name() + " and " + players[3]->get_name();
    }

    

    Player* getPlayer1() {
        return players[0];
    }

    Player* getPlayer2() {
        return players[1];
    }

    Player* getPlayer3() {
        return players[2];
    }

    Player* getPlayer4() {
        return players[3];
    }

    string getShuffle() {
        return shuffle;
    }


    Pack* getPack() {
        return pack;
    }

    int* getScore() {
        return score;
    }

    string* getTeam() {
        return team;
    }


    //is this a good way to store and create the players array?
    static string cardType(Card& card) {
        return card.get_rank() + " of " + card.get_suit();
    }

    static void deal_player(Player* player, Pack& pack, int number) {
        for (int i = 0; i < number; i++) {
            player->add_card(pack.deal_one());
        }
    }

    void setUpTable();

    void makingTrump();

    void trickTaking();

    void scoring();

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





    Game* x = new Game(&argc, argv);
    if (x->getShuffle() == "shuffle") {
        x->getPack()->shuffle();
    }

    x->getPlayer1()->



