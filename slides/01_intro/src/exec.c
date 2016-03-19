/* Exec command passed as command line arguments with options */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  if (argc < 2) {
    return EXIT_SUCCESS;
  }

  pid_t pid = fork();
  if (!pid) { // child branch
    int rv = execvp(argv[1], argv + 1);
    if (rv == -1) {
      perror("execp");
      return EXIT_FAILURE;
    }
  }
  // parent branch
  pid = wait(NULL);
  if (pid == -1) {
    perror("wait");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
