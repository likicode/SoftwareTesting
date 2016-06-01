#include <iostream>
#include "tools.h"
#include <sqlite3.h>


int main(){
	DataBase money;
	Income IncomeData;
	Table mytable;
	Type IncomeType;

	/*
	//Process 1
	initDataBase();
	addInvestment();
	addInvestment();
	addInvestment();
	removeInvestment();
	searchInvestmentByName();
	*/

	//Process 2

	//add new records
	changeSocietyInsurance();
	changeSocietyInsurance();
	//change the record
	changeSocietyInsurance();
	outputSocientyInsuranceState();





	return 0;
}