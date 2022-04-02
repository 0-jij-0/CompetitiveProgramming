#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> B;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int h, w; cin >> h >> w;
	B.resize(w, vector<int>(h));
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> B[j][i];

	for (auto& x : B) { for (auto& y : x) cout << y << ' '; cout << '\n'; }
}