#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t; while(t--) {
        int n; string s; cin >> n >> s;
        set<string> st;
        for(int i = 1; i < n; i++)
            st.insert(s.substr(i - 1, 2));
        cout << st.size() << '\n';
    }
}