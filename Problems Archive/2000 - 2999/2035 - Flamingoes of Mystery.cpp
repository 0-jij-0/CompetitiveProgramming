#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> res;

int query(int i = -1, int j = -1) {
	if (i == -1) {
		string s = "!";
		for (auto& x : res)
			s += " " + to_string(x);
		cout << s << endl; return 0;
	}

	cout << "? " + to_string(i) + " " + to_string(j) << endl;
	int sum; cin >> sum; return sum;
}

int main() {
	int n; cin >> n; res.resize(n);
	int a1 = query(1, 2), a2 = query(2, 3), a3 = query(1, 3);
	res[2] = a3 - a1; res[1] = a2 - res[2]; res[0] = a1 - res[1];

	int sum = a3, nextSum = a3;
	for (int i = 3, sum = a3; i < n; i++, sum = nextSum) 
		res[i] = (nextSum = query(1, i + 1)) - sum;
	
	query();
}