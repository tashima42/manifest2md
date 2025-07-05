#include "json-c/json_object.h"
#include "json-c/json_tokener.h"
#include "json-c/json_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 2048

ssize_t read_line(char *buf, size_t size) {
  if (!fgets(buf, size, stdin)) {
    return -1;
  }

  buf[strcspn(buf, "\n")] = 0;

  return strlen(buf);
}

int main() {
  char buf[MAX_INPUT_LEN];
  ssize_t len;

  while (1) {
    fflush(stdout);

    len = read_line(buf, MAX_INPUT_LEN);
    if (len == -1) {
      break;
    }
  }

  json_object *root = NULL;
  root = json_tokener_parse(buf);
  if (!root) {
    fprintf(stderr, "failed to parse json\n");
    return 1;
  }

  json_object *layers = NULL;
  int res = json_object_object_get_ex(root, "mediaType", &layers);
  printf("res: %d\n", res);
  if (res == 0) {
    fprintf(stderr, "invalid object, 'layers' not found\n");
    return 1;
  }

  json_object_put(root);

  printf("mediaType: %s\n", json_object_get_string(layers));

  free(layers);

  return 0;
}
