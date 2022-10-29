#include <iostream>
using namespace std;

int countWays(int n, int k) {
    // base case
    if (n == 0) return 1;

    // recursive case
    int ways = 0;
    for (int i = 1; i <= k; i++) {
        if (n-i >= 0) {
            ways += countWays(n-i, k);
        }
    }

    return ways;
}

int countWaysTD(int n, int k, int lookup[]) {
    // base case
    if (n == 0) return 1;
    if (lookup[n] != 0) return lookup[n];

    // recursive case
    int ways = 0;
    for (int i = 1; i <= k; i++) {
        if (n-i >= 0) {
            ways += countWaysTD(n-i, k, lookup);
        }
    }
    lookup[n] = ways;
    return ways;
}

int main(void) {
    int n, k;
    cin >> n >> k;
    // cout << countWays(n, k)<< endl;

    int lookup[100] = { 0 };
    cout << countWaysTD(n, k, lookup) << endl;
    return 0;
}