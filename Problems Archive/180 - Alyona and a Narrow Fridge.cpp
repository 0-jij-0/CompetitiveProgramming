#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int n, h;

bool compare(const pair<int, int> &p1, const pair<int, int> &p2) {
	bool b1 = p1.first > p2.first;
	bool b2 = p1.first == p2.first;
	bool b3 = p1.second < p2.second;
	return b1 || (b2 && b3);
}

bool check(int k) {
	int r = h; int c = 0; bool new_shelf = true;
	for (int i = 0; i < n; i++) {
		if (c >= k) { return true; }
		if (v[i].second >= k) { continue; }
		if (new_shelf && v[i].first > r) { return false; }
		c++; if (new_shelf) { r -= v[i].first; }
		new_shelf = !new_shelf;
	}
	return c >= k;
}

int find_k(int low, int high) {
	if (low == high) { return low; }
	int mid = (low + high + 1) / 2;
	bool b = check(mid);
	if (b) { return find_k(mid, high); }
	return find_k(low, mid - 1);
}

int main() {
	cin >> n >> h;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		pair<int, int> p(a, i);
		v.push_back(p);
	}
	sort(v.begin(), v.end(), compare);
	cout << find_k(0, n) << endl;
	cin.ignore(2); return 0;
}