#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int r, c; cin >> r >> c;
		res.clear(); res.resize(r << 1 | 1);

		string D(c << 1 | 1, '|');
		string U(c << 1 | 1, '+');
		for (int i = 1; i < (c << 1 | 1); i += 2)
			U[i] = '-', D[i] = '.';

		for (int i = 0; i < (r << 1 | 1); i++)
			res[i] = i & 1 ? D : U;

		res[0][0] = res[0][1] = res[1][0] = '.';

		cout << "Case #" << t << ":\n";
		for (auto& x : res) cout << x << '\n';
	}

	cin.ignore(2); return 0;
}