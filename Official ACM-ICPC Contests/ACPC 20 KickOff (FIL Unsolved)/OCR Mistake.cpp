#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	freopen("ocr.in", "r", stdin);

	int t; cin >> t; while (t--) {
		string s; cin >> s; 
		int n = (int)s.size(); bool ok = true;
		for (int i = 0; i < (n - 1) && ok; i++)
			if (s[i] == 'r' && s[i + 1] == 'n')
				ok = false;
		
		cout << (ok ? "sure" : "not sure") << '\n';
	}
	return 0;
}