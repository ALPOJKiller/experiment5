#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    unsigned m,n;
    cin >> n >> m;
    std::vector<std::vector<bool>> mat(n+2,std::vector<bool>(m+2,false));
    for (size_t i = 1; i <= n; ++i) {
      for (size_t j = 1; j <= m; ++j) {
          char ch;
          cin >> ch;
          if(ch == '*') {
            mat[i][j] = true;
          }
      }
    }
    for (size_t i = 1; i <= n; ++i) {
      for (size_t j = 1; j <= m; ++j) {
        if(mat[i][j]) {
          cout << '*';
        } else {
          unsigned count_bomb = 0;
          for (size_t p = i-1; p <= i+1; ++p) {
            for (size_t q = j-1; q <= j+1; ++q) {
              count_bomb += mat[p][q];
            }
          }
          cout << count_bomb;
        }
      }
      cout << endl;
    }
    return 0;
}
