#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Visitor {
public:
    Visitor(string name, string id) : name(name), id(id), checkInTime(""), checkOutTime("") {}

    string getName() const { return name; }
    string getId() const { return id; }
    string getCheckInTime() const { return checkInTime; }
    string getCheckOutTime() const { return checkOutTime; }

    void checkIn(string time) { checkInTime = time; }
    void checkOut(string time) { checkOutTime = time; }

private:
    string name, id, checkInTime, checkOutTime;
};

class VisitorManagementSystem {
public:
    void run() {
        while (true) {
            displayMenu();
            int choice;
            cin >> choice;

            switch (choice) {
                case 1: registerVisitor(); break;
                case 2: checkInVisitor(); break;
                case 3: checkOutVisitor(); break;
                case 4: displayVisitors(); break;
                case 5: return;
                default: cout << "Invalid choice. Please try again.\n";
            }
        }
    }

private:
    vector<Visitor> visitors;

    void displayMenu() {
        cout << "\nVisitor Management System\n"
             << "1. Register Visitor\n"
             << "2. Check In Visitor\n"
             << "3. Check Out Visitor\n"
             << "4. Display Visitors\n"
             << "5. Exit\n"
             << "Enter your choice: ";
    }

    void registerVisitor() {
        string name, id;
        cout << "Enter visitor name: ";
        cin >> name;
        cout << "Enter visitor ID: ";
        cin >> id;

        visitors.push_back(Visitor(name, id));
        cout << "Visitor registered successfully.\n";
    }

    Visitor* findVisitor(const string& id) {
        for (auto& visitor : visitors) {
            if (visitor.getId() == id) {
                return &visitor;
            }
        }
        return nullptr;
    }

    void checkInVisitor() {
        string id, time;
        cout << "Enter visitor ID: ";
        cin >> id;
        cout << "Enter check-in time (HH:MM): ";
        cin >> time;

        Visitor* visitor = findVisitor(id);
        if (visitor) {
            visitor->checkIn(time);
            cout << "Visitor checked in successfully.\n";
        } else {
            cout << "Visitor not found.\n";
        }
    }

    void checkOutVisitor() {
        string id, time;
        cout << "Enter visitor ID: ";
        cin >> id;
        cout << "Enter check-out time (HH:MM): ";
        cin >> time;

        Visitor* visitor = findVisitor(id);
        if (visitor) {
            visitor->checkOut(time);
            cout << "Visitor checked out successfully.\n";
        } else {
            cout << "Visitor not found.\n";
        }
    }

    void displayVisitors() {
        if (visitors.empty()) {
            cout << "No visitors registered.\n";
            return;
        }

        cout << "\nVisitor List:\n";
        for (const auto& visitor : visitors) {
            cout << "Name: " << visitor.getName() << ", ID: " << visitor.getId() << "\n";
            if (!visitor.getCheckInTime().empty()) {
                cout << "  Check-in time: " << visitor.getCheckInTime() << "\n";
            }
            if (!visitor.getCheckOutTime().empty()) {
                cout << "  Check-out time: " << visitor.getCheckOutTime() << "\n";
            }
        }
    }
};

int main() {
    VisitorManagementSystem system;
    system.run();
    return 0;
}