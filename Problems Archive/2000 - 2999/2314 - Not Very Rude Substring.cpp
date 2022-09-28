#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; ll c; cin >> n >> c >> s;

	int res = 0, a = 0, b = 0; ll cur = 0;
	auto cont = [&](int j, int &a, int &b) {
		if (s[j] == 'a') { ++a; return 0; }
		if (s[j] == 'b') { ++b; return a; }
		return 0;
	};

	for (int i = 0, j = 0; i < n; i++) {
		while (j < n) { 
			int add = cont(j, a, b);
			if (cur + add > c) { --b; break; }
			cur += add; ++j;
		}
		res = max(res, j - i);
		s[i] == 'a' ? cur -= b, --a : s[i] == 'b' ? --b : 0;
	}

	cout << res << '\n';
}