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
 
	int n, m; cin >> n >> m;
	string lastP, cipher; cin >> lastP >> cipher;
	string ans(m, ' ');
	vector<int> k(m);
	for (int i = n - 1; i >= 0; i--) { 
		int idx = m - (n - i);
		ans[idx] = lastP[i]; 
		k[idx] = (cipher[idx] - lastP[i] + 26) % 26;
	}
 
	int c = 1;
	while (true) {
		int j = m - n * c - 1;
		for (; j >= max(m - n * (c+1), 0); j--) {
			ans[j] = 'a'+k[j + n];
			k[j] = (cipher[j] - ans[j] + 26) % 26;
		}
		if (j < 0) { break; }
		c++;
	}
 
	cout << ans << '\n';
}