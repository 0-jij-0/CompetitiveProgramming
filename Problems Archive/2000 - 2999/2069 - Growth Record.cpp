#include <iostream>
using namespace std;

int main() {
	int n, m, x, t, d; cin >> n >> m >> x >> t >> d;
	if (m >= x) { cout << t << '\n'; }
	else { cout << t - (x - m) * d << '\n'; }
}