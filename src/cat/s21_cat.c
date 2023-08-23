#include "s21_cat_support.h"

int main(int argc, char **argv) {
  int bflag = 0, eflag = 0, nflag = 0, sflag = 0, tflag = 0, vflag = 0;
  int opt;
  int option_index = 0;
  static struct option long_options[] = {{"number-nonblank", 0, 0, 'b'},
                                         {"number", 0, 0, 'n'},
                                         {"squeeze-blank", 0, 0, 's'},
                                         {NULL, 0, NULL, 0}};

  while ((opt = getopt_long(argc, argv, "benstET", long_options,
                            &option_index)) != -1) {
    switch (opt) {
      case 'b':
        bflag = 1;
        break;
      case 'e':
        eflag = 1;
        vflag = 1;
        break;
      case 'E':
        eflag = 1;
        break;
      case 'n':
        nflag = 1;
        break;
      case 's':
        sflag = 1;
        break;
      case 't':
        tflag = 1;
        vflag = 1;
        break;
      case 'T':
        tflag = 1;
        break;
      case '?':
        printf("usage: ./s21_cat [-benst] [file ...]\n");
        exit(1);
    }
  }

  int currentFile = optind;
  FILE *fp;

  while (currentFile < argc) {
    fp = fopen(argv[currentFile], "r");
    if (fp == NULL) {
      fprintf(stderr, "%s: %s: No such file or directory", argv[0],
              argv[currentFile]);
      exit(1);
    }

    if (sflag) {
      squeeze(fp);
    } else if (bflag) {
      blank(fp);
    } else if (nflag) {
      number(fp);
    } else if (eflag) {
      dollars(fp, vflag);
    } else if (tflag) {
      tabs(fp, vflag);
    } else {
      just_print(fp);
    }
    fclose(fp);
    currentFile++;
  }
  return 0;
}
