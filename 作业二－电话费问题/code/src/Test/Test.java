package Test;

import Control.AccountManager;
import Model.Account;
import org.apache.poi.openxml4j.exceptions.InvalidFormatException;
import org.apache.poi.ss.usermodel.*;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

/**
 * Created by Angel on 16/4/29.
 */
public class Test {
    public static void main(String[] args) throws IOException, InvalidFormatException {
        // Read the test files
        InputStream inp=new FileInputStream("决策表测试用例.xlsx");
        System.out.println("决策表测试用例:");

//        InputStream inp=new FileInputStream("等价类测试用例.xlsx");
//        System.out.println("等价类测试用例:");

//        InputStream inp=new FileInputStream("边界值测试用例.xlsx");
//        System.out.println("边界值测试用例:");

        Workbook wb= WorkbookFactory.create(inp);
        Sheet sheet=wb.getSheetAt(0);
        int n=sheet.getPhysicalNumberOfRows();


        //从第二行开始遍历
        for (int i=0;i<n-1;i++) {
            System.out.println(i);
            Row row=sheet.getRow(i+1);

            Cell cell1=row.getCell(0);
            Cell cell2=row.getCell(1);
            Cell cell3=row.getCell(2);

            float _duration= Float.parseFloat(cell1.toString());
            int _unpaid= Integer.parseInt(cell2.toString());
            String _discount=cell3.toString();

            Account account=new Account(_duration,_unpaid);
            AccountManager manager=new AccountManager(account);

            String discount=manager.computeBill();

            if(discount.equals(_discount)){
                System.out.println("pass");
            }else {
                System.out.println("fail");
            }
        }
    }
}
