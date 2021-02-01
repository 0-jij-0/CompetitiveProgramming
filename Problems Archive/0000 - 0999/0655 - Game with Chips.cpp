#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k; cin >> n >> m >> k;
	bool b = true;
	for (int i = 0; i < 2*k; i++) {
		int x, y; cin >> x >> y;
	}
	string res = string(m - 1, 'L') + string(n - 1, 'U');
	for (int i = 0; i < n; i++) {
		res += b ? string(m - 1, 'R') : string(m - 1, 'L');
		b = !b; if (i + 1 != n) { res.push_back('D'); }
	}
	cout << res.size() << endl << res << endl;
	cin.ignore(2); return 0;
}