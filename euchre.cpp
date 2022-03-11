//Project UID 1d9f47bfc76643019cfbf037641defe1
#include "Player.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "Pack.h"
#include "Card.h"
#include <cstring>
using namespace std;


class Game {
private:
    Player * players[4];
    Player * ordered[4];
    string shuffle;

    Pack pack;
    int score[2];
    int handScore[2];
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
        fin.open(argv[1]);
        Pack gamePack(fin);
        pack = gamePack;
        score[0] = 0;
        score[1] = 0;
        handScore[0] = 0;
        handScore[1] = 0;
        hand = 0;
        team[0] = players[0]->get_name() + " and " + players[2]->get_name();
        team[1] = players[1]->get_name() + " and " + players[3]->get_name();
    }


    static string cardType(Card& card) {
        return card.get_rank() + " of " + card.get_suit();
    }

    void deal_player(Player* player, int number) {
        for (int i = 0; i < number; i++) {
            player->add_card(pack.deal_one());
        }
    }
    
    //NEW FUNCTION that orders players into a new array
    void players_ordered() {
        for (int i = 0; i < 4; i++) {
            ordered[i] = players[(dealer_index(hand) + i + 1) % 4];
        }
        
    }
    
    void deal(Player * dealer) {
        
        players_ordered();
        for (int i = 0; i < 4; i++) {
            if (i % 2 == 0) {
                deal_player(ordered[i], 3);
            }
            else {
                deal_player(ordered[i], 2);
            }

    
        }
        
        for (int i = 0; i < 4; i++) {
            if (i % 2 == 0) {
                deal_player(ordered[i], 2);
            }
            else {
                deal_player(ordered[i], 3);
            }
        }
        /*
        
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
        */
        
    }
    
    int dealer_index(int hand) {
        return hand % 4;
        //if hand = 0, player 0 deals
        //if hand = 1, player 1 deals
        // ...
        //if hand = 4, player 0 deals
    }
    
    

    Card setUpTable() {
        if (shuffle == "shuffle") {
            pack.shuffle();
        }
        
        deal(players[dealer_index(hand)]);
        //WE MIGHT NEED TO ITERATE HAND HERE
        
        cout << "Hand " << hand << endl;
        cout << players[dealer_index(hand)]->get_name() << " deals" << endl;
        Card upCard = pack.deal_one();
        cout << upCard.get_rank() << " of " << upCard.get_suit() << " turned up" << endl;
        
        return upCard;
    }
    
    bool is_dealer(Player * player) {
        if (players[dealer_index(hand)] == player) {
            return true;
        }
        else {
            return false;
        }
    }

    string makingTrump(Card upCard) {
        string trump = "";
        for (int j = 1; j <= 2; ++j) {
            for (int i = 0; i < 4; ++i) {
                Player *player = ordered[i];
                string upCardSuit = upCard.get_suit();
                if (player->make_trump(upCard, is_dealer(player), j, upCardSuit)) {
                    trump = upCardSuit;
                    cout << player->get_name() << " orders up " << upCardSuit << endl;
                    cout << endl;
                    break;
                }
                else {
                    cout << player->get_name() << " passes" << endl;
                }
            }
        }
        return trump;
    }
    
    int getIndex(Player *player) {
        for (int i = 0; i < 4; ++i) {
            if (ordered[i] == player) {
                return i;
            }
        }
        return -1;
    }
    
    //rewrites ordered s.t. the first index is the player who won the trick and shifts everyone else after in order
    void shiftOrdered(Player *trickTaker) {
        getIndex(trickTaker);
        Player * tempArray[4];
        for (int i = 0; i < 4;  ++i) {
            tempArray[i] = ordered[(getIndex(trickTaker) + i) % 4];
        }
        
        for (int i = 0; i < 4; ++i) {
            ordered[i] = tempArray[i];
        }
        
        
    }

    void trickTaking(string trump) {
        for (int i = 0; i < 5; ++i) {
        Card ledCard = ordered[0]->lead_card(trump);
        cout << ledCard.get_rank() << " of " << ledCard.get_suit() << " led by " << ordered[0]->get_name() << endl;
        Card maxCard = ledCard;
        
        Card card1 = ordered[1]->play_card(ledCard, trump);
        cout << card1.get_rank() << " of " << card1.get_suit() << " played by " << ordered[1]->get_name() << endl;
            if (Card_less(maxCard, card1, ledCard, trump)) { maxCard = card1; }
        
        Card card2 = ordered[2]->play_card(ledCard, trump);
        cout << card2.get_rank() << " of " << card2.get_suit() << " played by " << ordered[2]->get_name() << endl;
            if (Card_less(maxCard, card2, ledCard, trump)) { maxCard = card2; }
        
        Card card3 = ordered[3]->play_card(ledCard, trump);
        cout << card3.get_rank() << " of " << card3.get_suit() << " played by " << ordered[3]->get_name() << endl;
            if (Card_less(maxCard, card3, ledCard, trump)) { maxCard = card3; }
        
        
        if (maxCard == ledCard) {
            cout << ordered[0]->get_name() << " takes the trick" << endl;
            ++handScore[0];
            shiftOrdered(ordered[0]);
            //newindex starts at player after player0
        }
        
        else if (maxCard == card1) {
            cout << ordered[1]->get_name() << " takes the trick" << endl;
            ++handScore[1];
            shiftOrdered(ordered[1]);
            
            //new index starts at player after player1
        }
        
        else if (maxCard == card2) {
            cout << ordered[2]->get_name() << " takes the trick" << endl;
            ++handScore[0];
            shiftOrdered(ordered[2]);
        }
        
        else {
            cout << ordered[3]->get_name() << " takes the trick" << endl;
            ++handScore[1];
            shiftOrdered(ordered[3]);
        }
        cout << endl;
        }
        score[0] += handScore[0];
        score[1] += handScore[1];
        if (handScore[0] > handScore[1]) {
            cout << team[0] << " win the hand" << endl;
        }
        else {
            cout << team[1] << " win the hand" << endl;
        }
        //EUCHRED AND MARCH
        if (score[0] > score[1]) {
            cout << team[0] << " have " << score[0] << " points" << endl;
        }
        //Taking all 5 tricks is called a march. If the winning team did not order up, they receive 2 points for taking 3, 4 or 5 tricks, which is called euchred.
    }

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


    Pack getPack() {
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
        if (i == argc - 1) {
            cout << argv[i] << " " << endl;
        }
        else {
            cout << argv[i] << " ";
        }
    }
    
    
    
    Game x = Game(&argc, argv);
    Card upCard = x.setUpTable();
    string trump = x.makingTrump(upCard);
    x.trickTaking(trump);
    
    
    
    //delete all the players!!!!!!

}


/*
    Game* x = new Game(&argc, argv);
    if (x->getShuffle() == "shuffle") {
        x->getPack()->shuffle();
    }

    x->getPlayer1()->
*/


