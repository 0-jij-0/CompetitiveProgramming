#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	freopen("elevator.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; int x; cin >> s >> x; x--;
	vector<string> v = { "123", "456", "789" };
	int i = x / 3, j = x % 3; for (char& c : s) {
		if (c == 'U') { i = (i + 1) % 3; }
		if (c == 'D') { i = (i + 2) % 3; }
		if (c == 'L') { j = (j + 2) % 3; }
		if (c == 'R') { j = (j + 1) % 3; }
	}
	cout << v[i][j] << '\n';
	cin.ignore(2); return 0;
}