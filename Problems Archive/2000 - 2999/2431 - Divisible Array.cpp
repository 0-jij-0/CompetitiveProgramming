#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

/*
N

2 4 6 8 .. 2N
*/
int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t; while(t--) {
        int n; cin >> n;
        for(int i = 1; i <= n; i++){
            cout << (i << 1) << ' ';
        }
        cout << '\n';
    }
}