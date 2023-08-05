package 第二章例题.方法重构;

import java.util.Scanner;
// 方法重构 --> 相同方法名以参数数目、类型判断调用
public class example_2 {
    public static void main(String args[]){
        Scanner reader = new Scanner(System.in) ;
        System.out.println("请输入两个数:") ;
        int a = reader.nextInt() ;
        int b = reader.nextInt() ;
        System.out.println("方法一的结果:") ;
        add(a,b) ;
        System.out.println("方法二的结果:") ;
        add((double)a,(double)b) ;
        reader.close() ;
    }
    // 以下两个方法为方法重构实例
    // 方法名相同,而实际参数数目、类型会存在一定不同->系统判别调用方法的标注
    static void add(int a , int b ){
        System.out.println(a+b) ;
    }
    static void add(double a , double b){
        System.out.println(a+b) ;
    }
    // 从底层原理来说,是因为java程序编译时将方法编译为包含参数类型、个数
    // 和返回值的一个结构体从而分辨实际调用哪个方法.
    // 而C语言对方法的编译是形成一个指向方法的指针,所以一般不允许方法名相同情况的出现
}
