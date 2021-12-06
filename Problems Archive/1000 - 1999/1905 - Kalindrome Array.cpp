#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

bool isPalindrome(int x) {
	int i = 0, j = (int)v.size() - 1;
	while (i < j) {
		if (v[i] == x) { i++; continue; }
		if (v[j] == x) { j--; continue; }
		if (v[i] != v[j]) { return false; }
		i++; j--;
	}
	return true;
}

bool isKalindrome() {
	int i = 0, j = (int)v.size() - 1;
	while (i < j) {
		if (v[i] == v[j]) { i++; j--; continue; }
		return isPalindrome(v[i]) || isPalindrome(v[j]);
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; }
		cout << (isKalindrome() ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}