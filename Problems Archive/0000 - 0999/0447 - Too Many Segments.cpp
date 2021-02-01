#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>
using namespace std;

struct Segment { 
	int l, r; Segment() {}
	bool operator < (const Segment &rhs) const{
		pair<int, int> p1(l, r), p2(rhs.l, rhs.r);
		return p1 < p2;
	}
};

vector<int> v;
vector<pair<Segment, int>> seg;

int main() {
	int n, k; cin >> n >> k; int i = 1;
	v.resize(200002); seg.resize(n);
	for (auto &x : seg) {
		cin >> x.first.l >> x.first.r; x.second = i;
		v[x.first.l]++; v[x.first.r + 1]--; i++;
	}
	partial_sum(v.begin(), v.end(), v.begin());
	sort(seg.begin(), seg.end()); int j = 0;
	vector<int> dec(200002, 0); int pref = 0;
	vector<int> res;
	priority_queue<pair<int, int>> pq;
	for (int i = 1; i <= 200000; i++) {
		pref += dec[i - 1]; v[i] += pref;
		if (v[i] <= k) { continue; }
		int r = v[i] - k;
		for (; j < n; j++)
			if (seg[j].first.r >= i) { break; }
		while (j < n && seg[j].first.l <= i) {
			pq.push({ seg[j].first.r, seg[j].second }); j++;
		}
		dec[i] -= r; while (r--) { dec[pq.top().first]++; res.push_back(pq.top().second); pq.pop(); }
	}
	cout << res.size() << endl;
	for (auto &x : res) { cout << x << ' '; }
	cout << endl; cin.ignore(2); return 0;
}