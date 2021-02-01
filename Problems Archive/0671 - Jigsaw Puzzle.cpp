#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct piece {
	int top, left, bot, right;
	piece(int a, int b, int c, int d) : top(a), left(b), bot(c), right(d) {}
};

void rotateLeft(piece& p) {
	int prevTop = p.top, prevLeft = p.left, prevBot = p.bot, prevRight = p.right;
	p.top = prevRight; p.right = prevBot; p.bot = prevLeft; p.left = prevTop;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	if (n == 1) { cout << 1 << " " << 1 << endl << 1 << endl; return 0; }

	map<int, vector<int>> sideToPieces;
	vector<int> boundaries;	vector<piece> pieces;
	for (int i = 0; i < n; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		piece cur = piece(a, b, c, d); pieces.push_back(cur);
		if (a) { sideToPieces[a].push_back(i); } if (b) { sideToPieces[b].push_back(i); }
		if (c) { sideToPieces[c].push_back(i); } if (d) { sideToPieces[d].push_back(i); }
		if ((!a && !b) || (!b && !c) || (!c && !d) || (!d && !a)) { boundaries.push_back(i); }
	}

	if (boundaries.size() > 4) { cout << "impossible" << endl; return 0; }
	for (int tL = 0; tL < boundaries.size(); tL++) {
		vector<bool> used(n + 1, false); bool OK = true;

		int topLeft = boundaries[tL];
		while (pieces[topLeft].top != 0 || pieces[topLeft].left != 0) { rotateLeft(pieces[topLeft]); }
		vector<vector<int>> grid(1); grid[0].push_back(topLeft); used[topLeft] = 1;

		int neededSide = pieces[topLeft].right;
		while (neededSide != 0) {
			int curPiece = -1;
			for (int candidate : sideToPieces[neededSide]) {
				if (used[candidate]) { continue; }
				curPiece = candidate; break;
			}
			if (curPiece == -1) { OK = false; break; }
			while (pieces[curPiece].left != neededSide) { rotateLeft(pieces[curPiece]); }
			if (pieces[curPiece].top != 0) { OK = false; break; }

			grid[0].push_back(curPiece); used[curPiece] = 1;
			neededSide = pieces[curPiece].right;
		}
		if (!OK) { continue; }

		int width = grid[0].size(); if (n % width != 0) { continue; }
		int height = n / width; grid.resize(height);

		for (int i = 1; i < height; i++) {
			grid[i].resize(width);
			for (int j = 0; j < width; j++) {
				int neededSide = pieces[grid[i - 1][j]].bot;

				int curPiece = -1;
				for (int candidate : sideToPieces[neededSide]) {
					if (used[candidate]) { continue; }
					curPiece = candidate; break;
				}
				if (curPiece == -1) { OK = false; break; }
				while (pieces[curPiece].top != neededSide) { rotateLeft(pieces[curPiece]); }
				grid[i][j] = curPiece; used[curPiece] = 1;

				if (j == 0 && pieces[curPiece].left != 0) { OK = false; break; }
				if (j != 0 && (pieces[grid[i][j - 1]].right != pieces[curPiece].left || pieces[curPiece].left == 0)) { OK = false; break; }
				if (j == width - 1 && pieces[curPiece].right != 0) { OK = false; break; }
				if (i == height - 1 && pieces[curPiece].bot != 0) { OK = false; break; }
			}
			if (!OK) { break; }
		}
		if (!OK) { continue; }

		cout << grid.size() << " " << grid[0].size() << endl;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				cout << grid[i][j] + 1 << " ";
			}
			cout << endl;
		}
		return 0;
	}

	cout << "impossible" << endl;
}