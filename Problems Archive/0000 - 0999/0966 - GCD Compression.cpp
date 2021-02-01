#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; n <<= 1;
		vector<int> e, o;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			(x % 2 ? o : e).push_back(i);
		}
		if (o.size() % 2) { o.pop_back(); e.pop_back(); }
		else if (o.size()) { o.pop_back(); o.pop_back(); }
		else { e.pop_back(); e.pop_back(); }
		for (int i = 0; i < (int)e.size(); i += 2)
			cout << e[i] + 1 << ' ' << e[i + 1] + 1 << '\n';
		for (int i = 0; i < (int)o.size(); i += 2)
			cout << o[i] + 1 << ' ' << o[i + 1] + 1 << '\n';
	}
	cin.ignore(2); return 0;
}