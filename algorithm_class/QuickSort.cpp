#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <ctime>
using namespace std;
//快速排序 
//时间复杂度：平均nlogn   最坏n^2   最好nlogn   空间复杂度 O(logn) 最坏n  递归空间消耗    不稳定
/*
    1、挑选基准值：从数列中挑出一个元素，称为 “基准”（pivot）一般选数组最后一个 ；

    2、分割：重新排序序列，所有比基准值小的元素摆放在基准前面，所有比基准值大的元素摆在基准后面（与基准值相等的数可以到任何一边）。在这个分割结束之后，对基准值的排序就已经完成；

    3、递归排序子序列：递归地将小于基准值元素的子序列和大于基准值元素的子序列排序。

    递归到最底部的判断条件是序列的大小是零或一，此时该数列显然已经有序。

    选取基准值有数种具体方法，此选取方法对排序的时间性能有决定性影响。
*/

void swap(int *A, int i, int j){   //交换数组中i,j下标元素值
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }

class QuickSort {
public:
    void partition(int *A, int start, int end){   //递归的思想，与归并排序一样
        if (start >= end)      //递归结束条件
            return;
        
        //基础方法：选取基准为最后一个值 pivot=end
        int curval = A[end];   

        //  优化方法一：随机基准
        // srand(time(0));
        // int pivot = rand()%(end - start) + start;   
        // swap(A, pivot, end); //把随机基准位置的元素和end位置元素互换
        // int curval = A[end];

        //  优化方法二：三数取中： 取第一个数，最后一个数，第（N/2）个数。三个数数值中间的那个数作为基准值。
        // int mid = start + (end - start)/2;
        // if (A[start] > A[mid])  swap(A, start, mid);   
        // if (A[start] > A[end])  swap(A,start,end);        //此时end为中数
        // if (A[mid]   < A[end])  swap(A, mid,end);
        // //上面三步完成之后，A[end]就是三个数中中间的那个数
        // int curval = A[end];


        int cur = start - 1;    // 很重要
 
        for (int i = start; i < end; ++i){   //两个指针，cur和i
            if (A[i] < curval){
                ++cur;
                swap(A, cur, i);
            }
        }
 
        swap(A, ++cur, end);    //这一步很重要，把基准放到中间，同时cur指向基准，i这是指向end
 
        partition(A, start, cur - 1);  //递归
        partition(A, cur + 1, end);
    }
 
    int* quickSort(int* A, int n) {
        partition(A, 0, n - 1);
        return A;
    }
};

//双路快排，尽量写这种
class QuickSort2 {
public:
    void partition(int *A, int start, int end){
        if(start>=end)      //递归结束条件
            return;

        //产生start和end之间的随机数
        srand(time(0));
        int index = (rand() % (end - start + 1)) + start;
        //将选中的数字交换到end位置
        swap(A, index, end);
        
        int pivot = A[end]; 

        //双路快排初始值
        int i = start , j = end-1;
	    while (true){
            while (i <= end-1 && A[i] <= pivot)
                i++;
            while (j >= start && A[j] >= pivot)
                j--;
            if (i > j)      //最后肯定是i==j
                break;
            swap(A, i, j);  
            //下面这两行重要，swap交换之后，双方需要移动，否则会增加一次无用的比较
            i++;
            j--;
        }
        swap(A,i, end);
        partition(A,start,i-1);
        partition(A,i+1,end);
    }

    int* quickSort(int *A, int n){
        partition(A,0,n-1);
        return A;
    }
};

int main(int argc, char const *argv[])
{
    int A[] = {3,5,8,1,2,9,4,7,6};
    //int n = sizeof(A) / sizeof(A[0]);
    int n = end(A) - begin(A);
    QuickSort2 sorter;
    sorter.quickSort(A, n);
    
    for(int i=0;i!=n;i++){
        cout<<A[i]<<" ";
    }
    system("pause");
    return 0;
}
