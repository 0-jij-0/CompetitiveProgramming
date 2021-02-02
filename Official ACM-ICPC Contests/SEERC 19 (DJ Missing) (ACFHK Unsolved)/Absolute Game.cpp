#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
typedef long long ll;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	int n; cin >> n;
	vector<int> alice(n), bob(n);
	for (auto &x : alice) { cin >> x; }
	for (auto &x : bob) { cin >> x; }
	sort(bob.begin(), bob.end());
 
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int curA = alice[i], curB = 0;
 
		int cand1, cand2;
		int closeAIdx = lower_bound(bob.begin(), bob.end(), curA) - bob.begin();
		if (closeAIdx == n) { cand1 = cand2 = bob[n - 1]; }
		else { cand1 = bob[max(closeAIdx - 1, 0)]; cand2 = bob[closeAIdx]; }
 
		if (abs(cand1 - curA) < abs(cand2 - curA)) { curB = cand1; }
		else { curB = cand2; }
 
		ans = max(ans, abs(curA - curB));
	}
 
	cout << ans << endl;
}