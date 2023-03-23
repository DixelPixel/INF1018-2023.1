/* programa 3*/
#include <stdio.h>

int main (void) {
  int x = 0xffffffff;
  unsigned int y = -2;
  signed char sc = -1;
  unsigned int ui = sc;
  printf("x=%u, y=%u\n", x, y);
  printf("0x%08x\n", ui);
  return 0;
}