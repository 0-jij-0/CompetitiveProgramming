#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> v, sufMax, winMax, winSum;

vector<ll> slidingWindowMax(int k) {
	deque<ll> dq; vector<ll> res;
	for (int i = 0; i < k; i++) {
		while (!dq.empty() && v[i] > dq.back()) { dq.pop_back(); }
		dq.push_back(v[i]);
	}
	res.push_back(dq.front());
	for (int i = k; i < (int)v.size(); i++) {
		if (dq.front() == v[i - k]) { dq.pop_front(); }
		while (!dq.empty() && v[i] > dq.back()) { dq.pop_back(); }
		dq.push_back(v[i]); res.push_back(dq.front());
	}
	return res;
}

int main() {
	int n, a, b; cin >> n >> a >> b;
	v.resize(n); sufMax.resize(n);
	for (auto &x : v) { cin >> x; }
	partial_sum(v.begin(), v.end(), v.begin());
	sufMax.back() = v.back();
	for (int i = n - 2; i >= 0; i--)
		sufMax[i] = max(v[i], sufMax[i + 1]);
	winMax = slidingWindowMax(b - a + 1);

	int j = a; ll res = winMax[j - 1];
	for(; j < n - (b - a + 1); j++)
		res = max(res, winMax[j] - v[j - a]);
	for (; j < n; j++)
		res = max(res, sufMax[j] - v[j - a]);
	cout << res << '\n';
}