#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n);
		long long s = 0, xs = 0;
		for (auto &x : v) { cin >> x; s += x; xs ^= x; }
		cout << 2 << endl << xs << ' ' << s + xs << endl;
	}
	cin.ignore(2); return 0;
}