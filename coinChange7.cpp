#include <iostream>
#include <vector>
using namespace std;

int minCoins(vector<int> &coins, int m) {
    vector<int> dp (m+1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= m; i++) {
        for (int coin: coins) {
            if (i - coin >= 0 && dp[i-coin] != INT_MAX) {
                dp[i] = min(dp[i-coin]+1, dp[i]);
            }
        }
    }

    return dp[m] == INT_MAX ? -1 : dp[m];
}


int main(void) {
    vector<int> coins = {1, 5, 7, 10};
    int target = 8;

    cout << minCoins(coins, target) << endl;

    return 0;
}
