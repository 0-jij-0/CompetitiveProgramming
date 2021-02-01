#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <bitset>
using namespace std;
typedef double ld;

pair<ld, ld> dp[258][258][10][2];
vector<ld> prob[2]; int N;

pair<ld, ld> maxProb(int s1, int s2, int t, bool p) {
	if (t == N) {
		int p1 = bitset<8>(s1).count();
		int p2 = bitset<8>(s2).count();
		if (p1 == p2) { return { 0, 1 }; }
		if (p1 > p2) { return { 1,0 }; }
		else { return { 0, 0 }; }
	}
	if (!s1 || !s2) { return { s2 == 0, s1 == 0 }; }
	if (dp[s1][s2][t][p].first > -0.5) { return dp[s1][s2][t][p]; }
	if (!p && !((1 << t) & s1)) { return dp[s1][s2][t][p] = maxProb(s1, s2, t, 1); }
	if (p && !((1 << t) & s2)) { return dp[s1][s2][t][p] = maxProb(s1, s2, t + 1, 0); }

	pair<ld, ld> ans = { 0 ,0 };
	if (!p) {
		for (int it = 1; it <= s2; it <<= 1) {
			if (!(it & s2)) { continue; }

			int next2 = s2 ^ it;
			pair<ld, ld> curP1 = maxProb(s1, next2, t, 1);
			curP1.first *= prob[0][t]; curP1.second *= prob[0][t];
			pair<ld, ld> curP2 = maxProb(s1, s2, t, 1);
			curP2.first *= (1.0 - prob[0][t]); curP2.second *= (1.0 - prob[0][t]);

			pair<ld, ld> cur(curP1.first + curP2.first, curP1.second + curP2.second);
			if (cur.first > ans.first) { ans = cur; }
			else if ((cur.first == ans.first) && (cur.second > ans.second)) { ans = cur; }
		}
	}
	else {
		ans = { 1, 0 };
		for (int it = 1; it <= s1; it <<= 1) {
			if (!(it & s1)) { continue; }

			int next1 = s1 ^ it;
			pair<ld, ld> curP1 = maxProb(next1, s2, t + 1, 0);
			curP1.first *= prob[1][t]; curP1.second *= prob[1][t];
			pair<ld, ld> curP2 = maxProb(s1, s2, t + 1, 0);
			curP2.first *= (1.0 - prob[1][t]); curP2.second *= (1.0 - prob[1][t]);
			pair<ld, ld> cur(curP1.first + curP2.first, curP1.second + curP2.second);

			if ((cur.second + cur.first) < (ans.second + ans.first)) { ans = cur; }
			else if (((cur.second + cur.first) == (ans.second + ans.first)) && (cur.first < ans.first)) { ans = cur; }
		}
	}
	return dp[s1][s2][t][p] = ans;
}

int main() {
	cin >> N; prob[0].resize(N); prob[1].resize(N);
	for (auto &x : prob) for (auto &y : x) { cin >> y; }

	for (int i = 0; i < 258; i++)
		for (int j = 0; j < 258; j++)
			for (int k = 0; k < 10; k++)
				dp[i][j][k][0] = dp[i][j][k][1] = { -1.0, -1.0 };

	pair<ld, ld> ans = maxProb((1 << N) - 1, (1 << N) - 1, 0, 0);
	cout << setprecision(4) << fixed << ans.first << " " << ans.second << endl;
}