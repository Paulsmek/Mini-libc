// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	int n = strlen(source);
    for (int i = 0; i <= n; i++) {
        destination[i] = source[i];
    }
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	int n = len;
	if (strlen(source) < len) {
		n = strlen(source);
	}
    for (int i = 0; i <= n; i++) {
        destination[i] = source[i];
    }
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	strcpy(destination + strlen(destination), source);
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	unsigned len1 = strlen(destination);
    unsigned len2 = strlen(source);
    if (len2 < len) {
		strcpy(destination + len1, source);
    } else {
		strncpy(destination + len1, source, len);
		destination[len1 + len] = '\0';
    }
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	unsigned char litera1, litera2;
	const unsigned char *sir1 = (const unsigned char *) str1;
	const unsigned char *sir2 = (const unsigned char *) str2;
  	do {
		litera1 = (unsigned char) *sir1++;
		litera2 = (unsigned char) *sir2++;
		if (litera1 == '\0') {
			return litera1 - litera2;
		}
	} while (litera1 == litera2);
	return litera1 - litera2;
	return -1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	if (len == 0) return -1;
	unsigned char litera1, litera2;
	const unsigned char *sir1 = (const unsigned char *) str1;
	const unsigned char *sir2 = (const unsigned char *) str2;
	do {
		litera1 = (unsigned char) *sir1++;
		litera2 = (unsigned char) *sir2++;
		if (litera1 == '\0') {
			return litera1 - litera2;
		}
	} while (--len != 0 && litera1 == litera2);
	return litera1 - litera2;
	return -1;
}

size_t strlen(const char *str)
{
	size_t i = 0;
	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	char ch = c;
	for (; ; ++str)
	{
		if (*str == ch) return ((char *)str);
		if (*str == '\0') return (NULL);
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	char ch = c;
	int a = strlen(str) - 1;
	for (; ; a--)
	{
		if (*(str+a) == ch) return ((char *)(str+a));
		if (*(str+a) == '\0') return (NULL);
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	int len = strlen(needle);
    while (*haystack++) {
        if (strncmp(haystack - 1, needle, len) == 0) {
            return (char *) --haystack;
        }
    }
    return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	int len = strlen(needle);
	char * last = NULL;
    while (*haystack++) {
        if (strncmp(haystack - 1, needle, len) == 0) {
            last = (char *) (haystack - 1);
        }
    }
    return last;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *d = (char *)destination;
    const char *s = (const char *)source;
    for (; num; num--) {
        d[num - 1] = s[num - 1];
    }
    return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *d = (char *)destination;
    const char *s = (const char *)source;
	for (; num; num--) {
        d[num - 1] = s[num - 1];
    }
    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const unsigned char *d = (const unsigned char *)ptr1;
    const unsigned char *s = (const unsigned char *)ptr2;
    for (; num ; num--) {
        if (d[num - 1] < s[num - 1]) {
            return -1;
        } else if (d[num - 1] > s[num - 1]) {
            return 1;
        }
    }
    return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	if (num) {
		register unsigned char *p = (unsigned char*) source;
		while (num--) {
			*p++ = value;
		}
	}
	return source;
}


