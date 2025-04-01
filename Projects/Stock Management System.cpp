#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Stock {
    public:
        Stock(string n, float p, int q) : name(n), price(p), quantity(q) {}
        void show();
        bool checkName(string nm);
        void withdraw(int qty);
        void refill(int qty);
    private:
        string name;
        float price;
        int quantity;
};

vector<Stock> inventory;
void displayStock();
void addNewProduct();
void purchaseProduct();
void refillProduct();
void removeProduct();

int main() {
    int choice;
    while (true) {
        cout<<"\n========= STOCK MANAGEMENT MENU =========";
        cout<<"\n1. Add Product";
        cout<<"\n2. Display Stock";
        cout<<"\n3. Purchase Product";
        cout<<"\n4. Refill Product";
        cout<<"\n5. Remove Product";
        cout<<"\n6. Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch (choice) {
            case 1: 
                addNewProduct(); 
                break;
            case 2: 
                displayStock(); 
                break;
            case 3: 
                purchaseProduct(); 
                break;
            case 4: 
                refillProduct(); 
                break;
            case 5: 
                removeProduct(); 
                break;
            case 6: 
                cout<<"Exiting..."; 
                return 0;
            default: 
                cout<<"Invalid Input!\n";
        }
    }
}


void Stock::show() {
    cout<<"\n"<< name << "\t\t"<<quantity<<"\t\t"<<price;
}

bool Stock::checkName(string nm) {
    return name == nm;
}

void Stock::withdraw(int qty) {
    if (quantity >= qty) {
        quantity -= qty;
        cout<<"\nStock updated. Total price: "<<price * qty;
    } 
    else {
        cout<<"\nInsufficient stock";
    }
}
        
void Stock::refill(int qty) {
    quantity += qty;
    cout<<"\nStock updated.";
}


// Stock Management Functions Not Stock Class
void displayStock() {
    cout<<"\n================== STOCK ITEMS ==================";
    cout<<"\nName\t\tQuantity\t\tPrice";
    for (Stock &item : inventory) {
        item.show();
    }
    cout<<"\n===============================================\n";
}

void addNewProduct() {
    string name;
    float price;
    int quantity;
    cout<<"\nEnter product name: ";
    cin>>name;
    cout<<"Enter price: ";
    cin>>price;
    cout<<"Enter quantity: ";
    cin>>quantity;
    inventory.push_back(Stock(name, price, quantity));
    cout<<"Product added successfully!\n";
}

void purchaseProduct() {
    string name;
    int quantity;
    cout<<"\nEnter product name to purchase: ";
    cin>>name;
    cout<<"Enter quantity: ";
    cin>>quantity;
    for (Stock &item : inventory) {
        if (item.checkName(name)) {
            item.withdraw(quantity);
            return;
        }
    }
    cout<<"Product not found!\n";
}

void refillProduct() {
    string name;
    int quantity;
    cout<<"\nEnter product name to refill: ";
    cin>>name;
    cout<<"Enter quantity: ";
    cin>>quantity;
    for (Stock &item : inventory) {
        if (item.checkName(name)) {
            item.refill(quantity);
            return;
        }
    }
    cout<<"Product not found!\n";
}

void removeProduct() {
    string name;
    cout<<"\nEnter product name to remove: ";
    cin>>name;
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->checkName(name)) {
            inventory.erase(it);
            cout<<"Product removed successfully!\n";
            return;
        }
    }
    cout<<"Product not found!\n";
}

