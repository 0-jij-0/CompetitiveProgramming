#include <iostream>
#include <vector>
using namespace std;

long long DP[101][51];
vector<long long> dread;
vector <int> price;

long long minDread(int p, int i) {
	if (DP[p][i] != -1) { return DP[p][i]; }
	if (i == dread.size()) { DP[p][i] = 0; return 0; }

	long long d2 = minDread(p, i + 1);
	long long d3 = (dread[i] > d2) ? dread[i] : d2;

	if (p < price[i]) {	DP[p][i] = d3; return d3; }

	long long d1 = minDread(p - price[i], i + 1) - dread[i];
	long long d = (d1 < d3) ? d1 : d3;
	DP[p][i] = d; return d;
}

struct MonstersValley {
	MonstersValley() {};
	int minimumPrice() {
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 51; j++) { DP[i][j] = -1; }
		}
		int p = 0;
		while (minDread(p, 0) > 0) { p++; }
		return p;
	}
};

int main() {

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		long long a; cin >> a; dread.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		int a; cin >> a; price.push_back(a);
	}
	MonstersValley m;
	cout << m.minimumPrice();

	cin.ignore(2); return 0;
}