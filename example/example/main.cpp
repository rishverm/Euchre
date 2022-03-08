//
//  main.cpp
//  example
//
//  Created by Jenna Elwing on 2/23/22.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void insert_multiple(int array[], int size, int item, int num_copies) {
    
    for (int i = size - 1; i >= 0; --i) {
        array[i] = array[i - num_copies];
        
    }
    

    for (int i = 0; i < num_copies; ++ i) {
        array[i] = item;
    }

}


void world(char x[], char y[], std::string z) {
    if(x == y)
        std::cout << z;
}


    // REQUIRES: 'array' is an array with 'size' elements
    // 0 <= 'num_copies' && 'num_copies' <= 'size' // MODIFIES: 'array'
    // EFFECTS : Inserts the specified number of copies of the given item // into the beginning of the array. Existing elements are // shifted to the right, and those that shift off the end of // the array are discarded.
    // EXAMPLE : int arr[5] = { 1, 2, 3, 4, 5 };
    // insert_multiple(arr, 5, 9, 3);
    // // arr now contains { 9, 9, 9, 1, 2 }
    // NOTE: Drawing a picture will be very helpful for solving this problem.
    
    
    //int arr[5] = {1, 2, 3, 4, 5};
    //insert_multiple(arr, 5, 9, 3);



int find_longest_sequence(const string &input) {
  if(input.empty()) return 0;
  int longest = 0;     // length of longest sequence seen so far
  int cur_length = 1;  // string starts with a sequence of 1, but
                       // it SHOULD actually have been set to 0
  char last_char = input[0]; // previous char seen

  // move through each character
  for(int i = 0; i < input.length(); i++) {
    if(input[i] == last_char) {
      cur_length++;

      // max() returns the larger of the two integers passed in
      longest = max(longest, cur_length);
    }
    else {
      cur_length = 1; // restart sequence at 1
      last_char = input[i];
    }
  }
  return longest;
}

double averagePlayerScore(const int *player, int numScores) {
    double sum = 0;
    for (int i = 0; i < numScores; ++i) {
        sum += player[i];
        
    }
    return sum / numScores;
}

// REQUIRES: All players have the same number of scores, numScores.
// MODIFIES: Nothing
// EFFECTS: Prints "HIGH SCORE" or "LOW SCORE" to standard output
//          for each player in the list, depending on whether the
//          average score for that player is > 30 or <= 30.
//          All print statements should end with a newline.
void classifyPlayer(const vector<int*> playerList, int numScores) {
    for (int i = 0; i < playerList.size(); ++ i) {
        if (averagePlayerScore(playerList[i], numScores) > 30) {
            cout << "HIGH SCORE" << endl;
        }
        else {
            cout << "LOW SCORE" << endl;
        }
    }
}

// REQUIRES: length is the length of the array
//           the arr is a valid pointer to an array of integers
// MODIFIES: nothing
// EFFECTS: Returns the total score of the given player, and
//          prints the total score of the given player to cout.


// REQUIRES: src points to a valid C-style string
//           dst points to a character array with enough space
//           for the secret message
//           target appears in src exactly once
//           target is not the null character
// MODIFIES: *dst
// EFFECTS:  Copies the secret message from src (ALL characters after
//           target) to dst
// EXAMPLES: See the reference material for several examples
void extract_secret_message(char target, char *dst, const char *src) {
  // Move src forward until we find the target character
  while(*src != target) {
    ++src;
  }
  ++src; // move past the target character

  // Copy the secret message into dst
  while(*src) {
      *dst = *src;
      ++dst;
      ++src;

  }

  // Terminate the string copied to dst
    *dst = '\0';
;
}

void filter(char *str, char target) {
  while (*str != target) {
    ++str;
  }
  ++str;
  while (*str) {
    *(str-1) = *str;
    ++str;
  }
  *(str-1) = '\0';
}

    
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {

  if (argc != 3
) {
    cout << "Invalid number of arguments" << endl;
      return 1
;
  }

  ifstream fin(argv[2]
);
  // assume the input file always opens successfully

  ofstream fout(argv[3]
);
  if (!fout.is_open()
) {
    cout << "Error opening file" << endl;
    return 1
;
  }

  string A; string B; string C; string junk;
  while (fin >> A >> B >> C >> junk
) {
      fout << C << endl;
      fout << A << " " << B << endl;
      fout << junk;
      

  }

  fin.close();
  fout.close();

  return 0;
}

struct Ingredient {
  string name; // name of the ingredient. Example: "cheese"
  bool vegan; // true if the ingredient is vegan
  double price; // price of each ingredient in dollars
};

class Sandwich {
private:
  string name; // name of this sandwich. Example: "Grilled Cheese"
  vector<Ingredient> ingredients;

public:

  // MODIFIES: this Sandwich
  // EFFECTS: Initializes a Sandwich with given name and ingredients
  Sandwich(const string &name_in,
           const vector<Ingredient> &ingredients_in) : Ingredient(name_in) {
      name = name_in;
      ingredients = ingredients_in;
  }

  // MODIFIES: this Sandwich
  // EFFECTS: add an Ingredient object to vector
  void add_ingredient(const Ingredient &ing);

  // EFFECTS: returns price of the sandwich, which is $2
  //          plus the sum of all ingredient prices
  double calculate_price();

  // EFFECTS: returns true if all ingredients in this
  //          Sandwich are vegan, false otherwise
  bool is_vegan();

  // EFFECTS: return name of sandwich
  const string & get_name();

  // EFFECTS: returns true if this Sandwich has a
  //          higher price than other Sandwich
  bool more_expensive_than(const Sandwich &other);
}; // END of Sandwich class


// EFFECTS: Iterates through menu to find the first
//          Sandwich with name matching sandwich_name
//          and returns the price of that sandwich.
//          Returns 0 if no matching Sandwich is found.
double order_sandwich(const string &sandwich_name,
                      vector<Sandwich> &menu) {
    for (int i = 0; i < menu.size(); ++i) {
        if (menu[i].get_name() == sandwich_name) {
            return menu[i].calculate_price();
        }
    }
         
         return 0;
}
