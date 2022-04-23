#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, r, b; cin >> n >> r >> b;
		string res(n, 'R');

		int gap = r / (b + 1), rem = r % (b + 1);
		for (int i = gap + (rem > 0); i < n; i += gap + 1 + (rem > 0), rem--)
			res[i] = 'B';
		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}