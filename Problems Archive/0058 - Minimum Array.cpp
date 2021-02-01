#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> a, b;

void rearrange(int n) {
	map<int, int> indices;
	vector<int> c, mod, first;
	c.resize(n); mod.resize(n); first.resize(n);

	for (int i = 0; i < n; i++) {
		b[i] %= n; a[i] %= n; 
		first[i] = i; mod[b[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (mod[i] != 0) { pair<int, int> p(i, i); indices.insert(p); }
	}

	for (int i = 0; i < n; i++) {
		int x = (n - a[i]) % n;
		int &f = first[x];
		if (mod[f] == 0) {
			//f++; if (f == n) { f = 0; }
			map<int, int>::iterator it = indices.upper_bound(f);
			if (it == indices.end()) { it = indices.begin(); }
			f = it->first;
		}
		mod[f]--; if (mod[f] == 0) { indices.erase(f); }
		c[i] = (a[i] + f) % n; cout << c[i];
		if (i + 1 != n) { cout << " "; }
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	a.resize(n); b.resize(n);
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	for (int i = 0; i < n; i++) { cin >> b[i]; }
	rearrange(n);
	cout << endl;
	cin >> n; return 0;
}