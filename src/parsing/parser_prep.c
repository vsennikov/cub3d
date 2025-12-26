#include "../../includes/cub3d.h"

static void basic_error_exit(char *msg) {
  printf("Error\n%s\n", msg);
  exit(1);
}

int name_validation(char *name) {
  int i;
  char *extension;

  i = 0;
  while (name[i]) {
    if (name[i] == '.' && name[i + 4] == '\0') {
      extension = ft_substr(name, i, 5);
      if (!extension)
        basic_error_exit("memory allocation during name_validation failed");
      if (ft_strncmp(extension, ".cub", 5) != 0) {
        free(extension);
        basic_error_exit("map not .cub");
      } else
        return (free(extension), 1);
    }
    i++;
  }
  basic_error_exit("map not .cub");
  return (1);
}