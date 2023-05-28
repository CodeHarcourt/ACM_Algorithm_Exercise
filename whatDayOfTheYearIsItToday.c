//任给三个用一个空格隔开的整数，依次表示年、月、日，说出它是今年的第几天。定义该年的第1天是1月1日。
//
//Standard Input
//有多组测试数据.输入的第一行是整数T(1<=T<=200), 表示随后测试数据的组数. 每组测试数据占一行, 由三个分别表示年、月、日的正整数构成. 相邻两个数之间有一个空格.
//
//Standard Output
//对应每组测试数据, 输出一行的结果.
#include<stdio.h>
int main(){
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        int year,month,day;
        int dayNum=0;
        //Scan the year、month、day from the input.
        scanf("%d %d %d",&year,&month,&day);
        int j;
        //if the month is the first month in the year,print the day to the screen.
        if(month==1) {printf("%d\n",day);continue ;}
        else{
            for(j=1;j<=(month-1);j++){
                switch(j){
                    case 1:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:
                    case 12:
                        dayNum+=31;
                        break;
                    case 4:
                    case 6:
                    case 9:
                    case 11:
                        dayNum+=30;
                        break;
                        //When the j is 2,we need to judge the year is or not leap year,because in leap year,the second month have 29 days.
                        //According to the tradition,"Four years a leap year, 100 years not leap year, 400 years and leap year"
                        //I design this case.
                    case 2:{
                        if(year%100==0&&year%400!=0) dayNum+=28;
                        else if(year%4==0||year%400==0) dayNum+=29;
                        else dayNum+=28;
                    }
                        break;
                }
            }
            dayNum+=day;
            printf("%d\n",dayNum);
            continue;
        }
    }
}
