#include <iostream>
#include <vector>
using namespace std;

long long wine_trade(vector<int> &wine) {
	long long current_cost = 0, total_cost = 0;
	for (int i = 0; i < wine.size(); i++) {
		current_cost += wine[i];
		total_cost += (current_cost > 0) ? current_cost : - current_cost;
	}
	return total_cost;
}

int main() {
	int n; cin >> n;
	
	while (n != 0) {
		int a; vector<int> wine;
		for (int i = 0; i < n; i++) {
			cin >> a; wine.push_back(a);
		}
		cout << wine_trade(wine) << endl;
		cin >> n;
	}
	cout << endl; cin.ignore(2); return 0;
}