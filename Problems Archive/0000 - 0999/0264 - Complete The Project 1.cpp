#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> pos, neg;

bool check_pos(int &r) {
	for (auto &x : pos) {
		if (x.first > r) { return false; }
		r += x.second;
	}
	return true;
}

bool compare(const pair<int, int> &p1, const pair<int, int> &p2) {
	return (p1.first + p1.second) < (p2.first + p2.second);
}

bool check_neg(int &r) {
	for (auto &x : neg) {
		x.first = max(x.first, -x.second);
	}
	sort(neg.rbegin(), neg.rend(), compare);
	for (auto &x : neg) {
		if (x.first > r) { return false; }
		r += x.second;
	}
	return true;
}

int main() {
	int n, r; cin >> n >> r;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		pair<int, int>p(a, b);
		((b < 0) ? neg : pos).push_back(p);
	}
	sort(pos.begin(), pos.end());
	sort(neg.rbegin(), neg.rend());
	bool b = check_pos(r);

	if (!b) { cout << "NO" << endl; }
	else {
		b = check_neg(r);
		if (b) { cout << "YES" << endl; }
		else { cout << "NO" << endl; }
	}
	cin.ignore(2); return 0;
}