#include "Chapter2.h"

using namespace std;

Chapter2::Chapter2()
{
    //ctor
}

Chapter2::~Chapter2()
{
    //dtor
}

void Chapter2::insertSort()
{
    cout<<"插入排序"<<endl;
    cout<<"实现思路： 抓牌思路，保证手中的牌始终有序，向桌子上抓一张牌时，对此牌排序。直到牌抓完"<<endl;
    cout<<"输入:{3,4,6,8,12,7,865}"<<endl;
    int array[]= {4,3,6,8,12,7,865};
    insertSortExecute(array,7);
    cout<<"输出:"<<endl;
    for(int i=0;i<7;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void Chapter2::insertSortExecute(int *array,int length)
{
    if(length<=2)
    {
        cout<<"无需排序"<<endl;
        return;
    }
    for(int catchedNum=1; catchedNum<length; catchedNum++)
    {
        int catchCard=array[catchedNum];
        int compareIndex=catchedNum-1;
        //逐一比较，直到找到抓上来的牌该塞进的位置
        while(compareIndex>=0&&array[compareIndex]>catchCard){
            array[compareIndex+1]=array[compareIndex];
            compareIndex-=1;
        }
        array[compareIndex+1]=catchCard;
    }
}

void Chapter2::mergeSort(){
    cout<<"归并排序"<<endl;
    cout<<"实现思路: 两个排好序的牌堆，比较值，较小的，加入第三个牌堆，第三个牌堆就是此两个牌堆的合并排序。\n"
                +string("注意为避免为空,两个排好序的堆加入了一个无穷大的数，保证堆不为空")<<endl;
    cout<<"输入:{3,4,6,8,12,7,865}"<<endl;
    int array[]= {4,3,6,8,12,7,865};
    mergeSortExecute(array,0,6);
    cout<<"输出:"<<endl;
    for(int i=0;i<7;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void Chapter2::mergeSortExecute(int *array,int p,int r){
    if(p<r){
        int q=(p+r)/2;
        mergeSortExecute(array,p,q);
        mergeSortExecute(array,q+1,r);
        merge(array,p,q,r);
    }
}

void Chapter2::merge(int *array,int p,int q,int r){
    int leftLength=q-p+1;
    int rightLength=r-q;
    int leftArray[leftLength+1];
    int rightArray[rightLength+1];

    for(int i=0;i<leftLength;i++){
        leftArray[i]=array[p+i];
    }

    for(int j=0;j<rightLength;j++){
        rightArray[j]=array[q+1+j];
    }

    leftArray[leftLength]=INT_MAX;
    rightArray[rightLength]=INT_MAX;

    int i=0;
    int j=0;
    for(int k=p;k<=r;k++){
        if(leftArray[i]<=rightArray[j]){
            array[k]=leftArray[i];
            i++;
        }else{
            array[k]=rightArray[j];
            j++;
        }
    }
}
