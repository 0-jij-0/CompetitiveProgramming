#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> smallRes = {"", "", "-1", "-1", "2 4 1 3", "2 4 1 3 5", "2 4 6 3 5 1", "2 4 6 3 7 5 1"};

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n < 8) { cout << smallRes[n] << endl; continue; }
		int x = 2; while (x + 2 <= n) { cout << x << ' '; x += 2; }
		if (x == n) {
			cout << x << ' ' << x - 3 << ' ' << x - 1 << ' ';
			x -= 5; while (x >= 1) { cout << x << ' '; x -= 2; }
			cout << endl; continue;
		}
		else {
			cout << x << ' ' << x - 3 << ' ' << x + 1 << ' ' << x - 1 << ' ';
			x -= 5; while (x >= 1) { cout << x << ' '; x -= 2; }
			cout << endl; continue;
		}
	}
	cin.ignore(2); return 0;
}