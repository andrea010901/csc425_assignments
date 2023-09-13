/*********************************************
   Your name: Andrea Maria Ola Mejicanos 
   Question 1: The task can be performed without calling wait() in the parent. We can use a for loop or the function sleep(), implmented in the parent process. 
*********************************************/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  printf("hello world (pid:%d)\n", (int) getpid());
  int rc = fork();
  if (rc < 0) {
    // fork failed
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    // child (new process)
    printf("hello, I am child (pid:%d)\n", (int) getpid());
  } 
  else 
  {
    
      //for (int i = 0; i < 1000000; i++)
      //{
        //  ;
      //}
    // parent goes down this path (main)
    sleep(1);
    printf("goodbye, I am parent of %d (pid:%d)\n", rc, (int) getpid());
  }
  //printf("Value of x at the end: %d\n", x);
  return 0;
}
