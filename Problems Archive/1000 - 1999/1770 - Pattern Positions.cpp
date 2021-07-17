#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct RMQ {
	vector<vector<int>> rmq;
	vector<int> logb2; RMQ() {}
	RMQ(vector<int> &v) { //O(nlogn) time and space
		int n = (int)v.size(); logb2.resize(n + 1, 0);
		rmq.resize(1, vector<int>(n));
		for (int i = 0; i < n; i++) { rmq[0][i] = v[i]; }

		for (int i = 0; (1 << i) <= n; i++) { logb2[1 << i] = i; } //Precomputing Logs
		for (int i = 1; i <= n; i++) { logb2[i] = max(logb2[i], logb2[i - 1]); }
		rmq.resize(logb2.back() + 1);

		for (int t = 1; t < (int)rmq.size(); t++) {
			rmq[t].resize(n - (1 << t) + 1);
			for (int i = 0; i <= n - (1 << t); i++)
				rmq[t][i] = min(rmq[t - 1][i], rmq[t - 1][i + (1 << (t - 1))]);
		}
	}

	int query(int i, int j) { //O(1)
		if (i > j) { swap(i, j); }
		int k = logb2[j - i + 1];
		return min(rmq[k][i], rmq[k][j - (1 << k) + 1]);
	}
};

void countingSort(vector<int> &p, vector<int> &c) {
	int n = p.size();
	vector<int> cnt(n, 0);
	for (auto &x : c) { cnt[x]++; }

	vector<int> newP(n);
	vector<int> pos(n); pos[0] = 0;
	for (int i = 1; i < n; i++) { pos[i] = pos[i - 1] + cnt[i - 1]; }
	for (auto x : p) {
		int i = c[x];
		newP[pos[i]] = x; pos[i]++;
	}
	p = newP;
}

void suffArray(string s, vector<int> &sufA) {
	s.push_back('#');
	int n = s.size();
	vector<int> p(n), c(n);

	vector<pair<char, int>> a(n);
	for (int i = 0; i < n; i++) { a[i] = { s[i], i }; }
	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++) { p[i] = a[i].second; }
	c[p[0]] = 0;
	for (int i = 1; i < n; i++) {
		if (a[i].first == a[i - 1].first) { c[p[i]] = c[p[i - 1]]; }
		else { c[p[i]] = c[p[i - 1]] + 1; }
	}

	int k = 0;
	while (c[p[n - 1]] != n - 1) {
		for (int i = 0; i < n; i++) { p[i] = (p[i] - (1 << k) + n) % n; }
		countingSort(p, c);

		vector<int> newC(n); newC[p[0]] = 0;
		for (int i = 1; i < n; i++) {
			pair<int, int> prev = { c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n] };
			pair<int, int> now = { c[p[i]], c[(p[i] + (1 << k)) % n] };
			if (prev == now) { newC[p[i]] = newC[p[i - 1]]; }
			else { newC[p[i]] = newC[p[i - 1]] + 1; }
		}

		c = newC; k++;
	}
	sufA = p;
}

int firstSubstr(string &s, string &t, vector<int> &sufA, RMQ &rmq) {
	int firstOcc = -1, lastOcc = -2;

	for (int k = 0; k < 2; k++) {
		int l = 0, r = s.size();
		while (l <= r) {
			int mid = (l + r) >> 1;
			int curS = sufA[mid], curT = 0;

			while (curS < s.size() && curT < t.size()) {
				if (s[curS] == t[curT]) { curS++; curT++; }
				else if (s[curS] > t[curT]) { r = mid - 1; break; }
				else { l = mid + 1; break; }
			}
			if (curT == t.size()) {
				if (!k) { firstOcc = mid; r = mid - 1; }
				else { lastOcc = mid; l = mid + 1; }
			}
			if (curS == s.size()) { l = mid + 1; }
		}
	}
	if (lastOcc < firstOcc) { return -1; }
	return 1 + rmq.query(firstOcc, lastOcc);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int k; string s; cin >> s >> k;
	vector<int> SA; suffArray(s, SA); RMQ rmq(SA);
	while (k--) {
		string t; cin >> t;
		cout << firstSubstr(s, t, SA, rmq) << '\n';
	}

	cin.ignore(2); return 0;
}