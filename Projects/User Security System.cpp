#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void registerUser() {
  string name, password, age;
  cout<<"\tRegister Form\n";
  cout<<"Please Enter Username: ";
  cin>>name;
  cout<<"Please Enter Password: ";
  cin>>password;
  cout<<"Please Enter Your Age: ";
  cin>>age;

  ofstream file("file.txt");
  if(file.is_open()) {
    file<<name<<"\n"<<password<<"\n"<<age;
    file.close();
    cout<<"Registration Completed Successfully!\n";
  } else {
    cout<<"Unable To Open File For Writing.\n";
  }
}

bool loadCredentials(string& storedUser, string& storedPass, string& storedAge) {
  ifstream file("file.txt");
  if(file.is_open()) {
    getline(file, storedUser);
    getline(file, storedPass);
    getline(file, storedAge);
    file.close();
    return true;
  }
  return false;
}

void loginUser() {
  string inputUser, inputPass, storedUser, storedPass, storedAge;
  cout<<"\tLogin Form\n";
  cout<<"Please Enter Username: ";
  cin>>inputUser;
  cout<<"Please Enter Password: ";
  cin>>inputPass;

  if(loadCredentials(storedUser, storedPass, storedAge)) {
    if(inputUser==storedUser && inputPass==storedPass) {
      cout<<"Login Completed Successfully!\n";
      cout<<"\n\tDetails:\n";
      cout<<"Username: "<<storedUser<<endl;
      cout<<"Password: "<<storedPass<<endl;
      cout<<"Age: "<<storedAge<<endl;
    } else {
      cout<<"\nIncorrect Credentials!\n";
    }
  } else {
    cout<<"No Registered User Found. Please Register First.\n";
  }
}

void changePassword() {
  string oldPass, newPass1, newPass2;
  string storedUser, storedPass, storedAge;

  cout<<"\tChange Password Form\n";
  if(!loadCredentials(storedUser, storedPass, storedAge)) {
    cout<<"No User Found. Please Register First.\n";
    return;
  }

  cout<<"Please Enter The Old Password: ";
  cin>>oldPass;

  if(oldPass==storedPass) {
    cout<<"Please Enter New Password: ";
    cin>>newPass1;
    cout<<"Please Enter New Password Again: ";
    cin>>newPass2;

    if(newPass1==newPass2) {
      ofstream file("file.txt");
      if(file.is_open()) {
        file<<storedUser<<"\n"<<newPass1<<"\n"<<storedAge;
        file.close();
        cout<<"Password Changed Successfully!\n";
      } else {
        cout<<"Unable To Open File To Save New Password.\n";
      }
    } else {
      cout<<"Passwords Do Not Match. Try Again.\n";
    }
  } else {
    cout<<"Incorrect Old Password!\n";
  }
}

int main() {
  int choice;

  do {
    cout<<"\n\tSecurity System Menu\n";
    cout<<"___________________________________\n";
    cout<<"1 - Register\n";
    cout<<"2 - Login\n";
    cout<<"3 - Change Password\n";
    cout<<"0 - Exit\n";
    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice) {
      case 1:
        registerUser();
        break;
      case 2:
        loginUser();
        break;
      case 3:
        changePassword();
        break;
      case 0:
        cout<<"Thanks For Using Our Security System!\n";
        cout<<"\tExit Of The Program...\n";
        break;
      default:
        cout<<"Wrong Input! Select From The Given Numbers Please!\n";
    }
  } while(choice!=0);

  return 0;
}
