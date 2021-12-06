#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll countGoodSegment(vector<int>& a, ll S) {
	int i = 0, j = 0, n = (int)a.size();
	ll curSum = 0, res = 0;

	while (i != n) {
		while (j != n && curSum < S) { curSum += a[j++]; }
		if (curSum >= S) res += n - j + 1;
		curSum -= a[i++];
	}
	return res;
}

vector<int> v;

int main() {
	int n; ll S; cin >> n >> S; v.resize(n);
	for (auto& x : v) { cin >> x; }

	cout << countGoodSegment(v, S) << '\n';
	cin.ignore(2); return 0;
}