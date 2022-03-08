//Project UID 1d9f47bfc76643019cfbf037641defe1

#include <cstdlib>
#include <fstream>
#include <cstring>
#include <iostream>
#include <string>
#include "Player.h"
#include "Pack.h"

using namespace std;


//
/*
Player * setUpPlayers(char *argv[], int argc) {
    Player *players[4];
    int ind = 0;
    for (int i = 4; i < argc; i+=2) {
        players[ind] = Player_factory(argv[i], (argv[i + 1]));
        ++ind;
    }
    return players[0];
}

*/

Player * setUpPlayers(char *argv[], int argc) {
    int ind = 0;
    Player *players[4];
    for (int i = 4; i < argc; i+=2) {
        players[ind] = Player_factory(argv[i], (argv[i + 1]));
        ++ind;
    }
    return players[0];
}

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
        Player *players[4];
        string shuffle;
        //should this be 24?
        Pack *cards[24];
        int score[2];
    
    public:
        
        Game(int argc, char *argv[]) {
            int ind = 0;
            for (int i = 4; i < argc; i+=2) {
                players[ind] = Player_factory(argv[i], (argv[i + 1]));
                ++ind;
            }
            shuffle = argv[2];
            
            cards = Pack(&file);
            
            
            
            
            
        }
            
        
        //is this a good way to store and create the players array?
        

        
        void setUpTable();
        
        void makingTrump();
        
        void trickTaking();
        
        void scoring();
        
    };
    
    
    Player *player_array = setUpPlayers(argv, argc);
    //Game *y = new Game(&player_array);
    
    
    
    
    return 0;
}
