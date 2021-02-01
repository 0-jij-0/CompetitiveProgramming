#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> v, minD, maxD;
priority_queue<pair<int, int>> pq;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k; 
		v.resize(n); minD.clear(), maxD.clear();
		for (auto &x : v) { cin >> x; }
		vector<int> freq(2 * k + 1, 0);
		int i = 0, j = n - 1;
		while (i < j) { 
			maxD.push_back(max(v[i], v[j]) + k);
			minD.push_back(min(v[i], v[j]) + 1);
			freq[v[i] + v[j]]++; i++; j--;
		}
		for (int i = 0; i <= 2 * k; i++) 
			if (freq[i]) { pq.push({ freq[i], i }); }

		sort(minD.begin(), minD.end());
		sort(maxD.begin(), maxD.end());
		int res = n;
		while (!pq.empty()) {
			pair<int, int> p = pq.top(); pq.pop();
			int x = n / 2 - p.first;
			x += lower_bound(maxD.begin(), maxD.end(), p.second) - maxD.begin();
			x += minD.size() - (upper_bound(minD.begin(), minD.end(), p.second) - minD.begin());
			res = min(res, x);
		}
		cout << min(res, n/2) << endl;
	}
	cin.ignore(2); return 0;
}