/*
    1300. 转变数组后最接近目标值的数组和
    难度：中等
    给你一个整数数组 arr 和一个目标值 target ，请你返回一个整数 value ，
    使得将数组中所有大于 value 的值变成 value 后，
    数组的和最接近  target （最接近表示两者之差的绝对值最小）。
    如果有多种使得和最接近 target 的方案，请你返回这些整数中的最小值。

    请注意，答案不一定是 arr 中的数字。

示例 1:
    输入：arr = [4,9,3], target = 10
    输出：3
    解释：当选择 value 为 3 时，数组会变成 [3, 3, 3]，和为 9 ，这是最接近 target 的方案。

示例 2：
    输入：arr = [2,3,5], target = 10
    输出：5

示例 3：
    输入：arr = [60864,25176,27249,21296,20204], target = 56803
    输出：11361
*/

//解法
/*
    纯逻辑分析
    很多if else
    
    应该要双重二分
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int sum = 0;
        int sum_pre = 0;
        int length = arr.size();
        int ans = 0;
        int left_value = 0;
        int right_value= 0;
        sort(arr.begin(),arr.end());        //先排序

        for(int i=0;i<length;++i){
            sum_pre +=arr[i]; 
            sum = sum_pre + (length-i-1)*arr[i];
            if(sum == target){
                ans = arr[i];
                return ans;
            }
            else if(sum<target){
                if(i==length-1){
                    return arr[i];
                }
                else{
                    continue;
                }
            }
            else if(i>0&&sum>target){       //找到左右边界。
                left_value = arr[i-1];
                right_value = arr[i];
                while(left_value<=right_value){
                    int sub_sum = sum_pre - arr[i] + (length-i)*left_value;
                    if(sub_sum<target){
                        left_value++;
                    }
                    else if(sub_sum == target){
                        break;
                    }
                    else{
                        if((sub_sum - target)>=(target - sub_sum + length -i)){
                            --left_value;
                            break;
                        }
                        else{
                            break;
                        }
                    }
                }
                ans = left_value;
                return ans;
            }
            else if(i==0 && sum>target){
                if((target -(target/length)*length)>((target/length+1)*length-target)){
                    ans = target/length+1;
                }
                else{
                    ans = target/length;
                }
                return ans;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> arr = {4,3,9};
    Solution solver;
    int ans = solver.findBestValue(arr, 10);
    cout<<ans<<endl;
    system("pause");
    return 0;
}