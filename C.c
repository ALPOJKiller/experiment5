#include <stdio.h>

long long getANumber() {
    long long n;
    scanf("%lld", &n);
    return n;
}

int main() {
    unsigned m, n;
    scanf("%u %u", &m, &n);
    long long ans = 0;
    // 如果只有一行或者一列
    if (m == 1 || n == 1) {
        for (size_t i = 0; i < m + n - 1; ++i) {
            ans += getANumber();
        }
    } else {
        for (size_t i = 0; i < n; ++i) {
            ans += getANumber();
        }
        for (size_t i = 1; i < m - 1; ++i) {
            ans += getANumber();
            for (size_t j = 1; j < n - 1; ++j) {
                getANumber();
            }
            ans += getANumber();
        }
        for (size_t i = 0; i < n; ++i) {
            ans += getANumber();
        }
    }
    printf("%lld", ans);
    return 0;
}
