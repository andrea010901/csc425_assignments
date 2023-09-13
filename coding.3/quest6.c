/*********************************************
   Your name: Andrea Ola Mejicanos 
   Question 1: wn this case, aitpid() a√llows us to be specific abput the child process that we want to wait for.
*********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  printf("hello world (pid:%d)\n", (int) getpid());
  int rc = fork();
  int stat;
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("hello, I am child of (pid:%d)\n", (int) getpid());
  } else {
    int rc_waitpid = waitpid(rc, &stat,WUNTRACED);
  printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",
          rc, rc_waitpid, (int) getpid());

  }
  return 0;
}
