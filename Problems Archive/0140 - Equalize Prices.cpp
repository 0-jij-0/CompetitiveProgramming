#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int n, k; cin >> n >> k;
		v.clear(); int min = 100000001, max = 0;
		for (int j = 0; j < n; j++) { 
			int a; cin >> a; v.push_back(a);
			if (a < min) { min = a; }
			if (a > max) { max = a; }
		}
		if (max - min > 2 * k) { cout << -1 << endl; }
		else { cout << min + k << endl; }
	}
	cin.ignore(2); return 0;
}