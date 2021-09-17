#include <fstream>
#include <string>
using namespace std;

string s;

int main() {
	ifstream cin("A1.in.txt");
	ofstream cout("A1.out.txt");

	int T; cin >> T; 
	for(int t = 1; t <= T; t++) {
		int n; cin >> n >> s; int res = 0, i = 0;
		while (i < n && s[i] == 'F') { i++; }
		if (i == n) { cout << "Case #" << t << ": 0\n"; continue; }
		bool O = s[i] == 'O'; while (i < n) {
			if (s[i] == 'F') { i++; continue; }
			if (O && s[i] == 'O') { i++; continue; }
			if (!O && s[i] == 'X') { i++; continue; }
			res++; O ^= 1; i++;
		}
		cout << "Case #" << t << ": " << res << '\n';
	}

	 return 0;
}