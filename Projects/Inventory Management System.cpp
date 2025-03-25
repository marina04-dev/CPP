#include <iostream>
#include <map>
#include <string>

using namespace std;

class Item {
    public:
        Item(int id, string name, int quantity, double price);
        int id() const;
        string name() const;
        int quantity() const;
        double price() const;
        void setQuantity(int quantity);
    private:
        int id_;
        string name_;
        int quantity_;
        double price_;
};

class Inventory {
    public:
        void addItem(const Item& item);
        void removeItem(int id);
        void updateQuantity(int id, int quantity);
        void printInventory();
    private:
        map<int, Item> items_;
};


int main() {
    Inventory inventory;
    int choice, quantity, id;
    string itemName;
    double price;
    char op;

    do {
        cout<<"\n\t------------------------------------------"<<endl;
        cout<<"\tWelcome To The Inventory Managament System"<<endl;
        cout<<"\t------------------------------------------"<<endl;
        cout<<"1. Add an item"<<endl;
        cout<<"2. Remove an item"<<endl;  
        cout<<"3. Update item quantity"<<endl;  
        cout<<"4. View inventory"<<endl;  
        cout<<"0. Exit"<<endl;
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"Enter ID: "; 
                cin>>id;
                cout<<"Enter name: "; 
                cin>>itemName;
                cout<<"Enter price: "; 
                cin>>price;
                cout<<"Enter quantity: "; 
                cin>>quantity;
                inventory.addItem(Item(id, itemName, quantity, price));
                cout<<"Item added!\n"; 
                break;
            case 2:
                cout<<"Enter ID to remove: "; 
                cin>>id;
                inventory.removeItem(id);
                cout<<"Item removed!\n"; 
                break;
            case 3:
                cout<<"Enter ID: "; 
                cin>>id;
                cout<<"Enter new quantity: "; 
                cin>>quantity;
                inventory.updateQuantity(id, quantity);
                break;
            case 4:
                inventory.printInventory(); 
                break;
            case 0:
                cout<<"Exit\n"; 
                return 0;
            default:
                cout<<"Invalid choice. Try again.\n";
        }
        cout<<"\nDo you want to proceed to another action (y/n)? ";
        cin>>op;
    } while(op=='y' || op=='Y');
}

// Item Class Methods Implementation
Item::Item(int id, string name, int quantity, double price) : id_(id), name_(name), quantity_(quantity), price_(price) {}


int Item::id() const { 
    return id_; 
}

string Item::name() const { 
    return name_; 
}

int Item::quantity() const { 
    return quantity_; 
}

double Item::price() const { 
    return price_; 
}

void Item::setQuantity(int quantity) { 
    quantity_ = quantity; 
}

// Inventory Methods Implementation
void Inventory::addItem(const Item& item) {
    items_[item.id()] = item; 
}


void Inventory::removeItem(int id) { 
    items_.erase(id); 
}

void Inventory::updateQuantity(int id, int quantity) {
    if (items_.find(id) != items_.end()) {
        items_[id].setQuantity(quantity);
        cout<<"Quantity updated!\n";
    } else {
        cout<<"Item not found.\n";
    }
}


void Inventory::printInventory() {
    if (items_.empty()) { cout << "Inventory is empty.\n"; return; }
    for (const auto& item : items_) 
        cout << "ID: " << item.second.id() << ", Name: " << item.second.name() 
             << ", Quantity: " << item.second.quantity() << ", Price: " << item.second.price() << endl;
}
