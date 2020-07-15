//整数二进制表示中1的个数

//方法一
int fun(unsigned int n){   //unsigned不能少
    int count = 0;
    while(n>0){
        n &= (n-1);
        count ++;
    }
    return count;
}


//方法二
int fun2(unsigned int n){   //unsigned不能少
    int count = 0;
    while(n!=0){
        if(n&1) count++;    //查看最低为是否为1
        n>>1;               //右移
    }
    return count;
}
