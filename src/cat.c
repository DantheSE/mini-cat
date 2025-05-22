#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define STANDARD_BUFFER 1024
static char buff[STANDARD_BUFFER];


int main(int argc, char *argv[])
{
  if (argc > 2 || argc <= 1)
  {
    char *helpMessage = "Usage: <compiled executable> <file_name>\ne.g ./cat test.txt\n";
    write(STDERR_FILENO, helpMessage, strlen(helpMessage));
    exit(EXIT_FAILURE);
  }

  int fd = open(argv[1], O_RDONLY);
  
  if (fd < 0)
  {
    perror("Error");
    exit(EXIT_FAILURE);
  }


  ssize_t bytes_read, n;

  while ((bytes_read = read(fd, buff, STANDARD_BUFFER)) > 0)
  {

    ssize_t bytes_written = 0;

    while (bytes_written < bytes_read)
    {
      n = write(STDOUT_FILENO, buff + bytes_written, bytes_read - bytes_written);
      bytes_written += n;
    }

    if (n < 0)
    {
      perror("Error");
      exit(EXIT_FAILURE);
    }

  }

  if (bytes_read < 0)
  {
    perror("Error");
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}

