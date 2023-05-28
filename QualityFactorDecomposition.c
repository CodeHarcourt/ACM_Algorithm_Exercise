//读入一个自然数n, 将n分解为质因子连乘的形式输出.
//
//Standard Input
//有多组测试数据. 输入的第一行是整数T（0<T<=10000）, 表示测试数据的组数. 每一组测试数据只有一行, 由待分解的自然数n构成. 1<n<2^31.
//
//Standard Output
//对应每组输入, 输出一行分解结果, 具体样式参看样例
#include <stdio.h>
#include<math.h>
void Find(int n) {
    int i, j;
    int k = n;
    int p;
    p=sqrt(k);
//In order to judge the number is or not the prime number,I use this function to calculate the square root of this number.
    for(i=2;i<=p;i++) {
        if (n % i == 0) {
            break;
        }
    }
    if(i>p) {printf("%d",n);return;}
//Judge the number is or not the prime number,if the number is the prime number ,it will be have one prime factor(itself).
//if the number is not the prime number,it will have some prime factor.
    for (i = 1; i <=p; ) {
        i++;
        while (n % i == 0) {
            if (n == i) {
                printf("%d", i);
                return;
            }
            printf("%d*", i);
            n = n / i;
        }
    }
    if(i>p){printf("%d",n);}
}
//Decompose the number into output in the form of continuous multiplication of quality factors
int main(){
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        printf("%d=",n);
        Find(n);
        putchar('\n');
//Printf a null sting.
    }
}
