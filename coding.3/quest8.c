/*********************************************
   Your name: Andrea  Ola Mejicanos 
   Question 1: DNA
*********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
    int p[2];

    if (pipe(p) < 0)
      exit(1);

    int rc1 = fork();
    if (rc1 < 0) {
        fprintf(stderr, "f1 failed\n");
        exit(1);
    } else if (rc1 == 0) { 
       printf(" Child 1\n");
       dup2(p[1], 1); 
       printf("Child message \n");
    } else {
        int rc2 = fork();
        if (rc2 < 0) {
          fprintf(stderr, "fork 2 failed\n");
          exit(1);
        } else if (rc2 == 0) {
          printf(" Child 2 \n");
          dup2(p[0], STDIN_FILENO);
          char message[100];
          fgets(message,sizeof(message), stdin);
          printf("Child 2 message \"%s\n", message);     

        } else {
          int wc = waitpid(rc2, NULL, 0);
          printf("Parent: goodbye\n");
        }
    }
    return 0;
   }
