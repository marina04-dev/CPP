#include <iostream>
#include <cstring>
using namespace std;

class STRING {
    public:
        STRING();
        STRING(char *in_str);
        STRING(const STRING &ob);
        ~STRING();
        int get_length() const;
        char *get_str() const;
        void set_str(char *in_str);
        STRING &operator= (STRING &right);
        char &operator[] (int i);
        bool operator<(STRING &right);
        bool operator>(STRING &right);
        bool operator==(STRING &right);
        friend ostream &operator<<(ostream &left, const STRING &ob);
        friend istream &operator>>(istream &left, STRING &ob);
    private:
        int length;
        char *str;
};

ostream &operator<<(ostream &left, const STRING &ob);
istream &operator>>(istream &left, STRING &ob);

int main() {
    char s[80]="This is a string";
    STRING s1(s);
    cout<<"Enter a string: "<<endl;
    cin>>s1;
    cout<<"New string: "<<endl;
    cout<<s1;
    return 0;
}

STRING::STRING() {
    length=0;
    str=new char [1];
    str[0]='\0';
}

STRING::STRING(char *in_str) {
    length=strlen(in_str);
    str = new char [length+1];
    if (!str) cout<<"Error Allocating Memory!";
    strcpy(str, in_str);
}

STRING::STRING(const STRING &ob) {
    length=ob.get_length();
    str=new char [length+1];
    if (!str) cout<<"Error Allocating Memory!";
    strcpy(str, ob.get_str());
}

STRING::~STRING() {
    delete [] str;
}

int STRING::get_length() const {
    return length;
}

char *STRING::get_str() const {
    return str;
}

void STRING::set_str(char *in_str) {
    if (str!=NULL) {
        delete str;   
    }
    length = strlen(in_str);
    str=new char [length+1];
    if (!str) cout<<"Error Allocating Memory!";
    strcpy(str, in_str);
}

STRING &STRING::operator= (STRING &right)
{
    if (this==&right) return *this; 
    length=right.length;
    delete [] str;
    str=new char [length+1];
    if (!str) cout<<"Error Allocating Memory!";
    strcpy(str, right.str);
    return *this;
}

char &STRING::operator[](int i) {
    if (i>=0 && i<=length) {
        return str[i];
    }
    else {
        cout<<"Index Out Of Bounds!";
    }
}

bool STRING::operator<(STRING &right) {
    if (strcmp(str, right.str)<0) {
        return true;
    }
    else {
        return false;
    }
}

bool STRING::operator>(STRING &right) {
    if (strcmp(str, right.str)>0) {
        return true;
    }
    else {
        return false;
    }
}

bool STRING::operator==(STRING &right) {
    if (strcmp(str, right.str)==0) {
        return true;
    }
    else {
        return false;
    }
}

ostream &operator<<(ostream &left, const STRING &ob) {
    left<<ob.str;
    return left;
}

istream &operator>>(istream &left, STRING &ob) {
    char in_str[80];
    left>>in_str;
    if (ob.str!=NULL) {
        delete [] ob.str;
    }
    ob.str = new char [strlen(in_str)+1];
    if (ob.str==NULL) {
        cout<<"Error Allocating Memory!";
    }
    ob.length=strlen(in_str);
    strcpy(ob.str, in_str);
    return left;
}
