#include <stdio.h>
long long getN() {
  long long n;
  scanf("%lld",&n);
  return n;
}
int main() {
  unsigned m,n;
  scanf("%u %u",&m,&n);
  long long ans = 0;
  if(m == 1 || n == 1) {
    for (size_t i = 0; i < m + n - 1; ++i) {
      ans += getN();
    }
  } else {
    for (size_t i = 0; i < n; ++i) {
      ans += getN();
    }
    for (size_t i = 1; i < m-1; ++i) {
      ans += getN();
      for (size_t j = 1; j < n-1; ++j) {
        getN();
      }
      ans += getN();
    }
    for (size_t i = 0; i < n; ++i) {
      ans += getN();
    }
  }
  printf("%lld",ans);
  return 0;
}
