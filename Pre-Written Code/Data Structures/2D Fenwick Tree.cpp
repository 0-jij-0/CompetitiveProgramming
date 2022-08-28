#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

//Queries take O(log^2 n) time
struct FT2D {
	int n, m; vector<vector<int>> vals; FT2D() {}
	FT2D(int _n, int _m) : n(_n), m(_m), vals(_n + 1, vector<int>(_m + 1, 0)) {}

	//Adds val to (i,j) 0-indexed
	void update(int i, int j, int val) {
		for (++i, ++j; i <= n; i += i & -i)
			for (int _j = j; _j <= m; _j += _j & -_j) 
				vals[i][_j] += val;
	}

	//Sum of the rectangle (0,0), (i,j)  0-indexed
	int query(int i, int j) const {
		int sum = 0;
		for (++i, ++j; i; i -= i & -i)
			for (int _j = j; _j; _j -= _j & -_j)
				sum += vals[i][_j];
		return sum;
	}

	//Sum of the rectangle (i1,j1), (i2,j2)
	int query(int i1, int j1, int i2, int j2) const {
		return query(i2, j2) - query(i2, j1 - 1) - 
			query(i1 - 1, j2) + query(i1 - 1, j1 - 1);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}