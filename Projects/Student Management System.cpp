#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    Student(int in_rollno, int in_age, string in_name);
    void set_rollno(int in_rollno);
    int get_rollno() const;
    void set_age(int in_age);
    int get_age() const;
    void set_name(string in_name);
    string get_name() const;
    void display_student() const;  // Προσθήκη const
private:
    int rollno, age;
    string name;
};

void add_student(vector<Student> &students);
void display_allStudents(const vector<Student> &students);
void search_student(const vector<Student> &students);
void student_update(vector<Student> &students);
void delete_student(vector<Student> &students);

int main() {
    vector<Student> students;
    char choice;
    students.push_back(Student(1, 20, "Ali"));

    do {
        int op;
        cout<<"\t------------------------"<<endl;
        cout<<"\tStudent Management System"<<endl;
        cout<<"\t------------------------"<<endl;
        cout<<"1. Add New Student"<<endl;
        cout<<"2. Display All Students"<<endl;
        cout<<"3. Search Student"<<endl;
        cout<<"4. Update Student"<<endl;
        cout<<"5. Delete Student"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>op;

        switch (op) {
            case 1:
                add_student(students);
                break;
            case 2:
                display_allStudents(students);
                break;
            case 3:
                search_student(students);
                break;
            case 4:
                student_update(students);
                break;
            case 5:
                delete_student(students);
                break;
            case 0:
                cout<<"Thanks For Using Student Management System!"<<endl;
                break;
            default:
                cout<<"Invalid Input"<<endl;
        }
        cout<<"\nDo you want to proceed to another action (y/n)? ";
        cin>>choice;
    } while (choice == 'y' || choice == 'Y');
}

Student::Student(int in_rollno, int in_age, string in_name) {
    rollno = in_rollno;
    age = in_age;
    name = in_name;
}

void Student::set_rollno(int in_rollno) {
    rollno = in_rollno;
}

int Student::get_rollno() const {
    return rollno;
}

void Student::set_age(int in_age) {
    age = in_age;
}

int Student::get_age() const {
    return age;
}

void Student::set_name(string in_name) {
    name = in_name;
}

string Student::get_name() const {
    return name;
}

void Student::display_student() const {
    cout<<"Student's Roll Number: "<<rollno<<endl;
    cout<<"Student's Age: "<<age<<endl;
    cout<<"Student's Name: "<<name<<endl;
}

// function to add student
void add_student(vector<Student> &students) {
    int rollno, age;
    string name;
    cout<<"Enter Roll Number: ";
    cin>>rollno;

    // check if student already exists
    for (const auto &student : students) {
        if (student.get_rollno() == rollno) {
            cout<<"Student Already Exists..."<<endl;
            return; // Σταματά την εισαγωγή αν υπάρχει ήδη
        }
    }

    cout<<"Enter Student's Age: ";
    cin>>age;
    cout<<"Enter Student's Name: ";
    cin.ignore();
    getline(cin, name);
    
    students.emplace_back(rollno, age, name);
    cout<<"\nStudent Added Successfully!"<<endl;
}

// function to display all students
void display_allStudents(const vector<Student> &students) {
    if (students.empty()) {
        cout<<"Error Displaying Students! Empty List Of Students"<<endl;
        return;
    }
    for (const auto &student : students) {
        student.display_student();
        cout<<endl;
    }
}

// function to search student 
void search_student(const vector<Student> &students) {
    int rollno;
    bool found = false;

    cout<<"Enter Roll Number: ";
    cin>>rollno;

    for (const auto &student : students) {
        if (student.get_rollno() == rollno) {
            cout<<"Student With Roll Number "<<rollno<<" Found"<<endl;
            student.display_student();
            found = true;
            break;
        }
    }

    if (!found) {
        cout<<"Student Not Found!"<<endl;
    }
}

// function to update student record 
void student_update(vector<Student> &students) {
    int in_rollno, choice;
    bool found = false;
    
    cout<<"Enter Roll Number To Update Record: ";
    cin>>in_rollno;
    
    for (auto &student : students) {
        if (student.get_rollno() == in_rollno) {
            found = true;
            cout<<"Student Found"<<endl;
            cout<<"1. Update Roll Number"<<endl;
            cout<<"2. Update Age"<<endl;
            cout<<"3. Update Name"<<endl;
            cout<<"Enter Your Choice: ";
            cin>>choice;

            string nm;
            switch (choice) {
                case 1: {
                    int rno;
                    cout<<"Enter New Roll Number: ";
                    cin>>rno;
                    student.set_rollno(rno);
                    break;
                }
                case 2: {
                    int in_age;
                    cout<<"Enter New Age: ";
                    cin>>in_age;
                    student.set_age(in_age);
                    break;
                }
                case 3:
                    cout<<"Enter New Name: ";
                    cin.ignore();
                    getline(cin, nm);
                    student.set_name(nm);
                    break;
                default:
                    cout<<"Invalid Input!"<<endl;
            }
            cout<<"Student Record Updated Successfully!"<<endl;
            return;
        }
    }

    if (!found) {
        cout<<"Record Not Found!"<<endl;
    }
}

// function to delete student 
void delete_student(vector<Student> &students) {
    int in_rollno;
    cout<<"Enter Roll Number to Delete: ";
    cin>>in_rollno;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->get_rollno() == in_rollno) {
            students.erase(it);
            cout<<"Student Removed Successfully"<<endl;
            return;
        }
    }
    cout<<"Student Not Found!"<<endl;
}
