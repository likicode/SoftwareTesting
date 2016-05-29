/*
电子记帐软件1.0（命令行版）
用来测试几个类的主程序
作者:zwdnet@163.com
日期:2011-10-16
许可协议：GPL3
*/
#include <iostream>
#include "database.h"
#include "datadeal.h"

using namespace std;

int main()
{
	/*
	//DataBase的测试代码
	DataBase mydata;
	if (!mydata.initDataBase())
	{
		cout<<"初始化数据库失败，错误信息为:"<<mydata.getErrorMessage()<<endl;
	}
	string sql = "INSERT INTO Income VALUES(\
		      NULL, 20111016, \"午餐\", 8.00, 1001, \"第一笔\");";
	if (!mydata.modifyDataBase(sql))
	{
		cout<<"查询数据库失败，错误信息为:"<<mydata.getErrorMessage()<<endl;
	}
	sql = "INSERT INTO Income VALUES(\
		      NULL, 20111016, \"晚餐\", 8.00, 1001, NULL);";
	if (!mydata.modifyDataBase(sql))
	{
		cout<<"查询数据库失败，错误信息为:"<<mydata.getErrorMessage()<<endl;
	}
	sql = "INSERT INTO Investment VALUES(\
		      NULL, 20111016, \"储蓄\", 100, 2001, NULL);";
	if (!mydata.modifyDataBase(sql))
	{
		cout<<"查询数据库失败，错误信息为:"<<mydata.getErrorMessage()<<endl;
	}
	sql = "INSERT INTO Investment VALUES(\
		      NULL, 20111016, \"股票\", 200, 2002, \"无\");";
	if (!mydata.modifyDataBase(sql))
	{
		cout<<"查询数据库失败，错误信息为:"<<mydata.getErrorMessage()<<endl;
	}
	sql = "INSERT INTO Income VALUES(\
		      NULL, 20111016, \"停车费\", 0.50, 1002, \"无\");";
	if (!mydata.modifyDataBase(sql))
	{
		cout<<"查询数据库失败，错误信息为:"<<mydata.getErrorMessage()<<endl;
	}
	sql = "INSERT INTO IncomeType VALUES(\
		      1001, \"食品\");";
	if (!mydata.modifyDataBase(sql))
	{
		cout<<"查询数据库失败，错误信息为:"<<mydata.getErrorMessage()<<endl;
	}
	sql = "INSERT INTO IncomeType VALUES(\
		      1002, \"交通\");";
	if (!mydata.modifyDataBase(sql))
	{
		cout<<"查询数据库失败，错误信息为:"<<mydata.getErrorMessage()<<endl;
	}
	sql = "INSERT INTO InvestmentType VALUES(\
		      2001, \"无风险投资\");";
	if (!mydata.modifyDataBase(sql))
	{
		cout<<"查询数据库失败，错误信息为:"<<mydata.getErrorMessage()<<endl;
	}
	sql = "INSERT INTO InvestmentType VALUES(\
		      2002, \"高风险投资\");";
	if (!mydata.modifyDataBase(sql))
	{
		cout<<"查询数据库失败，错误信息为:"<<mydata.getErrorMessage()<<endl;
	}
	sql = "SELECT * FROM Income WHERE ID >= 2;";
	QueryResult res;
	if (!mydata.runSQL(sql, res))
	{
		cout<<"查询数据库失败，错误信息为:"<<mydata.getErrorMessage()<<endl;
	}
	else
	{
		cout<<"查询结果为:"<<endl;
		cout<<"行数为"<<res.row<<" 列数为:"<<res.col<<endl;
		int n = (res.row+1)*res.col;
		for (int i = 0; i < n; i++)
		{
			cout<<"i = "<<i<<" ";
			if (res.result[i] == NULL)
			{
				cout<<endl;
			}
			else
			{
				cout<<res.result[i]<<" ";
				cout<<endl;
			}
		}
		cout<<endl;
	}
	*/
	/*
	//测试字符串与数字转换函数
	string str1 = num2str(22);
	string str2 = num2str(33.32);
	int i3 = str2int(str1);
	double d4 = str2float("55.32");
	cout<<str1<<" "<<str2<<" "<<i3<<" "<<d4<<endl;
	*/
	/*



	
	//收入支出类的测试
	DataBase database;
	database.initDataBase();
	Income IncomeData;
	Table mytable;
	mytable.ID = 0;
	mytable.time = 20111017;
	mytable.name = "午餐";
	mytable.amount = -8.0;
	mytable.typeID = 1001;
	mytable.remark = "吃的盒饭";
	if (!IncomeData.setValue(mytable))
	{
		cout<<"插入数据出错，错误信息："<<IncomeData.getErrorMessage()<<endl;
	}
	mytable.ID = 0;
	mytable.time = 20111017;
	mytable.name = "晚餐";
	mytable.amount = -8.5;
	mytable.typeID = 1001;
	mytable.remark = "吃的盒饭";
	if (!IncomeData.setValue(mytable))
	{
		cout<<"插入数据出错，错误信息："<<IncomeData.getErrorMessage()<<endl;
	}
	mytable.ID = 0;
	mytable.time = 20111017;
	mytable.name = "错误的";
	mytable.amount = -8.0;
	mytable.typeID = 1001;
	mytable.remark = "吃的盒饭";
	if (!IncomeData.setValue(mytable))
	{
		cout<<"插入数据出错，错误信息："<<IncomeData.getErrorMessage()<<endl;
	}
	if (!IncomeData.removeValue(3))
	{
		cout<<"删除数据出错，错误信息："<<IncomeData.getErrorMessage()<<endl;
	}
	mytable.ID = 0;
	mytable.time = 20111017;
	mytable.name = "工资";
	mytable.amount = 100;
	mytable.typeID = 1002;
	mytable.remark = "9月份工资";
	if (!IncomeData.setValue(mytable))
	{
		cout<<"插入数据出错，错误信息："<<IncomeData.getErrorMessage()<<endl;
	}
	mytable.ID = 0;
	mytable.time = 20110917;
	mytable.name = "午餐";
	mytable.amount = -20.0;
	mytable.typeID = 1001;
	mytable.remark = "吃的盒饭";
	if (!IncomeData.setValue(mytable))
	{
		cout<<"插入数据出错，错误信息："<<IncomeData.getErrorMessage()<<endl;
	}
	Type IncomeType;
	IncomeType.typeID = 1001;
	IncomeType.typeName = "饮食";
	if (!IncomeData.setType(IncomeType))
	{
		cout<<"插入类型数据出错，错误信息："<<IncomeData.getErrorMessage()<<endl;
	}
	else
	{
		string sql = "饮食";
		cout<<sql<<"在类型表中的ID值为:"<<IncomeData.getTypeID(sql)<<endl;
	}
	string mysql = "服装";
	int ID = IncomeData.getTypeID(mysql);
	if (ID == -1)
	{
		cout<<"在类型表中没有"<<mysql<<"的类型"<<endl;
	}
	else
	{
		cout<<"在类型表中"<<mysql<<"的ID值为:"<<ID<<endl;
	}
	IncomeType.typeID = 1002;
	IncomeType.typeName = "工资";
	if (!IncomeData.setType(IncomeType))
	{
		cout<<"插入类型数据出错，错误信息："<<IncomeData.getErrorMessage()<<endl;
	}
	cout<<"收入支出总额为:"<<IncomeData.getSum()<<endl;
	cout<<"2011年10月份的收入支出总和为:"<<IncomeData.getSum(20111001, 20111031)<<endl;
	cout<<"收入总额为:"<<IncomeData.getSumIncome()<<endl;
	cout<<"2011年10月份的收入总额为:"<<IncomeData.getSumIncome(20111001, 20111031)
	    <<endl;
	cout<<"支出总额为:"<<IncomeData.getSumExpense()<<endl;
	cout<<"2011年10月份的支出总额为:"<<IncomeData.getSumExpense(20111001, 20111031)
	    <<endl;
	ID = IncomeData.getTypeID("饮食");
	if (ID != -1)
	{
		cout<<"饮食消费总额为:"<<IncomeData.getSumByType(ID)<<endl
		    <<"10月份的饮食消费总额为:"
		    <<IncomeData.getSumByType(20111001, 20111031, ID)<<endl;
	}
	//资产负债类的测试
	Investment InvestmentData;
	mytable.ID = 0;
	mytable.time = 20111017;
	mytable.name = "储蓄";
	mytable.amount = 100;
	mytable.typeID = 2001;
	mytable.remark = "浦发银行，定期储蓄，1年期";
	if (!InvestmentData.setValue(mytable))
	{
		cout<<"插入数据出错，错误信息："<<InvestmentData.getErrorMessage()<<endl;
	}
	mytable.ID = 0;
	mytable.time = 20111017;
	mytable.name = "股票";
	mytable.amount = 105;
	mytable.typeID = 2002;
	mytable.remark = "宝钢股份";
	if (!InvestmentData.setValue(mytable))
	{
		cout<<"插入数据出错，错误信息："<<InvestmentData.getErrorMessage()<<endl;
	}
	mytable.ID = 0;
	mytable.time = 20111017;
	mytable.name = "错误的";
	mytable.amount = -8.0;
	mytable.typeID = 2001;
	mytable.remark = "储蓄，错误的";
	if (!InvestmentData.setValue(mytable))
	{
		cout<<"插入数据出错，错误信息："<<InvestmentData.getErrorMessage()<<endl;
	}
	if (!InvestmentData.removeValue(3))
	{
		cout<<"删除数据出错，错误信息："<<InvestmentData.getErrorMessage()<<endl;
	}
	mytable.ID = 0;
	mytable.time = 20111017;
	mytable.name = "借债";
	mytable.amount = -50;
	mytable.typeID = 2003;
	mytable.remark = "借别人50";
	if (!InvestmentData.setValue(mytable))
	{
		cout<<"插入数据出错，错误信息："<<InvestmentData.getErrorMessage()<<endl;
	}
	mytable.ID = 0;
	mytable.time = 20110917;
	mytable.name = "房贷";
	mytable.amount = -20.0;
	mytable.typeID = 2004;
	mytable.remark = "借债";
	if (!InvestmentData.setValue(mytable))
	{
		cout<<"插入数据出错，错误信息："<<InvestmentData.getErrorMessage()<<endl;
	}
	Type InvestmentType;
	InvestmentType.typeID = 2001;
	InvestmentType.typeName = "储蓄";
	if (!InvestmentData.setType(InvestmentType))
	{
		cout<<"插入类型数据出错，错误信息："<<InvestmentData.getErrorMessage()<<endl;
	}
	else
	{
		string sql = "储蓄";
		cout<<sql<<"在类型表中的ID值为:"<<InvestmentData.getTypeID(sql)<<endl;
	}
	mysql = "高利贷";
	ID = InvestmentData.getTypeID(mysql);
	if (ID == -1)
	{
		cout<<"在类型表中没有"<<mysql<<"的类型"<<endl;
	}
	else
	{
		cout<<"在类型表中"<<mysql<<"的ID值为:"<<ID<<endl;
	}
	InvestmentType.typeID = 2002;
	InvestmentType.typeName = "股票";
	if (!InvestmentData.setType(InvestmentType))
	{
		cout<<"插入类型数据出错，错误信息："<<InvestmentData.getErrorMessage()<<endl;
	}
	InvestmentType.typeID = 2003;
	InvestmentType.typeName = "借债";
	if (!InvestmentData.setType(InvestmentType))
	{
		cout<<"插入类型数据出错，错误信息："<<InvestmentData.getErrorMessage()<<endl;
	}
	InvestmentType.typeID = 2004;
	InvestmentType.typeName = "房贷";
	if (!InvestmentData.setType(InvestmentType))
	{
		cout<<"插入类型数据出错，错误信息："<<InvestmentData.getErrorMessage()<<endl;
	}
	cout<<"资产负债总额为:"<<InvestmentData.getSum()<<endl;
	cout<<"2011年10月份的资产负债总和为:"<<InvestmentData.getSum(20111001, 20111031)<<endl;
	cout<<"资产总额为:"<<InvestmentData.getSumInvestment()<<endl;
	cout<<"2011年10月份的资产总额为:"<<InvestmentData.getSumInvestment(20111001, 20111031)
	    <<endl;
	cout<<"负债总额为:"<<InvestmentData.getSumDebt()<<endl;
	cout<<"2011年10月份的负债总额为:"<<InvestmentData.getSumDebt(20111001, 20111031)
	    <<endl;
	ID = InvestmentData.getTypeID("股票");
	if (ID != -1)
	{
		cout<<"股票资产总额为:"<<InvestmentData.getSumByType(ID)<<endl
		    <<"10月份的股票资产总额为:"
		    <<InvestmentData.getSumByType(20111001, 20111031, ID)<<endl;
	}
	*/

	return 0;
}
