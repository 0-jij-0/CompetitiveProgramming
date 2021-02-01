#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

string s; int n, mod = 1000 * 1000 * 1000 + 7;
map<char, int> m = { {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3} };

int main() {
	cin >> n >> s; vector<int> freq(4, 0);
	for (char &c : s) { freq[m[c]]++; }
	int m = *max_element(freq.begin(), freq.end()), k = 0;
	for (int i = 0; i < 4; i++) { if (freq[i] == m) { k++; } }
	ll ans = 1; while(n--) { ans = (ans * k) % mod; }
	cout << ans << endl; cin.ignore(2); return 0;
}