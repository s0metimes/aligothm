#include <stdio.h>

int main() {
  int cnt = 1;
  long long int res = 2;
  while(res < 100000000000) {
    res *= 2;
    cnt++;
  }
  printf("%lld\n", 100000000000 - res/2);
  return 0;
}
