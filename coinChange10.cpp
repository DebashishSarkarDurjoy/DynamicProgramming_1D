#include <iostream>
#include <vector>
using namespace std;

int minCoins(vector<int> coins, int target) {
    vector<int> dp (target+1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= target; i++) {
        for (int coin: coins) {
            if (i-coin >= 0 && dp[i-coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i-coin] + 1);
            }
        }
    }
    return dp[target] == INT_MAX ? -1 : dp[target];
}

int main(void) {
    vector<int> coins = {1,3,4,7,10};
    int target = 16;

    cout << minCoins(coins, target) << endl;

    return 0;
}
