#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> & board) {
  int p = 0;
  int s = 0;
  while (p >= 0 && p < board.size()) {
    int v = board[p];
    int pp = p + v;
    board[p] = v >= 3 ? v - 1 : v + 1;
    p = pp;
    ++s;
  }
  return s;
}

int main(int argc, char ** argv) {
  vector<int> board;
  int n;
  while (cin >> n) {
    board.push_back(n);
  }
  cout << solve(board) << endl;
}