#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct comp {
	bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
		if (p1.first == p2.first) { return p1.second > p2.second; }
		return p1.first > p2.first;
	}
};

string s;
priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

bool check(string &res) {
	int m = 0;
	for(int i = s.size() - 1; i >= 0; i--) {
		if (res[i] == '1') { m = s[i] - '0'; break; }
	}
	for (int i = 0; i < (int) s.size(); i++) {
		if (res[i] == '2' && s[i] - '0' < m) { return false; }
		else if (res[i] == '2') { m = s[i] - '0'; }
	}
	return true;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n >> s; string res(n, '2');
		for (int i = 0; i < n; i++) { pq.push({ s[i] - '0', i }); }
		int max_idx1 = -1, lim = -1; bool b = false;
		while (!pq.empty()) {
			int idx = pq.top().second, x = pq.top().first;
			if (b && x != lim) { break; }
			if (idx > max_idx1) { res[idx] = '1'; max_idx1 = idx; }
			else if (!b) { lim = x; b = true; }	pq.pop();
		}
		if (check(res)) { cout << res << endl; }
		else { cout << '-' << endl; }
		while (!pq.empty()) { pq.pop(); }
	}
	cin.ignore(2); return 0;
}