#include <iostream>
using namespace std;

bool query(int x) {
	cout << x << endl;
	int r; cin >> r;
	return r;
}

int main() {
	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k;
		if (query(0)) { continue; }

		for (int i = 1; i < n; i++)
			if (query(i ^ (i - 1))) break;
	}
}