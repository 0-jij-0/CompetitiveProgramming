#include <iostream>
#include <map>
using namespace std;

map<int, int> m;

int main() {
	int n, t; cin >> n >> t;
	for (int i = 0; i < n; i++) {
		int s, d; cin >> s >> d;
		if (s >= t) { m.insert({ s, i }); continue; }
		int x = (t - s) / d; s += x * d;
		while (s < t) { s += d; }
		m.insert({ s, i });
	}
	cout << m.lower_bound(t)->second + 1 << endl;
	cin.ignore(2); return 0;
}