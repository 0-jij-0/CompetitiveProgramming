#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ones;

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		string s; cin >> s; ones.clear();
		for(int j = 0; j < (int)s.size(); j++)
			if (s[j] == '1') { ones.push_back(j); }

		long long res = 0;
		for(int idx = 0; idx < (int)s.size(); idx++) {
			long long num = 0;
			int k = lower_bound(ones.begin(), ones.end(), idx) - ones.begin();
			if (k == ones.size()) { break; }
			int j = ones[k];
			for (; j < (int)s.size(); j++) {
				if (s[j] == '1') { num++; }
				long long range = j - idx + 1;
				if (num == range) { res++; }
				else if (num > range) { break; }
				num <<= 1;
			}
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}