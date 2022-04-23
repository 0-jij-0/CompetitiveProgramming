#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b, c, d, e, f, x;
	cin >> a >> b >> c >> d >> e >> f >> x;

	int T = ((x / (a + c)) * a * b) + (min(a, x % (a + c)) * b);
	int A = ((x / (d + f)) * d * e) + (min(d, x % (d + f)) * e);

	cout << (T == A ? "Draw" : (T < A ? "Aoki" : "Takahashi")) << '\n';
	cin.ignore(2); return 0;
}