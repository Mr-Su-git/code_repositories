package 第二章例题.获取素数;
import java.util.Scanner;
// 输入:length=所需素数的个数
// 输出:长度为length的素数表
// 算法思想:如果x不能整除比它小的任何一个素数,那么它(x)也必定是个素数
public class example_3 {
    public static void main(String args[]){
        System.out.print("请输入想要获取的素数的个数:") ;
        //输入控制部分
        Scanner reader = new Scanner(System.in) ;
        int length = 0 ;
        boolean valid = false ; //判别正确输入的标志
        while(!valid){
            if(reader.hasNextInt()){
                int num = reader.nextInt() ;
                if(num >= 0){
                    valid = true ;
                    length = num ;
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
        int[] arr = new int[length] ; //存放素数的数组
        int count = 1 ; //记录素数个数同时也可充当数组下标使用
        arr[0] = 2 ;
        System.out.println("数组长度为:"+arr.length) ;
        MAIN_LOOP:
        for(int x = 3 ; count < arr.length; x++){
            for(int i = 0 ; i < count ; i++){
                if(x % arr[i] == 0){
                    continue MAIN_LOOP ; //直接下一次x遍历开始 同时防止循环后将x加入素数表中
                }
            }
            arr[count++] = x ;
             //如果x不能整除素数表中的任何一个素数 那么它也必定是个素数
            // 将x加入素数表并将下标加一
        }
        System.out.print("素数表为:") ;
        for(int k : arr){
            System.out.print(k+" ") ;
        }
    }
}