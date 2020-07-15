//问题描述
/*
    模式串匹配算法
*/


#include <iostream>
using namespace std;

int __next[20] = {-1};//全局变量int数组

void get_next(string temp, int next[])
{//求解next数组
    int len_temp = (int)temp.length();
    next[1] = 0;//KMP算法中j == 0时，已单独处理。故不必处理next[0],在本例中，在初始化next时，将next[0]=-1；
    int j = 1;
    int k = -1;//k表示temp数组的下标
    while (j < len_temp)//停止条件为 j==len_temp
    {//如何计算呢？ 从j=1开始一个一个计算，直到全部计算结束
        if (k == -1 || temp[j] == temp[k])//temp[j]?temp[k]的结果才是核心条件，k==0是对特殊条件的处理
        {
            next[++j] = ++k;
            /*
            j++;
            k++;
            if (temp[j] != temp[k])
                next[j] = k;
            else
                next[j] = next[k];
            */
        }//已知假设条件是next[j]=k,根据next函数定义可得next[j+1]=k+1
        else
        {
            k = next[k]; //为什么要用k=next[k]?
        }//因为在temp[j]?temp[k]为假后，需要计算P1···Pk在Pk匹配失败后需要移动到的位置，这恰恰也可以看作是部分的KMP算法
        //以P1···Plen_temp作为主串,以P1···Pk为字串在k处失配后的处理，故用k=next[k]
    }
}

int KMP(string str, string temp)
{
    int len_str = (int)str.length();
    int len_temp = (int)temp.length();
    int i=0;
    int j=0;
    while (i<len_str && j<len_temp)
    {
        if (str[i] == temp[j])//逐个字符进行对比
        {//为真，对比下一个字符
            i++;
            j++;
        }
        else
        {//为假时，有两种情形
            if (j == 0)
                i++;//在本轮匹配的第一个位置匹配失败，需移动到主串的下一个字符开始匹配
            else
                j = __next[j];//在本轮匹配的非第一个位置匹配失败，根据next数组确定从模式串的什么位置开始匹配
        }
    }
    if (j == len_temp)//返回数组下标
        return i - j;
    else
        return -1;
}

int main(int argc, const char * argv[]) {

    string str = "agctagcagctabcabdabcdagctg";
    string temp = "abcabdabcd";
    //  a  b  a  c
    //  0  0  1  0  ->1
    // -1  0  0  1  next[]
    
    //  a  a  b
    //  0  1  0 ->1
    // -1  0  1 next[]
    
    //  a  a  a  b
    //  0  1  1  0 ->1
    // -1  0  1  1 next[]
    
    //  a  b  c  a  b  d  a  b  c  d
    //  0  0  0  1  2  0  1  2  3  0 ->1
    // -1  0  0  0  1  2  0  1  2  3 next[]
    get_next(temp, __next);
    cout<<KMP(str, temp)<<endl;
    return 0;
}
