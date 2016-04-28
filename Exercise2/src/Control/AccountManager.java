package Control;

import Model.Account;
/**
 * Created by Angel on 16/4/27.
 */
public class AccountManager {
    private Account account;

    public AccountManager(Account account){
        this.account=account;
    }

    public float computeBill(){
        float bill;
        float callDuration=account.getCallDuration();
        float unpaid=account.getUnpaid();

        if(callDuration<0){
            return -1;
            //"不合法通话分钟数"
        }
        if(unpaid<0||unpaid>11){
            return -2;
            //"不合法累计未缴费次数"
        }

        if(60<callDuration && callDuration<=120 && unpaid<=2){
            bill=(float)(25+callDuration*0.15*(1-0.015));
            return bill;
        }
        if(120<callDuration && callDuration<=180 && unpaid<=3){
            bill=(float)(25+callDuration*0.15*(1-0.020));
            return bill;
        }
        if(180<callDuration && callDuration<=300 && unpaid<=3){
            bill=(float)(25+callDuration*0.15*(1-0.025));
            return bill;
        }
        if(300<callDuration && unpaid<=4){
            bill=(float)(25+callDuration*0.15*(1-0.030));
            return bill;
        }

        bill=(float)(25+callDuration*0.15);
        return bill;
    }

    //月底结算
    private void debit(){
        int unpaid=account.getUnpaid();
        float balance=account.getBalance();
        float bill=computeBill();

        //月初余额不足，欠费一次
        if(balance<bill){
            account.setUnpaid(unpaid+1);
        }

        account.setBalance(balance=balance-bill);
    }

    //充值
    public void recharge(float amount){
        float balance=account.getBalance();
        account.setBalance(balance+amount);
    }

}
