/*********************************************
   Your name: Andrea Ola Mejicanos 
   Question 1: Both child and parent have acess to the file descriptor. 
   Question 2: When they are writing to the file concurrently,both are able to perform the task in an undeterministic way.
*********************************************/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  printf("hello world (pid:%d)\n", (int) getpid());
  int op = open("./p4.c", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
  int rc = fork();
  if (rc < 0) {
    // fork failed
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    // child (new process)
    printf("hello, I am child (pid:%d)\n", (int) getpid());
    char x = 'e';
    write(op, &x, 1);
    //printf("The value read in child is: %d\n", x);
    printf("Writing to a file concurrently child\n");
  } else {
    // parent goes down this path (main)
    printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
    char x = 'f';
    write(op, &x, 1);
    printf("Writig to a file concurently parent\n");
    //printf("Value of read in parent is: %d\n", x);
  }
  //printf("Value of x at the end: %d\n", x);
  return 0;
}
