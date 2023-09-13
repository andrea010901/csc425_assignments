/*********************************************
   Your name: Andrea Maria Ola Mejicanos 
   Question 1: In this case no error occurs, but nothing is printed to the screen. This is because we have closed the stdour file  descriptor.
*********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

  int rc = fork();
  if (rc < 0) {
    // fork failed
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    close(STDOUT_FILENO);
    open("./p4.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
    printf("Child MessageÂ\n");
    char *myargs[3];
    execvp(myargs[0], myargs);
  } else {
    int rc_wait = wait(NULL);
  }
  return 0;

}
