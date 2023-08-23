#ifndef SRC_CAT_S21_CAT_SUPPORT_H_
#define SRC_CAT_S21_CAT_SUPPORT_H_

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _POSIX_C_SOURCE 200809L

void just_print(void* fp);
void squeeze(void* fp);
void* s21_reallocf(void* str, size_t size);
void blank(void* fp);
void number(void* fp);
void dollars(void* fp, int vflag);
void tabs(void* fp, int vflag);

#endif  // SRC_CAT_S21_CAT_SUPPORT_H_
