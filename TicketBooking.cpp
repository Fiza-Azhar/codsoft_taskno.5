#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Movie {
public:
    string title;
    double ticketPrice;
    int seats;

    Movie(string title, double ticketPrice, int seats) : title(title), ticketPrice(ticketPrice), seats(seats) {}

    void displayInfo() {
        cout << "Movie: " << title << endl;
        cout << "Ticket Price: $" << ticketPrice << endl;
        cout << "Available Seats: " << seats << endl;
    }

    bool bookSeats(int numSeats) {
        if (seats >= numSeats) {
            seats -= numSeats;
            return true;
        }
        return false;
    }
};

class BookingSystem {
private:
    vector<Movie> movies;

public:
    void addMovie(string title, double ticketPrice, int seats) {
        Movie movie(title, ticketPrice, seats);
        movies.push_back(movie);
    }

    void displayMovies() {
        cout << "Available Movies:" << endl;
        for (size_t i = 0; i < movies.size(); ++i) {
            cout << i + 1 << ". " << movies[i].title << endl;
        }
    }

    void displayMovieInfo(size_t movieIdx) {
        if (movieIdx < movies.size()) {
            movies[movieIdx].displayInfo();
        } else {
            cout << "Invalid movie index." << endl;
        }
    }

    void makeBooking(size_t movieIdx, int numTickets) {
        if (movieIdx < movies.size()) {
            if (movies[movieIdx].bookSeats(numTickets)) {
                double totalCost = numTickets * movies[movieIdx].ticketPrice;
                cout << "Booking successful! Total cost: $" << totalCost << endl;
            } else {
                cout << "Not enough seats available." << endl;
            }
        } else {
            cout << "Invalid movie index." << endl;
        }
    }
};

int main() {
    BookingSystem bookingSystem;

    while (true) {
        cout << "\n1. Add Movie" << endl;
        cout << "2. View Movie Listings" << endl;
        cout << "3. View Movie Info" << endl;
        cout << "4. Make Booking" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();            // Clear the fail state
            cin.ignore(1000, '\n'); // Ignore the invalid input
            continue;               // Skip the rest of the loop body and start over
        }

        switch (choice) {
            case 1: {
                string title;
                double ticketPrice;
                int seats;
                cout << "Enter movie title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter ticket price: ";
                cin >> ticketPrice;
                cout << "Enter number of seats: ";
                cin >> seats;
                bookingSystem.addMovie(title, ticketPrice, seats);
                break;
            }
            case 2: {
                bookingSystem.displayMovies();
                break;
            }
            case 3: {
                size_t movieIdx;
                cout << "Enter movie index: ";
                cin >> movieIdx;
                bookingSystem.displayMovieInfo(movieIdx - 1);
                break;
            }
            case 4: {
                size_t movieIdx;
                int numTickets;
                cout << "Enter movie index: ";
                cin >> movieIdx;
                cout << "Enter number of tickets: ";
                cin >> numTickets;
                bookingSystem.makeBooking(movieIdx - 1, numTickets);
                break;
            }
            case 5: {
                cout << "Exiting program." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    return 0;
}

