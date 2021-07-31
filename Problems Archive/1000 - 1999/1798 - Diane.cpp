#include <iostream>
#include <string>
using namespace std;

string edges = "abcdefghijklmnopqrstuvwxyz";

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; int h = n / 2;
		if (n <= 26) { cout << edges.substr(0, n) << '\n'; continue; }
		string left = string(h, 'a'), right = string(h - 1, 'a');
		cout << left + (n & 1 ? "bc" : "b") + right << '\n';
	}
	cin.ignore(2); return 0;
}