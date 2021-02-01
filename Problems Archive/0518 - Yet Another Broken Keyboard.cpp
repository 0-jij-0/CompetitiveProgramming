#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

set<int> valid;
vector<int> not_valid;
string s;

int main() {
	int n, k; cin >> n >> k >> s;
	for (int i = 0; i < k; i++) {
		char c; cin >> c; valid.insert(c);
	}

	not_valid.push_back(-1);
	for (int i = 0; i < n; i++)
		if (!valid.count(s[i]))
			not_valid.push_back(i);
	not_valid.push_back(n);
	
	long long res = 0;
	for (int i = 0; i < (int)not_valid.size() - 1; i++) {
		long long m = not_valid[i + 1] - not_valid[i] - 1;
		res += (m * (m + 1)) >> 1;
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}