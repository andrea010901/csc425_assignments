#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("hello world (pid:%d)\n", (int) getpid());
  int x = 100;
  int rc = fork();
  if (rc < 0) {
    // fork failed
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    // child (new process)
    printf("hello, I am child (pid:%d)\n", (int) getpid());
    x = 150;
    printf("Value of x in child is: %d\n", x);
  } else {
    // parent goes down this path (main)
    printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
    x = 200;
    printf("Value of x in parent is: %d\n", x);
  }
  //printf("Value of x at the end: %d\n", x);
  return 0;
}

/*********************************************
   Your name:
   Question 1: The value of the x variable does not change and is the same for the child process.
   Question 2: The value of the x variable changes accordingly for each, the child and the parent. 
*********************************************/
