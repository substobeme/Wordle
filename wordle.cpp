#include <bits/stdc++.h>
using namespace std;

class Wordle {
private:
    vector<string> wordList = {
        "tiger", "tapir", "based", "eagle", "flame", "roman", "quirk",
        "olive", "joker", "knife", "drama", "igloo", "gnome", "ocean", "peace",
        "quiet", "river", "okapi", "xebec", "unity", "voice", "shard", "yacht"
    };
    
    string target;
    vector<string> guesses;
    const int MAX_GUESSES = 6;
    const int WORD_LEN = 5;

public:
    Wordle() {
        srand(time(0));
        pickRandomWord();
        guesses.resize(MAX_GUESSES);
    }
    
    void pickRandomWord() {
        int index = rand() % wordList.size();
        target = wordList[index];
    }
    
    bool isValidGuess(const string& guess) {
        if (guess.length() != WORD_LEN) return false;
        for (char c : guess) {
            if (!isalpha(c)) return false;
        }
        string temp = guess;
        for (int i = 0; i < temp.length(); i++) {
            temp[i] = tolower(temp[i]);
        }
        return find(wordList.begin(), wordList.end(), temp) != wordList.end();
    }
    
    string getFeedback(const string& guess) {
        string result = guess;
        string temp_target = target;
        
        for (int i = 0; i < WORD_LEN; i++) {
            if (guess[i] == temp_target[i]) {
                result[i] = 'G';
                temp_target[i] = '#';
            }
        }
        
        for (int i = 0; i < WORD_LEN; i++) {
            if (result[i] != 'G') {
                size_t pos = temp_target.find(guess[i]);
                if (pos != string::npos) {
                    result[i] = 'Y';
                    temp_target[pos] = '#';
                }
            }
        }
        return result;
    }
    
    void printBoard() {
        cout << "\n=== WORDLE ===\n\n";
        
        for (int i = 0; i < MAX_GUESSES; i++) {
            if (!guesses[i].empty()) {
                cout << i+1 << ". ";
                for (char c : guesses[i]) {
                if (c == 'G') cout << "[" << c << "]";     
                else if (c == 'Y') cout << "(" << c << ")"; 
                else cout << c;                            
                }

                cout << endl;
            } else {
                cout << i+1 << ". _____\n";
            }
        }
    }
    
  void play() {
    cout << "Guess the 5-letter word! 6 tries.\n\n";
    
    for (int guess_num = 0; guess_num < MAX_GUESSES; guess_num++) {
        string guess;
        printBoard();
        
        cout << "Guess " << (guess_num + 1) << "/" << MAX_GUESSES << ": ";
        cin >> guess;
        
        if (!isValidGuess(guess)) {
            cout << "Invalid! Not in List.\n";
            continue;  
        }
        
        guesses[guess_num] = getFeedback(guess);
        
        if (guess == target) {
            printBoard();
            cout << "\nYOU WIN!\n";
            return;
        }
    }
    
    printBoard();
    cout << "\nGame Over! Word was: " << target << "\n";
}

    
    void newGame() {
        guesses.clear();
        guesses.resize(MAX_GUESSES);
        pickRandomWord();
    }
};

int main() {
    Wordle game;
    
    while (true) {
        game.newGame();
        game.play();
        
        char again;
        cout << "\nPlay again? (Y/N): ";
        cin >> again;
        if (again != 'y' && again != 'Y') {
            break;
        }
        cout << endl;
    }
    return 0;
}
