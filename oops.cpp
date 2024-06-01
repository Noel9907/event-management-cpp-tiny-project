#include <iostream>
#include <string> 

using namespace std;

class Event {
    string name;
    string date;
    string venue;

public:
    Event() {}

    Event(string n, string d, string v) : name(n), date(d), venue(v) {}

    void display() const {
        cout << "Event: " << name << "\nDate: " << date << "\nVenue: " << venue << endl;
    }
};

int main() {
    const int Maxevents = 100;
    Event event[Maxevents]; // array to store events.

    int count = 0;
    string eventName, eventDate, eventVenue;
    int choice;

    do {
        cout << "\nEvent Management System\n";
        cout << "1. Add Event\n";
        cout << "2. Display All Events\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                if (count < Maxevents) {
                    cout << "Enter event name: ";
                    cin.ignore(); // To ignore the newline character left in the input buffer
                    getline(cin, eventName);

                    cout << "Enter event date: ";
                    getline(cin, eventDate);

                    cout << "Enter event venue: ";
                    getline(cin, eventVenue);

                    event[count] = Event(eventName, eventDate, eventVenue);

                    cout << "Event added successfully!" << endl;
                    count++;
                } else {
                    cout << "Cannot add more events. Maximum limit reached." << endl;
                }
                break;

            case 2: 
                if (count == 0) {
                    cout << "No events available." << endl;
                } else {
                    cout << "List of all events:" << endl;
                    for (int i = 0; i < count; i++) {
                        event[i].display();
                        cout << "_____________" << endl;
                    }
                }
                break;

            case 3: 
                cout << "Exiting!" << endl;
                break;

            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
