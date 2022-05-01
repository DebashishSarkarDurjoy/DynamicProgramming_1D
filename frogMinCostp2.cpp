#include <iostream>
#include <vector>

using namespace std;


int minCost(vector<int> stones) {
    vector<int> prevCosts (stones.size(), 0);
    prevCosts[0] = 0;
    prevCosts[1] = abs(stones[0] - stones[1]);

    for (int k = 2; k < stones.size(); k++) {
        int jump_1 = abs(stones[k] - stones[k-2]) + prevCosts[k-2];
        int jump_2 = abs(stones[k] - stones[k-1]) + prevCosts[k-1];

        prevCosts[k] = min(jump_1, jump_2);
    }

    return prevCosts[stones.size() - 1];
}

int main(void) {
    vector<int> stones = {30,10,60,10,60,50};

    cout << "Min cost is " << minCost(stones) << endl;

    return 0;
}
