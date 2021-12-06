#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int longestGoodSegment(vector<int>& a, ll S) {
	int i = 0, j = 0, n = (int)a.size();
	ll curSum = 0; int res = 0; 
	
	while (j != n) {
		curSum += a[j];
		while (i <= j && curSum > S) { curSum -= a[i++]; }
		res = max(res, j - i + 1); j++;
	}
	return res;
}

vector<int> v;

int main() {
	int n; ll S; cin >> n >> S; v.resize(n);
	for (auto& x : v) { cin >> x; }

	cout << longestGoodSegment(v, S) << '\n';
	cin.ignore(2); return 0;
}