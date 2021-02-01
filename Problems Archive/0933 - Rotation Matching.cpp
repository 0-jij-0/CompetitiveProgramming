#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> a, b, ida, idb;
map<int, int> freqL, freqR;

int main() {
	int n; cin >> n; a.resize(n); b.resize(n);
	ida.resize(n); idb.resize(n); freqL.clear(); freqR.clear();
	for (int i = 0; i < n; i++) { cin >> a[i]; ida[--a[i]] = i; }
	for (int i = 0; i < n; i++) { cin >> b[i]; idb[--b[i]] = i; }

	for (int i = 0; i < n; i++) { 
		int dL = (ida[i] < idb[i]) ? n + ida[i] - idb[i] : ida[i] - idb[i];
		int dR = (ida[i] < idb[i]) ? idb[i] - ida[i] : n + idb[i] - ida[i];
		freqL[dL]++; freqR[dR]++;
	}
	int res = 0; 
	for (auto &x : freqL) { res = max(res, x.second); }
	for (auto &x : freqR) { res = max(res, x.second); }
	cout << res << endl; cin.ignore(2); return 0;
}