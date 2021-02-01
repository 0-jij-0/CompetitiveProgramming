#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool operator < (const pair<int, int> &p1, const pair<int, int> &p2) {
	return p1.first < p2.first;
}

priority_queue<pair<int, int>> pq;
vector<int> v;
vector<vector<int>> quarrel;

void add_quarrel(int i, int j) {
	if (v[i] == v[j]) { return; }
	int max = (v[i] > v[j]) ? i : j;
	int min = (v[i] > v[j]) ? j : i;
	quarrel[max].push_back(min);
}

void mentors(int n) {
	vector<int> res; res.resize(n);
	while (!pq.empty()) {
		vector<pair<int, int>> same;
		same.push_back(pq.top()); pq.pop();
		while (!pq.empty() && same.back().first == pq.top().first) {
			same.push_back(pq.top()); pq.pop();
		}
		for (unsigned int i = 0; i < same.size(); i++) {
			int &idx = same[i].second;
			res[idx] = pq.size() - quarrel[idx].size();
		}
	}
	for (int i = 0; i < n; i++) {
		cout << res[i];
		if (i + 1 != n) { cout << " "; }
		else { cout << endl; return; }
	}
}

int main() {
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		pair<int, int> p(a, i);
		v.push_back(a);
		pq.push(p);
	}
	quarrel.resize(n);
	for (int i = 0; i < k; i++) {
		int x, y; cin >> x >> y;
		add_quarrel(x - 1, y - 1);
	}
	mentors(n);
	cin.ignore(2); return 0;
}

