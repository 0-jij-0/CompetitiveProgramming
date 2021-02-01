#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> pre, suf;
string a, b;

string check(int k) {
	if (pre[k - 1] < (int)a.size())
		return b.substr(0, k);
	if (suf[(int)b.size() - k] >= 0)
		return b.substr((int)b.size() - k, k);

	for (int i = 0; i < k - 1; i++)
		if (pre[i] < suf[(int)b.size() - (k - i - 1)])
			return b.substr(0, i + 1) + b.substr((int)b.size() - (k - i - 1), k - i - 1);

	return "-1";
}

string find_max_substr() {
	int l = 0, r = (int) b.size();
	while (l != r) {
		int mid = (l + r + 1) >> 1;
		string s = check(mid);
		s == "-1" ? r = mid - 1 : l = mid;
	}
	if (l == 0) { return "-"; }
	return check(l);
}

int main() {
	cin >> a >> b;
	pre.resize(b.size(), (int)a.size());
	suf.resize(b.size(), -1);
	int i = 0, j = 0;
	while (i < (int)a.size() && j < (int)b.size()) {
		if (a[i] != b[j]) { i++; continue; }
		pre[j] = i; 
		j++; i++;
	}
	i = (int)a.size() - 1; j = (int)b.size() - 1;
	while (i >= 0 && j >= 0) {
		if (a[i] != b[j]) { i--; continue; }
		suf[j] = i; 
		i--; j--;
	}
	cout << find_max_substr() << endl;
	cin.ignore(2); return 0;
}