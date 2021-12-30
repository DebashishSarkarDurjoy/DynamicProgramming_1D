//using recursion

#include <iostream>
using namespace std;

int countWaysRecursion(int n, int k) {
    if (n == 0) return 1;
    if (n < 0) return 0;

    int ans = 0;
    for (int i = 1; i <=k; i++) {
        ans += countWaysRecursion(n-i, k);
    }
    return ans;
}

int main(void) {
    int n, k;
    cin >> n >> k;
    cout << countWaysRecursion(n, k) << endl;

    return 0;
}
