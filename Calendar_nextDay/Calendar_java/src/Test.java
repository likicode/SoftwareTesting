import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.util.ArrayList;

import javafx.scene.control.Cell;
import jxl.Sheet;
import jxl.Workbook;
/**
 * Created by Angel on 16/3/18.
 */
public class Test {
    public static void main(String[] args) throws FileNotFoundException {

        jxl.Workbook rwb=null;
        /* 读入测试文件 */
        try {
            InputStream is = new FileInputStream("test_input.xls");
            rwb=Workbook.getWorkbook(is);

            //获取第一张表表格
            Sheet readsheet=rwb.getSheet(0);
            int rsColums=readsheet.getColumns();
            int rsRows=readsheet.getRows();

            int[] currYears=new int[rsColums];
            int[] currMonths=new int[rsColums];
            int[] currDays=new int[rsColums];

            int[] nextYears=new int[rsColums];
            int[] nextMonths=new int[rsColums];
            int[] nextDays=new int[rsColums];

            for(int i=0;i<rsColums;i++){
                    jxl.Cell cell0=readsheet.getCell(0,i);
                    int currYear=Integer.parseInt(cell0.getContents());

                    jxl.Cell cell1=readsheet.getCell(1,i);
                    int currMonth=Integer.parseInt(cell1.getContents());

                    jxl.Cell cell2=readsheet.getCell(2,i);
                    int currDay=Integer.parseInt(cell2.getContents());

                    /*
                    Validate the input.
                    */
                    if(!Validate.isYear(currYear)){
                        System.out.println("Invalid Year");
                        return;
                    }
                    if(!Validate.isMonth(currMonth)){
                        System.out.println("Invalid Month");
                        return;
                    }
                    if(!Validate.isDay(currYear,currMonth,currDay)){
                        System.out.println("Invalid Day");
                        return;
                    }
                    System.out.printf("The Current Date is: %d-%d-%d  ", currYear, currMonth, currDay);

                /*
                Compute the next date.
                */
                int nextDay   =ComputeDate.getNextDay(currDay);
                int nextMonth =ComputeDate.getNextMonth(currMonth,currDay);
                int nextYear  =ComputeDate.getNextYear(currYear,currMonth,nextMonth);

                System.out.printf("The Next Date is: %d-%d-%d \n", nextYear, nextMonth, nextDay);
            }
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
