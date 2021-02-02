#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
typedef long long ll;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	ll res = (ll)1e15;
	ll n, carSize; cin >> n >> carSize;
	ll ageCar, priceCar, ageMot, priceMot; cin >> ageCar >> priceCar >> ageMot >> priceMot;
	ll price1Y, d; cin >> price1Y >> d;
 
	vector<ll> ages(n); int minMotorNeeded = -1;
	for (auto &x : ages) { cin >> x; }
	sort(ages.begin(), ages.end());
 
	ll neededY = 0, spareY = 0;
	for (int i = 0; i < n; i++) {
		if (ages[i] > ageMot) { spareY += min(d, ages[i] - ageMot); }
		else { neededY += ageMot - ages[i]; }
		if (ages[i] + d < ageMot) { minMotorNeeded = i+1; }
	}
 
	if (neededY <= spareY && minMotorNeeded == -1) { res = neededY * price1Y + priceMot * n; }
 
	int l = -1;	//idx of last pass
 
	//c: idx of last car driver
	for (int c = n - 1; c >= 0; c--) {
		if (l >= c || ages[c] + d < ageCar) { break; }
		if (ages[c] > ageMot) { spareY -= min(d, ages[c] - ageMot); }
		else { neededY -= (ageMot - ages[c]); }	
		if (ages[c] > ageCar) { spareY += min(d, ages[c] - ageCar); }
		else { neededY += ageCar - ages[c]; }
 
		for (int j = 0; j < carSize - 1; j++) {
			l++; if (l == c) { break; }
			if (ages[l] > ageMot) { spareY -= min(d, ages[l] - ageMot); }
			else { neededY -= (ageMot - ages[l]); }
			spareY += min(d, ages[l] - 1);
		}
 
		if (neededY <= spareY && l >= minMotorNeeded) {
			ll cur = neededY * price1Y + max(0,(c - l - 1))*priceMot + (n - c)*priceCar;
			res = min(res, cur);
		}
	}
 
	cout << (res == (ll)1e15 ? -1 : res) << endl;
}