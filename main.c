#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stdio.h>
#include <stdint.h>
#include "stb_image_write.h"

char *usage_str = "\nUSAGE:\n\n\
    ./myimage <IMAGE FILE NAME>\n\n";

uint32_t pixels[] = {
  0xFF000000, 0xFF0000FF,
  0xFF0000FF, 0xFF000000,
};

void usage() {
  printf("%s", usage_str);
}

int main(int argc, char *argv[])
{
  int res;

  if (argc == 1) {
    usage();
    return 127;
  }

  char *filename = argv[1];

  printf("created an image: %s\n", argv[1]);
  res = stbi_write_png(filename, 2, 2, 4, pixels, 2*sizeof(uint32_t));
  return 0;
}
