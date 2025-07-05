#include "json-c/json_object.h"
#include "json-c/json_tokener.h"
#include "json-c/json_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 2048
#define MAX_STR_LEN (1024 * 1024)

/**
 * Reads stdin to a dynamically allocated buffer.
 *
 * @param str_ptr Pointer to the buffer pointer.
 * @return Number of characters read or -1 on error.
 */
ssize_t read_input(char **str_ptr) {
  FILE *input = stdin;
  char *str = NULL;

  if (!input) {
    fprintf(stderr, "Error: failed to use stdin");
    return -1;
  }

  ssize_t len = 0;
  size_t line_max = 0;
  char line[MAX_LINE_LEN];

  while (fgets(line, MAX_LINE_LEN, stdin) != NULL) {
    fflush(stdout);

    size_t line_len = strlen(line);

    if (len + line_len + 1 > MAX_STR_LEN) {
      fprintf(stderr, "Error: input exceeds %d\n", MAX_STR_LEN);
      free(str);
      return -1;
    }

    if (len + line_len + 1 > line_max) {
      line_max = len + line_len + 1;
      str = realloc(str, line_max);
    }

    memcpy(str + len, line, line_len);

    len += line_len;
  }

  *str_ptr = str;

  return len;
}

int main() {
  char *str = NULL;

  if (read_input(&str) == -1) {
    return 1;
  }

  json_object *root = json_tokener_parse(str);
  if (!root) {
    fprintf(stderr, "Error: failed to parse json\n");
    return 1;
  }
  free(str);

  json_object *layers = NULL;
  if (json_object_object_get_ex(root, "layers", &layers) == 0) {
    fprintf(stderr, "Error: invalid object, 'layers' not found\n");
    return 1;
  }

  int layers_len = json_object_array_length(layers);
  if (layers_len < 1) {
    fprintf(stderr, "Error: manifest has no layers\n");
    return 1;
  }

  for (int i = 0; i < layers_len; i++) {
    json_object *layer = json_object_array_get_idx(layers, i);

    json_object *digest = NULL;
    if (json_object_object_get_ex(layer, "digest", &digest) == 0) {
      fprintf(stderr, "Error: malformed layer, 'digest' not found\n");
      return 1;
    }

    json_object *annotations = NULL;
    if (json_object_object_get_ex(layer, "annotations", &annotations) == 0) {
      fprintf(stderr, "Error: malformed layer, 'annotations' not found\n");
      return 1;
    }

    json_object *title = NULL;
    if (json_object_object_get_ex(annotations, "org.opencontainers.image.title",
                                  &title) == 0) {
      fprintf(stderr, "Error: malformed layer, "
                      "'org.opencontainers.image.title' not found\n");
      return 1;
    }

    printf("  * %s: %s\n", json_object_get_string(title),
           json_object_get_string(digest));
  }

  json_object_put(root);
  return 0;
}
