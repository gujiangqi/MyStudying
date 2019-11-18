#include "string.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
char *strim(char *str)
{
    char *end, *sp, *ep;
    size_t len;

    sp = str;
    end = ep = str + strlen(str) - 1;
    // while (sp <= end && isspace(*sp))
    //     sp++;
    // while (ep >= sp && isspace(*ep))
    //     ep--;
    // len = (ep < sp) ? 0 : (ep - sp) + 1;
    // sp[len] = '\0';
    return sp;
}

int main(int argc, char const *argv[])
{
    char p[1024];
    strcpy(p, "ni = a");
    char *result = strim(p);
    printf("%c", result);
    system("pause");
    return 0;
}
