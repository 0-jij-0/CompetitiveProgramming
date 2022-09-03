#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, k, r, c; cin >> n >> k >> r >> c;
		res.clear(); res.resize(n, string(n, '.'));

		int ir = --r / k, jc = --c / k;
		int X = ir * k, Y = jc * k;
		for (int a = 0; a < (n / k); a++)
			for (int b = 0; b < (n / k); b++)
				for (int z = 0, i = r - X, j = c - Y; z < k; z++) {
					res[a * k + i][b * k + j] = 'X';
					i = (i + 1) % k; j = (j + 1) % k;
				}
		
		for (auto& x : res) cout << x << '\n';
	}
}