#include <fstream>
#include <string>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

string s;

int main() {
	ifstream cin("A2.in.txt");
	ofstream cout("A2.out.txt");

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n; cin >> n >> s; ll res = 0; 
		int i = 0; while (i < n && s[i] == 'F') { i++; }
		if (i == n) { cout << "Case #" << t << ": 0\n"; continue; }

		bool O = s[i] == 'O'; int j = i + 1; while (j < n) {
			if (s[j] == 'F') { j++; continue; }
			if (O && s[j] == 'O') { i = j++; continue; }
			if (!O && s[j] == 'X') { i = j++; continue; }
			ll L = i + 1, R = n - j;
			res = (res + L * R) % mod;
			O ^= 1; i = j++;
		}
		cout << "Case #" << t << ": " << res << '\n';
	}

	return 0;
}