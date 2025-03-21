#include <iostream>
#include <string>
using namespace std;

class Movie {
    public:
        Movie();
        Movie(string in_name, double in_imdbScore, int in_premiereDate);
        virtual double score();
        friend ostream &operator<<(ostream &left, Movie &right);
    protected:
        string name;
        double imdbScore;
        int premiereDate;
};

class Thriller: virtual public Movie {
    public:
        Thriller(double in_fear_factor);
        Thriller(string in_name, double in_imdbScore, int in_premiereDate, double in_fear_factor);
        virtual double score();
        friend ostream &operator<<(ostream &left, Thriller &right);
    protected:
        double fear_factor;
};

class Comedy: virtual public Movie {
    public:
        Comedy(double in_fun_factor);
        Comedy(string in_name, double in_imdbScore, int in_premiereDate, double in_fun_factor);
        virtual double score();
        friend ostream &operator<<(ostream &left, Comedy &right);
    protected:
        double fun_factor;
};

class ComedyThriller: public Thriller, public Comedy {
    public:
        ComedyThriller(string in_name, double in_imdbScore, int in_premiereDate, double in_fear_factor, double in_fun_factor);
        double score();
        friend ostream &operator<<(ostream &left, ComedyThriller &right);
};

int main() {
    Thriller it("IT Chapter 2", 6.8, 10, 8.0);
    Thriller us("Us",6.9, 30, 7.0);
    Thriller silOfLambs("Silence of the Lambs", 8.6, 1540, 9.0);
    Comedy jexi("Jexi", 6.6, 4, 3.0);
    ComedyThriller adamsFamily("Adams Family", 5.9, 5, 3.0, 4.0);
    ComedyThriller shaunDead("Shaun Of The Dead", 7.9, 825, 4.0, 9.0);
    cout<<it.score()<<endl;
    cout<<us.score()<<endl;
    cout<<silOfLambs.score()<<endl;
    cout<<jexi.score();
    cout<<adamsFamily.score();
    cout<<shaunDead.score()<<endl;
    cout<<it;
    cout<<us;
    cout<<silOfLambs;
    cout<<jexi;
    cout<<adamsFamily;
    cout<<shaunDead;
    return 0;
}

Movie::Movie() {}

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

Thriller::Thriller(double in_fear_factor) {
    fear_factor = in_fear_factor;
}

Thriller::Thriller(string in_name, double in_imdbScore, int in_premiereDate, double in_fear_factor): Movie(in_name, in_imdbScore, in_premiereDate) {
    fear_factor = in_fear_factor;
}


double Thriller::score() {
    return fear_factor*Movie::score();
}

ostream &operator<<(ostream &left, Thriller &right) {
    left<<"Movie's Name: "<<right.name<<endl<<"Movie's Score: "<<right.imdbScore<<endl<<"Weeks From Premiere: "<<right.premiereDate<<endl<<"Movie's Fear Factor: "<<right.fear_factor<<endl;
    return left;
}

Comedy::Comedy(double in_fun_factor) {
    fun_factor = in_fun_factor;
}

Comedy::Comedy(string in_name, double in_imdbScore, int in_premiereDate, double in_fun_factor): Movie(in_name, in_imdbScore, in_premiereDate) {
    fun_factor = in_fun_factor;
}

double Comedy::score() {
    return fun_factor*(Movie::score());
}

ostream &operator<<(ostream &left, Comedy &right) {
    left<<"Movie's Name: "<<right.name<<endl<<"Movie's Score: "<<right.imdbScore<<endl<<"Weeks From Premiere: "<<right.premiereDate<<endl<<"Movie's Fun Factor: "<<right.fun_factor<<endl;
    return left;
}

ComedyThriller::ComedyThriller(string in_name, double in_imdbScore, int in_premiereDate, double in_fear_factor, double in_fun_factor): Movie(in_name, in_imdbScore, in_premiereDate), Thriller(in_fear_factor), Comedy(in_fun_factor) { }

double ComedyThriller::score() {
    return ((fun_factor+fear_factor)/2)*(Movie::score());
}

ostream &operator<<(ostream &left, ComedyThriller &right) {
    left<<"Movie's Name: "<<right.name<<endl<<"Movie's Score: "<<right.imdbScore<<endl<<"Weeks From Premiere: "<<right.premiereDate<<endl<<"Movie's Fear Factor: "<<right.fear_factor<<endl<<"Movie's Fun Factor: "<<right.fun_factor;
    return left;
}
