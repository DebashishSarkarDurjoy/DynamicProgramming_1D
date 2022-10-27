#include <vector>
#include <iostream>

using namespace std;

int minCoins(vector<int> coins, int target) {
    // bottom up approach
    vector<int> lookup(target+1, INT_MAX);
    lookup[0] = 0;

    for (int i = 1; i <= target; i++) {
        for (int c: coins) {
            if ( (i-c >= 0) && (lookup[i-c] != INT_MAX) ) {
                lookup[i] = min(lookup[i], lookup[i-c] + 1);
            }
        }
    }

    return lookup[target] == INT_MAX ? -1 : lookup[target];
}

int main(void) {
    vector<int> coins = {1,3,4,7,10};
    int target = 14;

    cout << minCoins(coins, target) << endl;

    return 0;
}