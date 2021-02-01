#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, s, k; cin >> n >> s >> k;
		set<int> st;
		for (int i = 0; i < k; i++) {
			int a; cin >> a; st.insert(a);
		}
		int up = 1000, down = 1000;
		for(int i = s; i <= min(n, s + k + 1); i++)
			if (!st.count(i)) { up = i - s; break; }
		for (int i = s; i >= max(1, s - k - 1); i--)
			if (!st.count(i)) { down = s - i; break; }

		cout << min(up, down) << endl;
	}
	cin.ignore(2); return 0;
}