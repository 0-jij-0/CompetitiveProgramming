#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, int> freq;
vector<int> v;

int main() {
	int n, k; cin >> n >> k; v.resize(n);
	for (auto &x : v) { cin >> x; }
	int l = 0, r = 0;
	int ml = 0, mr = 0, ms = 0;
	for (int i = 0; i < n; i++) {
		freq[v[i]]++;
		if ((int)freq.size() > k) {
			while ((int)freq.size() > k) {
				if (freq[v[l]] == 1) { freq.erase(v[l]); }
				else { freq[v[l]]--; } l++;
			}
		}
		if (r - l + 1 > ms) {
			ms = r - l + 1; ml = l; mr = r;
		}
		r++;
	}
	cout << ml + 1 << ' ' << mr + 1 << endl;
	cin.ignore(2); return 0;
}