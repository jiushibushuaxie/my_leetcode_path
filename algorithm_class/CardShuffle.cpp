//给定N张扑克牌和一个随机函数，设计一个洗牌算法

//假定Ｎ=54，首先，我们有一个随机函数发生器，能够产生1-54之间的随机数，如何保证抽第一张牌有54种可能，抽第二张牌有53种可能，……
//可以这样做，假设扑克牌是一个54维的数组card， 我们要做的就是从这个数组中随机取一个元素，然后在剩下的元素里再随机取一个元素… 
//这里涉及到一个问题，就是每次取完元素后，我们就不会让这个元素参与下一次的选取。

#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

//随机产生序列号，类似选择排序(通过index=i + rand()%(n-i)保证前面选好的元素下标不会再次被使用），完成元素交换
void shuffle(int *cards, int n)
{
	if(cards==NULL)
		return ;
 
	srand(time(0));  //头文件在<ctime>中  ，time（0）可以输出一个与时间有关的数，相当于seed,在结合srand()函数即可产生真正的随机数
 
	for(int i=0;i<n-1;++i)
	{   //获得0—100的数rand()%100;
        //如果想获得100-200之间的数 100 + rand()%100
		//保证每次第i位的值不会涉及到第i位以前
		int index=i+rand()%(n-i);//保证前面已经确定的元素不会参加下面的选取
        //保证抽第一张牌有54种可能，抽第二张牌有53种可能....
        
        //交换而不是赋值
		int temp=cards[i];
		cards[i]=cards[index];
		cards[index]=temp;
	}
}
