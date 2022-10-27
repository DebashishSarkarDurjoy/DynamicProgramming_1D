#include <iostream>
using namespace std;

// bottom up approach
int maxProfit(int prices[], int n) {
    int lookup[100] = { 0 };

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i < len; i++) {
            int cut = i + 1;
            lookup[len] = max(prices[i] + lookup[len - cut], lookup[len]);
        }
    }
    return lookup[n];
}

int main(void) {
    int prices[] = {1,5,8,9,10,17,17,20};

    int n;
    cin >> n;

    int lookup[100] = { 0 };
    cout << maxProfit(prices, n) << endl; 
    return 0;
}