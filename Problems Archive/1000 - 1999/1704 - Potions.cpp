#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

priority_queue<int, vector<int>, greater<int>> pq;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; v.resize(n);
	for (auto& x : v) { cin >> x; }

	int i = 0, res = 0; ll cur = 0; while (i != n) {
		if (v[i] >= 0) { res++; cur += v[i++]; continue; }
		if (cur + v[i] >= 0) { res++; cur += v[i]; pq.push(v[i++]); continue; }
		if (!pq.empty() && v[i] > pq.top()) { cur += v[i] - pq.top(); pq.pop(); pq.push(v[i++]); }
		else { i++; }
	}

	cout << res << '\n'; cin.ignore(2); return 0;
}