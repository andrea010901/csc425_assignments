/*********************************************
   Your name: Andrea Maria Ola 
   Question 1: wait() returns the PID of the child.
   Question 2: when used in the chil√d process, wait() returns -1. This is because, there no process to wait.
*********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  printf("hello world (pid:%d)\n", (int) getpid());
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    int rc_wait = wait(NULL);
    printf("hello, I am child of %d (rc_wait:%d) (pid:%d)\n", (int) getpid(), rc_wait);
  } else {
    //int rc_wait = wait(NULL);
  printf("hello, I am parent of (pid:%d)\n",
          rc, (int) getpid());

  }
  return 0;
}
