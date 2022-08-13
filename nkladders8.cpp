#include <iostream>

using namespace std;

int nkLaddersTDDP(int c, int k, int *dp)
{
    if (c == 0)
        return 1;
    if (c < 0) return 0;
    if (dp[c] != 0) return dp[c];

    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += nkLaddersTDDP(c - i, k, dp);
    }
    dp[c] = ans;

    return ans;
}

int main(void)
{
    int n, k;
    cin >> n >> k;
    int dp[100] = {0};

    cout << "No. of steps: " << nkLaddersTDDP(n, k, dp) << endl;
}