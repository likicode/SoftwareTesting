#include <iostream>
#include "database.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <sqlite3.h>

using namespace std;

DataBase test_modifyDataBase(DataBase mydata){
	std::ifstream infile("/Users/liki/Desktop/Money/testcase/TC_modifyDataBase");
	std::string sql;
	while (std::getline(infile, sql)){
		if (!mydata.modifyDataBase(sql)){
			cout<<"修改数据库失败，错误信息为:"<<mydata.getErrorMessage()<<endl;
		}else{
			cout << "Done" <<endl;
		}
	}
	return mydata;
}



void test_runSQL(DataBase mydata){
	test_modifyDataBase(mydata);
	std::ifstream infile("/Users/liki/Desktop/Money/testcase/TC_runSQL");
	std::ofstream outfile("/Users/liki/Desktop/Money/testcase/Res_runSQL");
	std::string line;
	string deli = "\t";
	string res_deli = " ";
	QueryResult res;
    while (std::getline(infile, line)){
    	outfile << line << "\t\t"; 
        size_t pos = line.find(deli);
        string sql =line.substr(0, pos);
        cout <<sql <<endl;
        //line.erase(0, pos + deli.length());
        //size_t pos2 = line.find(deli);
        //string res =line.substr(0, pos);
        if (!mydata.runSQL(sql, res))
		{
			cout << -1;
			cout<<"查询数据库失败，错误信息为:"<<mydata.getErrorMessage()<<endl;
		}
		else
		{			
			int n = (res.row+1)*res.col;
			int t = 0;
			for (int i = res.col ; i < (res.row+1)*res.col; i++)
			{	
				t++;
				if (res.result[i] == NULL)
				{
					cout<<"NO" <<endl;
				}
				else
				{
					//if (res.result[i] != "TypeID" && res.result[i] != "TypeName" && res.result[i] != "Amount"){
					if(t!=5){
						outfile << string(res.result[i]) << " ";
						cout<<res.result[i]<<" ";
					}
				}
			}
		}
			outfile << '\n';
			cout <<endl;
	}
}




int main(){
	DataBase mydata;
	if (!mydata.initDataBase())
	{
		 cout<<"初始化数据库失败，错误信息为:"<<mydata.getErrorMessage()<<endl;
	}


	//test openDatabase()
	if(!mydata.openDataBase()){
		cout << "打来数据库失败" <<endl; 
	}else{
		cout << "成功打开数据库" << endl;
	}
	

	//test modifyDataBase()
	mydata = test_modifyDataBase(mydata);
	//test_runSQL(mydata);
	test_runSQL(mydata);


	//test clearResult()
	mydata.clearResult(res);
	cout<<"清除结果后行数"<<res.row << endl;
	cout<<"清楚结果后列数"<<res.col << endl; 

	return 0;

}




