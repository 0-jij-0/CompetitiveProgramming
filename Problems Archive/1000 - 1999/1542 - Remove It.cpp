#include <iostream>
#include <vector>
using namespace std;

vector<int> v, res;

int main() {
	int n, x; cin >> n >> x;
	for (int i = 0; i < n; i++) {
		int y; cin >> y;
		if (y != x) v.push_back(y);
	}
	for (auto& x : v) cout << x << ' '; cout << '\n';
	cin.ignore(2); return 0;
}