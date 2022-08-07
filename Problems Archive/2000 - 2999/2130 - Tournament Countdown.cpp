#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <assert.h>
using namespace std;

vector<int> v;

int query(int a, int b = -1) {
	if (b == -1) { cout << "! " + to_string(a) << endl; return 0; }
	cout << "? " + to_string(a) + " " + to_string(b) << endl;
	int x; cin >> x; return x;
}

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize((1 << n));
		iota(v.begin(), v.end(), 1); bool odd = false;
		while (v.size() > 2) {
			if (odd) for (int i = 0, k = 0; i < (int)v.size(); i += 2) {
				int x = query(v[i], v[i + 1]);
				x == 1 ? v[k++] = v[i] : v[k++] = v[i + 1];
			}

			else for (int i = 0, k = 0; i < (int)v.size(); i += 4) {
				int x = query(v[i], v[i + 2]);
				if (x == 0) { v[k++] = v[i + 1]; v[k++] = v[i + 3]; continue; }
				if (x == 1) { v[k++] = v[i]; v[k++] = v[i + 3]; continue; }
				v[k++] = v[i + 1]; v[k++] = v[i + 2];
			}

			v.resize(v.size() >> 1); odd ^= 1;
		}

		int x = query(v[0], v[1]);
		query(v[x == 2]);
	}
}