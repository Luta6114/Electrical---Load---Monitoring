#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

struct Appliance {
    string name;
    double powerW;
    double hoursPerDay;
};

void clearBadInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

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

Appliance registerAppliance() {
    Appliance a;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    do {
        cout << "Enter appliance name: ";
        getline(cin, a.name);
    } while (a.name.empty());

    while (true) {
        cout << "Enter power rating (W): ";
        cin >> a.powerW;
        if (!cin.fail() && a.powerW > 0) break;
        clearBadInput();
    }

    while (true) {
        cout << "Enter usage hours per day (0 - 24): ";
        cin >> a.hoursPerDay;
        if (!cin.fail() && a.hoursPerDay >= 0 && a.hoursPerDay <= 24) break;
        clearBadInput();
    }

    cout << "Appliance registered successfully!\n";
    return a;
}

void viewAllAppliances(const vector<Appliance>& appliances) {
    if (appliances.empty()) {
        cout << "No appliances registered.\n";
        return;
    }

    cout << "\n================= APPLIANCES =================\n";
    cout << left
         << setw(5)  << "No."
         << setw(20) << "Name"
         << setw(12) << "Power(W)"
         << setw(12) << "Hours/day"
         << "\n----------------------------------------------\n";

    for (size_t i = 0; i < appliances.size(); i++) {
        cout << left
             << setw(5)  << (i + 1)
             << setw(20) << appliances[i].name
             << setw(12) << appliances[i].powerW
             << setw(12) << appliances[i].hoursPerDay
             << "\n";
    }
}

int main() {
    vector<Appliance> appliances;

    while (true) {
        int choice = menu();

        switch (choice) {

        case 1:
            appliances.push_back(registerAppliance());
            break;

        case 2:
            viewAllAppliances(appliances);
            break;

        case 0:
            cout << "Goodbye!\n";
            return 0;

        default:
            cout << "Feature not implemented yet.\n";
        }
    }
}
