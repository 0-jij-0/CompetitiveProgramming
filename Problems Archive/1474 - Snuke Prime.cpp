#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;
typedef long long ll;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; ll C; cin >> n >> C;
	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		pq.push({ a, c }); pq.push({ b + 1, -c });
	}

	ll res = 0, cur = 0; int last = 0; while (!pq.empty()) {
		ll change = 0; int curDay = pq.top().first;
		res += min(cur, C) * (curDay - last);
		while(!pq.empty() && pq.top().first == curDay) {
			change += pq.top().second; pq.pop();
		}
		cur += change; last = curDay;
	}

	cout << res << '\n';
	cin.ignore(2); return 0;
}