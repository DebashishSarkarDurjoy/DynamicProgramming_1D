//using dynamic programming

#include <iostream>
using namespace std;

int countWaysTDDP(int n, int k, int* dp) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    if (dp[n] != 0) return dp[n];

    int ans = 0;
    for (int i = 1; i <=k; i++) {
        ans += countWaysTDDP(n-i, k, dp);
    }
    return dp[n] = ans;
}

int main(void) {
    int n, k;
    cin >> n >> k;
    int dp[100] = {0};
    cout << countWaysTDDP(n, k, dp) << endl;

    return 0;
}
