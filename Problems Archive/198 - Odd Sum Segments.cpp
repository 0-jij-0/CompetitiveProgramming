#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n, k;

int main() {
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> n >> k; int odd = 0;
		v.clear(); v.resize(n, 0);
		for (int j = 0; j < n; j++) {
			int a; cin >> a;
			odd += a % 2; v[j] = a % 2;
		}
		if (odd < k) { cout << "NO" << endl; }
		else if ((odd - k) % 2) { cout << "NO" << endl; }
		else {
			cout << "YES" << endl; int j = 0;
			while (k != 1) {
				if (v[j]) {
					cout << j + 1 << ' '; k--;
				}
				j++;
			}
			cout << n << endl;
		}
	}
	cin.ignore(2); return 0;
}