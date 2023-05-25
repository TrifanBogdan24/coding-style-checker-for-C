#ifndef _LINER_H_
#define _LINER_H_

int blank_line(char *sir);

int multiple_blank_lines(char const *f_name, char **txt, int nr_lines, int i, int *error);

void long_line(char const *f_name, char **txt, int nr_lines, int lin, int *error);

void comma(char const *f_name, char **txt, int nr_lines, int lin, int *error);

void trailing_whitespace(char const *f_name, char **txt, int nr_lines, int lin, int *error);

void space_bracket(char const *f_name, char **txt, int nr_lines, int lin, int *error);

void punct_si_virgula(char const *f_name, char **txt, int nr_lines, int lin, int *error);

void verify_for(char const *f_name, char **txt, int nr_lines, int lin, int *error);

void verify_if(char const *f_name, char **txt, int nr_lines, int lin, int *error);

#endif
