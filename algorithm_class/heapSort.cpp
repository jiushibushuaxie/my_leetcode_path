#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;
//堆排序
/*
    堆是具有下列性质的完全二叉树:每个结点的值都大于或等于其左右孩子结点的值，称为大顶堆 ; 
    或者每个结点的值都小于或等于其左右孩子结点的值，称为小顶堆

    堆满足两个性质: 
    1、堆的每一个父节点都大于（或小于）其子节点； 
    2、堆的每个左子树和右子树也是一个堆。 

    堆的存储： 
    一般都用数组来表示堆，i结点的父结点下标就为(i–1)/2。它的左右子结点下标分别为2*i+1和2*i+2。

    堆排序： 
    由上面的介绍我们可以看出堆的第一个元素要么是最大值（大顶堆），要么是最小值（小顶堆），
    这样在排序的时候（假设共n个节点），直接将第一个元素和最后一个元素进行交换，然后从第一个元素开始进行向下调整至第n-1个元素。
    所以，如果需要升序，就建一个大堆，需要降序，就建一个小堆。 

    堆排序的步骤分为三步: 
    1、建堆（升序建大堆，降序建小堆）； 另外求前 k 大，用小顶堆，求前 k 小，用大顶堆。
    2、交换数据； 
    3、调整HeapAdjust。 

    时间复杂度：nlogn 空间复杂度 O(1)  不稳定
*/

class HeapSort {
public:
    void swap(int *A,int i, int j){
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    void HeapAdjust(int *A, int s, int n){      //这里的n表示长度减1，即最大下标
        int temp = A[s];

        for(int i=s*2+1;i<=n;i=i*2+1){   //2*s+1表示指向左子节点
            if(i<n && A[i]<A[i+1]) i++;     //左子节点小于右子节点，则++j
            if(temp<A[i]) {         //不满足大顶堆
                swap(A,s,i);        //交换
                s=i;                //将下一次判断的双亲结点变成此次判断双亲结点的子节点，继续判断，这一步一定要用
            }
        }
    }

    int* heapSort(int* A, int n) {
        //1、建堆  从n/2结点开始递减，因为从n/2开始递减 为非叶子节点
        //建大顶堆后，能保证第一个数为最大的，但不能保证前n/2-1都是最大的。
        for(int i=n/2-1; i>=0;i--){    //重要的一点，从下往上调整，非常重要，从下往上调整
            HeapAdjust(A,i,n-1);
        }
        
        //2、交换数据； 
        //3、调整HeapAdjust。
        //关键，每次调用HeapAdjust得到当前序列中最大的一个，同时当前序列长度减1
        for(int i=n-1;i>0;i--){        
            swap(A,0,i);                //先交换数据
            HeapAdjust(A,0,i-1);        //再进行堆调整，
        }
        return A;
    }
};
