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
	int n; cin >> n;
	vector<ll> sticks(n);
	for (auto &x : sticks) { cin >> x; }
	sort(sticks.begin(), sticks.end());
 
	bool possible = false;
	for (int i = 0; i < n - 2; i+=3) {
		if (sticks[i] + sticks[i + 1] > sticks[i + 2]) { possible = true; break; }
	}
 
	cout << (possible ? "possible" : "impossible") << endl;
}