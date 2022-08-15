#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCoins(vector<int> &coins, int target, int *dp) {
    if (target == 0) return 0;
    if (target < 0) return 0;
    if (dp[target] != 0) return dp[target];

    int ans = INT_MAX;
    for (int coin: coins) {
        if (target - coin >= 0) {
            int current_ans = minCoins(coins, target-coin, dp) + 1;
            ans = min(current_ans, ans);
        }
    }
    dp[target] = ans;

    return dp[target];
}

int main(void) {
    vector<int> coins = {1,3,4,7,10};
    int target = 16;

    int dp[100] = { 0 };

    cout << minCoins(coins, target, dp) << endl;

    return 0;
}