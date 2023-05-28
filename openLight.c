//
// Created by Amazon Panda on 2023/3/19.
//
//有n盏灯, 编号为1~n. 第1个人把所有灯打开, 第2个人按下所有编号为2的倍数的开关(这些灯将被关掉), 第3个人按下所有编号为3的倍数的开关(其中关掉的灯将被打开, 开着的灯将被关闭), 依此类推. 一共有k个人, 问最后有哪些灯开着?
//
//Standard Input
//有多组测试数据. 输入的第一行是整数T(0<T≤100), 表示测试数据的组数. 每一组测试数据只有一行, 依次为正整数n和k, 两数之间有一个空格. k<=n<=1000.
//
//Standard Output
//对应每组输入, 输出一行还开着灯的编号, 按从小到大的顺序, 每个编号后有一个空格.
#include<stdio.h>
int main(){
    int T,i;
    scanf("%d",&T);
//Set the circle times
    for(i=0;i<T;i++){
        int n,k;
        int j,p,time=0;
        scanf("%d%d",&n,&k);
//Record the number of Lights and the number of person.
        for(j=1;j<=n;j++){
            for(p=1;p<=k;p++){
                if(j%p==0)
                    time++;
           }
//This loop is order to find the light of fixed-position which be touch by how many people.
            if(time%2==1)
                printf("%d ",j);
//This if conditional sentence is order to judge the times is odd or even numbers. The odd numbers instead of the light is open.The even numbers instead of the light is closed.
            time=0;
       }
    }
}
