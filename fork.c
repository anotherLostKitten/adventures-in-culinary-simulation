#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(){
  printf("who would win in a fight, my first child process or my second child process???\n");
  int fork2=0,fork1=fork();
  if(fork1)
    fork2=fork();
  if(fork1&&fork2) {// daddy
    int message=0,first=wait(&message);
    printf("baby with pid %d exited in %d seconds.\n",first,WEXITSTATUS(message));
  } else {// baby
    printf("hi, my name is %d...\n", getpid());
    unsigned int myfile = open("/dev/random",O_RDONLY),r;
    read(myfile, &r, sizeof(int));
    r=r%16+5;
    printf("%d\n",r);
    close(myfile);
    sleep(r);
    printf("bye bye!!\n");
    return r;
  }
  printf("parent process.... OUT!!!!!!!!!!!!\n");
  return 0;
}
