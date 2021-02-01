#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<pair<pair<int, int>, int>> v;

bool compare(const pair<pair<int, int>, int>& p1, const pair<pair<int, int>, int>& p2) {
	if (p1.first.first != p2.first.first) return p1.first.first < p2.first.first;
	return p1.first.second > p2.first.second;
}

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (int i = 0; i < n; i++) { 
			cin >> v[i].first.first >> v[i].first.second;
			v[i].second = i;
		}
		sort(v.begin(), v.end(), compare); 
		int mW = 1 << 30, mWi = -1;
		vector<int> res(n, -1);
		vector<int> minW(n); minW[0] = v[0].first.second;
		vector<int> minWi(n); minWi[0] = v[0].second;

		//for (auto& x : v) cout << x.first.first << ' ' << x.first.second << ' ' << x.second << '\n'; cout << '\n';

		for (int i = 1; i < n; i++) { 
			if (minW[i - 1] <= v[i].first.second) { minW[i] = minW[i - 1]; minWi[i] = minWi[i - 1]; continue; }
			minW[i] = v[i].first.second; minWi[i] = v[i].second;
		}

		//for (int i = 0; i < n; i++) cout << minW[i] << ' ' << minWi[i] << '\n';
		
		for (int i = 0; i < n; i++) {
			if (minW[i] < v[i].first.second) { res[v[i].second] = minWi[i]; continue; }

			pair<pair<int, int>, int> p = { {v[i].first.second, 1 << 30}, -1 };
			auto it = upper_bound(v.begin(), v.end(), p, compare);
			int idx = it - v.begin() - 1; if (idx < 0) { continue; }
			if (minW[idx] < v[i].first.first) { res[v[i].second] = minWi[idx]; }			
		}
		
		for (auto& x : res) cout << x + (x != -1) << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}