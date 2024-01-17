#include <iostream>
#include <chrono>
using namespace std;

void moveDisks(int, int, int, int);
void printIt(int , int , int );

int main() {
    const int FROMPEG = 1;
    const int TOPEG = 3;
    const int TEMPPEG = 2;
    const int NUMDISKS = 3;

    for (auto numDisks : {5, 10, 15, 20, 25, 30, 35}) {
        cout << "Numdisks: " << numDisks << endl;

        auto start_time = chrono::high_resolution_clock::now();
        moveDisks(numDisks, FROMPEG, TOPEG, TEMPPEG);
        auto end_time = chrono::high_resolution_clock::now();

        cout << "Moved " << numDisks << " pegs"
             << " from peg " << FROMPEG
             << " to peg " << TOPEG << endl;

        auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
        cout << "Time taken: " << duration.count() << " milliseconds" << endl;
    }

    return 0;
}

void moveDisks(int num, int fromPeg, int toPeg, int tempPeg) {
    if (num > 0) {
        moveDisks(num -1, fromPeg, tempPeg, toPeg);
        printIt(num, fromPeg, toPeg);
        moveDisks(num-1, tempPeg, toPeg, fromPeg);
    }
}

void printIt(int disk, int fromPeg, int toPeg) {
    // Do nothing for timing test, but otherwise
    cout<< "Move disk " << disk
        << " from peg " << fromPeg
        << " to peg " << toPeg << endl;
}
