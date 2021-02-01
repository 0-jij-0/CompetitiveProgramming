#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int v;

vector <int> divisors(int n) {
	vector<int> res;
	int m = (int)floor(sqrt(n + 0.0));
	for (int i = 1; i <= m; i++) {
		if (n % i == 0) { res.push_back(i); }
	}
	return move(res);
}

int surf(int a, int b, int c) { return 2 * (a * b + a * c + b * c); }

int min_surf(vector<int> &d) {
	int ret = surf(1, 1, v);
	for (int i = 0; i < (int)d.size(); i++) {
		int &a = d[i], div = v / a;
		vector <int> d2 = divisors(div);
		for (int j = 0; j < (int)d2.size(); j++) {
			int b = d2[j], c = div / b;
			ret = min(ret, surf(a, b, c));
		}
	}
	return ret;
}

int main() {
	cin >> v; vector<int> div = divisors(v);
	cout << min_surf(div) << endl;

	cin.ignore(2); return 0;
}