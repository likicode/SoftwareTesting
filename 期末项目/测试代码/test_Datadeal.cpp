#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "database.h"
#include "datadeal.h"
#include "tools.h"
#include <sqlite3.h>
using namespace std;

Table test_setValue(Income IncomeData, Table mytable,string fname){
	std::ifstream infile(fname);
    std::ofstream outfile("/Users/liki/Desktop/Money/UnitTest/Res_setValue");
    string line;
    cout << "work!" <<endl;
    while (std::getline(infile, line)){
        cout << "anything" <<endl;
        std::istringstream iss(line);
        float _time,_typeID;
        string _name,_remark;
        float _amount;
        if(!(iss >> _time >> _name >> _amount >> _typeID >>_remark)){
            cout <<"wro"<<endl;
            break;
        }else{
        	cout << _time <<" "<< _name << _amount << _typeID << _remark << endl;
        	mytable.ID = 0;
			mytable.time = _time;
			mytable.name = _name;
			mytable.amount = _amount; 
			mytable.typeID = _typeID;
			mytable.remark = _remark;

            //test setValue()
            if (!IncomeData.setValue(mytable))
			{
				cout<<"插入数据出错，错误信息："<<IncomeData.getErrorMessage()<<endl;
                outfile << line << '\t' <<"false" << "\n";
			}else{
                outfile << line <<'\t'<< "true" <<"\n";
                cout << "true" <<endl;
			}
        }
    }
    return mytable;
}



Table test_removeValue(Income IncomeData, Table mytable, string fname){
	std::ifstream infile(fname);
    string line;
    std::ofstream outfile("/Users/liki/Desktop/Money/UnitTest/Res_removeValue");
    while(std::getline(infile,line)){
    	std::istringstream iss(line);
    	float _ID;
    	if(!(iss >> _ID)){
    		break;
    	}else{
    		//test removeValue()
    		cout << _ID << endl;
    		if (!IncomeData.removeValue(_ID) || _ID - int(_ID) != 0){
				cout<<"删除数据出错，错误信息："<<IncomeData.getErrorMessage()<<endl;
                outfile << line << '\t' <<"false" << "\n";
			}else{
				cout <<"Remove Successfully" << endl;
                outfile << line <<'\t'<< "true" <<"\n";
			}
    	}
    }
    infile.close();
    return mytable;
}


Income test_setType(Income IncomeData, Type IncomeType, string fname){
	std::ifstream infile(fname);
    string line;
    std::ofstream outfile("/Users/liki/Desktop/Money/UnitTest/Res_setType");

    while(std::getline(infile,line)){
    	std::istringstream iss(line);
    	int _typeID;
    	string _typeName;
    	if(!(iss >> _typeID >> _typeName)){
    		break;
    	}else{
    		//test setType()
    		cout << _typeID << _typeName << endl;
			IncomeType.typeID = _typeID;
			IncomeType.typeName = _typeName;

			if (!IncomeData.setType(IncomeType)){
				cout<<"插入类型数据出错，错误信息："<<IncomeData.getErrorMessage()<<endl;
                outfile << line << '\t' <<"false" << "\n";
			}else{
				cout << "成功插入" <<endl;
                outfile << line <<'\t'<< "true" <<"\n";
			}
		}
	}
    return IncomeData;
}


Income test_getSum(Income IncomeData, Table mytable, string fname){

    //桩1
	mytable.ID = 1;
	mytable.time = 19800101;
	mytable.name = "午餐";
	mytable.amount = 370.703;
	mytable.typeID = 1001;
	mytable.remark = "吃的盒饭";
	IncomeData.setValue(mytable);

    //桩2
    mytable.ID = 2;
    mytable.time = 20000105;
    mytable.name = "学费";
    mytable.amount = -1074.0841;
    mytable.typeID = 1001;
    mytable.remark = "英语课";
    IncomeData.setValue(mytable);    

	std::ifstream infile(fname);
    std::ofstream outfile("/Users/liki/Desktop/Money/UnitTest/Res_getSum");
    string line;
    while(std::getline(infile,line)){
    	std::istringstream iss(line);
    	int _beginTime, _endTime;
    	if(!(iss >> _beginTime >> _endTime)){
    		break;
    	}
    	//test getSum()
    	cout << _beginTime <<  _endTime << endl;
    	cout <<"收入支出总额为" << IncomeData.getSum(_beginTime,_endTime) <<endl;
        outfile << line << '\t' << IncomeData.getSum(_beginTime,_endTime) << "\n" ;
    }
    infile.close();
    return IncomeData;
}


Income test_getSumExpense(Income IncomeData, Table mytable, string fname){
	//桩1
    mytable.ID = 1;
    mytable.time = 19800101;
    mytable.name = "午餐";
    mytable.amount = -1085;
    mytable.typeID = 1001;
    mytable.remark = "吃的盒饭";
    IncomeData.setValue(mytable);

    //桩2
    mytable.ID = 2;
    mytable.time = 20000105;
    mytable.name = "学费";
    mytable.amount = -2074.5841;
    mytable.typeID = 1001;
    mytable.remark = "英语课";
    IncomeData.setValue(mytable); 

     //桩3
    mytable.ID = 3;
    mytable.time = 20000505;
    mytable.name = "学费";
    mytable.amount = 1500.50;
    mytable.typeID = 1001;
    mytable.remark = "英语课";
    IncomeData.setValue(mytable);  

	std::ifstream infile(fname);
    std::ofstream outfile("/Users/liki/Desktop/Money/UnitTest/Res_getSumExpense");
    string line;
    while(std::getline(infile,line)){
    	std::istringstream iss(line);
    	int _beginTime, _endTime;
    	if(!(iss >> _beginTime >> _endTime)){
    		break;
    	}else{
    		//test getSum()
    		cout << _beginTime <<  _endTime << endl;
    		cout <<"支出总额为" << IncomeData.getSumExpense(_beginTime,_endTime) <<endl;
            outfile << line << '\t' << IncomeData.getSumExpense(_beginTime,_endTime) << "\n" ;
    	}
    }
    infile.close();
    return IncomeData;
}


Income test_getSumIncome(Income IncomeData, Table mytable, string fname){
	//桩1
    mytable.ID = 1;
    mytable.time = 19800101;
    mytable.name = "午餐";
    mytable.amount = 370.703;
    mytable.typeID = 1001;
    mytable.remark = "吃的盒饭";
    IncomeData.setValue(mytable);

    //桩2
    mytable.ID = 2;
    mytable.time = 20000105;
    mytable.name = "学费";
    mytable.amount = 1000.50;
    mytable.typeID = 1001;
    mytable.remark = "英语课";
    IncomeData.setValue(mytable); 

     //桩3
    mytable.ID = 3;
    mytable.time = 20000505;
    mytable.name = "学费";
    mytable.amount = -1500.50;
    mytable.typeID = 1001;
    mytable.remark = "英语课";
    IncomeData.setValue(mytable);  

	std::ifstream infile(fname);
    string line;
    std::ofstream outfile("/Users/liki/Desktop/Money/UnitTest/Res_getSumIncome");
    while(std::getline(infile,line)){
    	std::istringstream iss(line);
    	int _beginTime, _endTime;
    	if(!(iss >> _beginTime >> _endTime)){
    		break;
    	}else{
    		//test getSumIncome()
    		cout <<"收入总额为" << IncomeData.getSumIncome(_beginTime,_endTime) <<endl;
            outfile << line << '\t' << IncomeData.getSumIncome(_beginTime,_endTime) << "\n" ;
    	}
    }
    infile.close();
    return IncomeData;
}


Income test_getSumByType(Income IncomeData,Table mytable,Type IncomeType, string fname){
    //桩1
    mytable.ID = 1;
    mytable.time = 19800101;
    mytable.name = "午餐";
    mytable.amount = 7652.25269;
    mytable.typeID = 1;
    mytable.remark = "吃的盒饭";
    IncomeData.setValue(mytable);

    //桩2
    mytable.ID = 2;
    mytable.time = 20000105;
    mytable.name = "学费";
    mytable.amount = -314.203;
    mytable.typeID = 7;
    mytable.remark = "英语课";
    IncomeData.setValue(mytable); 

     //桩3
    mytable.ID = 3;
    mytable.time = 20140301;
    mytable.name = "学费";
    mytable.amount = 0;
    mytable.typeID = 12;
    mytable.remark = "英语课";
    IncomeData.setValue(mytable);  


	std::ifstream infile(fname);
    std::ofstream outfile("/Users/liki/Desktop/Money/UnitTest/Res_getSumByType");
    string line;
    while(std::getline(infile,line)){
    	std::istringstream iss(line);
    	int _beginTime, _endTime, _typeID;
    	string _typeName;
    	if(!(iss >> _typeID >> _beginTime >> _endTime )){
    		break;
    	}
    	//test getSumByType()      
    	cout << "该ID对应总支出为" << IncomeData.getSumByType(_beginTime,_endTime,_typeID) <<endl;
        outfile << line << '\t' << IncomeData.getSumByType(_beginTime,_endTime,_typeID) << "\n" ;
    }
    
    return IncomeData;
}



int main(){
	// test case for setValue()
	string TC_setValue = "/Users/liki/Desktop/Money/UnitTest/TC_setValue"; 
	// test case for removeValue() 
	string TC_removeValue = "/Users/liki/Desktop/Money/UnitTest/TC_removeValue";
	//test case for setType()
	string TC_setType = "/Users/liki/Desktop/Money/UnitTest/TC_setType";
	//test case for getSum()
	string TC_getSum = "/Users/liki/Desktop/Money/UnitTest/TC_getSum";
	//test case for getSumIncome()
	string TC_getSumIncome = "/Users/liki/Desktop/Money/UnitTest/TC_getSumIncome";
	//test case for getSumExpense()
	string TC_getSumExpense = "/Users/liki/Desktop/Money/UnitTest/TC_getSumExpense";
	//test case for getSumByType()
	string TC_getSumByType = "/Users/liki/Desktop/Money/UnitTest/TC_getSumByType";

	DataBase database;
	database.initDataBase();
	Income IncomeData;
	Table mytable;
	Type IncomeType;

	//mytable =  test_setValue(IncomeData,mytable,TC_setValue);
	//mytable  = test_removeValue(IncomeData,mytable,TC_removeValue);
	//IncomeData = test_setType(IncomeData,IncomeType,TC_setType);
	//IncomeData = test_getSum(IncomeData,mytable,TC_getSum);
    //IncomeData = test_getSumIncome(IncomeData,mytable,TC_getSumIncome);
    //IncomeData = test_getSumExpense(IncomeData,mytable,TC_getSumExpense);
    IncomeData = test_getSumByType(IncomeData,mytable,IncomeType,TC_getSumByType);

	return 0;
}