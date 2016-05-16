package View;

import com.sun.tools.javac.comp.Flow;

import javax.swing.*;
import java.awt.*;

/**
 * Created by Angel on 16/4/28.
 */
public class RechargeUI extends JFrame {
    JPanel row1=new JPanel();
    JLabel label;

    JPanel row2=new JPanel();
    JButton moneyButton1;
    JButton moneyButton2;
    JButton moneyButton3;
    JButton moneyButton4;
    JButton moneyButton5;
    JButton moneyButton6;

    JPanel row3=new JPanel();
    JButton okButton;

    public RechargeUI(){
        super("电话费缴费系统");
        setSize(300,400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        GridLayout gridLayout=new GridLayout(3,1,10,10);
        setLayout(gridLayout);
        setLocation(300,300);

        FlowLayout flowLayout=new FlowLayout(FlowLayout.LEFT,40,10);
        row1.setLayout(flowLayout);
        label=new JLabel("充值金额");
        row1.add(label);
        add(row1);

        GridLayout gridLayout1=new GridLayout(2,3,10,40);
        row2.setLayout(gridLayout1);
        moneyButton1=new JButton("500");
        moneyButton2=new JButton("300");
        moneyButton3=new JButton("100");
        moneyButton4=new JButton("50");
        moneyButton5=new JButton("30");
        moneyButton6=new JButton("10");
        row2.add(moneyButton1);
        row2.add(moneyButton2);
        row2.add(moneyButton3);
        row2.add(moneyButton4);
        row2.add(moneyButton5);
        row2.add(moneyButton6);
        add(row2);

        FlowLayout flowLayout1=new FlowLayout(FlowLayout.RIGHT);
        row3.setLayout(flowLayout1);
        okButton=new JButton("确定");
        row3.add(okButton);
        add(row3);

        setVisible(true);

        //Action Listeners


    }

}
