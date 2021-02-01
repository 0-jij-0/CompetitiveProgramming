#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
string str; ll r;
int nb, ns, nc;
int pb, ps, pc;

int b, s, c;

bool check(ll x) {
	ll bp = max(0ll, x*b - nb) * pb;
	ll bs = max(0ll, x*s - ns) * ps;
	ll bc = max(0ll, x*c - nc) * pc;

	return bp + bs + bc <= r;
}

ll find_max() {
	ll left = 0, right = nb + ns + nc + r;
	while (left != right) {
		ll mid = (left + right + 1) >> 1;
		bool b = check(mid);
		b ? left = mid : right = mid - 1;
	}
	return left;
}

int main() {
	cin >> str; b = s = c = 0;
	for (char &x : str) {
		if (x == 'B') { b++; continue; }
		if (x == 'S') { s++; continue; }
		if (x == 'C') { c++; continue; }
	}
	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;
	cin >> r;

	cout << find_max() << endl;
	cin.ignore(2); return 0;
}