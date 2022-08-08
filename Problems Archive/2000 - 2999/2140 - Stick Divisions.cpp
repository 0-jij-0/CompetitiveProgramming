#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int x, n; cin >> x >> n; while (n--) {
		int d; cin >> d; pq.push(d);
	}

	ll res = 0; while (pq.size() > 1) {
		int f = pq.top(); pq.pop();
		int s = pq.top(); pq.pop();
		res += f + s; pq.push(f + s);
	}

	cout << res << '\n';
}