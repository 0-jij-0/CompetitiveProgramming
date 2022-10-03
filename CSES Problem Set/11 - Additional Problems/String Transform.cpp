#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

string inverseBWT(string& BWT) {
	vector<int> next(BWT.size());
	iota(next.begin(), next.end(), 0);

	auto comp = [&](int a, int b) { return BWT[a] < BWT[b]; };
	stable_sort(next.begin(), next.end(), comp);

	string res = ""; for (int i = next[0]; i;) 
		res += BWT[i = next[i]];
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string BWT; cin >> BWT;
	cout << inverseBWT(BWT) << '\n';
}