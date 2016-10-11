#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(){

  pid_t p;


  p = fork();
  if(p == -1){
    perror("probleme sur le fork.\n");
    return EXIT_FAILURE;
  }
  if(p == 0)
    printf("p = %d : donc je suis le fils. Mon pid est %d\n", p, getpid());
  else
    printf("p = %d : donc je suis le pere. Mon pid est %d\n", p, getpid());
}

