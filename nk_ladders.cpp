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



int main(void) {
    int n, k;
    cin >> n >> k;
    cout << countWays(n, k)<< endl;

    return 0;
}