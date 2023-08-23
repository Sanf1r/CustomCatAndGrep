#ifndef SRC_GREP_S21_GREP_SUPPORT_H_
#define SRC_GREP_S21_GREP_SUPPORT_H_

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _POSIX_C_SOURCE 200809L

typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
} flags;

void making_pattern(const char *patt, flags flag, regex_t *pattern);
void printing(const char *name, FILE *fp, flags flag, regmatch_t flagopattern,
              regex_t pattern);
void printing_with_name(const char *name, FILE *fp, flags flag,
                        regmatch_t flagopattern, regex_t pattern);

#endif  // SRC_GREP_S21_GREP_SUPPORT_H_
