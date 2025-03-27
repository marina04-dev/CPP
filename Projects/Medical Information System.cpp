#include <iostream>
#include <string>
using namespace std;

struct Patient {
  long long ID;
  string firstName;
  string lastName;
  int age;
  string bloodGroup;
  char gender;
  Patient* next;
};

class LinkedQueue {
  public:
    LinkedQueue(string name) : head(nullptr), last(nullptr), departmentName(name) {}
    void insertAtEnd();
    void insertAtBeginning();
    void servePatient();
    void listPatients();
    bool search(int id);
    string getDepartmentName() { return departmentName; }
  private:
    Patient* head;
    Patient* last;
    string departmentName;
};

void departmentMenu(LinkedQueue& q); // Function prototype

int main() {
  LinkedQueue departments[] = { {"General Clinic"}, {"Heart Clinic"}, {"Lung Clinic"}, {"Plastic Surgery"} };
  int choice;
  do {
    cout << "\n--- Hospital Management System ---\n";
    for (int i = 0; i < 4; i++) {
      cout<<i + 1<<": "<<departments[i].getDepartmentName()<<"\n";
    }
    cout<<"5: Exit\nEnter choice: ";
    cin>>choice;
    if (choice >= 1 && choice <= 4) {
      departmentMenu(departments[choice - 1]);
    }
  } while (choice != 5);
  cout<<"\nThank you!\n";
  return 0;
}





bool LinkedQueue::search(int id) {
  Patient* temp = head;
  while (temp) {
    if (temp->ID == id) {
      return true;
    }
    temp = temp->next;
  }
  return false;
}

void LinkedQueue::insertAtEnd() {
    Patient* p = new Patient();
    cout<<"Enter Patient's First Name: "; 
    cin>>p->firstName;
    cout<<"Enter Patient's Last Name: "; 
    cin>>p->lastName;
    cout<<"Enter Patient's Blood Group: "; 
    cin>>p->bloodGroup;
    cout<<"Enter Patient's Gender (m/f): "; 
    cin>>p->gender;
    cout<<"Enter Patient's Age: "; 
    cin>>p->age;
    cout<<"Enter Patient's Mobile Number: "; 
    cin>>p->ID;

    if (search(p->ID)) {
      cout<<"\nDuplicate ID, Operation Cancelled.\n";
      delete p;
      return;
    }

    p->next = nullptr;
    if (!head) {
      head = last = p;
    } 
    else {
      last->next = p;
      last = p;
    }
    cout<<"\nPatient Added Successfully!\n";
}

void LinkedQueue::insertAtBeginning() {
    Patient* p = new Patient();
    cout<<"Enter Patient's First Name: "; 
    cin>>p->firstName;
    cout<<"Enter Patient's Last Name: "; 
    cin>>p->lastName;
    cout<<"Enter Patient's Blood Group: "; 
    cin>>p->bloodGroup;
    cout<<"Enter Patient's Gender (m/f): "; 
    cin>>p->gender;
    cout<<"Enter Patient's Age: "; 
    cin>>p->age;
    cout<<"Enter Patient's Mobile Number: "; 
    cin>>p->ID;

    if (search(p->ID)) {
      cout<<"\nDuplicate ID, Operation Cancelled.\n";
      delete p;
      return;
    }

    p->next = head;
    head = p;
    if (!last) {
      last = p;
    }
    cout<<"\nCritical Patient Added Successfully!\n";
}

void LinkedQueue::servePatient() {
  if (!head) {
    cout<<"\nNo Patients in Queue.\n";
    return;
  }
  Patient* temp = head;
  head = head->next;
  cout<<"\nServing Patient: "<<temp->firstName<<" "<<temp->lastName<<"\n";
  delete temp;
}

void LinkedQueue::listPatients() {
  if (!head) {
    cout<<"\nNo Patients in Queue.\n";
    return;
  }
  Patient* temp = head;
  cout<<"\nList of Patients:\n";
  while (temp) {
    cout<<temp->firstName<<" "<<temp->lastName<<" - Age: "<<temp->age<<" - Blood: "<<temp->bloodGroup<<"\n";
    temp = temp->next;
  }
}

void departmentMenu(LinkedQueue& q) {
    int choice;
    do {
      cout<<"\n--- "<<q.getDepartmentName()<<" ---\n";
      cout<<"1. Add Normal Patient\n2. Add Critical Patient\n3. Serve Patient\n4. List Patients\n5. Exit\nEnter choice: ";
      cin >> choice;
      switch (choice) {
        case 1: 
          q.insertAtEnd(); 
          break;
        case 2: 
          q.insertAtBeginning(); 
          break;
        case 3: 
          q.servePatient(); 
          break;
        case 4: 
          q.listPatients(); 
          break;
      }
    } while (choice != 5);
}
