#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

string s; int n;

int main() {
	freopen("lis.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> s; n = (int) s.size();

	int l = 0, r = n * 9; while (l < r) {
		int mid = (l + r + 1) >> 1;
		int num = mid / 9, rem = mid % 9; string cur;

		cur = string(num + (rem != 0), '9'); 
		cur[0] = rem ? '0' + rem : '9';

		bool b = (cur.size() < s.size() || (cur.size() == s.size() && cur <= s));
		b ? l = mid : r = mid - 1;
	}

	cout << l << '\n';
	cin.ignore(2); return 0;
}