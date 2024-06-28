#include <iostream>
#include <string> 

using namespace std;

class Event {
    string name;
    string time;
    string date;
    string venue;

public:
    Event() {}
    Event(string n, string d, string t, string v) : name(n), date(d), time(t), venue(v) {}
    void display() const {
        cout << "\nEvent: " << name << "\nDate: " << date << "\nTime: " << time << "\nVenue: " << venue << endl;
    }

    string getDate() const {
        return date;
    }
};

int main() {
    const int MaxEvents = 100;
    Event events[MaxEvents]; 
    int count = 0;
    string data;
    int choice;
    cout << "\nEnter dates in (DD/MM/YYYY) format\n";
    cout << "Enter today's date: ";
    cin >> data;
    cout << "\n";

    do {
        cout << "------------------------------\n\n";
        cout << "Event Management System\n\n";
        cout << "------------------------------\n\n";
        cout << "1. Add Event\n";
        cout << "2. Display All Events\n";
        cout << "3. Today's Events\n";
        cout << "4. Upcoming Events\n";
        cout << "5. Exit\n\n";
        cout << "----------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                if (count < MaxEvents) {
                    string eventName, eventDate, eventTime, eventVenue;
                    
                    cout << "Enter event name: ";
                    cin.ignore();
                    getline(cin, eventName);

                    cout << "Enter event date: ";
                    getline(cin, eventDate);

                    cout << "Enter time of the event: ";
                    getline(cin, eventTime);

                    cout << "Enter event venue: ";
                    getline(cin, eventVenue);

                    events[count] = Event(eventName, eventDate, eventTime, eventVenue);
                    cout << "\nEvent added successfully!!\n";
                    count++;
                } else {
                    cout << "Cannot add more events\n" ;
                }
                break;

            case 2: 
                if (count == 0) {
                    cout << "No events available\n" ;
                    cout << "-------------------\n";
                } else {
                    cout << "\nList of all events:\n";
                    cout << "------------------\n";
                    for (int i = 0; i < count; i++) {
                        events[i].display();
                        
                    }
                }
                break;
            
            case 3:
                cout << "\nToday's Events:\n";
                {
                    bool today = false;
                    for (int i = 0; i < count; i++) {
                        if (events[i].getDate() == data) {
                            events[i].display();
                            cout << "---------------------\n";
                            today = true;
                        }
                    }
                    if (!today) {
                        cout << "No events scheduled for today.\n\n";
                    }
                }
                break;

            case 4:
                cout << "\nUpcoming Events:\n\n";
                {
                    bool tmw = false;
                    for (int i = 0; i < count; i++) {
                        if (events[i].getDate() > data) {
                            events[i].display();
                            tmw = true;
                        }
                    }
                    if (!tmw) {
                        cout << "No upcoming events.\n";
                    }
                }
                break;

            case 5: 
                cout << "Thank You\n";
                cout << "Exiting!\n";
                break;

            default:
                cout << "Invalid choice, please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}