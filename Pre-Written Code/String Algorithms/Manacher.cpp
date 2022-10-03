#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//If even is true, res[i] = length/2 of the even palindrome with right center at i
//If even is false, res[i] = (length-1)/2 of the odd palindrome with center at i
//For example, "aaaa" even returns: 0 1 2 1, odd: 0 1 1 0
vector<int> manacher(string& s, bool even) {
	int n = s.size(); vector<int> res(n);
	int l = 0, r = -1;
	for (int i = 0; i < n; i++) {
		int k = (i > r) ? 1 : min(res[l + r - i + even], r - i + even) + 1;
		while (i + k - even < n && i - k >= 0 && s[i + k - even] == s[i - k]) { k++; }
		res[i] = --k; if (i + k - even > r) { l = i - k; r = i + k - even; }
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

}
