#include <iostream>
#include <vector>
using namespace std;

vector<int> mic;
vector<pair<int, int>> offers;
int n, m;

bool can_buy(int day, int sum) {
	vector<int> last;
	last.resize(n + 1, -1);
	for (int i = 0; i < m; i++) {
		if (offers[i].first <= day) {
			int type = offers[i].second;
			last[type] = (offers[i].first > last[type]) ? offers[i].first : last[type];
		}
	}
	vector<vector<int>> valid_offers;
	valid_offers.resize(2 * sum);
	for (int i = 1; i <= n; i++) {
		if (last[i] != -1) { valid_offers[last[i]].push_back(i); }
	}

	int money = 0; int need = sum;
	vector<int> mictran = mic;
	for (int i = 1; i <= day; i++) {
		money++;
		if (valid_offers[i].empty()) { continue; }
		for (unsigned int j = 0; j < valid_offers[i].size(); j++) {
			int k = valid_offers[i][j];
			if (money > mictran[k]) {
				money -= mictran[k]; need -= mictran[k];
				mictran[k] = 0;
			}
			else {
				mictran[k] -= money; need -= money;
				money = 0; break;
			}
		}
	}
	return 2 * need <= money;
}

int first_day(int sum) {
	int left = sum, right = 2 * sum;
	while (left != right) {
		int mid = (left + right) / 2;
		if (can_buy(mid, sum)) { right = mid; }
		else { left = mid + 1; }
	}
	return left;
}

int main() {
	cin >> n >> m;
	mic.resize(n + 1, 0); int sum = 0;
	for (int i = 1; i <= n; i++) { cin >> mic[i]; sum += mic[i]; }
	for (int i = 0; i < m; i++) {
		int d, t; cin >> d >> t;
		pair<int, int> p(d, t);
		offers.push_back(p);
	}
	cout << first_day(sum) << endl;
	return 0;
}