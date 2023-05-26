#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<int> A, B;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t; while(t--) {
        int n, k; cin >> n >> k;
        A.resize(n); for(auto &x : A) cin >> x;
        B.resize(n); for(auto &x : B) cin >> x;

        multiset<int> sB(B.begin(), B.end());
        vector<int> idx(n); iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int &i, int &j){return A[i] < A[j];});

        for(int i = 0; i < n; i++){
            auto it = sB.lower_bound(A[idx[i]] - k);
            A[idx[i]] = *it; sB.erase(it);
        }

        for(auto &x : A) cout << x << ' '; cout << '\n';
    }
}