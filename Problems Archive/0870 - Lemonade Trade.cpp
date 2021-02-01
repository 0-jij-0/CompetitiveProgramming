#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <iomanip>
using namespace std;

map<string, double> m;
bool ten = false;

int main() {
	int n; cin >> n; m["pink"] = 0.0; m["blue"] = -1e14;
	for (int i = 0; i < n; i++) {
		string o, w; double r; cin >> o >> w >> r;
		if (!m.count(w)) { m[w] = -1e14; }
		if (!m.count(o)) { m[o] = -1e14; }
		double ans = m[w] + log2(r);
		m[o] = max(ans, m[o]);
	}
	m["blue"] = min(m["blue"], log2(10));
	cout << fixed << setprecision(6) << pow(2.0, m["blue"]) << endl;
	cin.ignore(2); return 0;
}