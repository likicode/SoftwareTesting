package View;

import Control.AccountManager;
import Control.DAO;
import Model.Account;
import org.apache.poi.openxml4j.exceptions.InvalidFormatException;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

/**
 * Created by Angel on 16/4/28.
 */
public class SearchUI extends JFrame {
    DAO dao;
    String tel;

    JPanel blankPanel1=new JPanel();
    JPanel blankPanel2=new JPanel();
    JPanel searchPanel=new JPanel();
    JLabel searchLabel=new JLabel("输入手机号码",JLabel.LEFT);
    JTextField telText=new JTextField();
    JButton searchButton=new JButton("查询");

    public SearchUI() throws IOException, InvalidFormatException {
        super("电话费缴费系统");

        // Try to read all the accounts
        try {
            dao=new DAO();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (InvalidFormatException e) {
            e.printStackTrace();
        }


        setSize(300,400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        GridLayout gridLayout=new GridLayout(3,1,40,10);
        setLayout(gridLayout);
        setLocation(300,300);


        add(blankPanel1);

        GridLayout gridLayout1=new GridLayout(3,1,40,10);
        searchPanel.setLayout(gridLayout1);
        searchPanel.add(searchLabel);
        searchPanel.add(telText);
        searchPanel.add(searchButton);
        add(searchPanel);

        add(blankPanel2);
        setVisible(true);

        // Action Listeners
        searchButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //search accounts
                tel=telText.getText();
                Account account=dao.find(tel);
                //Account account=new Account("15221622858", (float) 32.45,400,2);
                AccountManager manager=new AccountManager(account);
                String discount=manager.computeBill();

                setVisible(false);
                AccountUI accountUI=new AccountUI(account,discount);
            }
        });

    }


}
