#include <iostream>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m;
		int res = 0; while (n--) {
			int h1, h2, m1, m2; char c; 
			cin >> h1 >> c >> m1 >> h2 >> c >> m2;
			res += (h2 - h1) * 60 + m2 - m1;
		}
		cout << (res >= 60 * m ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}