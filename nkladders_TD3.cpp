#include <iostream>

using namespace std;

int maxProfit(int *prices, int n, int *dp) {
    if (n == 0) return 0;
    if (dp[n] != 0) return dp[n];

    for (int len = 1; len <= n; len++) {
        
    }
}

int main(void) {
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n;
    cin >> n;

    int dp[n+1] = {0};
    cout << maxProfit(prices, n, dp) << endl;

    return 0;
}