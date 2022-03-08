
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <iostream>
#include <string>
#include "Player.h"
#include "Pack.h"
using namespace std;

int main(int argc, char *argv[]) {
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
    
    /*
    if (strcmp(argv[2], "shuffle") != 0 && strcmp(argv[2], "noshuffle") != 0) {
            cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
                 << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
                 << "NAME4 TYPE4" << endl;
            return 1;
        }
    
    
    */
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
    
    class Game {
    private:
        Player *players[4] = {player1, ;
        //should this be 24?
        Pack *cards[24];
        int score[2];
    
    public:
        void setUpPlayers(
        void setUpTable(argv[2], argv[3], arg)
        
    };
    
    Player *player1 = Player_factory(argv[4], argv[5]);
    Player *player2 = Player_factory(argv[6], argv[7]);
    Player *player3 = Player_factory(argv[8], argv[9]);
    Player *player4 = Player_factory(argv[10], argv[11]);
    
    
    
    return 0;
}
