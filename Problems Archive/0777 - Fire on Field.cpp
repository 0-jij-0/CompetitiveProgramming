#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

void fillRes() {
	v.resize(1001);
	for (int i = 0; i <= 1000; i++) {
		vector<int> res(1000, 1);
		for (int k = 1; i - 2 * k >= 0; k++) {
			//if (v[i - k] - v[i - 2*k] < 0) { continue; }
			int dif = v[i - k] - v[i - 2 * k];
			if (v[i - k] + dif < 0) { continue; }
			res[v[i - k] + dif] = 0;
		}
		v[i] = find(res.begin() + 1, res.end(), 1) - res.begin();
	}
}

int main() {
	fillRes(); int n; cin >> n; cout << v[n] << endl;
	cin.ignore(2); return 0;
}