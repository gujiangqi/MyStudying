
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()

{

    char szTest[1000] = {0};

    int len = 0;

    FILE *fp = fopen("C:\\Users\\gujiangqi\\Desktop\\test.txt", "r");

    if (NULL == fp)

    {

        printf("failed to open dos.txt\n");

        return 1;
    }

    while (!feof(fp))

    {

        memset(szTest, 0, sizeof(szTest));

        fgets(szTest, sizeof(szTest) - 1, fp); // 包含了换行符          

        printf("%s", szTest);
    }

    fclose(fp);

    printf("\n");
    system("pause");
    return 0;
}