#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<char, int>> s;

bool compare(const pair<int, int> &p1, const pair<int, int> &p2) {
	return p1.second < p2.second;
}

int main() {
	int n, k; cin >> n >> k; s.resize(n);
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		s[i] = { c, i };
	}
	sort(s.rbegin(), s.rend());
	for (int i = 0; i < k; i++) { s.pop_back(); }
	sort(s.begin(), s.end(), compare);
	for (auto &x : s) { cout << x.first; }
	cout << endl; cin.ignore(2); return 0;
}