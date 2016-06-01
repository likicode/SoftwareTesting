#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "database.h"
#include "datadeal.h"
#include "tools.h"
#include <sqlite3.h>

using namespace std;

int main(){
    DataBase database;
    database.initDataBase();
    Income IncomeData;
    Table mytable;
    Type IncomeType;


    //setValue()
    std::ifstream infile("/Users/liki/Desktop/Money/testcase/TC_setValue");
    std::ofstream outfile("/Users/liki/Desktop/Money/IntegrationTest/Res_setValue");
    string line;
    cout << "work!" <<endl;
    while (std::getline(infile, line)){
        cout << "anything" <<endl;
        std::istringstream iss(line);
        int _time,_typeID;
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
            if (!IncomeData.setValue(mytable) )
            {
                cout<<"插入数据出错，错误信息："<<IncomeData.getErrorMessage()<<endl;
                outfile << line << '\t' <<"false" << "\n";
            }else{
                outfile << line <<'\t'<< "true" <<"\n";
                cout << "true" <<endl;
            }
        }
    }


    //getSum()
    std::ifstream infile2("/Users/liki/Desktop/Money/IntegrationTest/TC_getSum");
    std::ofstream outfile2("/Users/liki/Desktop/Money/IntegrationTest/Res_getSum");
    while(std::getline(infile2,line)){
        std::istringstream iss(line);
        int _beginTime, _endTime;
        if(!(iss >> _beginTime >> _endTime)){
            break;
        }
        //test getSum()
        cout << _beginTime <<  _endTime << endl;
        cout <<"收入支出总额为" << IncomeData.getSum(_beginTime,_endTime) <<endl;
        outfile2 << line << '\t' << IncomeData.getSum(_beginTime,_endTime) << "\n" ;
    }


    //getSumExpense()
    std::ifstream infile3("/Users/liki/Desktop/Money/IntegrationTest/TC_getSumExpense");
    std::ofstream outfile3("/Users/liki/Desktop/Money/IntegrationTest/Res_getSumExpense");
    while(std::getline(infile3,line)){
        std::istringstream iss(line);
        int _beginTime, _endTime;
        if(!(iss >> _beginTime >> _endTime)){
            break;
        }else{
            //test getSum()
            cout << _beginTime <<  _endTime << endl;
            cout <<"支出总额为" << IncomeData.getSumExpense(_beginTime,_endTime) <<endl;
            outfile3 << line << '\t' << IncomeData.getSumExpense(_beginTime,_endTime) << "\n" ;
        }
    }

    //getSumIncome()
    std::ifstream infile4("/Users/liki/Desktop/Money/IntegrationTest/TC_getSumIncome");
    std::ofstream outfile4("/Users/liki/Desktop/Money/IntegrationTest/Res_getSumIncome");
    while(std::getline(infile4,line)){
        std::istringstream iss(line);
        int _beginTime, _endTime;
        if(!(iss >> _beginTime >> _endTime)){
            break;
        }else{
            //test getSumIncome()
            cout <<"收入总额为" << IncomeData.getSumIncome(_beginTime,_endTime) <<endl;
            outfile4 << line << '\t' << IncomeData.getSumIncome(_beginTime,_endTime) << "\n" ;
        }
    }


    //getSumByType()
    std::ifstream infile5("/Users/liki/Desktop/Money/IntegrationTest/TC_getSumByType");
    std::ofstream outfile5("/Users/liki/Desktop/Money/IntegrationTest/Res_getSumByType");
    while(std::getline(infile5,line)){
        cout << "Good" <<endl;
        std::istringstream iss(line);
        int _beginTime, _endTime, _typeID;
        string _typeName;
        if(!(iss >> _typeID >> _beginTime >> _endTime )){
            break;
        }
        //test getSumByType()      
        cout << "该ID对应总支出为" << IncomeData.getSumByType(_beginTime,_endTime,_typeID) <<endl;
        outfile5 << line << '\t' << IncomeData.getSumByType(_beginTime,_endTime,_typeID) << "\n" ;
    }

    return 0;


}