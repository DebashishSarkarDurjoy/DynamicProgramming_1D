#include <iostream>
#include <vector>
using namespace std;

int countWaysBU(int n, int k) {
    vector<int> dp(n+1, 0);

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int jump = 1; jump <= k; jump++) {
            if (i-jump < 0) continue;
            else {
                dp[i] += dp[i-jump];
            }
        }
    }
    return dp[n];
}

int main(void) {
    int n, k;
    cin >> n >> k;
    cout << countWaysBU(n, k) << endl;

    return 0;
}
