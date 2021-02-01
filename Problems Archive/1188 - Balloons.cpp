#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; int res = 0;
		while (n--) { int x; cin >> x; res += (x != 0); }
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}