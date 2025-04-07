#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Room {
    public:
        int roomNumber;
        string name;
        string address;
        string phone;
        int days;
        float fare;
        Room(int r,string n,string a,string p,int d,float f)
            :roomNumber(r),name(n),address(a),phone(p),days(d),fare(f) {}
        void display() const;
};

class Hotel {
    public:
        void checkIn();
        void checkOut();
        void searchRoom();
        void viewRooms() const;
    private:
        vector<Room> rooms;
        Room* findRoom(int roomNumber) {
            for(auto& room:rooms) {
                if(room.roomNumber==roomNumber)
                    return &room;
            }
            return nullptr;
        }
};

int main() {
    Hotel hotel;
    int choice;

    do {
        cout<<"\n--- Hotel Management System ---\n";
        cout<<"1. Check In\n";
        cout<<"2. Check Out\n";
        cout<<"3. Search Room\n";
        cout<<"4. View All Rooms\n";
        cout<<"0. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
            case 1:
                hotel.checkIn();
                break;
            case 2:
                hotel.checkOut();
                break;
            case 3:
                hotel.searchRoom();
                break;
            case 4:
                hotel.viewRooms();
                break;
            case 0:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid choice.\n";
        }
    } while(choice!=5);

    return 0;
}


void Room::display()const {
    cout<<"\nRoom Number: "<<roomNumber;
    cout<<"\nCustomer's Name: "<<name;
    cout<<"\nCustomer's Address: "<<address;
    cout<<"\nCustomer's Phone: "<<phone;
    cout<<"\nDays: "<<days;
    cout<<"\nTotal Fare: $"<<fare*days<<endl;
}

void Hotel::checkIn() {
    int roomNumber;
    cout<<"Enter Room Number: ";
    cin>>roomNumber;

    if(findRoom(roomNumber)) {
        cout<<"Room is already booked.\n";
        return;
    }

    string name,address,phone;
    int days;
    float fare;

    cin.ignore(); 
    cout<<"Enter Customer's Name: ";
    getline(cin,name);
    cout<<"Enter Customer's Address: ";
    getline(cin,address);
    cout<<"Enter Customer's Phone: ";
    getline(cin,phone);
    cout<<"Enter Number of Days: ";
    cin>>days;
    cout<<"Enter Fare per Day: ";
    cin>>fare;

    rooms.emplace_back(roomNumber,name,address,phone,days,fare);
    cout<<"Room Booked Successfully.\n";
}


void Hotel::checkOut() {
    int roomNumber;
    cout<<"Enter Room Number to Check Out: ";
    cin>>roomNumber;

    for(auto it=rooms.begin();it!=rooms.end();++it) {
        if(it->roomNumber==roomNumber) {
            cout<<"Customer "<<it->name<<" has been checked out.\n";
            rooms.erase(it);
            return;
        }
    }

    cout<<"Room not found.\n";
}

void Hotel::searchRoom() {
    int roomNumber;
    cout<<"Enter Room Number to Search: ";
    cin>>roomNumber;

    Room* room=findRoom(roomNumber);
    if(room) {
        room->display();
    } else {
        cout<<"Room not found.\n";
    }
}

void Hotel::viewRooms()const {
    if(rooms.empty()) {
        cout<<"No rooms booked.\n";
        return;
    }
    for(const auto& room:rooms) {
        room.display();
    }
}

