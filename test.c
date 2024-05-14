#include <stdio.h>
#include <stdlib.h>

struct test
{
    int x;
};

void testcopy(int* x_p)
{
    printf("copied pointer: %p\n", x_p);    
}
void setx(struct test* param);

int main(int argc, char const *argv[])
{
    struct test* testStruct = malloc(sizeof(struct test));
    testStruct->x = 1;
    setx(testStruct);
    printf("test: %d", testStruct->x);

    return 0;
}

void setx(struct test* param)
{
    
    param->x = 100;
    return;
}
