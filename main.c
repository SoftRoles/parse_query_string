#if defined(_WIN32)
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char query_str[100] = "id=123&name=Huseyin";
  char *keyval = strtok(query_str, "&");
  printf("%s\n", query_str);

  while (keyval != NULL)
  {
    printf("%s: %d\n", keyval, strlen(keyval)); //printing each token

    char *keyval_copy = malloc(strlen(keyval) + 1);
    strncpy(keyval_copy, keyval, strlen(keyval));
    keyval_copy[strlen(keyval)] = '\0';
    printf("%s\n", keyval_copy);
    char *e = strchr(keyval_copy, '=');
    int index = (int)(e - keyval_copy);
    keyval_copy[index] = '\0';
    printf("%d\n", index);
    char *key = malloc(sizeof(char *) * (strlen(keyval_copy) + 1));
    strcpy(key, keyval_copy);
    printf("%s: %d\n", key, strlen(key));
    char *val = malloc(sizeof(char *) * (strlen(e + 1) + 1));
    strcpy(val, e + 1);
    printf("%s: %d\n", val, strlen(val));
    free(key);
    free(val);
    free(keyval_copy);
    keyval = strtok(NULL, "&");
  }

  return 0;
}
