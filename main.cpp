#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void displayWelcomeMessage() {
    const string GREEN = "\033[32m";
    const string RESET = "\033[0m";

    cout << GREEN;
    cout << "************************************************************\n";
    cout << "*                                                           *\n";
    cout << "*      __        __   _                                     *\n";
    cout << "*      \\ \\      / /__| | ___ ___  _ __ ___   __             *\n";
    cout << "*       \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_  _ \\ / _\\             *\n";
    cout << "*        \\ V  V /  __/ | (_| (_) | | | | | |  __/           *\n";
    cout << "*         \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|           *\n";
    cout << "*                                                           *\n";
    cout << "************************************************************\n";
    cout << RESET;
}

void displayMainMenu() {
    cout << "************************* MAIN MENU ************************\n";
    cout << "************************************************************\n";
    cout << "*                          1. Signup                       *\n";
    cout << "*                          2. Login                        *\n";
    cout << "*                          3. Exit                         *\n";

    cout << "************************************************************\n";
    cout << "************************************************************\n";
}

void displayUserMenu() {
    cout << "****************** USER MENU ******************\n";
    cout << "* 1. View Now Playing Movies                  *\n";
    cout << "* 2. View Upcoming Movies                     *\n";
    cout << "* 3. Buy Tickets                              *\n";
    cout << "* 4. Report a Movie                           *\n";
    cout << "* 5. Review a Movie                           *\n";
    cout << "* 6. Review a Cinema                          *\n";
    cout << "* 7. Suggest a Feature                        *\n";
    cout << "* 8. Delete Account                           *\n";
    cout << "* 9. Logout                                   *\n";
    cout << "* 10. View Cinema Reviews                     *\n";
    cout << "* 11. View Movie Reviews                      *\n";
    cout << "* 0. Return to Main Menu                      *\n";
    cout << "***********************************************\n";
}

void displaySnacks(string snacks[], double snackPrices[], int size) {
    cout << "****************** SNACKS ******************\n";
    for (int i = 0; i < size; ++i) {
        cout << "* " << i + 1 << ". " << snacks[i] << " - " << snackPrices[i] << " PKR\n";
    }
    cout << "* 0. No more snacks\n";
    cout << "*********************************************\n";
}

void displaySeating(bool seats[5][10]) {
    cout << "****************** SEATING ******************\n";
    cout << "  1234567890\n";
    for (int i = 0; i < 5; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < 10; ++j) {
            if (seats[i][j]) {
                cout << "X";
            } else {
                cout << "O";
            }
        }
        cout << "\n";
    }
    cout << "O = Available, X = Booked\n";
    cout << "*********************************************\n";
}

void displayPaymentMethods() {
    cout << "****************** PAYMENT METHODS ******************\n";
    cout << "* 1. Online Payment                               *\n";
    cout << "* 2. Cash Payment                                 *\n";
    cout << "****************************************************\n";
}

void handleOnlinePayment(double totalAmount) {
    string username, accountName, cardType, pin;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your account name: ";
    cin >> accountName;
    cout << "Enter your card type: ";
    cin >> cardType;
    cout << "Enter your PIN: ";
    cin >> pin;
    cout << "Processing payment...\n";
    cout << "Amount " << totalAmount << " PKR has been deducted from " << accountName << "'s account.\n";
}

int main() {
    string users[100][2];
    int userCount = 0;
    string currentUser = "";

    string cities[7] = {"Lahore", "Karachi", "Islamabad", "Quetta", "Peshawar", "Muzaffarabad", "Hunza"};
    string cinemas[7][3] = {
            {"DHA Lahore", "Central Park Lahore", "Wapda town Lahore"},
            {"Nagin Chorangi Karachi", "Bahria Town Karachi", "Clifton Karachi"},
            {"Sector E9 Islamabad", "Sector F7 Islamabad", "Giga Mall Islamabad"},
            {"Fauji 1 Quetta", "Fauji 2 Quetta", "Fauji 3 Quetta"},
            {"Mall 99 Peshawar", "Bahria Peshawar", "Fauji 1 Peshawar"},
            {"Arangkhel Muzaffarabad", "PirChanasi Muzaffarabad", "Bagh Muzaffarabad"},
            {"Gulmit Hunza", "Passu Cones Hunza", "Hidden Lake Hunza"}
    };

    string movies[8] = {"End-Game", "Fatih 1453", "Planet of Apes", "IP Man", "Untold Hate story", "Escape Room", "Missing", "Snow State"};
    bool isNowPlaying[8] = {true, true, true, true, false, false, false, false};
    string releaseDates[8] = {"2024-06-01", "2024-06-15", "2024-06-20", "2024-07-01", "2024-07-10", "2024-08-01", "2024-08-15", "2024-09-01"};

    string snacks[12] = {"Pop Corn", "Caramel Pop Corn", "Nachos", "Pizza Slice", "Lemon Malt", "Soda", "Chocolate", "Candy", "Hot Dog", "Burger", "Ice Cream", "Coffee"};
    double snackPrices[12] = {150, 200, 250, 300, 120, 100, 180, 80, 350, 400, 200, 150};

    bool seats[5][10] = {{false}};
    string suggestions[100];
    string movieReports[100];
    string cinemaReviews[100];
    string movieReviews[100];
    int suggestionCount = 0;
    int movieReportCount = 0;
    int cinemaReviewCount = 0;
    int movieReviewCount = 0;

    ifstream userFile("users.txt");
    if (userFile) {
        userFile >> userCount;
        for (int i = 0; i < userCount; ++i) {
            userFile >> users[i][0] >> users[i][1];
        }
        userFile.close();
    }

    ifstream suggestionFile("suggestions.txt");
    if (suggestionFile) {
        suggestionFile >> suggestionCount;
        suggestionFile.ignore();
        for (int i = 0; i < suggestionCount; ++i) {
            getline(suggestionFile, suggestions[i]);
        }
        suggestionFile.close();
    }

    ifstream movieReportFile("movieReports.txt");
    if (movieReportFile) {
        movieReportFile >> movieReportCount;
        movieReportFile.ignore();
        for (int i = 0; i < movieReportCount; ++i) {
            getline(movieReportFile, movieReports[i]);
        }
        movieReportFile.close();
    }

    ifstream cinemaReviewFile("cinemaReviews.txt");
    if (cinemaReviewFile) {
        cinemaReviewFile >> cinemaReviewCount;
        cinemaReviewFile.ignore();
        for (int i = 0; i < cinemaReviewCount; ++i) {
            getline(cinemaReviewFile, cinemaReviews[i]);
        }
        cinemaReviewFile.close();
    }

    ifstream movieReviewFile("movieReviews.txt");
    if (movieReviewFile) {
        movieReviewFile >> movieReviewCount;
        movieReviewFile.ignore();
        for (int i = 0; i < movieReviewCount; ++i) {
            getline(movieReviewFile, movieReviews[i]);
        }
        movieReviewFile.close();
    }

    displayWelcomeMessage();

    while (true) {
        displayMainMenu();
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter username: ";
            string username;
            cin >> username;
            cout << "Enter password: ";
            string password;
            cin >> password;
            users[userCount][0] = username;
            users[userCount][1] = password;
            userCount++;
            cout << "Signup successful! Please login to continue.\n";
        } else if (choice == 2) {
            cout << "Enter username: ";
            string username;
            cin >> username;
            cout << "Enter password: ";
            string password;
            cin >> password;
            bool loggedIn = false;
            for (int i = 0; i < userCount; ++i) {
                if (users[i][0] == username && users[i][1] == password) {
                    currentUser = username;
                    loggedIn = true;
                    break;
                }
            }
            if (loggedIn) {
                cout << "Login successful! Welcome " << currentUser << "!\n";
                while (true) {
                    displayUserMenu();
                    int userChoice;
                    cin >> userChoice;
                    if (userChoice == 0) {
                        break;
                    } else if (userChoice == 1) {
                        cout << "Now Playing Movies:\n";
                        for (int i = 0; i < 8; ++i) {
                            if (isNowPlaying[i]) {
                                cout << "- " << movies[i] << " (Release Date: " << releaseDates[i] << ")\n";
                            }
                        }
                    } else if (userChoice == 2) {
                        cout << "Upcoming Movies:\n";
                        for (int i = 0; i < 8; ++i) {
                            if (!isNowPlaying[i]) {
                                cout << "- " << movies[i] << " (Release Date: " << releaseDates[i] << ")\n";
                            }
                        }
                    } else if (userChoice == 3) {
                        int row, column;
                        double totalAmount = 0;
                        double seatAmount = 0;
                        double snackAmount = 0;
                        do {
                            displaySeating(seats);
                            cout << "Enter row (1-5): ";
                            cin >> row;
                            cout << "Enter column (1-10): ";
                            cin >> column;
                            if (row < 1 || row > 5 || column < 1 || column > 10) {
                                cout << "Invalid seat position. Please try again.\n";
                                continue;
                            }
                            if (seats[row - 1][column - 1]) {
                                cout << "Seat already booked. Please choose another seat.\n";
                                continue;
                            }
                            seats[row - 1][column - 1] = true;
                            seatAmount += 500;
                            totalAmount += 500;
                            cout << "Seat booked successfully! Do you want to book another seat? (yes/no): ";
                            string bookMore;
                            cin >> bookMore;
                            if (bookMore == "no" || bookMore == "NO" || bookMore == "No") {
                                break;
                            }
                        } while (true);

                        do {
                            displaySnacks(snacks, snackPrices, 12);
                            int snackChoice;
                            cout << "Enter the snack number to add to your order (0 to finish): ";
                            cin >> snackChoice;
                            if (snackChoice == 0) {
                                break;
                            } else if (snackChoice < 0 || snackChoice > 12) {
                                cout << "Invalid choice. Please try again.\n";
                            } else {
                                snackAmount += snackPrices[snackChoice - 1];
                                totalAmount += snackPrices[snackChoice - 1];
                                cout << "Snack added! Do you want to add more snacks? (yes/no): ";
                                string addMoreSnacks;
                                cin >> addMoreSnacks;
                                if (addMoreSnacks == "no" || addMoreSnacks == "NO" || addMoreSnacks == "No") {
                                    break;
                                }
                            }
                        } while (true);

                        cout << "\n****************** BILL SUMMARY ******************\n";
                        cout << left << setw(20) << "Item" << setw(20) << "Amount (PKR)" << "\n";
                        cout << left << setw(20) << "Seat Booking" << setw(20) << seatAmount << "\n";
                        cout << left << setw(20) << "Snacks" << setw(20) << snackAmount << "\n";
                        cout << left << setw(20) << "Total" << setw(20) << totalAmount << "\n";
                        cout << "**************************************************\n";

                        displayPaymentMethods();
                        int paymentChoice;
                        cin >> paymentChoice;
                        if (paymentChoice == 1) {
                            handleOnlinePayment(totalAmount);
                        } else if (paymentChoice == 2) {
                            cout << "Please pay " << totalAmount << " PKR in cash at the counter.\n";
                        } else {
                            cout << "Invalid payment choice. Please try again.\n";
                        }
                    } else if (userChoice == 4) {
                        cout << "Enter movie report: ";
                        string report;
                        cin.ignore();
                        getline(cin, report);
                        movieReports[movieReportCount++] = report;
                        cout << "Report submitted successfully!\n";
                    } else if (userChoice == 5) {
                        cout << "Enter movie review: ";
                        string review;
                        cin.ignore();
                        getline(cin, review);
                        movieReviews[movieReviewCount++] = review;
                        cout << "Review submitted successfully!\n";
                    } else if (userChoice == 6) {
                        cout << "Enter cinema review: ";
                        string review;
                        cin.ignore();
                        getline(cin, review);
                        cinemaReviews[cinemaReviewCount++] = review;
                        cout << "Review submitted successfully!\n";
                    } else if (userChoice == 7) {
                        cout << "Enter your suggestion: ";
                        string suggestion;
                        cin.ignore();
                        getline(cin, suggestion);
                        suggestions[suggestionCount++] = suggestion;
                        cout << "Suggestion submitted successfully!\n";
                    } else if (userChoice == 8) {
                        for (int i = 0; i < userCount; ++i) {
                            if (users[i][0] == currentUser) {
                                for (int j = i; j < userCount - 1; ++j) {
                                    users[j][0] = users[j + 1][0];
                                    users[j][1] = users[j + 1][1];
                                }
                                userCount--;
                                currentUser = "";
                                cout << "Account deleted successfully!\n";
                                break;
                            }
                        }
                        break;
                    } else if (userChoice == 9) {
                        currentUser = "";
                        cout << "Logged out successfully!\n";
                        break;
                    } else if (userChoice == 10) {
                        cout << "Cinema Reviews:\n";
                        for (int i = 0; i < cinemaReviewCount; ++i) {
                            cout << "- " << cinemaReviews[i] << "\n";
                        }
                    } else if (userChoice == 11) {
                        cout << "Movie Reviews:\n";
                        for (int i = 0; i < movieReviewCount; ++i) {
                            cout << "- " << movieReviews[i] << "\n";
                        }
                    } else {
                        cout << "Invalid choice. Please try again.\n";
                    }
                }
            } else {
                cout << "Invalid username or password.\n";
            }
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    ofstream outFile("users.txt");
    outFile << userCount << endl;
    for (int i = 0; i < userCount; ++i) {
        outFile << users[i][0] << " " << users[i][1] << endl;
    }
    outFile.close();

    ofstream suggestionOutFile("suggestions.txt");
    suggestionOutFile << suggestionCount << endl;
    for (int i = 0; i < suggestionCount; ++i) {
        suggestionOutFile << suggestions[i] << endl;
    }
    suggestionOutFile.close();

    ofstream movieReportOutFile("movieReports.txt");
    movieReportOutFile << movieReportCount << endl;
    for (int i = 0; i < movieReportCount; ++i) {
        movieReportOutFile << movieReports[i] << endl;
    }
    movieReportOutFile.close();

    ofstream cinemaReviewOutFile("cinemaReviews.txt");
    cinemaReviewOutFile << cinemaReviewCount << endl;
    for (int i = 0; i < cinemaReviewCount; ++i) {
        cinemaReviewOutFile << cinemaReviews[i] << endl;
    }
    cinemaReviewOutFile.close();

    ofstream movieReviewOutFile("movieReviews.txt");
    movieReviewOutFile << movieReviewCount << endl;
    for (int i = 0; i < movieReviewCount; ++i) {
        movieReviewOutFile << movieReviews[i] << endl;
    }
    movieReviewOutFile.close();

    return 0;
}