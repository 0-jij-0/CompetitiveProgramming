#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	v.resize(10); for (auto& x : v) cin >> x;

	int a = 0; while (a < 10 && v[a] == "..........") { a++; }
	int b = a; while (b < 10 && v[b] != "..........") { b++; }
	int c = 0; while (c < 10 && v[a][c] == '.') { c++; }
	int d = c; while (d < 10 && v[a][d] == '#') { d++; }

	cout << a + 1 << ' ' << b << '\n' << c + 1 << ' ' << d << '\n';
}
