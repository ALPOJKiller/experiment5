#include <stdio.h>

int main() {
  unsigned m,n;
  scanf("%u %u",&m,&n);
  // 我在用纯粹的C
  // 根据OJ的规则，有C99的支持
  // 题目说m和n不大
  // 综上，我可以使用VLA
  unsigned mat[m][n];
  unsigned element_count = m * n;
  unsigned equal_count = 0;
  for (size_t i = 0; i < m; ++i) {
    for (size_t j = 0; j < n; ++j) {
      scanf("%u",&mat[i][j]);
    }
  }
  for (size_t i = 0; i < m; ++i) {
    for (size_t j = 0; j < n; ++j) {
      unsigned num;
      scanf("%u",&num);
      if(num == mat[i][j])
        ++equal_count;
    }
  }
  printf("%.2f",100.0*equal_count/element_count);
  return 0;
}
