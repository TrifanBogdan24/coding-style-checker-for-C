// TELECOMMS PROTOCOL - TRIFAN BOGDAN CRISTIAN - 312CD
#ifndef _BYTE_STRING_H_
#define _BYTE_STRING_H_

int byteop_strlen(char *sir_unu);

int byteop_strcmp(char *sir_unu, char* sir_doi);

void byteop_strcpy(char *destinatie, char *sursa);

void byteop_strcat(char *destinatie, char *sursa);

char *byteop_strstr(char *destinatie, char *sursa);

char *byteop_strtok(char *str, char *sep);

#endif
