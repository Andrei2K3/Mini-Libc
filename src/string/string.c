// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source) {
  /* TODO: Implement strcpy(). */
  size_t i;
  for (i = 0; source[i]; i++)
    destination[i] = source[i];
  destination[i] = 0;
  return destination;
}

char *strncpy(char *destination, const char *source, size_t len) {
  /* TODO: Implement strncpy(). */
  size_t i;
  for (i = 0; source[i] && i < len; i++)
    destination[i] = source[i];
  for (; i < len; i++)
    destination[i] = 0;
  return destination;
}

char *strcat(char *destination, const char *source) {
  /* TODO: Implement strcat(). */
  size_t i;
  for (i = 0; destination[i]; i++)
    ;
  size_t j;
  for (j = 0; source[j]; j++)
    destination[i + j] = source[j];
  destination[i + j] = 0;
  return destination;
}

char *strncat(char *destination, const char *source, size_t len) {
  /* TODO: Implement strncat(). */
  size_t i;
  for (i = 0; destination[i]; i++)
    ;
  size_t j;
  for (j = 0; source[j] && j < len; j++)
    destination[i + j] = source[j];
  destination[i + j] = 0;
  return destination;
}

int strcmp(const char *str1, const char *str2) {
  /* TODO: Implement strcmp(). */
  int i;
  for (i = 0; str1[i] && str2[i]; i++)
    if (str1[i] == str2[i])
      continue;
    else
      return str1[i] - str2[i];
  return str1[i] - str2[i];
  // return -1;
}

int strncmp(const char *str1, const char *str2, size_t len) {
  /* TODO: Implement strncmp(). */
  size_t i;
  for (i = 0; str1[i] && str2[i] && i < len; i++)
    if (str1[i] == str2[i])
      continue;
    else
      return str1[i] - str2[i];
  if (i == len)
    return 0;
  return str1[i] - str2[i];
  // return -1;
}

size_t strlen(const char *str) {
  size_t i = 0;

  for (; *str != '\0'; str++, i++)
    ;

  return i;
}

char *strchr(const char *str, int c) {
  /* TODO: Implement strchr(). */
  int i;
  for (i = 0; str[i]; i++)
    if (str[i] == c)
      return (char *)(str + i);
  return NULL;
}

char *strrchr(const char *str, int c) {
  /* TODO: Implement strrchr(). */
  char *aux = NULL;
  int i;
  for (i = 0; str[i]; i++)
    if (str[i] == c)
      aux = (char *)(str + i);
  return aux;
  // return NULL;
}

char *strstr(const char *haystack, const char *needle) {
  /* TODO: Implement strstr(). */
  int i;
  size_t lenghtNeedle = strlen(needle);
  for (i = 0; haystack[i]; i++)
    if (strncmp(haystack + i, needle, lenghtNeedle) == 0)
      return (char *)(haystack + i);
  return NULL;
}

char *strrstr(const char *haystack, const char *needle) {
  /* TODO: Implement strrstr(). */
  int i;
  size_t lenghtNeedle = strlen(needle);
  for (i = (int)strlen(haystack) - 1; i >= 0; i--)
    if (strncmp(haystack + i, needle, lenghtNeedle) == 0)
      return (char *)(haystack + i);
  return NULL;
}

void *memcpy(void *destination, const void *source, size_t num) {
  /* TODO: Implement memcpy(). */
  size_t i;
  char *dest = (char *)destination;
  const char *sour = (const char *)source;
  for (i = 0; i < num; i++)
    dest[i] = sour[i];
  return destination;
}

void *memmove(void *destination, const void *source, size_t num) {
  /* TODO: Implement memmove(). */
  int i;
  char *dest = (char *)destination;
  const char *sour = (const char *)source;

  if (dest - sour > 0) {
    for (i = (int)num - 1; i >= 0; i--)
      dest[i] = sour[i];
  } else {
    for (i = 0; i < (int)num; i++)
      dest[i] = sour[i];
  }
  return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num) {
  /* TODO: Implement memcmp(). */
  const unsigned char *cptr1 = (const unsigned char *)ptr1;
  const unsigned char *cptr2 = (const unsigned char *)ptr2;

  size_t i;
  for (i = 0; i < num; i++)
    if (cptr1[i] == cptr2[i])
      continue;
    else
      return cptr1[i] - cptr2[i];
  return 0;
}

void *memset(void *source, int value, size_t num) {
  /* TODO: Implement memset(). */
  unsigned char *sour = (unsigned char *)source;
  size_t i;
  for (i = 0; i < num; i++)
    sour[i] = value;
  return source;
}
