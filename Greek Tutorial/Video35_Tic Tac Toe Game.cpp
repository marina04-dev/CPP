#include <iostream>
using namespace std;

#define N 3 

class TicTacToe {
    public:
        TicTacToe();
        bool play(int x, int y);
        char check_winner();
        void print();
        void next_player();
        char get_player() const;
    private:
        char array[N][N];     
        char player;
};


int main() {
    TicTacToe t;
    int x,y, step=0;
    while (true) {
        cout<<"ARRAY: "<<endl;
        t.print();
        cout<<"Player "<<t.get_player()<<" plays!"<<endl;
        
        cout<<endl<<"Enter the x dimension: ";
        cin>>x;
        cout<<endl<<"Enter the y dimension: ";
        cin>>y;
        
        if (!t.play(x,y)) {
            cout<<"Wrong Move! Try Again!";
            continue;
        }
        else {
            step++;
        }
        
        if (t.check_winner()!='-') {
            t.print();
            cout<<"Winner is: "<<t.check_winner();
            break;
        }
        else if (step==9) {
            t.print();
            cout<<"Draw"<<endl;
            break;
        }
        
        t.next_player();
        
    }
    return 0;
}

TicTacToe::TicTacToe() {
    int i,j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            array[i][j]='-';
        }
    }
    player='X';
}

bool TicTacToe::play(int x, int y) {
    if (array[x][y]=='-') {
        array[x][y]=player;
        return true;
    }
    else {
        return false;
    }
}

char TicTacToe::check_winner() {
    int i,j;
    /* lines check */
    for (i=0; i<N; i++) {
        if (array[i][0]==array[i][1] && array[i][1]==array[i][2]) {
            return array[i][0];
        }
    }
    
    /* columns check */
    for (j=0; j<N; j++) {
        if (array[0][j]==array[1][j] && array[1][j]==array[2][j]) {
            return array[0][j];
        }
    }
    
    /* diagonials checking */
    if (array[0][0]==array[1][1] && array[1][1]==array[2][2]) {
        return array[0][0];
    }
    if (array[0][2]==array[1][1] && array[1][1]==array[2][0]) {
        return array[0][2];
    }
    
    /* no winner */
    return '-';
}

void TicTacToe::print() {
    int i,j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            cout<<array[i][j];
        }
        cout<<endl;
    }
}

void TicTacToe::next_player() {
    if (player=='X') {
        player='O';
    }
    else {
        player='X';
    }
}

char TicTacToe::get_player() const {
    return player;
}
