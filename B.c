#include <stdio.h>
#include <stdbool.h>

int main() {
  int N,i,j;
  scanf("%d %d %d",&N,&i,&j);
  for (int a = 1; a <= N; ++a) {
    if(a != 1)
      printf(" ");
    printf("(%u,%u)",i,a);
  }
  printf("\n");
  for (int a = 1; a <= N; ++a) {
    if(a != 1)
      printf(" ");
    printf("(%u,%u)",a,j);
  }
  printf("\n");
  bool printed = false;
  for (int a = 1; a <= N && (a+(j-i)) <= N ; ++a) {
    if((a+(j-i)) >= 1) {
      if(printed)
        printf(" ");
      printf("(%u,%u)",a,(a+(j-i)));
      printed = true;
    }
  }
  printf("\n");
  printed = false;
  for (int a = ((i+j-1) > N ? N : (i+j-1)); a >= 1 && (i+j-a) >= 1 && (i+j-a) <= N; --a) {
    if(printed)
      printf(" ");
    printf("(%u,%u)",a, (i+j-a));
    printed=true;
  }
  return 0;
}
