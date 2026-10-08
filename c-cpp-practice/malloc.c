#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *make_greeting(void) {
  char tmp[] = "hello";
  char *greeting = malloc(sizeof(tmp));
  if (greeting == NULL) {
    perror("malloc() failed");
    return NULL;
  }
  strcpy(greeting, tmp);
  return greeting;
}

int main(void) {
  char *greeting = make_greeting();
  if (greeting == NULL) {
    return EXIT_FAILURE;
  }
  printf("%s\n", greeting);
  free(greeting);
  return EXIT_SUCCESS;
}
