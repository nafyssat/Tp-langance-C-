#include <stdio.h>
int main(int argc, char const *argv[])
{
    int t[] = {1, 2, 3}, *pt1;
    pt1 = t;
    printf("pt1=%p\n",pt1);
    int tab[3] = {1, 2, 3}, *pt2;
    pt2 = &tab[0];
    printf("pt2=%p\n",pt2);
    return 0;
}
