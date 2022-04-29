#include <iostream>
#include <vector>

using namespace std;

int minCoins(vector<int> coins, int m) {
    vector<int> changes(m+1);
    changes[0] = 0;


    for (int i = 1; i <= m; i++) {
        changes[i] = INT_MAX;
        for (int coin: coins) {
            if (i-coin >= 0 || changes[i-coin] != INT_MAX) {
                changes[i] = min(changes[i-coin] + 1, changes[i]);
            }
        }
    }


    return changes[m] == INT_MAX ? -1 : changes[m];
}

int main(void) {
    vector<int> coins = {1,5,7,10};
    int target = 2;

    cout << "Min coins required: " << minCoins(coins, target) << endl;

    return 0;
}
