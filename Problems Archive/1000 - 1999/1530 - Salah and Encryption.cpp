#include <iostream>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int k; char c; cin >> k >> c;
	int e = (c - 'a' + k) % 26;
	cout << (char)(e + 'a') << '\n';
	cin.ignore(2); return 0;
}