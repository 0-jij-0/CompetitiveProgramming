#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
 
using namespace std;
typedef long long ll;
 
bool comp(pair<int, int> &p1, pair<int, int> &p2) {
	if (p1.first == p2.first) { return p1.second > p2.second; }
	return p1.first < p2.first;
}
 
bool comp2(pair<int, int> &p1, pair<int, int> &p2) {
	return p1.second > p2.second;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	ifstream ifs("icecream.in");
	int t; ifs >> t;
 
	while (t--) {
		int n, k; ifs >> n >> k; int ik = k;
		vector<pair<int, int>> iceCream(n);
		for (auto &x : iceCream) { ifs >> x.first; }
		for (auto &x : iceCream) { ifs >> x.second; }
 
		sort(iceCream.begin(), iceCream.end(), comp);
 
		int calories = iceCream[k-1].first; ll happiness = 0;
		while (k < n && iceCream[k].first == calories) { k++; }
		sort(iceCream.begin(), iceCream.begin() + k, comp2);
 
		for (int i = 0; i < ik; i++) { happiness += iceCream[i].second; }
		
		cout << calories << " " << happiness << endl;
	}
}