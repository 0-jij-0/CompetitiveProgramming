#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k; v.resize(n);
	for (auto& x : v) cin >> x;

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < k; i++) pq.push(v[i]);
	cout << pq.top() << '\n';

	for (int i = k; i < n; i++) {
		if (v[i] > pq.top()) { pq.pop(); pq.push(v[i]); }
		cout << pq.top() << '\n';
	}

	cin.ignore(2); return 0;
}