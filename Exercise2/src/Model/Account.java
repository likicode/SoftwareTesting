package Model;

/**
 * Created by Angel on 16/4/28.
 */
public class Account {

    private String tel;
    private float balance;
    private float callDuration;
    private int unpaid;

    public Account(String tel,float balance,float callDuration,int unpaid){
        this.tel=tel;
        this.balance=balance;
        this.callDuration=callDuration;
        this.unpaid=unpaid;
    }

    public float getBalance(){return this.balance;}
    public void setBalance(float balance){
        this.balance=balance;
        return;
    }

    public float getCallDuration(){return this.callDuration;}
    public void setCallDuration(float callDuration){
        this.callDuration=callDuration;
        return;
    }

    public int getUnpaid(){return this.unpaid;}
    public void setUnpaid(int unpaid){
        this.unpaid=unpaid;
        return;
    }

}
