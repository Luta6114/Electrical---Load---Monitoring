#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <fstream>   // NEW

using namespace std;

struct Appliance {
    string name;
    double powerW;
    double hoursPerDay;

    double energyKWhPerDay() const {
        return (powerW * hoursPerDay) / 1000.0;
    }
};

void clearBadInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string toLowerStr(string s) {
    transform(s.begin(), s.end(), s.begin(),
              [](unsigned char c) { return tolower(c); });
    return s;
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

    return a;
}

void saveApplianceToFile(const Appliance& a) {
    ofstream file("appliances.txt", ios::app);

    if (file.is_open()) {
        file << a.name << ", "
             << a.powerW << ", "
             << a.hoursPerDay << ", "
             << a.energyKWhPerDay() << " kWh/day\n";
        file.close();
    } else {
        cout << "Error saving to file.\n";
    }
}

void viewAllAppliances(const vector<Appliance>& appliances) {
    if (appliances.empty()) {
        cout << "No appliances registered.\n";
        return;
    }

    for (const auto& a : appliances) {
        cout << a.name << " | "
             << a.powerW << "W | "
             << a.hoursPerDay << " hrs | "
             << a.energyKWhPerDay() << " kWh/day\n";
    }
}

void searchAppliance(const vector<Appliance>& appliances) {
    if (appliances.empty()) {
        cout << "No appliances registered.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string query;
    cout << "Enter appliance name to search: ";
    getline(cin, query);

    string qLower = toLowerStr(query);
    bool found = false;

    for (const auto& a : appliances) {
        if (toLowerStr(a.name).find(qLower) != string::npos) {
            cout << a.name << " | "
                 << a.powerW << "W | "
                 << a.hoursPerDay << " hrs | "
                 << a.energyKWhPerDay() << " kWh/day\n";
            found = true;
        }
    }

    if (!found)
        cout << "No appliance matched.\n";
}

void showEnergySummary(const vector<Appliance>& appliances) {
    if (appliances.empty()) {
        cout << "No appliances registered.\n";
        return;
    }

    double total = 0.0;

    for (const auto& a : appliances)
        total += a.energyKWhPerDay();

    cout << "TOTAL ENERGY: "
         << fixed << setprecision(3)
         << total << " kWh/day\n";
}

void calculateBill(const vector<Appliance>& appliances) {
    if (appliances.empty()) {
        cout << "No appliances registered.\n";
        return;
    }

    double tariff;
    while (true) {
        cout << "Enter electricity tariff per kWh: ";
        cin >> tariff;

        if (!cin.fail() && tariff > 0) break;
        clearBadInput();
    }

    double totalEnergy = 0.0;
    for (const auto& a : appliances)
        totalEnergy += a.energyKWhPerDay();

    double totalCost = totalEnergy * tariff;

    cout << "\n===== BILL SUMMARY =====\n";
    cout << "Total Energy: " << totalEnergy << " kWh/day\n";
    cout << "Tariff: " << tariff << " per kWh\n";
    cout << "Total Cost: " << totalCost << "\n";
}

int main() {
    vector<Appliance> appliances;

    while (true) {
        int choice = menu();

        switch (choice) {

        case 1: {
            Appliance a = registerAppliance();
            appliances.push_back(a);
            saveApplianceToFile(a);
            break;
        }

        case 2:
            viewAllAppliances(appliances);
            break;

        case 3:
            searchAppliance(appliances);
            break;

        case 4:
            showEnergySummary(appliances);
            break;

        case 5:
            calculateBill(appliances);
            break;

        case 0:
            cout << "Goodbye!\n";
            return 0;

        default:
            cout << "Invalid choice.\n";
        }
    }
}