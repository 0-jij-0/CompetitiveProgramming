#include <iostream>
#include <string>
#include <stack>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000;

string s;

pair<ll, ll> decodePath(int l, int r) {
	ll dx = 0, dy = 0; int i = l, j = l;
	while (j != r + 1) {
		while (i < r + 1 && s[i] > '9') {
			if (s[i] == 'N') { dy = (dy - 1 + mod) % mod; }
			if (s[i] == 'S') { dy = (dy + 1) % mod; }
			if (s[i] == 'W') { dx = (dx - 1 + mod) % mod; }
			if (s[i] == 'E') { dx = (dx + 1) % mod; }
			j = i = i + 1;
		}
		if (i == r + 1) { break; }
		int f = s[i] - '0'; j = i + 2; int d = 1;
		while (d) {
			if (s[j] == '(') { d++; j++; continue; }
			if (s[j] == ')') { d--; j++; continue; }
			j++;
		}
		pair<ll, ll> p = decodePath(i + 2, j - 2);
		dx = (dx + f*p.first) % mod;
		dy = (dy + f*p.second) % mod;
		i = j;
	}
	return { dx, dy };
}

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> s;
		pair<ll, ll> p = decodePath(0, (int)s.size() - 1);
		cout << "Case #" << t << ": ";
		cout << p.first + 1 << ' ';
		cout << p.second + 1 << '\n';
	}
	cin.ignore(2); return 0;
}