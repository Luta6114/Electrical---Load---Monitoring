#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Basic appliance structure
struct Appliance {
    string name;
    double powerW;
    double hoursPerDay;
};

// Menu function
int menu() {
    cout << "\n==============================\n";
    cout << "     Electrical Load Monitoring\n";
    cout << "==============================\n";
    cout << "1. Register appliance\n";
    cout << "2. View all appliances\n";
    cout << "3. Search appliance by name\n";
    cout << "4. Energy summary (kWh/day)\n";
    cout << "5. Billing summary\n";
    cout << "0. Exit\n";
    cout << "Choose: ";

    int choice;
    cin >> choice;
    return choice;
}

int main() {
    vector<Appliance> appliances;

    while (true) {
        int choice = menu();

        switch (choice) {
            case 0:
                cout << "Goodbye!\n";
                return 0;

            default:
                cout << "Feature not implemented yet.\n";
        }
    }
}