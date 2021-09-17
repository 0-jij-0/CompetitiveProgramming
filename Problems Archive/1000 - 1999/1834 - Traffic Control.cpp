#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> res;

void solveV(int n, int m, int a, int b) {
	for (int i = 0; i < m; i++) { res[0][i] = 1; }
	for (int i = 0; i < n; i++) { res[i][m - 1] = 1; }
	for (int i = 0; i < m; i++) { res[n - 1][i] = 1; }

	res[0][0] = a - (n + m - 2);
	res[n - 1][0] = b - (n + m - 2);
}

void solveH(int n, int m, int a, int b) {
	for (int i = 0; i < n; i++) { res[i][0] = 1; }
	for (int i = 0; i < m; i++) { res[n - 1][i] = 1; }
	for (int i = 0; i < n; i++) { res[i][m - 1] = 1; }

	res[0][0] = a - (n + m - 2);
	res[0][m - 1] = b - (n + m - 2);
}

int main() {
	ifstream cin("B.in.txt");
	ofstream cout("B.out.txt");

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, m, a, b; cin >> n >> m >> a >> b; 
		res.clear(); res.resize(n, vector<int>(m, 1000));
		cout << "Case #" << t << ": ";
		if (min(a, b) < n + m - 1) { cout << "Impossible\n"; continue; }

		if (n > 2 || m > 2) {
			(n > 2 ? solveV : solveH)(n, m, a, b); cout << "Possible\n";
			for (auto& x : res) { for (auto& y : x) cout << y << ' '; cout << '\n'; }
		}
		else {
			bool ok = false;
			for(int x = 1; x <= a && !ok; x++)
				for (int y = 1; y <= b; y++) {
					res[0][0] = x; res[1][1] = y; res[0][1] = (a - x - y); 
					res[1][0] = b - min(x, y) - res[0][1];
					if (res[0][1] <= 0 || res[1][0] <= 0) { continue; }
					if (res[1][0] + x + y >= a) { ok = true; break; }
				}
			if (!ok) { cout << "Impossible\n"; continue; }
			cout << "Possible\n";
			for (auto& x : res) { for (auto& y : x) cout << y << ' '; cout << '\n'; }
		}
	}
	return 0;
}