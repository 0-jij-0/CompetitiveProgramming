#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<pair<int, int>> pairs;

bool operator <(const pair<int, int> &p1, const pair<int, int> &p2){
	return p1.first < p2.first;
}

bool find_pair(int n) {
	unsigned int i = 0;
	int a, b, fixed;
	for (; i < pairs.size(); i++) {
		if (pairs[i].first == n || pairs[i].second == n) { continue; }
		a = pairs[i].first; b = pairs[i].second; break;
	}
	for (; i < pairs.size(); i++) {
		if (pairs[i].first == n || pairs[i].second == n) { continue; }
		if (pairs[i].first == a && pairs[i].second == b) { continue; }
		int a1 = pairs[i].first, b1 = pairs[i].second;
		if (a != a1 && a != b1 && b != a1 && b != b1) { return false; }
		if (a1 == a || b1 == a) { fixed = a; break; }
		fixed = b; break;
	}
	for (; i < pairs.size(); i++) {
		if (pairs[i].first == n || pairs[i].second == n) { continue; }
		if (pairs[i].first == fixed || pairs[i].second == fixed) { continue; }
		return false;
	}
	return true;
}

bool check(int n, int m) {
	if (m == 1) { return true; }
	vector<int> freq; freq.resize(n + 1);
	for (int i = 0; i < m; i++) {
		freq[pairs[i].first]++; freq[pairs[i].second]++;
	}
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i <= n; i++) {
		if (freq[i] > 0) {
			pair<int, int> p(freq[i], i);
			pq.push(p);
		}
	}
	pair<int, int> cand = pq.top(); pq.pop();
	while (cand.first >= ((m + 1) / 2)) {
		if (find_pair(cand.second)) { return true; }
		if (pq.empty()) { break; }
		cand = pq.top(); pq.pop();
	}
	return false;
}

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		int x = (a < b) ? a : b;
		int y = (a < b) ? b : a;
		pair<int, int> p(x, y);
		pairs.push_back(p);
	}
	if (check(n, m)) { cout << "YES" << endl; }
	else { cout << "NO" << endl; }
	return 0;
}