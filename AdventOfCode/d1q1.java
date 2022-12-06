import java.io.*;
import java.util.ArrayList;
public class d1q1{
    public static void main(String[] args) {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int max=0,max2=0,max3=0;
        int sum = 0;
        String num="0";
        do{
            try{
                num = br.readLine();
                if(num.equals("")) sum = 0;
                else sum += Integer.parseInt(num);
                if(sum > max3){
                    if(sum > max2){
                        if (sum > max){
                            max3 = max2;
                            max2 = max;
                            max = sum;
                        }else{
                            max3 = max2;
                            max2 = sum;
                        }
                    }else{
                        max3 = sum;
                    }
                }
            }catch(Exception e){
                System.out.println(e);
                max = 0;
            }
        }while(!num.equals("-1"));
        System.out.println(max + max2 + max3);
    }
}