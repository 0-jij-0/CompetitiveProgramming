#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000 * 1000 * 1000;

vector<int> ver, hor;

int main() {
	int n, m; cin >> n >> m; ver.resize(n);
	for (auto &x : ver) { cin >> x; }
	sort(ver.begin(), ver.end()); ver.push_back(INF);
	for (int i = 0; i < m; i++) {
		int x1, x2, y; cin >> x1 >> x2 >> y;
		if (x1 == 1) hor.push_back(x2);
	}
	sort(hor.begin(), hor.end()); m = (int)hor.size();
	int j = 0, res = n + m; for (int i = 0; i <= n; i++) {
		while (j != m && hor[j] < ver[i]) { j++; }
		res = min(res, i + m - j);
	}
	cout << res << '\n';
	cin.ignore(2); return 0;
}