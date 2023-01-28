#include <iostream>
using namespace std;

int lcs(string &s1, string &s2, int i, int j) {
    // base case
    if ( (s1[i] == '\0') || (s2[j] == '\0') ) {
        return 0;
    }

    // recursive case
    if ( s1[i] == s2[j] ) {
        return 1 + lcs(s1, s2, i+1, j+1);
    }
    else {
        return max( lcs(s1, s2, i+1, j), lcs(s1, s2, i, j+1) );
    }

}

int main(void) {
    string s1 = "ABCD";
    string s2 = "ABEDG";

    cout << lcs(s1, s2, 0, 0) << endl;

    return 0;
}