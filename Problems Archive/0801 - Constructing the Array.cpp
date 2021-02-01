#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct compareType {
	bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) const {
		int l1 = p1.second - p1.first + 1, l2 = p2.second - p2.first + 1;
		if (l1 != l2) { return l1 < l2; }
		return p1.first > p2.first;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compareType> pq;
vector<int> res;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; res.resize(n);
		pq.push({ 0, n - 1 }); int i = 1;
		while (i <= n) {
			pair<int, int> p = pq.top(); pq.pop();
			int mid = (p.first + p.second) >> 1; res[mid] = i++;
			if (mid != p.first) { pq.push({ p.first, mid - 1 }); }
			if (mid != p.second) { pq.push({ mid + 1, p.second }); }
		}
		for (auto &x : res) { cout << x << ' '; } cout << endl;
	}
	cin.ignore(2); return 0;
}