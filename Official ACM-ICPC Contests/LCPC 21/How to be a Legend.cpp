#include <iostream>
#include <string>
using namespace std;

int main() {
	freopen("square.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string n, m; cin >> n >> m; n += m;
	int N = stoi(n); bool square = false;
	for (int i = 0; i * i <= N; i++)
		if (i * i == N) { square = true; break; }

	cout << (square ? "YES" : "NO") << '\n';
	cin.ignore(2); return 0;
}