#include <iostream>
#include <vector>
using namespace std;

vector<int> stops;

bool max_subarray(int &from, int &to) {
	int a = 1, b = 2;
	int current_sum = 0, max_sum = -1;

	for (int i = 0; i < stops.size(); i++) {
		current_sum += stops[i];
		if (current_sum < 0) { a = b = i + 2; current_sum = 0;  }
		else if (current_sum > max_sum) { max_sum = current_sum; from = a; to = b;}
		else if (current_sum == max_sum && (to - from) < (b - a)) { from = a; to = b; }
		b++;
	}
	if (max_sum < 0) { return false; }
	return true;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		stops.clear();
		int r; cin >> r;
		for (int j = 0; j < r - 1; j++) {
			int a; cin >> a;
			stops.push_back(a);
		}
		int from, to;
		bool b = max_subarray(from, to);
		if (!b) { cout << "Route " << i + 1 << " has no nice parts" << endl; }
		else { cout << "The nicest part of route " << i + 1 << " is between stops " << from << " and " << to << endl; }
	}
	cout << endl; cin.ignore(2); return 0;
}