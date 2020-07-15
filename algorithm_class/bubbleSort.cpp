#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;
//冒泡排序
//给定一个int数组A及数组的大小n，请返回排序后的数组。
//把最大的放在数组最后，然后比较的数组长度减一

class BubbleSort {
public:
    int* bubbleSort(int* A, int n) {
        // write code here
        for(int i=0;i!=n;++i){          //n-i表示要比较的数组长度，i表示已排序好的数组大小，把大的放在最后
            bool flag = true;           //当已经排序好了之后，flag可以减少不必要的迭代
            for(int j=0;j!=n-i-1;++j){  //j表示要比较的下标
                if(A[j]>A[j+1]){
                    int temp = A[j];
                    A[j] = A[j+1];
                    A[j+1] = temp;
                    flag = false;
                }
            }
            if(flag)
                break;
        }
        return A;
        
    }
};

int main(int argc, char const *argv[])
{
    int A[] = {2,3,4,7,1,5,8,6,9};
    //int n = sizeof(A) / sizeof(A[0]);
    int n = end(A) - begin(A);
    // int n = length(A);
    BubbleSort sorter;
    sorter.bubbleSort(A, n);
    for(int i=0;i!=n;i++){
        cout<<A[i]<<" ";
    }
    system("pause");
    return 0;
}
