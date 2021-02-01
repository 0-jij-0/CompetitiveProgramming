#include <iostream>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int x, y; cin >> x >> y;
			res += (x + y != 0);
		}
	cout << res << endl;
	cin.ignore(2); return 0;
}