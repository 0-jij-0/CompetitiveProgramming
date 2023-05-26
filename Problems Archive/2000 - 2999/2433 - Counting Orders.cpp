#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

vector<int> A, B;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t; while(t--) {
        int n; cin >> n; 
        A.resize(n); for(auto &x : A) cin >> x;
        B.resize(n); for(auto &x : B) cin >> x;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        for(auto &x : A)
            x = lower_bound(B.begin(), B.end(), x) - B.begin();

        int i = n - 1; ll res = 1;
        for(int j = n - 1; j >= 0; j--){
            while(i >= 0 && A[i] > j){--i;}
            if(i > j){ res = 0; }
            res = (res * (j - i)) % mod;
        }
        cout << res << '\n';
    }
}