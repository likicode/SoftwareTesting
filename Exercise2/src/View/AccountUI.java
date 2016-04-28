package View;



import Model.Account;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by Angel on 16/4/28.
 */
public class AccountUI extends JFrame {
    private Account account;

    JPanel row1=new JPanel();
    Chooser dateChooser;

    JPanel row2=new JPanel();
    JLabel balanceLabel1;
    JLabel balanceLabel2;
    JLabel unpaidLabel1;
    JLabel unpaidLabel2;
    JLabel durationLabel1;
    JLabel durationLabel2;
    JLabel billLabel1;
    JLabel billLabel2;
    JLabel discountLabel1;
    JLabel discountLabel2;

    JPanel row3=new JPanel();
    JButton rechargeButton;

    public AccountUI(Account account,float bill,String discount) throws HeadlessException{
        super("电话费缴费系统");
        this.account=account;

        setSize(300,400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        GridLayout gridLayout=new GridLayout(3,1,10,10);
        setLayout(gridLayout);

        FlowLayout flowLayout=new FlowLayout(FlowLayout.CENTER,10,40);
        row1.setLayout(flowLayout);
        dateChooser= Chooser.getInstance();
        javax.swing.JTextField text = new JTextField();
        text.setBounds(10, 10, 200, 30);
        text.setText("2013-10-11");
        dateChooser.register(text);
        row1.add(dateChooser);
        add(row1);

        GridLayout gridLayout1=new GridLayout(5,2,10,10);
        row2.setLayout(gridLayout1);
        balanceLabel1=new JLabel("账户余额：",JLabel.RIGHT);
        balanceLabel2=new JLabel(String.valueOf(account.getBalance()));
        unpaidLabel1=new JLabel("未缴费次数：",JLabel.RIGHT);
        unpaidLabel2=new JLabel(String.valueOf(account.getUnpaid()));
        durationLabel1=new JLabel("通话总时长：",JLabel.RIGHT);
        durationLabel2=new JLabel(String.valueOf(account.getCallDuration()));
        billLabel1=new JLabel("本月消费金额：",JLabel.RIGHT);
        billLabel2=new JLabel(String.valueOf(bill));
        discountLabel1=new JLabel("优惠方案：",JLabel.RIGHT);
        discountLabel2=new JLabel(discount);

        row2.add(balanceLabel1);
        row2.add(balanceLabel2);
        row2.add(unpaidLabel1);
        row2.add(unpaidLabel2);
        row2.add(durationLabel1);
        row2.add(durationLabel2);
        row2.add(billLabel1);
        row2.add(billLabel2);
        row2.add(discountLabel1);
        row2.add(discountLabel2);
        add(row2);

        FlowLayout flowLayout2=new FlowLayout(FlowLayout.RIGHT,10,10);
        row3.setLayout(flowLayout2);
        rechargeButton=new JButton("充值");
        row3.add(rechargeButton);
        add(row3);

        setVisible(true);

        //Listeners
        rechargeButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                setVisible(false);
                RechargeUI rechargeUI=new RechargeUI();
            }
        });
    }

}
