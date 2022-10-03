#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//Z[i] = length of max substring starting at i equal to a prefix (for i > 0) in O(n)
vector<int> zFunction(const string& s) {
    int n = (int)s.size(); vector<int> Z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) Z[i] = min(r - i + 1, Z[i - l]);
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) ++Z[i];
        if (i + Z[i] - 1 > r) l = i, r = i + Z[i] - 1;
    }
    return Z;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

}