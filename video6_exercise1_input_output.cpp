#include <iostream>
#include <string>

using namespace std;

int main() {
    char name[30], surname[30];
    int age;
    cout<<"Please enter your name: "<<"\n";
    cin>>name;
    cout<<"Please enter your surname: "<<"\n";
    cin>>surname;
    cout<<"Please enter your age: "<<"\n";
    cin>>age;
    
    cout<<surname<<" "<<name<<" "<<age;
    return 0;
}
