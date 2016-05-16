package Control;

import Model.Account;
import org.apache.poi.openxml4j.exceptions.InvalidFormatException;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.Array;
import java.util.ArrayList;

import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.ss.usermodel.Workbook;
import org.apache.poi.ss.usermodel.WorkbookFactory;
/**
 * Created by Angel on 16/4/28.
 */
public class DAO {
    private ArrayList<Account> accounts=new ArrayList<>();

    public DAO() throws IOException, InvalidFormatException {
        // Read .xsxl
        //创建要读入的文件的输入流
        InputStream inp = new FileInputStream("Accounts.xlsx");

        //根据上述创建的输入流 创建工作簿对象
        Workbook wb = WorkbookFactory.create(inp);
        //得到第一页 sheet
        //页Sheet是从0开始索引的
        Sheet sheet = wb.getSheetAt(0);
        int n=sheet.getPhysicalNumberOfRows();

        //从第二行开始遍历
        for (int i=0;i<n-1;i++) {
            Row row=sheet.getRow(i+1);

            Cell tel     =row.getCell(0);
            Cell balance =row.getCell(1);
            Cell duration=row.getCell(2);
            Cell unpaid  =row.getCell(3);

            String _tel=tel.toString();
            float _balance= Float.parseFloat(balance.toString());
            float _duration= Float.parseFloat(duration.toString());
            float _unpaid= Float.parseFloat(unpaid.toString());

            Account account=new Account(_tel,_balance,_duration,(int)_unpaid);
            accounts.add(account);
        }
        //关闭输入流
        inp.close();

    }

    public Account find(String tel){
        for(Account account:accounts){
            if(account.getTel().equals(tel)){
                return account;
            }
        }
        return null;
    }
}
