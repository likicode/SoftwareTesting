/**
 * Created by Angel on 16/3/18.
 */
public class ComputeDate {

    public static int getNextDay(int currDay){

        int nextDay=currDay+1;
        nextDay=(nextDay-1)%Const.maxDay+1;
        return nextDay;
    }

    public static int getNextMonth(int currMonth,int currDay){
        int nextMonth=currMonth;
        if(Const.maxDay==currDay){
            nextMonth=currMonth%Const.maxMonth+1;
        }
        return nextMonth;
    }

    public static int getNextYear(int currYear,int currMonth,int nextMonth){
        int nextYear=currYear;

        if(currMonth!=nextMonth && nextMonth==1){
            nextYear++;
        }
        return nextYear;
    }
}
