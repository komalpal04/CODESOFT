#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed random number generator
    srand(time(0));

    int number = rand() % 100 + 1;  // Random number between 1 and 100
    int guess;
    int count = 0;

    cout << "=============================\n";
    cout << "    GUESS THE NUMBER GAME   \n";
    cout << "=============================\n";
    cout << "I have picked a number between 1 and 100.\n";
    cout << "Try to guess it!\n";

    while (true) {
        cout << "\nEnter your guess: ";
        cin >> guess;
        count++;

        if (guess > number) {
            cout << "The guess is too high.";
        } else if (guess < number) {
            cout << "The guess is too low.";
        } else {
            cout << "Nice! you guesses the correct number " << count << " tries.\n";
            break;
        }
    }

    cout << "Thanks for playing!\n";
    return 0;
}

