#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Passenger {
    string name;
    string seatNumber;
};

struct Flight {
    string flightNumber;
    string origin;
    string destination;
    int capacity;
    vector<Passenger> passengers;
};

vector<Flight> flights;

void displayFlights() {
    cout << "Available Flights:" << endl;
    for (const Flight& flight : flights) {
        cout << "Flight Number: " << flight.flightNumber << endl;
        cout << "Origin: " << flight.origin << ", Destination: " << flight.destination << endl;
        cout << "Available Seats: " << flight.capacity - flight.passengers.size() << endl;
        cout << endl;
    }
}

void reserveSeat(string flightNumber, string passengerName) {
    for (Flight& flight : flights) {
        if (flight.flightNumber == flightNumber) {
            if (flight.passengers.size() < flight.capacity) {
                Passenger passenger;
                passenger.name = passengerName;
                passenger.seatNumber = "Seat" + to_string(flight.passengers.size() + 1);
                flight.passengers.push_back(passenger);
                cout << "Seat reserved successfully! Your seat number is " << passenger.seatNumber << endl;
            } else {
                cout << "No available seats for this flight." << endl;
            }
            return;
        }
    }
    cout << "Flight not found." << endl;
}

int main() {
    Flight flight1 = {"F001", "New York", "Los Angeles", 150, {}};
    Flight flight2 = {"F002", "Chicago", "Miami", 200, {}};

    flights.push_back(flight1);
    flights.push_back(flight2);

    displayFlights();

    reserveSeat("F001", "Alice");
    reserveSeat("F001", "Bob");
    reserveSeat("F001", "Charlie");

    reserveSeat("F002", "Dave");
    reserveSeat("F002", "Eve
