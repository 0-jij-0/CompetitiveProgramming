#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> v;

int a[11] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		vector<int> b(11, 0);
		int m = 0;
		for (auto &x : v) {
			for(int i = 0; i < 11; i++)
				if (x % a[i] == 0) {  
					if (!b[i]) { m++; b[i] = 1; }
					x = i; break;
				}
		}
		partial_sum(b.begin(), b.end(), b.begin());
		cout << m << endl;
		for (auto &x : v) { cout << b[x] << ' '; }
		cout << endl;
	}
	cin.ignore(2); return 0;
}