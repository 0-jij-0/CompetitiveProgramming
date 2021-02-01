#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
vector<int> c;

int main() {
	int n; cin >> n; v.resize(n);
	for (int i = 0; i < n; i++) {
		int s; cin >> s; v[i].resize(s);
		for (auto &x : v[i]) { cin >> x; }
	}
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		int j = 0, k = (int) v[i].size() - 1;
		while (j < k) { a += v[i][j]; b += v[i][k]; j++; k--; }
		if (j == k) { c.push_back(v[i][j]); }
	}
	sort(c.rbegin(), c.rend());
	for (int i = 0; i < (int)c.size(); i += 2) { 
		a += c[i]; b += (i+1 != (int)c.size())? c[i + 1] : 0;
	}
	cout << a << ' ' << b << endl;
	cin.ignore(2); return 0;
}