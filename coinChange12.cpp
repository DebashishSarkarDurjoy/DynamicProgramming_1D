#include <iostream>
#include <vector>

using namespace std;

int minCoins(vector<int> coins, int target) {
    // recursive approach
    // base case
    if (target == 0) return 0;
    if (target < 0) return 0;
    
    // recursive case
    int change = INT_MAX;
    for (int c: coins) {
        if (target - c >= 0) {
            change = min(minCoins(coins, target-c)+1, change);
        }
    }
    return change;
}

int main(void) {
    vector<int> coins = {1,3,4,7,10};
    int target;
    cin >> target;

    cout << minCoins(coins, target) << endl;

    return 0;
}