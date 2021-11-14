#include <iostream>
using namespace std;
typedef long long ll;

ll countSum(int s, int a, int b, int c) {
	int L = max(a, s - c);
	int R = min(b, s - b);
	return max(0, R - L + 1);
}

ll countMax(int s, int c, int d) {
	int L = c, R = min(d, s - 1);
	return max(0, R - L + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b, c, d; cin >> a >> b >> c >> d;
	ll res = 0; for (int s = a + b; s <= b + c; s++)
		res += countSum(s, a, b, c) * countMax(s, c, d);
	cout << res << '\n'; cin.ignore(2); return 0;
}