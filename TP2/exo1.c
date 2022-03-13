#include<stdio.h>
int g(int);
int f(int n){
    if (n==1){
        return 2;
    }else{
        return 2*g(n-1);
    }
}
int g(int n){
    if(n==1){
        return 2;
    }else{
        return 3*f(n/2);
    }
}
int main(int argc, char const *argv[])
{
    printf("f(20)=%d\n",f(20));
    return 0;
}

