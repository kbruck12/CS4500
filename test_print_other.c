#include <linux/unistd.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#define __NR_print_other 339

int main(int argc, char *argv[])
{
  int stat;
  syscall(__NR_print_other, 6148);
  waitpid(-1, &stat, WNOHANG); //waits for process to change state before continuing
  return 0;
}

