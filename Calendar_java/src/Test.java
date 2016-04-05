import java.awt.*;
import java.io.*;
import java.util.ArrayList;

import javafx.scene.control.Cell;
import jxl.Sheet;
import jxl.Workbook;
import jxl.write.Label;
import jxl.write.WritableSheet;
import jxl.write.WritableWorkbook;

/**
 * Created by Angel on 16/3/18.
 */
public class Test {
    public static void main(String[] args) throws FileNotFoundException {

        jxl.Workbook rwb=null;
        WritableWorkbook wwb=null;
        /* 读入测试文件 */
        try {
            InputStream is = new FileInputStream("Calendar_WeakRobustEquivalenceTest.xls");
            rwb = Workbook.getWorkbook(is);

            OutputStream os=new FileOutputStream("Calendar_output_WeakRobustEquivalenceTest.xls");
            wwb=Workbook.createWorkbook(os);
            WritableSheet sheet=wwb.createSheet("output",0);

            //获取第一张表表格
            Sheet readsheet = rwb.getSheet(0);
            int rsRows = readsheet.getRows();


            for (int i = 0; i < rsRows; i++) {
                //获取当前日期
                jxl.Cell cell0 = readsheet.getCell(0, i);
                int currYear = Integer.parseInt(cell0.getContents());

                jxl.Cell cell1 = readsheet.getCell(1, i);
                int currMonth = Integer.parseInt(cell1.getContents());

                jxl.Cell cell2 = readsheet.getCell(2, i);
                int currDay = Integer.parseInt(cell2.getContents());

                //将当前日期写到“Calendar_output_WeakRobustEquivalenceTest.xls”
                String input=currYear+"-"+currMonth+"-"+currDay;
                Label label=new Label(0,i,input);
                sheet.addCell(label);


                    /*
                    Validate the input.
                    */
                if (!Validate.isYear(currYear)) {
                    System.out.println("Invalid Year");
                    label=new Label(1,i,"Invalid Year");
                    sheet.addCell(label);
                    continue;
                }
                if (!Validate.isMonth(currMonth)) {
                    System.out.println("Invalid Month");
                    label=new Label(1,i,"Invalid Month");
                    sheet.addCell(label);
                    continue;
                }
                if (!Validate.isDay(currYear, currMonth, currDay)) {
                    System.out.println("Invalid Day");
                    label=new Label(1,i,"Invalid Day");
                    sheet.addCell(label);
                    continue;
                }
                //将计算出的下一天写到“Calendar_output_WeakRobustEquivalenceTest.xls”
                System.out.printf("The Current Date is: %d-%d-%d  ", currYear, currMonth, currDay);

                String output=currYear+"-"+currMonth+"-"+currDay;
                label=new Label(1,i,output);
                sheet.addCell(label);

                /*
                Compute the next date.
                */
                int nextDay = ComputeDate.getNextDay(currDay);
                int nextMonth = ComputeDate.getNextMonth(currMonth, currDay);
                int nextYear = ComputeDate.getNextYear(currYear, currMonth, nextMonth);

                System.out.printf("The Next Date is: %d-%d-%d \n", nextYear, nextMonth, nextDay);

        }
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
