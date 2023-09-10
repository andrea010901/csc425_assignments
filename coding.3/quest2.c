#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  printf("hello world (pid:%d)\n", (int) getpid());
  int op = open("./p4.c", O_RDONLY);
  int rc = fork();
  if (rc < 0) {
    // fork failed
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    // child (new process)
    printf("hello, I am child (pid:%d)\n", (int) getpid());
    char x;
    read(op, &x, 1);
    //printf("The value read in child is: %d\n", x);
    printf("Reading a character from the file from child and printing it\n%c\n", x);
  } else {
    // parent goes down this path (main)
    printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
    char x;
    read(op, &x, 1);
    printf("Reading a character from the file from child and printing it\n%c\n", x);
    //printf("Value of read in parent is: %d\n", x);
  }
  //printf("Value of x at the end: %d\n", x);
  return 0;
}



