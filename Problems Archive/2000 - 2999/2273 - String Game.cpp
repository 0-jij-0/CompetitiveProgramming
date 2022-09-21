#include <iostream>
#include <string>
#include <vector>
using namespace std;

string t, p; vector<int> v;

bool check(int M) {
	vector<int> off(t.size());
	for (int i = 0; i < M; i++) off[v[i]] = 1;

	int i = 0, n = (int)t.size();
	int j = 0, m = (int)p.size();
	while (i < n && j < m) {
		if (off[i] || t[i] != p[j]) { i++; }
		else { i++; j++; }
	}

	return j == m;
}

int maxNumLetters() {
	int L = 0, R = (int)v.size() - 1;
	while (L != R) {
		int M = (L + R + 1) >> 1;
		check(M) ? L = M : R = M - 1;
	}
	return L;
}

int main() {
	cin >> t >> p; v.resize(t.size());
	for (auto& x : v) { cin >> x; --x; }
	cout << maxNumLetters() << '\n';
}