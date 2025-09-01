#include <math.h>
#include <stdio.h>
#include <string.h>

#include "internal.h"

int8_t has_changed(struct Editor *editor) {
  FILE *fptr = fopen(editor->curr_file_path,
                     "ab+"); // Open file with read permissions
  if (!fptr)
    return ERR_ERRNO;

  ssize_t read;
  size_t len = 0;
  char *line = NULL;

  uint64_t file_hash = 0;
  uint32_t index = 0;
  while ((read = getline(&line, &len, fptr)) != -1) {
    for (char *ch = line; *ch != '\0'; ++ch) {
      file_hash += *ch * pow(2, index % PRIME_HASH_NUMBER);
      ++index;
    }
  }

  free(line);
  fclose(fptr);
  return file_hash != editor->original_hash;
}
