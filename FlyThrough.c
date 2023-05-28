//The home of flower fairies is being devastated by a monster called Littlefatcat.
// They have to leave the place where their generations lived with no other choices.
// CC, the greatest investigator of flower fairies, found a paradise in the west and will lead all the flower fairies there.
// This paradise is full of flowers and safe from attack of Littlefatcat. However, there are lots of huge rocks on the way to the paradise.
//Flower fairies are of different levels which are determined by their power.
// Fairies of higher level will fly higher. A fairy will persist in flying at the height corresponding to his or her level for honor and self-respect.
// Also, rocks on the way have specific height. When the route of a fairy hit a rock, the fairy will have to use magic to fly through the rock.
//Being aware of the height of all rocks and the specific height each fairy can fly at, CC want to know how many rocks each fairy will fly through
//The first line will be N M, representing for the numbers of rocks and fairies.
//The first line will be N M， representing for the numbers of rocks and fairies.
//The following line will give N numbers, giving the height of the rocks from the east to west.
//Then M lines followed. On the ith line, a number representing the specific height of fairy numbered i can fly at will be given.
//All numbers are positive and not bigger than 100000.
#include<stdio.h>
#include<stdlib.h>
// qsort的比较函数，从小到大进行排序
int comp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
//二分查找中的一类查找lower_bound，寻找大于X的最小数组下标
int lower_bound(int arr[], int N, int X){
    int mid;
    int low = 0;
    int high = N;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (X <= arr[mid]) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
    if(low < N && arr[low] < X) {
        low++;
    }
    return low;
}
int main(){
    int N,M,i,j;
//    读入数据N和M
    scanf("%d%d",&N,&M);
//    每一个getchar()是为了消除尾部输入的空格
    getchar();
    int rockHi[N];
    int floHi;
//    读入所有岩石的高度
    for(i=0;i<N;i++) scanf("%d",&rockHi[i]);
    getchar();
//    所有岩石的高度进行排序
    qsort(rockHi,N,4,comp);
    int sz = sizeof(rockHi) / sizeof(rockHi[0]);
    for(i=0;i<M;i++){
//        读入花仙子的飞行高度
        scanf("%d",&floHi);
        getchar();
//        当这个数值最高岩石的高度还要大的时候，是没有办法找到lower_bound的下标的，此时花仙子也不需要穿过岩石
        if(floHi>rockHi[N-1]) j=N;
//        二分查找去寻找下标
        else j=lower_bound(rockHi,sz,floHi);
//        N-j就是穿过岩石的数目
        printf("%d\n",(N-j));
    }
}
