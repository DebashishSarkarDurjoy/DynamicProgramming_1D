#include <iostream>
#include <vector>
using namespace std;

int minCost(vector<int> &steps) {
    vector<int> prevMinCost(steps.size(), 0);

    prevMinCost[0] = 0;
    prevMinCost[1] = abs(steps[1] - steps[0]);

    for (int i = 2; i <= steps.size(); i++) {
        int jump_1 = abs(steps[i] - steps[i-1]) + prevMinCost[i-1];
        int jump_2 = abs(steps[i] - steps[i-2]) + prevMinCost[i-2];

        prevMinCost[i] = min(jump_1, jump_2);
    }


    return prevMinCost[steps.size() - 1];
}

int main(void) {
    vector<int> steps = {30,10,60,10,60,50};
    cout << "Min cost: " << minCost(steps) << endl;

    return 0;
}
