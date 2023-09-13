/*********************************************
   Your name: Andrea Maria Ola Mejicanos 
   Question 1: Each call can be used in differnet ways as each one requires a slightly different implentation. It also provides flexibility for differnet cases , and we canns choose the one that fits better our final purpose.
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
    char *myargs[3];
    myargs[0] = strdup("ls");  
    myargs[1] = strdup("-a");   
    myargs[2] = NULL; 
    char *const envp[2] = {"", NULL};

    execle("/usr/bin/ls", "-a", NULL, envp);
    //execl("/usr/bin/ls", "ls", "-a", NULL);
    //execv("/usr/bin/ls", myargs);
    //execvp("ls", myargs);
    //exec("/usr/bin/ls", "ls", "-a", NULL);
    //execlp("ls", "ls", "-a", NULL);
    //execvpe("ls", myargs, envp);
  } 
  else 
  {
    int wc = wait(NULL);
    printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",rc, wc, (int)getpid());    
  }
  return 0;
}


