#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; x %= 2; }
		int s = accumulate(v.begin(), v.end(), 0);
		cout << (s == 0 || s == n ? "YES" : "NO") << endl;
	}
	cin.ignore(2); return 0;
}