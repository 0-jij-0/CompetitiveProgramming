#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

string s; int n, k;

bool check() {
	vector<int> freq(26, 0);
	for (char& c : s) freq[c - 'a']++;
	for (auto& x : freq) if (x % k) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> n >> k >> s;
		if (n % k) { cout << "-1\n"; continue; }
		if (check()) { cout << s << '\n'; continue; }

		vector<int> freq(26, 0); 
		ll rem = 0; bool ok = false;

		for (char& c : s) {
			rem -= (k - freq[c - 'a']) % k;
			freq[c - 'a'] = (freq[c - 'a'] + 1) % k;
			rem += (k - freq[c - 'a']) % k;
		}

		for (int i = n - 1; i >= 0 && !ok; i--) {
			rem -= (k - freq[s[i] - 'a']) % k;
			freq[s[i] - 'a'] = (freq[s[i] - 'a'] - 1 + k) % k;
			rem += (k - freq[s[i] - 'a']) % k;

			for (int j = s[i] - 'a' + 1; j < 26; j++) {
				rem -= (k - freq[j]) % k;
				freq[j] = (freq[j] + 1) % k; 
				rem += (k - freq[j]) % k;

				bool firstCond = (rem % k) == ((n - i - 1) % k);
				bool secondCond = rem <= (n - i - 1);
				if (firstCond && secondCond) {
					s[i] = 'a' + j;	int y = n - 1, h = 25; 
					
					while (h != -1) {
						if (freq[h] == 0) { h--; continue; }
						s[y--] = h + 'a'; 
						freq[h] = (freq[h] + 1) % k;
					}
					while (y != i) { s[y--] = 'a'; }
					ok = true; break;
				}

				rem -= (k - freq[j]) % k;
				freq[j] = (freq[j] - 1 + k) % k;
				rem += (k - freq[j]) % k;
			}
		}
		cout << (ok ? s : "-1") << '\n';
	}
	cin.ignore(2); return 0;
}