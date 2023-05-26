#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;
 
vector<int> v;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
 
    int t; cin >> t; while(t--) {
        int n; cin >> n; v.resize(n);
        for(auto &x : v) {cin >> x; --x;}
 
        vector<int> vis(n, 0); int res = 0;
        for(int i = 0; i < n; i++) 
            if(v[i] != i && !vis[i]){
                vector<int> cycle(1, i);
                vis[i] = true; int j = i;
                while(!vis[v[j]]){
                    cycle.push_back(j = v[j]); 
                    vis[j] = true;
                }
                sort(cycle.begin(), cycle.end());
                int g = 0; for(j = 1; j < (int)cycle.size(); ++j)
                    g = gcd(g, cycle[j] - cycle[j - 1]);
                res = gcd(res, g);
            }
        cout << res << endl;
    }
}