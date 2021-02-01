#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;
typedef double ld;
const ld EPS = 1e-10;

vector<int> v;

int main() {
	int t; cin >> t; while (t--) {
		int n, l; cin >> n >> l; v.resize(n);
		for (auto &x : v) { cin >> x; }
		ld first = 0.0, second = l - v.back();
		int speedA = 1, speedB = 2;
		for (int i = n - 2; i >= 0; i--)
			second += (v[i + 1] - v[i] + 0.0) / (0.0 + speedB++);

		ld res = 0.0; for (int i = 0; i < n; i++) {
			int distA = i ? v[i] - v[i - 1] : v[i];
			int distB = i == n - 1 ? l - v.back() : v[i + 1] - v[i];
			ld dif = first + (distA + 0.0) / (speedA + 0.0) - second;
			if (dif < EPS) {
				first += (distA + 0.0) / (speedA + 0.0);
				second -= (distB + 0.0) / (speedB - 1.0); 
				speedA++; speedB--; continue;
			}
			ld xA = (i ? v[i - 1] : 0) + (second - first) * speedA;
			res = second + (v[i] - xA) / (speedA + speedB + 0.0); break;
		}
		if (res < EPS) {
			ld xB = l - first;
			res = first + (xB - v.back()) / (n + 2.0);
		}
		cout << fixed << setprecision(10) << res << '\n';
	}
	cin.ignore(2); return 0;
}