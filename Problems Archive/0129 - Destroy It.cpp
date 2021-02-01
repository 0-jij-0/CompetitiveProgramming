#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct turn {
	long long one1, one2, one3, two, three;
	turn() :
	one1(0), one2(0), one3(0), two(0), three(0) {}
};

vector<turn> turns;
long long dp1[200001][4][2];
long long dp2[200001][10];

void fill_dp1() {
	for(unsigned int i = 0; i < turns.size(); i++){
		turn &t = turns[i];
		if (t.one3 == 0) { dp1[i][3][0] = -1; }
		else {
			dp1[i][3][0] = t.one1 + t.one2 + t.one3;
			dp1[i][3][1] = 2 * t.one1 + t.one2 + t.one3;
		}

		long long two1 = (t.one2 != 0) ? t.one1 + t.one2 : 0;
		long long two2 = (t.one1 != 0 && t.two != 0) ? t.two + t.one1 : 0;
		if (two1 == two2 && two1 == 0) { dp1[i][2][0] = -1; }
		else {
			if (two1 >= two2) {
				dp1[i][2][0] = two1; dp1[i][2][1] = two1 + t.one1;
			}
			else {
				dp1[i][2][0] = two2; long long m = (t.two < t.one1) ? t.one1 : t.two;
				dp1[i][2][1] = two2 + m;
			}
		}

		long long m1 = (t.one1 > t.two) ? t.one1 : t.two;
		long long m = (m1 > t.three) ? m1 : t.three;
		dp1[i][1][0] = m; dp1[i][1][1] = 2 * m;
	}
}

long long max_damage(int i, int m) {
	if (dp2[i][m] != -1) { return dp2[i][m]; }
	if (i == turns.size()) { return 0; }

	long long a, b, c, d;
	a = max_damage(i + 1, m);
	if (m > 8) { b = dp1[i][1][1] + max_damage(i + 1, 0); }
	else { b = dp1[i][1][0] + max_damage(i + 1, m + 1); }

	if (dp1[i][2][0] == -1) { c = 0; }
	else if (m > 7) { c = dp1[i][2][1] + max_damage(i + 1, (m + 2) % 10); }
	else { c = dp1[i][2][0] + max_damage(i + 1, m + 2); }

	if (dp1[i][3][0] == -1) { d = 0; }
	else if (m > 6) { d = dp1[i][3][1] + max_damage(i + 1, (m + 3) % 10); }
	else { d = dp1[i][3][0] + max_damage(i + 1, m + 3); }

	long long m1 = (a > b) ? a : b;
	long long m2 = (c > d) ? c : d;
	long long max = (m1 > m2) ? m1 : m2;
	dp2[i][m] = max; return max;
}

int main() {
	for (int i = 0; i < 200001; i++) {
		for (int j = 0; j < 10; j++) { dp2[i][j] = -1; }
	}
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		turn t;
		for (int j = 0; j < k; j++) {
			int c; long long d; cin >> c >> d;
			if (c == 1) {
				if(d >= t.one1){
					t.one3 = t.one2; t.one2 = t.one1; t.one1 = d;
					continue;
				}
				if (d >= t.one2) {
					t.one3 = t.one2; t.one2 = d;
					continue;
				}
				if (d > t.one3) { t.one3 = d; }
			}
			if (c == 2 && d > t.two) { t.two = d; continue; }
			if (c == 3 && d > t.three) { t.three = d; }
		}
		turns.push_back(t);
	}
	fill_dp1();
	cout << max_damage(0, 0) << endl;
	cin.ignore(2); return 0;
}