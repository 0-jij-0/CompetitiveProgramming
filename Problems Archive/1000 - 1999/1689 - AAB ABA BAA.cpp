#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

ll choose[61][61];

int main() {
	for (int i = 0; i < 61; i++)
		choose[i][0] = choose[i][i] = 1;

	for (int i = 2; i < 61; i++) for (int j = 1; j < i; j++)
		choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];

	int a, b; ll k; cin >> a >> b >> k; k--;
	string res = ""; while (a + b != 0) {
		ll cur = choose[a + b - 1][b];
		if (cur > k) { res.push_back('a'); a--; }
		else { res.push_back('b'); b--; k -= cur; }
	}

	cout << res << '\n';
	cin.ignore(2); return 0;
}