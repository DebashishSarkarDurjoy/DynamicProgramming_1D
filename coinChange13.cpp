#include <vector>
#include <iostream>

using namespace std;

int minCoins(vector<int> coins, int target, vector<int> &lookup) {
    // base case
    if (target <= 0) return 0;
    if (lookup[target] != 0) return lookup[target];

    // recursive case
    int ans = INT_MAX;
    for (int c: coins) {
        if (target-c >= 0) {
            ans = min(minCoins(coins, target-c, lookup)+1, ans);
        }
    }
    lookup[target] = ans;
    return ans;
}

int main(void) {
    vector<int> coins = {1,3,4,7,10};
    int target;
    cin >> target;

    vector<int> lookup(target+1, 0);
    cout << minCoins(coins, target, lookup) << endl;

    return 0;
}