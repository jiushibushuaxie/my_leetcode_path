#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;
//选择排序
//给定一个int数组A及数组的大小n，请返回排序后的数组。
//把最小的放在数组最前面，记录最下元素的下标
class SelectionSort {
public:
    int* selectionSort(int* A, int n) {
        // write code here
        for(int i=0;i!=n;++i){          //i表示前i个数已经排序号
            int min_index = i;          //min_index记录下最小元素的下标
            for(int j=i+1;j!=n;++j){    
                if(A[min_index]>A[j])
                    min_index = j;
            }
            swap(A[i],A[min_index]);
        }
        return A;
    }
};
