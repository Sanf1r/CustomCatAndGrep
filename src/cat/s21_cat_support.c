#include "s21_cat_support.h"

void just_print(void* fp) {
  char ch;

  while ((ch = fgetc(fp)) != EOF) {
    putchar(ch);
  }
}

void squeeze(void* fp) {
  int lastLineEmpty = 0;
  char* buff = NULL;
  size_t buff_size = 0;
  int length;

  while ((length = getline(&buff, &buff_size, fp)) != -1) {
    int currentLineEmpty;

    if (length == 1 && buff[0] == '\n') {
      currentLineEmpty = 1;
    } else {
      currentLineEmpty = 0;
    }
    if (lastLineEmpty && currentLineEmpty) {
      continue;
    }
    lastLineEmpty = currentLineEmpty;
    for (int i = 0; i < length; i++) {
      printf("%c", buff[i]);
    }
  }
  if (buff) free(buff);
}

void* s21_reallocf(void* str, size_t size) {
  void* temp = realloc(str, size);
  if (temp) return temp;
  free(str);
  return NULL;
}

void blank(void* fp) {
  int line_num = 1;
  char* buff = NULL;
  size_t buff_size = 0;
  int length;

  while ((length = getline(&buff, &buff_size, fp)) != -1) {
    if (length >= 1 && buff[0] != '\n') {
      printf("%6d\t", line_num++);
    }

    for (int i = 0; i < length; i++) {
      printf("%c", buff[i]);
    }
  }
  if (buff) free(buff);
}

void number(void* fp) {
  int line_num = 1;
  char* buff = NULL;
  size_t buff_size = 0;
  int length;

  while ((length = getline(&buff, &buff_size, fp)) != -1) {
    printf("%6d\t", line_num++);

    for (int i = 0; i < length; i++) {
      printf("%c", buff[i]);
    }
  }
  if (buff) free(buff);
}

void dollars(void* fp, int vflag) {
  char ch;

  while ((ch = fgetc(fp)) != EOF) {
    if (vflag && ch >= 0 && ch != 9 && ch != 10 && ch <= 31) {
      printf("^");
      printf("%c", ch + 64);
      continue;
    }
    if (ch == '\n') {
      printf("$");
      putchar(ch);
    } else {
      putchar(ch);
    }
  }
}

void tabs(void* fp, int vflag) {
  char ch;

  while ((ch = fgetc(fp)) != EOF) {
    if (vflag && ch >= 0 && ch != 9 && ch != 10 && ch <= 31) {
      printf("^%c", ch + 64);
      continue;
    }
    if (ch == '\t') {
      printf("^I");
    } else {
      putchar(ch);
    }
  }
}
