#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> v;
priority_queue<int> pq;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x.first >> x.second; }
	int e = 0, res = 0, prev = 0;
	for (int i = 0; i < n; i++) {
		e += v[i].first - prev;
		prev = v[i].first; pq.push(v[i].second);
		if (e < v[i].second) { e += pq.top(); pq.pop(); res++; }
		e -= v[i].second;
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}