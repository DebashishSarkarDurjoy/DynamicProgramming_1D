#include <iostream>

using namespace std;

int countWaysTD(int n, int k, int *dp) {
    if (n == 0) return 1;
    if (n < 0)  return 0;

    int ans = 0;
    for (int jump = 1; jump <= k; jump++) {
        ans += countWaysTD(n - jump, k, dp);
    }
    return dp[n] = ans;
}

int main(void) {
    int n, k;
    cin >> n >> k;
    int dp[1000] = {0};
    cout << countWaysTD(n, k, dp) << endl;

    return 0;
}
