#include "s21_grep_support.h"

int main(int argc, char **argv) {
  int opt, i, e_count = 0;
  char buff_e_flag[1000] = {'\0'}, for_f_flag[1000] = {'\0'};
  flags flag = {0};
  regex_t pattern;
  regmatch_t flagopattern;
  FILE *fp, *forF;
  int option_index = 0;

  static struct option long_options[] = {{NULL, 0, NULL, 0}};

  while ((opt = getopt_long(argc, argv, "e:ivclnhsf:o", long_options,
                            &option_index)) != -1) {
    switch (opt) {
      case 'i':
        flag.i = 1;
        break;
      case 'v':
        flag.v = 1;
        break;
      case 'c':
        flag.c = 1;
        break;
      case 'l':
        flag.l = 1;
        break;
      case 'n':
        flag.n = 1;
        break;
      case 'h':
        flag.h = 1;
        break;
      case 's':
        flag.s = 1;
        break;
      case 'e':
        flag.e = 1;
        e_count++;
        if (e_count == 1) {
          // printf("%s", optarg);
          strcpy(buff_e_flag, optarg);
          making_pattern(optarg, flag, &pattern);
        } else {
          regfree(&pattern);
          strncat(buff_e_flag, "|", strlen(buff_e_flag));
          strncat(buff_e_flag, optarg, strlen(buff_e_flag));
          making_pattern(buff_e_flag, flag, &pattern);
        }
        break;
      case 'f':
        flag.f = 1;
        if ((forF = fopen(optarg, "r")) != NULL) {
          fgets(for_f_flag, sizeof(for_f_flag), forF);
          for_f_flag[strlen(for_f_flag) - 1] = '\0';
          making_pattern(for_f_flag, flag, &pattern);
          fclose(forF);
        } else {
          printf("grep: %s: No such file or directory\n", optarg);
        }
        break;
      case 'o':
        flag.o = 1;
        break;
      case '?':
        printf("usage: ./s21_grep [-eivclnhsfo] [pattern] [file ...]\n");
        exit(1);
        break;
    }
  }

  if (!flag.e && !flag.f) {
    making_pattern(argv[optind], flag, &pattern);
    optind++;
  }

  for (i = optind; i < argc; i++) {
    fp = fopen(argv[i], "r");
    if (argc - optind > 1) {
      if (fp != NULL) {
        printing_with_name(argv[i], fp, flag, flagopattern, pattern);
        fclose(fp);
      } else {
        if (flag.s) {
        } else {
          printf("grep: %s: No such file or directory\n", argv[i]);
        }
      }

    } else if (fp == NULL && !flag.s) {
      printf("grep: %s: No such file or directory\n", argv[i]);

    } else if (fp != NULL) {
      printing(argv[i], fp, flag, flagopattern, pattern);
      fclose(fp);
    }
  }
  regfree(&pattern);
  return 0;
}
