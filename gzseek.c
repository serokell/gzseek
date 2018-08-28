#include <glib.h>
#include <stdio.h>

#define MIN_GZIP_SIZE 18

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s FILE\n", argv[0]);
    return EXIT_FAILURE;
  }

  g_autoptr(GMappedFile) file = g_mapped_file_new(argv[1], FALSE, NULL);

  gsize len = g_mapped_file_get_length(file);
  gsize ptr = 0;

  gchar *data = g_mapped_file_get_contents(file);

  while (len - MIN_GZIP_SIZE > ptr && data[ptr] != 0x1F &&
         data[ptr + 1] != 0x8B && data[ptr + 2] != 0x08)
    ptr++;

  fwrite(&data[ptr], sizeof(char), len - ptr, stdout);
}
