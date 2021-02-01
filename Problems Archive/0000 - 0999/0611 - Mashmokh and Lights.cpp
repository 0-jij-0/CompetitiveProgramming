#include <iostream>
#include <vector>
using namespace std;

vector<int> res;

int main() {
	int n, m; cin >> n >> m;
	res.resize(n); int on = n;
	for (int i = 0; i < m; i++) {
		int b; cin >> b; if (b > on) { continue; }
		while (on >= b) { res[on - 1] = b; on--; }
	}
	for (auto &x : res) { cout << x << ' '; }
	cout << endl; cin.ignore(2); return 0;
}