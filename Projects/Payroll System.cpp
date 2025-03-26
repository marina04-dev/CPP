#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
    public:
        Employee(string in_name, int in_id, double in_hourlyRate, double in_hoursWorked);
        double calculate_salary();
        void display_employee();
        int get_id();
    private:
        string name;
        int id;
        double hourlyRate, hoursWorked;
        const double TAX_RATE = 0.10;  // 10% tax
        const double BONUS_THRESHOLD = 2000; // Limit for bonus
        const double BONUS_RATE = 0.05; // 5% bonus
};

class Payroll {
    public:
        void addEmployee(Employee emp);
        void display_payroll();
        void removeEmployee(int id);
    private:
        vector<Employee> employees;
};

int main() {
    Payroll payroll;
    int choice;

    do {
        cout<<"\nPayroll System Menu:\n";
        cout<<"1. Add Employee\n";
        cout<<"2. Show Payroll\n";
        cout<<"3. Remove Employee\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            string name;
            int id;
            double rate, hours;
            cout<<"Enter Employee Name: ";
            cin>>name;
            cout<<"Enter Employee ID: ";
            cin>>id;
            cout<<"Enter Hourly Rate: ";
            cin>>rate;
            cout<<"Enter Hours Worked: ";
            cin>>hours;
            Employee emp(name, id, rate, hours);
            payroll.addEmployee(emp);
        } else if (choice == 2) {
            payroll.display_payroll();
        }
        else if (choice == 3) {
            int id;
            cout<<"Enter Employee's ID to remove: ";
            cin>>id;
            payroll.removeEmployee(id);
        }

    } while (choice != 4);

    cout<<"Thanks For Using Our Payroll System\n";
    cout<<"\tExit Of The Program";
    return 0;
}

Employee::Employee(string in_name, int in_id, double in_hourlyRate, double in_hoursWorked) {
    name = in_name;
    id = in_id;
    hourlyRate = in_hourlyRate;
    hoursWorked = in_hoursWorked;
}
        
        
double Employee::calculate_salary() {
    double grossSalary = hourlyRate * hoursWorked;
    if (grossSalary > BONUS_THRESHOLD) {
        grossSalary += grossSalary * BONUS_RATE; // 5% addition
    }
    double netSalary = grossSalary - (grossSalary * TAX_RATE);
    return netSalary;
}

void Employee::display_employee() {
    cout<<"Employee's ID: "<<id<<endl;
    cout<<"Employee's Name: "<<name<<endl;
    cout<<"Employee's Salary After Tax & Bonus: "<<calculate_salary()<<endl;
}

int Employee::get_id() {
    return id;
}
    
void Payroll::addEmployee(Employee emp) {
    employees.push_back(emp);
}    
        
void Payroll::display_payroll() {
    cout<<"\n------ Payroll Report ------\n";
    for (auto &emp : employees) {
        emp.display_employee();
    }
}
        

void Payroll::removeEmployee(int id) {
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if (it->get_id() == id) {
            employees.erase(it);
            cout<<"Employee with ID "<<id<<" has been removed.\n";
            return;
        }
    }
    cout<<"Employee with ID "<<id<<" not found.\n";
}
        
