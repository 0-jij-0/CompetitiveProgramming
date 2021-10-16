#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> X, Y;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n; cin >> n; X.clear(); Y.clear();
		for (int i = 0; i < n; i++) {
			int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
			X.emplace_back(x1); X.emplace_back(x2);
			Y.emplace_back(y1); Y.emplace_back(y2);
		}
		sort(X.begin(), X.end()); sort(Y.begin(), Y.end());
		cout << "Case #" << t << ": " << X[n - 1] << ' ' << Y[n - 1] << '\n';
	}
	cin.ignore(2); return 0;
}