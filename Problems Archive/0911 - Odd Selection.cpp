#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
		v.resize(n); int e = 0, o = 0; bool b = false;
		for (auto &y : v) { cin >> y; (y % 2 ? o : e)++; }
		if (o == 0) { cout << "No" << endl; continue; }
		if (e == 0 && x % 2 == 0) { cout << "No" << endl; continue; }
		if (o % 2 == 0) { o--; }
		cout << ((o + e) >= x ? "Yes" : "No") << endl;
	}
	cin.ignore(2); return 0;
}