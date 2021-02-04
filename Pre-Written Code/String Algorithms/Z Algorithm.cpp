#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

//Returns the array Z where Z[i] = length of max substring starting at i equal to a prefix (for i > 0)
//O(n)
vector<int> ZAlgo(string& s) {
    int n = s.size();
    vector<int> z(n, 0);
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R - L] == s[R]) { R++; }
            z[i] = R - L; R--;
        }
        else {
            int k = i - L;
            if (z[k] < R - i + 1) { z[i] = z[k]; continue; }
            L = i;
            while (R < n && s[R - L] == s[R]) { R++; }
            z[i] = R - L; R--;
        }
    }
    return move(z);
}