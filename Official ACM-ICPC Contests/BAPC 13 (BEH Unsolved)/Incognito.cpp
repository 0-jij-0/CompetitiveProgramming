#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
typedef long long ll;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	int t; cin >> t;
 
	while (t--) {
		int n; cin >> n;
		if (n == 0) { cout << 0 << '\n'; continue; }
 
		map<string, int> dis;
		for (int i = 0; i < n; i++) {
			string name, att; cin >> name >> att;
			dis[att]++;
		}
		ll res = 1;
		for (auto &p : dis) { res *= (p.second + 1); }
		cout << res - 1 << '\n';
	}
}