//运动员跳水时，有n个评委打分，分数为10分制，且有两位小数。得分规则为：去掉最高分和最低分，求剩下分数的平均值，就是运动员的最终得分。
//
//Standard Input
//有多组测试数据。第一行是整数T (T <= 100)，表示测试数据的组数，随后有T组测试数据。每一组测试数据占一行，分别为整数n和n个评委的打分，相邻数之间有一个空格。其中，2<n≤100。
//
//Standard Output
//对应每组输入，输出该运动员的得分，保留2位小数。
#include<stdio.h>
int main(){
//   声明变量（需要求解平均值的数据的组数，以及循环变量）
    int T,i,j;
    scanf("%d",&T);
//    使用getchar()去消除掉数据组数读入后结尾的空格
    getchar();
    float N;
    float sum;
    float max,min;
    for(i=0;i<T;i++){
        sum=0.0;
//        读入裁判个数，就代表了给出的分数的个数
        scanf("%f",&N);
//        声明一个数组来记录各个裁判给出的成绩，加入强转为int型是数组声明只能是整数
        float grade[(int) N];
        scanf("%f",&grade[0]);
//        先将第一个裁判给出的成绩作为最大值和最小值，之后每读入一个数据就与之对比，并对最大值和最小值不断更新
        max=grade[0]; min=grade[0];
        sum+=grade[0];
        for(j=1;j<N;j++){
            scanf("%f",&grade[j]);
            if(max<=grade[j]) max=grade[j];
            if(min>=grade[j]) min=grade[j];
//            更新的同时将其加到sum上，求总和
            sum+=grade[j];
        }
        printf("%.2f\n",(sum-max-min)/(float)(N-2));
    }
}
