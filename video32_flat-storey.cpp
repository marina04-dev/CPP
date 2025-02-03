#include <iostream>
using namespace std;

class flat {
    public:
        flat();
        ~flat();
        void set_people(int in_people);
        int get_people() const;
    private:
        int people;
};

class storey {
    public:
        storey();
        ~storey();
        void set_people(int in_flat, int in_people);
        int get_people() const;
    private:
        flat flats[2];
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}

flat::flat() {
    people = 0;
    cout<<"Constructing flat..."<<endl;
}

flat::~flat() {
    cout<<"Destructing flat..."<<endl;
}

void flat::set_people(int in_people) {
    people = in_people;
}

int flat::get_people() const {
    return people;
}


storey::storey() {
    cout<<"Constructing storey..."<<endl;
}

storey::~storey() {
    cout<<"Destructing storey..."<<endl;
}

void storey::set_people(int in_flat, int in_people) {
    flats[in_flat].set_people(in_people);
}

int storey::get_people() const {
    return flats[0].get_people()+flats[1].get_people();
}
