#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int totalFlips;
    int heads = 0, tails = 0;


    srand(time(0));


    cout << "Enter the number of coin flips: ";
    cin >> totalFlips;


    if (totalFlips <= 0) {

        cout << "Please enter a positive number." << endl;

        return 1;
    }


    for (int i = 0; i < totalFlips; i++) {

        if (rand() % 2 == 0) {

            heads++;

            cout << "Flip " << (i+1) << ": H" << endl;

        } else {

            tails++;

            cout << "Flip " << (i+1) << ": T" << endl;
        }
    }


    double headsPercentage = (static_cast<double>(heads) / totalFlips) * 100;
    double tailsPercentage = (static_cast<double>(tails) / totalFlips) * 100;


    cout << "\nResults:" << endl;
    cout << "Total flips: " << totalFlips << endl;
    cout << "Heads (H): " << heads << " (" << headsPercentage << "%)" << endl;
    cout << "Tails (T): " << tails << " (" << tailsPercentage << "%)" << endl;

    return 0;
}
