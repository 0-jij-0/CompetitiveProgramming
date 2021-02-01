#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<vector<int>> freq;

int main() {
	int t; cin >> t;
	while (t--) {
		v.clear(); freq.clear();
		int n; cin >> n; v.resize(n); freq.resize(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> v[i]; freq[v[i]].push_back(i);
		}
		int res = n + 1;
		for (int i = 1; i <= n; i++) {
			if ((int)freq[i].size() < 2) { continue; }
			for (int j = 1; j < (int)freq[i].size(); j++) 
				res = min(res, freq[i][j] - freq[i][j - 1]);
		}
		cout << (res == n + 1 ? -1 : res + 1) << endl;
	}
	cin.ignore(2); return 0;
}