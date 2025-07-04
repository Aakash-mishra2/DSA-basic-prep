// Problem Explanation: Printing Job Queue
// You are given:

// N: Total number of print jobs

// X: Time interval (in minutes) between each job's arrival

// Each print job takes 10 minutes to complete.

// The printer works sequentially, i.e., it finishes one job before starting the next.

// Goal:
// Find how long the last (Nth) job will have to wait in the queue after arriving, before the printer starts it.

// If it doesn’t have to wait at all, return 0.

#include <iostream>
using namespace std;

int printingJobWaitTime(int N, int X) {
    if (N <= 1) return 0;

    int lastArrival = (N - 1) * X;
    int processingTime = (N - 1) * 10;

    int waitTime = processingTime - lastArrival;
    return waitTime > 0 ? waitTime : 0;
}

int main() {
    int N = 4, X = 5;
    cout << printingJobWaitTime(N, X) << endl;  // Output: 15
    return 0;
}
