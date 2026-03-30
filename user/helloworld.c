#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  // 1 is the file descriptor for stdout (the screen)
  fprintf(1, "Hello World xv6\n");
  exit(0);
}