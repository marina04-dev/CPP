#include <iostream>
#include <string>
using namespace std;

class Movie {
    public:
        Movie(string in_name, double in_imdbScore, int in_premiereDate);
        double score();
        friend ostream &operator<<(ostream &left, Movie &right);
    protected:
        string name;
        double imdbScore;
        int premiereDate;
};

class Thriller: public Movie {
    public:
        Thriller(string in_name, double in_imdbScore, int in_premiereDate, double in_fear_factor);
        double score();
        friend ostream &operator<<(ostream &left, Thriller &right);
    private:
        double fear_factor;
};

int main() {
    Movie m("Roses", 7.7, 3);
    Thriller t("Billie Jean", 9, 2, 3);
    cout<<m.score()<<endl;
    cout<<t.score()<<endl;
    cout<<m;
    cout<<t;
    return 0;
}

Movie::Movie(string in_name, double in_imdbScore, int in_premiereDate) {
    name = in_name;
    imdbScore = in_imdbScore;
    premiereDate = in_premiereDate;
}

double Movie::score() {
    return imdbScore/(0.5*premiereDate);
}

ostream &operator<<(ostream &left, Movie &right) {
    left<<"Movie's Name: "<<right.name<<endl<<"Movie's Score: "<<right.imdbScore<<endl<<"Weeks From Premiere: "<<right.premiereDate;
    return left;
}

Thriller::Thriller(string in_name, double in_imdbScore, int in_premiereDate, double in_fear_factor): Movie(in_name, in_imdbScore, in_premiereDate) {
    fear_factor = in_fear_factor;
}

double Thriller::score() {
    return fear_factor*imdbScore;
}

ostream &operator<<(ostream &left, Thriller &right) {
    left<<"Movie's Name: "<<right.name<<endl<<"Movie's Score: "<<right.imdbScore<<endl<<"Weeks From Premiere: "<<right.premiereDate<<endl<<"Movie's Fear Factor: "<<right.fear_factor;
    return left;
}
