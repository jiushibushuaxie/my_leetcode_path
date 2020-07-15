#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;
//插入排序
//给定一个int数组A及数组的大小n，请返回排序后的数组。
//
class InsertionSort {
public:
    int* insertionSort(int* A, int n) {
        // write code here
        for(int i=1;i!=n;i++){           //i从1开始,表示待插入的那个数，注意i前面的数已经从小到大排好序了
            for(int j=0;j!=i;j++){
                if(A[j]>A[i])           //如果插入是中间位置，后续数组元素的移位也是通过swap来实现的。
                    swap(A[i],A[j]);
            }
        }
        return A;
    }
};
