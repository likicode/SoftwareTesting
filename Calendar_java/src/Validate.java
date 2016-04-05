/**
 * Created by Angel on 16/3/18.
 */
public class Validate {

    public static boolean isYear(int y){
        if(y>=Const.minYear && y<=Const.maxYear){
            return true;
        }
        else{
            return false;
        }
    }

    public static boolean isMonth(int m){
        if(m>=1 && m<=Const.maxMonth){
            return true;
        }
        else{
            return false;
        }
    }

    public static void setMaxDay(int y,int m,int d){


        if(m==4|m==6|m==9|m==11){
            Const.maxDay=30;
            return;
        }
        if(m==2){
            if(isLeapYear(y)){
                Const.maxDay=29;
            }
            else{
                Const.maxDay=28;
            }
            return;
        }else {
            Const.maxDay = 31;
            return;
        }
    }

    public static boolean isDay(int y,int m,int d){
        setMaxDay(y,m,d);
        if(d>=1 && d<=Const.maxDay){
            return true;
        }
        else{
            return false;
        }
    }

    public static boolean isLeapYear(int y){
        if((y%4==0)&&(y%100!=0)){
            return true;
        }
        if(y%400==0){
            return true;
        }

        return false;
    }


}
