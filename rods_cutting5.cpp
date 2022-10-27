#include <iostream>
using namespace std;

// basic recursive method
int maxProfit(int prices[], int n) {
    // base case
    if (n <= 0) return 0;

    // recursive case
    int ans = INT_MIN;
    int profit = 0;
    for (int i = 0; i < n; i++) {
        int cut = i + 1;
        profit = maxProfit(prices, n-cut) + prices[i];
        ans = max(ans, profit);
    }

    return ans;
}

int main(void) {
    int prices[] = {1,5,8,9,10,17,17,20};

    int n;
    cin >> n;
    cout << maxProfit(prices, n) << endl; 
    return 0;
}