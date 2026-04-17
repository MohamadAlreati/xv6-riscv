#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int before;
  int after_alloc;
  int after_free;
  void *buf;

  before = memsize();
  printf("memsize before alloc: %d bytes\n", before);

  buf = malloc(20 * 1024);
  if(buf == 0){
    fprintf(2, "memsize_test: malloc failed\n");
    exit(1);
  }

  after_alloc = memsize();
  printf("memsize after alloc: %d bytes\n", after_alloc);

  free(buf);

  after_free = memsize();
  printf("memsize after free: %d bytes\n", after_free);

  exit(0);
}
