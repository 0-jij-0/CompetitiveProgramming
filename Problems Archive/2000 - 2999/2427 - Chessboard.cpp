#include <bits/stdc++.h>
using namespace std;

vector<string> v;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	v.resize(8); for (auto& x : v) cin >> x;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (v[i][j] == '*')
				cout << char(j + 'a') << 8 - i << '\n';
}