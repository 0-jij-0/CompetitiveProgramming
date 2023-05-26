#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<int> P;

vector<int> operation(int L, int R){
    vector<int> res;
    res.insert(res.end(), P.begin() + R, P.end());
    size_t s = res.size();
    res.insert(res.end(), P.begin() + L, P.begin() + R);
    reverse(res.begin() + s, res.end());
    res.insert(res.end(), P.begin(), P.begin() + L);
    return res;
}

bool isSmaller(const vector<int> &A, const vector<int> & B){
    for(size_t i = 0; i < A.size(); ++i){
        if(A[i] < B[i]) return true;
        if(A[i] > B[i]) return false;
    }
    return false;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t; while(t--) {
        int n; cin >> n; P.resize(n);
        for(auto &x : P) cin >> x;

        int ma = max_element(P.begin(), P.end()) - P.begin();
        if (ma == 0) ma = max_element(P.begin() + 1, P.end()) - P.begin();
        vector<int> res = ma == n - 1 ? operation(ma, ma + 1) : operation(0, ma);
        for(int i = 0; i < ma; i++)
            if(vector<int> temp = operation(i, ma); isSmaller(res, temp)){
                res = move(temp);
            }

        for(auto &x : res) cout << x << ' '; cout << endl;
    }
}