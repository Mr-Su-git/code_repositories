package 第二章例题.例题1;

import java.util.Scanner;
//简单数字读入
public class example_1 {
    public static void main(String args[]){
        System.out.println("请开始输入数字:") ;
        Scanner reader = new Scanner(System.in) ;
        int x = reader.nextInt() ;
        int sum = 0 ;
        for(int i = 0 ; i < 4 ; i++){
            sum = sum + x ;
            if(i != 3)x = reader.nextInt() ;
        }
        reader.close() ;
        System.out.println(sum) ;
    }
    // 在读取多段的数字时,在读取时通过循环控制,等读取下半段数据时可使用
    // reader.hasNextInt()等方法判断数据类型或数目
}
