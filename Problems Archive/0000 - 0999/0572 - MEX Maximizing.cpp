#include <iostream>
#include <vector> 
#include <numeric>
using namespace std;

vector<int> f, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int q, x; cin >> q >> x;
	f.resize(q, 0); m.resize(x);
	iota(m.begin(), m.end(), 0);
	int mex = 0;
	for(int i = 0; i < q; i++) {
		int y; cin >> y; y %= x;
		f[m[y]] = 1; m[y] += x;
		if (m[y] >= q) { m[y] -= x; }
		while (mex < q && f[mex]) { mex++; }
		cout << mex << endl;
	}
	cin.ignore(2); return 0;
}