#include <iostream>
#include <vector>
using namespace std;

int lcs_top_down(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
    // base case
    if ( (s1[i] == '\0') || (s2[j] == '\0') ) return 0;

    // memoisation check
    if ( dp[i][j] != -1 ) return dp[i][j];
    
    
    // recursive case
    if ( s1[i] == s2[j] ) {
        dp[i][j] = 1 + lcs_top_down(s1, s2, i+1, j+1, dp);
        return dp[i][j];
    }
    else {
        int o1 = lcs_top_down(s1, s2, i+1, j, dp);
        int o2 = lcs_top_down(s1, s2, i, j+1, dp);

        dp[i][j] = max(o1, o2);
        return dp[i][j];
    }
}

int main(void) {
    string s1 = "ABCD";
    string s2 = "ABEDG";

    vector<vector<int>> dp(s1.size(), vector<int> (s2.size(), -1));
    cout << lcs_top_down(s1, s2, 0, 0, dp) << endl;

    return 0;
}