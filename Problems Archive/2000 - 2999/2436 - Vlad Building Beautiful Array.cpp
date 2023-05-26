#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<int> A;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t; while(t--) {
        int n; cin >> n; A.resize(n);
        for(auto &x : A) cin >> x;

        if(!count_if(A.begin(), A.end(), [&](int x){return abs(x - A[0]) & 1;})){
            cout << "YES\n"; continue;
        }

        sort(A.begin(), A.end());
        cout << (A[0] & 1 ? "YES" : "NO") << '\n';
    }
}