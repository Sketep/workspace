#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t my_strlen(const char *s) {
  size_t len = 0;

  while (*s != '\0') {
    len++;
    s++;
  }
  return len;
}

char *my_strcpy(char *dst, const char *src) {
  char *final = dst;
  while (*src != '\0') {
    *dst = *src;
    dst++;
    src++;
  }
  *dst = *src; // handle null terminator
  return final;
}

int my_strcmp(const char *a, const char *b) {
  while (*a == *b && *a != '\0' && *b != '\0') {
    a++;
    b++;
  }
  return *a - *b;
}

int main(void) {
  printf("%zu\n", my_strlen(""));
  printf("%zu\n", my_strlen("Five"));

  char buf[16];
  printf("%s\n", my_strcpy(buf, "Hey"));

  printf("%d\n", my_strcmp("Short", "Shorter"));
  printf("%d\n", my_strcmp("Short", "Sharter"));
  return EXIT_SUCCESS;
}
