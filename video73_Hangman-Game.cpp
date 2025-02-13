#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#define SIZE 10

int main() {
    
    // Game Initialization
    srand(time(0));
    string array[SIZE] = {"banana","apple","orange","skateboard","basketball","swimming","sun","face","bottle","family"};
    string hidden = array[rand()%10];
    string game(hidden.length(),'-');
    
    // Guesses
    string bad_guesses;
    string right_guesses;
    
    // Max Wrong Guesses
    int MAX=10;
    char letter;
    int wrong_guesses = 0;
    
    // Game Loop
    while (true) {
        cout<<endl<<"Hangman Game"<<endl<<"Hidden Word: "<<game<<endl;
        cout<<"Enter a letter: "<<endl;
        cin>>letter;
        if (bad_guesses.find(letter,0)!=bad_guesses.npos) {
            cout<<"The letter has already been entered!Try Another!"<<endl;
            continue;
        }
        if (right_guesses.find(letter,0)!=right_guesses.npos) {
            cout<<"The letter has already been entered!Try Another!"<<endl;
            continue;
        }
        if (hidden.find(letter,0)!=hidden.npos) { // letter found in hidden
        int pos;
            cout<<"Letter was found in hidden word!"<<endl;
            pos = hidden.find(letter);
            while (pos<hidden.length()) {
                game[pos]=hidden[pos];
                pos = hidden.find(letter,pos+1);
            }
            right_guesses.push_back(letter);
            
            // Game Over - Word Found
            if (game.find('-')==hidden.npos) {
                cout<<"Congratulations!!!"<<endl<<"You Win!"<<endl<<game<<endl;
                break;
            }
        }
        else { // letter was not found in hidden
            cout<<"The letter you chose does not exist in hidden word"<<endl;
            wrong_guesses ++;
            cout<<"Remained guesses: "<<MAX-wrong_guesses<<endl;
            bad_guesses.push_back(letter);
            
            // Game Over - Word Was Not Found - Ran Out Of Guesses
            if (wrong_guesses==MAX) {
                cout<<"Sorry!"<<endl<<"You Lost!!!"<<endl;
                cout<<"The hidden word was: "<<hidden<<endl;
                break;
            }
        }
    }
    return 0;
}
