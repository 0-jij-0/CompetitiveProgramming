#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool operator < (const pair<int, int> &p1, const pair<int, int> &p2) {
	bool b1 = p1.first < p2.first;
	bool b2 = p1.first == p2.first;
	bool b3 = p1.second < p2.second;

	return b1 || (b2 && b3);
}

bool compare(const pair<int, int> &p1, const pair<int, int> &p2) {
	return p1.second < p2.second;
}

vector<pair<int, int>> v;

void remove_dup() {
	sort(v.begin(), v.end());
	vector<pair<int, int>> unique;
	for (unsigned int i = 0; i < v.size() - 1; i++) {
		if (v[i].first != v[i + 1].first) { unique.push_back(v[i]); }
	}
	unique.push_back(v[v.size() - 1]);
	sort(unique.begin(), unique.end(), compare);
	cout << unique.size() << endl;
	for (unsigned int i = 0; i < unique.size(); i++) {
		cout << unique[i].first;
		if (i + 1 != unique.size()) { cout << " "; }
		else { cout << endl; return; }
	}
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		pair<int, int> p(a, i);
		v.push_back(p);
	}
	remove_dup();
	cin.ignore(2); return 0;
}