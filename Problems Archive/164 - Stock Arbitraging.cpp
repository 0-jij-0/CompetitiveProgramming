#include <iostream>
using namespace std;

int main() {
	int n, m, r; cin >> n >> m >> r;
	int min_s = 1000, max_b = 0;
	for (int i = 0; i < n; i++) {
		int s; cin >> s;
		if (s < min_s) { min_s = s; }
	}
	for (int i = 0; i < m; i++) {
		int b; cin >> b;
		if (b > max_b) { max_b = b; }
	}
	if (min_s >= max_b) { cout << r << endl; }
	else {
		int sr = r / min_s;
		cout << (r % min_s) + sr * max_b << endl;
	}
	cin.ignore(2); return 0;
}