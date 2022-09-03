#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> v = { {6}, {3}, {7, 1}, {4, 0}, {8, 2}, {5}, {9} };

bool standing(int i, string &s) {
	for (auto& x : v[i]) if (s[x] == '1') return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	string s; cin >> s;
	int i = 0; while (i < 7 && !standing(i, s)) { i++; }
	int j = 6; while (j > i && !standing(j, s)) { j--; }

	bool ok = false;
	for(int k = i + 1; k < j; k++)
		if (!standing(k, s)) { ok = true; break; }

	cout << (ok && s[0] == '0' ? "Yes" : "No") << '\n';
}