#include <iostream>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

struct Number {
    int num1,num2,sum,extraCard;
};

class BaccaratGame {
    private:
        string name;
        int money;
        int totalWins;
        int totalLosses;
        vector<string> history;
    
        void printCard1(int num1,int num2, int num3, int sum) {
            cout<<"=======\n";
            cout<<"|     |\n";
            cout<<"|  " <<sum<<"  |\n";
            cout<<"|     |\n";
            cout<<"=======\n";
            cout<<"First Card "<<num1<<"\n";
            cout<<"Second Card "<<num2<<"\n";
            cout<<"Extra Card "<<num3;
        }
    
        void printCard2(int num1,int num2, int sum) {
            cout<<"=======\n";
            cout<<"|     |\n";
            cout<<"|  "<<sum<<"  |\n";
            cout<<"|     |\n";
            cout<<"=======\n";
            cout<<"This is a natural win 8/9 \n";
            cout<<"First Card "<<num1<<"\n";
            cout<<"Second Card "<<num2;
        }
    
        bool playAgain(char x) {
            if (money > 0) {
                if (x == 'Y' || x == 'y') {
                    return true;
                }
                else if (x == 'N' || x == 'n') {
                    cout<<"THANK YOU FOR PLAYING!";
                    return false;
                }
            }
            else {
                cout<<"Insufficient fund!";
                return false;
            }
        }
    
        int winnerFunction(int bankerCard, int playerCard) {
            cout<<"\n==================================\n";
            if (bankerCard > playerCard) {
                cout<<"\nBANKER WIN, ";
                return 1;
            }
            else if ( bankerCard < playerCard) {
                cout<<"\nPLAYER WIN, ";
                return 2;
            }
            else {
                cout<<"\nDRAW, ";
                return 3;
            }
        }
    
        int declareWinner(int winner, int decision, int bet) {
            if (winner == decision) {
                cout <<"YOU WIN!\n";
                totalWins++;
                return bet;
            }
            if (winner == 3) {
                cout<<"Tie Game!"<<endl;
                return 0;
            }
            else {
                cout<<"YOU LOSE!\n";
                totalLosses++;
                bet *= -1;
                return bet;
            }
        }
    
        void displayStats() {
            cout<<"\n========== GAME STATS ==========\n";
            cout<<"Wins: " << totalWins << "\n";
            cout<<"Losses: " << totalLosses << "\n";
            cout<<"Current Money: PHP " << money << "\n";
            cout<<"========= HISTORY =========\n";
            for (size_t i = 0; i < history.size(); ++i) {
                cout<<i+1<<". "<<history[i]<<"\n";
            }
            cout<<"==============================\n";
        }

    public:
        BaccaratGame();
        void start();
};

int main() {
    BaccaratGame game;
    game.start();
    return 0;
}


BaccaratGame::BaccaratGame() {
    money = 10000;
    totalWins = 0;
    totalLosses = 0;
}

void BaccaratGame::start() {
    srand(time(NULL));
    system ("Color 2F");
    
    cout<<"==============================\n";
    cout<<"To Start, Please Enter your card\n";
    cout<<"Enter your name: ";
    getline(cin, name);
    
    cout<<"\nGood evening, "<<name<<endl;
    cout<<"==============================\n\n";
    cout<<"Welcome To Virtual Baccarat Table\n";
    cout<<"=================================\n";
    
    char play;
    bool logic = true;
    
    do {
        int decision, bet, winner, prize;
        cout<<"Current balance, PHP "<<money<<endl;
        cout<<"1 - Banker \n2 - Player \n";
        cout<<"Choose your bet ";
    
        while (!(cin >> decision) || (decision < 1 || decision > 2)) {
            cin.clear(); cin.ignore(10000, '\n');
            cout<<"\n"<<"Choose your bet ";
            cout<<"\n"<<"1 - Banker \n2 - Player \n";
        }
    
        do {
            cout<<"Place your bet, PHP: ";
            cin>>bet;
        } while (bet > money || bet <= 0);
    
        struct Number banker;
        banker.num1 = rand() % 10 + 1;
        banker.num2 = rand() % 10 + 1;
        banker.sum = (banker.num1 + banker.num2) % 10;
    
        cout<<"\n==============================\n";
        cout<<"      ="<<" Banker'S Card  "<<"=\n";
        cout<<"==============================\n";
    
        if (banker.sum != 9 && banker.sum != 8) {
            banker.extraCard = rand() % 10 + 1;
            banker.sum = (banker.sum + banker.extraCard) % 10;
            printCard1(banker.num1, banker.num2, banker.extraCard, banker.sum);
        }
        else {
            printCard2(banker.num1, banker.num2, banker.sum);
        }
    
        struct Number player;
        player.num1 = rand() % 10 + 1;
        player.num2 = rand() % 10 + 1;
        player.sum = (player.num1 + player.num2) % 10;
    
        cout<<"\n";
        cout<<"==============================\n";
        cout<<"      ="<<" PLAYER'S CARD"<<"  =\n";
        cout<<"==============================\n";
    
        if (player.sum != 9 && player.sum != 8) {
            player.extraCard = rand() % 10 + 1;
            player.sum = (player.sum + player.extraCard) % 10;
            printCard1(player.num1,player.num2,player.extraCard,player.sum);
        }
        else {
            printCard2(player.num1, player.num2, player.sum);
        }

        winner = winnerFunction(banker.sum, player.sum);
        prize = declareWinner(winner, decision, bet);
        cout<<"PHP "<<prize<<endl;
        money += prize;
        cout<<"Current Money, PHP "<<money<<"\n\n";
    
        string result = (winner == decision ? "Win" : (winner == 3 ? "Draw" : "Lose"));
        history.push_back(result);
    
        cout<<"Play Again? Y/N ";
        cin>>play;
        logic = playAgain(play);

    } while (logic != false);

    displayStats();
}
