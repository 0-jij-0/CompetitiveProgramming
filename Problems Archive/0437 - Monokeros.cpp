#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct val {
	int l, r; val() {}
	val(int _l, int _r) : 
		l(_l), r(_r) {}
};

map<int, val> d;
bool compare(int a, int b) { return a > b; }

int main() {
	int n; cin >> n;
	while (n--) {
		int x; cin >> x;
		if (d.empty()) { 
			cout << 1 << ' '; d[x] = val(1, 1); continue;
		}
		auto it = d.lower_bound(x);
		if (it == d.end()) {
			int new_d = d.rbegin()->second.r + 1;
			cout << new_d << ' '; d[x] = val(new_d, new_d);
		}
		else if (it->first == x) {
			int new_d = it->second.l + 1; it->second.l++;
			cout << new_d << ' ';
		}
		else if (it == d.begin()) {
			int new_d = it->second.l + 1; it->second.l++;
			cout << new_d << ' '; d[x] = { new_d, new_d };
		}
		else {
			int new_d = it->second.l + 1; it->second.l++;
			cout << new_d << ' '; d[x] = { new_d, new_d };
		}
	}
	cout << endl; cin.ignore(2); return 0;
}