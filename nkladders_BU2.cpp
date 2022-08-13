#include <iostream>
#include <vector>

using namespace std;

int nkladders_BU(int n, int k) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    cout << dp[0] << " ";
    cout << dp[1] << " ";
    for (int i = 2; i <= n; i++) {
        
        if (i <= k) dp[i] = 2 * dp[i-1]; 
        else dp[i] = 2*dp[i-1] - dp[i-k-1];

        cout << dp[i] << " ";
    }

    return dp[n];
}

void nkladders_BU_test(int n, int k) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    cout << dp[0] << " ";
    for (int i = 1; i <= n; i++) {
        for (int jump = 1; jump <= k; jump++) {
            if (i - jump >= 0) dp[i] += dp[i-jump];
        }
        cout << dp[i] << " ";
    }
    return ;
}

int main(void) {
    int n, k;

    cin >> n >> k;
    nkladders_BU(n, k);



    return 0;
}