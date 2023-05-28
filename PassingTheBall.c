//There are N people passing the ball.
//It starts from the first person, and each time the person who gets the ball should pass the ball to another one.
//So what is the number of situations in which the ball is passed back to the first person after passing M times.
//Including two integers N and M, and N∈[2,9],M∈[1,15].
#include<stdio.h>
#include <math.h>
//这道题是一道数学题，假设有n个人，m次传球，要求是求出最后一次传球回传给一号人物的情况次数
//传球给F(2)F(3)......F(n）的概率是一样的，所以F[1]+(N-1)*F[2]=(N-1)^M
//当1.2互传的时候，分两种情况，M为奇数或偶数的情况
//F[2]=F[1]+1(M为奇数)
//F[2]=F[1]-1(M为偶数)
//代入方程求解后有F[1]=((N-1)^M-N+1)/N(M为奇数)
//F[1]=((N-1)^M+N-1)/N(M为偶数)
int main()
{
    int n, m, num = 0;
    scanf("%d%d",&n,&m);
    if (m % 2 == 1)
    {
        num=((int)pow(n-1,m)-n+1)/n;
    }
    else
        num=((int)pow(n-1,m)+n-1)/n;
    printf("%d", num);
    return 0;
}