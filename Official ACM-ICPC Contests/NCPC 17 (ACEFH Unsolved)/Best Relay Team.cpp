#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<pair<double, string>> v1, v2, v;

int check(int i) {
	for (int j = 0; j < 8; j++) {
		if (j == i) { continue; }
		if (v[j].second == v[i].second) { return j; }
	}
	return -1;
}

int main() {
	int n; cin >> n; v1.resize(n); v2.resize(n);
	for (int i = 0; i < n; i++) {
		string s; double a, b; cin >> s >> a >> b;
		v1[i] = { a, s }; v2[i] = { b, s };
	}
	sort(v1.begin(), v1.end()); sort(v2.begin(), v2.end());
	for (int i = 0; i < 4; i++)
		v.push_back(v1[i]);
	for (int i = 0; i < 4; i++)
		v.push_back(v2[i]);

	int min_idx = 0; double m = v1.back().first * 4;
	for (int i = 0; i < 4; i++) {
		int idx = check(i);	double a;
		if (idx == -1) { a = v[i].first + v[4].first + v[5].first + v[6].first; }
		else {a = v[i].first + v[4].first + v[5].first + v[6].first + v[7].first - v[idx].first; }
		if (a < m) { m = a; min_idx = i; }
	}
	cout << m << endl << v[min_idx].second << endl;
	int idx = check(min_idx); bool b = idx == -1;
	for (int i = 4; i < 8 - b; i++)
		if (i != idx) { cout << v[i].second << endl; }
	cin.ignore(2); return 0;
}