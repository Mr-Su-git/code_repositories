#include <bits/stdc++.h>

using namespace std ;

char frac[730][730] ;

// 设置递归函数处理度数为n的分形
void setFrac(char frac[][730] , int start_x , int start_y , int n){
    if(n == 1)frac[start_x][start_y] = 'X' ;
    else {
        int L0 = (int)pow(3 , n-2) ;
        setFrac(frac , start_x+0 , start_y+0 , n-1) ; // 左下角分形的递归
        setFrac(frac , start_x+2*L0 , start_y+0 , n-1) ; // 右下角分形的递归
        setFrac(frac , start_x+L0 , start_y+L0 , n-1) ; // 中心部分分形的递归
        setFrac(frac , start_x+0 , start_y+2*L0 , n-1) ; // 左上角分形的递归
        setFrac(frac , start_x+2*L0 , start_y+2*L0 , n-1) ; // 右上角的递归
    }
}