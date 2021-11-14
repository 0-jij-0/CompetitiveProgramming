#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n >> s;

		bool two = false;
		for (int i = 1; i < n && !two; i++)
			if (s[i] == 'a' && s[i - 1] == 'a') two = true;
		if (two) { cout << 2 << '\n'; continue; }

		bool three = false;
		for (int i = 2; i < n && !three; i++)
			if (s[i] == 'a' && s[i - 2] == 'a') three = true;
		if (three) { cout << 3 << '\n'; continue; }

		bool four = false;
		for (int i = 3; i < n && !four; i++)
			if (s[i] == 'a' && s[i - 3] == 'a' && s[i - 1] != s[i - 2]) four = true;
		if (four) { cout << 4 << '\n'; continue; }

		bool seven = false;
		for (int i = 6; i < n && !seven; i++)
			if (s[i] == 'a' && s[i - 6] == 'a' && s[i - 3] == 'a')
				if (s[i - 1] != s[i - 5]) seven = true;
		if (seven) { cout << 7 << '\n'; continue; }

		cout << -1 << '\n';
	}
	cin.ignore(2); return 0;
}