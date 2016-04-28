package View;

import Control.AccountManager;
import Control.DAO;
import Model.Account;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by Angel on 16/4/28.
 */
public class SearchUI extends JFrame {
    String tel;

    JPanel blankPanel1=new JPanel();
    JPanel blankPanel2=new JPanel();
    JPanel searchPanel=new JPanel();
    JLabel searchLabel=new JLabel("输入手机号码",JLabel.LEFT);
    JTextField telText=new JTextField();
    JButton searchButton=new JButton("查询");

    public SearchUI(){
        super("电话费缴费系统");
        setSize(300,400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        GridLayout gridLayout=new GridLayout(3,1,40,10);
        setLayout(gridLayout);

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
        telText.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tel=telText.getText();
            }
        });

        searchButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //search accounts
                //Account account=DAO.find(tel);
                Account account=new Account("15221622858", (float) 32.45,400,2);
                AccountManager manager=new AccountManager(account);
                float bill=manager.computeBill();

                setVisible(false);
                AccountUI accountUI=new AccountUI(account,bill,"1.5折");
            }
        });
    }


}
