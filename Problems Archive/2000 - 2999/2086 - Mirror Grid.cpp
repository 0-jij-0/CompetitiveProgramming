#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<string>> V(4); int n;

vector<string> rotateMatrix(vector<string> v) {
    for (int x = 0; x < n / 2; x++) {
        for (int y = x; y < n - x - 1; y++) {
            int temp = v[x][y];
            v[x][y] = v[y][n - 1 - x];
            v[y][n - 1 - x] = v[n - 1 - x][n - 1 - y];
            v[n - 1 - x][n - 1 - y] = v[n - 1 - y][x];
            v[n - 1 - y][x] = temp;
        }
    }

    return v;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        cin >> n; V[0].resize(n);
        for (auto& x : V[0]) cin >> x;
        for (int i = 1; i < 4; i++)
            V[i] = rotateMatrix(V[i - 1]);

        int res = 0;
        for (int i = 0; i < n / 2; i++)
            for (int j = 0; j < (n + 1) / 2; j++) {
                int z = 0, o = 0;
                for (int k = 0; k < 4; k++)
                    (V[k][i][j] == '1' ? o : z)++;
                res += min(z, o);
            }

        cout << res << '\n';
    }
}