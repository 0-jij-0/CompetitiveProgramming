#include <iostream>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
typedef long long ll;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	int n; cin >> n;
	vector<pair<int, int>> acc;
	for (int i = 0; i < n; i++) {
		int a, d; cin >> a >> d;
		acc.push_back({ a,d });
	}
	double original = 0, v = 0;
	for (int i = 0; i < n; i++) {
		original += v * acc[i].second + 0.5 * acc[i].first * acc[i].second * acc[i].second;
		v += acc[i].first * acc[i].second;
	}
 
	sort(acc.rbegin(), acc.rend());
	double best = 0; v = 0;
	for (int i = 0; i < n; i++) {
		best += v * acc[i].second + 0.5 * acc[i].first * acc[i].second * acc[i].second;
		v += acc[i].first * acc[i].second;
	}
 
	cout << setprecision(1) << fixed << best - original << endl;
}