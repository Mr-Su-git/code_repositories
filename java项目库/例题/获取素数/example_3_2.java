package 第二章例题.获取素数 ;
import java.util.Scanner ;
// 输入:n 
// 输出:0-n之间的素数
// 算法思想:标记已知素数x的a倍数(ax<length,a这里最大取了4),将这些数标记,直至x==n结束
public class example_3_2 {
    public static void main(String args[]){
        System.out.print("请输入n的值:") ;
        //输入控制部分
        Scanner reader = new Scanner(System.in) ;
        int n = 0 ;
        boolean valid = false ; //判别正确输入的标志
        while(!valid){
            if(reader.hasNextInt()){
                int num = reader.nextInt() ;
                if(num >= 0){
                    valid = true ;
                    n = num ;
                }
                else{
                    System.out.print("您输入的数据类型或范围有误,请重新输入:") ;
                }
            }
            else{
                System.out.print("您输入的数据类型或范围有误,请重新输入:") ;
                reader.next() ;
            }
        }
        reader.close();
        //以上为输入控制部分
        boolean[] judge = new boolean[n] ;
        //标记数组初始化 true为素数 false为非素数
        for(int i = 0 ; i < judge.length ; i++){ 
            judge[i] = true ; 
        }
        // 开始遍历 从数字2所在位置开始 逐一判断
        // i:判断的初始数字x , k:判断数字的倍数a , 停止条件: i*k<judge.length -> a*x<n
        for(int i = 2 ;i < judge.length ; i++){
            if( judge[i] ){
                for(int k = 2 ; i * k < judge.length ; k++){
                    judge[i*k] = false ;
                }
            }
        }
        System.out.print(String.format("0-%d之间的素数表为:", n)) ;
        // 注意要从第3位开始读取判断 前两位为0、1默认排除在外，先前遍历时也是从2的位置开始的
        for(int i = 2 ; i < judge.length ; i++){
            if(judge[i]){
                System.out.print(i+" ") ;
            }
        }
    }
}