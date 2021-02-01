#include <iostream>
#include <string>
using namespace std;

bool check(int n, int k){
	int km = n % (k + 1);
	if (km == k) { return true; }
	return km % 3;
}

int main() {
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int n, k; cin >> n >> k;
		bool b;	if (k == n) { b = true; }
		else if (k > n || k % 3) { b = n % 3; }
		else if (k == 3) { b = n % 4; }
		else { b = check(n, k); }
		string res = (b) ? "Alice" : "Bob";
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}