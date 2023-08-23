#include "s21_grep_support.h"

void making_pattern(const char *patt, flags flag, regex_t *pattern) {
  int mode = REG_EXTENDED;

  if (flag.i) mode = REG_ICASE;

  regcomp(pattern, patt, mode);
}

void printing(const char *name, FILE *fp, flags flag, regmatch_t flagopattern,
              regex_t pattern) {
  char *buf = NULL;
  size_t size = 0;
  int res, count = 0, string_number = 0;
  int length;

  while ((length = getline(&buf, &size, fp)) != -1) {
    if (buf[length - 1] != '\n') {
      buf[length] = '\n';
      buf[length + 1] = '\0';
    }
    res = regexec(&pattern, buf, 0, NULL, 0);
    if (flag.v) {
      if (res == 0) {
        continue;
      } else {
        printf("%s", buf);
      }
    } else if (flag.c) {
      if (res == 0) {
        count++;
      }
    } else if (flag.l) {
      if (res == 0) {
        printf("%s\n", name);
        break;
      }
    } else if (flag.o) {
      while (regexec(&pattern, buf, 1, &flagopattern, 0) == 0) {
        for (int i = flagopattern.rm_so; i < flagopattern.rm_eo; i++) {
          printf("%c", buf[i]);
        }

        printf("\n");
        char *temp = calloc(size, sizeof(char));
        strcpy(temp, &buf[flagopattern.rm_eo]);
        strcpy(buf, temp);
        free(temp);
      }
    } else if (flag.n) {
      string_number++;
      if (res == 0) {
        printf("%d:%s", string_number, buf);
      }
    } else {
      if (res == 0) {
        printf("%s", buf);
      }
    }
  }

  if (flag.c) {
    printf("%d\n", count);
  }

  free(buf);
}

void printing_with_name(const char *name, FILE *fp, flags flag,
                        regmatch_t flagopattern, regex_t pattern) {
  char *buf = NULL;
  size_t size = 0;
  int found = 0, res, count = 0, string_number = 0;
  int length;

  while ((length = getline(&buf, &size, fp)) != -1) {
    if (buf[length - 1] != '\n') {
      buf[length] = '\n';
      buf[length + 1] = '\0';
    }
    res = regexec(&pattern, buf, 0, NULL, 0);
    if (flag.v) {
      if (res == 0) {
        continue;
      } else {
        printf("%s:%s", name, buf);
      }
    } else if (flag.c) {
      if (res == 0) {
        count++;
      }
    } else if (flag.l) {
      if (res == 0) {
        printf("%s\n", name);
        break;
      }
    } else if (flag.n) {
      string_number++;
      if (res == 0) {
        printf("%s:%d:%s", name, string_number, buf);
      }
    } else if (flag.h) {
      if (res == 0) {
        printf("%s", buf);
      }
    } else if (flag.o) {
      while (regexec(&pattern, buf, 1, &flagopattern, 0) == 0) {
        found++;
        if (found == 1) {
          printf("%s:", name);
        }
        for (int i = flagopattern.rm_so; i < flagopattern.rm_eo; i++) {
          printf("%c", buf[i]);
        }

        printf("\n");
        char *temp = calloc(size, sizeof(char));
        strcpy(temp, &buf[flagopattern.rm_eo]);
        strcpy(buf, temp);
        free(temp);
      }
      found = 0;
    } else {
      if (res == 0) {
        printf("%s:%s", name, buf);
      }
    }
  }

  if (flag.c) {
    printf("%s:%d\n", name, count);
  }

  free(buf);
}
