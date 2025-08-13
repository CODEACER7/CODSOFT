#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

int main() {
    srand(time(0)); // Seed the random number generator

    int secretNumber = rand() % 100 + 1; // Random number between 1 and 100
    int guess;

    cout << "🎯 Guess the Number Game!" << endl;
    cout << "I'm thinking of a number between 1 and 100..." << endl;

    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(1000, '\n'); // Discard invalid input
            cout << "⚠ Please enter a valid number!" << endl;
            continue;
        }

        if (guess < secretNumber) {
            cout << "Too low! 📉 Try again." << endl;
        } 
        else if (guess > secretNumber) {
            cout << "Too high! 📈 Try again." << endl;
        } 
        else {
            cout << "🎉 Congratulations! You guessed the correct number." << endl;
            break;
        }
    }

    return 0;
}