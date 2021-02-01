#include <iostream>
#include <vector>
using namespace std;

vector<int> p;

int main() {
	int n, s, t; cin >> n >> s >> t; s--; t--;
	p.resize(n); for (auto &x : p) { cin >> x; x--; }
	int i = 1; int S = p[s];
	while (S != s) {
		if (S == t) { break; }
		i++; S = p[S];
	}
	if (s == t) { cout << 0 << endl; }
	else if (S == s) { cout << -1 << endl; }
	else { cout << i << endl; }
	cin.ignore(2); return 0;
}