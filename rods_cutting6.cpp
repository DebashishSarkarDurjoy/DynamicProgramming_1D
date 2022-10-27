#include <iostream>
using namespace std;

// top down approach
int maxProfit(int prices[], int n, int lookup[]) {
    // base case
    if (n <= 0) return 0;
    if (lookup[n] != 0) return lookup[n];

    // recursive case
    int ans = INT_MIN;
    int profit = 0;
    for (int i = 0; i < n; i++) {
        int cut = i + 1;
        profit = maxProfit(prices, n-cut, lookup) + prices[i];
        ans = max(profit, ans);
    }
    lookup[n] = ans;
    return ans;
}

int main(void) {
    int prices[] = {1,5,8,9,10,17,17,20};

    int n;
    cin >> n;

    int lookup[100] = { 0 };
    cout << maxProfit(prices, n, lookup) << endl; 
    return 0;
}