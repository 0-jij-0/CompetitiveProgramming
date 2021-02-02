#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
typedef long long ll;
 
int main() {
	int d; cin >> d;
 
	vector<ll> prices(d);
	for (auto &x : prices) { cin >> x; }
 
	ll lastCost = INT_MAX, curMoney = 100, curAmount = 0;
	for (int i = 0; i < d; i++) {
		if (prices[i] < lastCost) { lastCost = prices[i]; }
		else {
			curAmount = min(100000ll, curMoney / lastCost);
			curMoney -= curAmount * lastCost;
			curMoney += curAmount * prices[i];
			lastCost = prices[i];
		}
	}
 
	cout << curMoney << endl;
}