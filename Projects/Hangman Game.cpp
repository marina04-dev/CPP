#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class Hangman {
    public:
        Hangman(const vector<string>& wordList);
        void display();
        bool isGameOver();
        void guess(char c);
        void gameResult()
    private:
        string word;
        string guessedWord;
        vector<char> incorrectGuesses;
        int maxTries;
        int tries;
    
        vector<string> hangmanStages{
            "  _______\n"
            "  |     |\n"
            "  |     O\n"
            "  |    /|\\\n"
            "  |    / \\\n"
            "  |\n"
            "__|__",
    
            "  _______\n"
            "  |     |\n"
            "  |     O\n"
            "  |    /|\\\n"
            "  |    / \n"
            "  |\n"
            "__|__",
    
            "  _______\n"
            "  |     |\n"
            "  |     O\n"
            "  |    /|\\\n"
            "  |     \n"
            "  |\n"
            "__|__",
    
            "  _______\n"
            "  |     |\n"
            "  |     O\n"
            "  |    /|\n"
            "  |     \n"
            "  |\n"
            "__|__",
    
            "  _______\n"
            "  |     |\n"
            "  |     O\n"
            "  |     |\n"
            "  |     \n"
            "  |\n"
            "__|__",
    
            "  _______\n"
            "  |     |\n"
            "  |     O\n"
            "  |     \n"
            "  |     \n"
            "  |\n"
            "__|__",
    
            "  _______\n"
            "  |     |\n"
            "  |     \n"
            "  |     \n"
            "  |     \n"
            "  |\n"
            "__|__"
        };
};

int main() {
    vector<string> wordList{"computer","hangman","keyboard","cplusplus","algorithm","function","variable"};
    Hangman game(wordList);
    char guessLetter;

    cout<<"===== Welcome to Hangman Game! =====\n";

    while(!game.isGameOver()) {
        game.display();
        cout<<"Enter your guess: ";
        cin>>guessLetter;
        game.guess(guessLetter);
    }

    game.display();
    game.gameResult();

    return 0;
}

Hangman::Hangman(const vector<string>& wordList) {
    srand(time(0));
    word = wordList[rand()%wordList.size()];
    guessedWord = string(word.length(), '_');
    maxTries = hangmanStages.size()-1;
    tries = 0;
}

void Hangman::display() {
    cout<<hangmanStages[maxTries-tries]<<endl;
    cout<<"\nWord: "<<guessedWord<<endl;
    cout<<"Incorrect guesses: ";
    for(char c: incorrectGuesses)
        cout<<c<<" ";
    cout<<"\nTries left: "<<maxTries-tries<<endl;
    cout<<"-----------------------------\n";
}

bool Hangman::isGameOver() {
    return guessedWord==word||tries>=maxTries;
}

void Hangman::guess(char c) {
    c=tolower(c);
    if(find(guessedWord.begin(),guessedWord.end(),c)!=guessedWord.end()||
       find(incorrectGuesses.begin(),incorrectGuesses.end(),c)!=incorrectGuesses.end()) {
        cout<<"You already guessed '"<<c<<"'. Try another letter.\n";
        return;
    }

    bool correct=false;
    for(size_t i=0;i<word.length();++i) {
        if(word[i]==c) {
            guessedWord[i]=c;
            correct=true;
        }
    }

    if(correct)
        cout<<"Correct guess!\n";
    else {
        cout<<"Wrong guess.\n";
        incorrectGuesses.push_back(c);
        ++tries;
    }
}

void Hangman::gameResult() {
    if(guessedWord==word)
        cout<<"\nCongratulations! You guessed the word: "<<word<<endl;
    else {
        cout<<hangmanStages[0]<<endl;
        cout<<"\nGame Over! The correct word was: "<<word<<endl;
    }
}
