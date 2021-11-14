#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, s; cin >> n >> s;
	if (s < (n << 1)) { cout << "NO\n"; return 0; }
	cout << "YES" << '\n'; int N = n - 1;
	while (N--) cout << 1 << ' ';
	cout << s - n + 1 << '\n' << n << '\n';
	cin.ignore(2); return 0;
}