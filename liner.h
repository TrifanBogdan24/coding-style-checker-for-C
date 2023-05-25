#ifndef _LINER_H_
#define _LINER_H_

int blank_line(char *sir);

int multiple_blank_lines(char const *f_name, char **txt, int nr_lin, int i, int *error);

void long_line(char const *f_name, char **txt, int idx, int *error);

#endif
