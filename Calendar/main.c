//
//  main.c
//  Calendar
//
//  Created by Liki on 3/23/16.
//  Copyright © 2016 Liki. All rights reserved.
//

#include <stdio.h>


int leapYearFilter(year){
    if(year% 4== 0 || year%400 == 0)
    {
        return 1;
    }else{
        return 0;
    }
}


int inputValid(int d, int m, int y,int month[12]){
    if((m>0 && m<13) && (d>0 && d<32) && y>0 ){
        if (m ==2 ){
            if(((leapYearFilter(y) && d < 30)) || ((!leapYearFilter(y) && d<29))){
                return 1;
            }else{
                return 0;
            }
        }else{
            if (d > month[m-1]){return 0;}
            else{ return 1;}
        }
    }else{return 0;}
}



void get_next_day(FILE* f,int y,int m,int d){
    if(f == NULL){
        printf("Error opening file!\n");
    //    exit(1);
    }
    
    int month[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    int nd,nm,ny,ndays;
    if(!inputValid(d, m, y,month)){
        //printf("invalid date input! Please input again!\n");
        const char* text = "Invalid date input";
        fprintf(f,"%d,%d,%d   %s\n",y,m,d,text);
        return;
    }
    ndays = month[m-1];
    if(m == 2 && leapYearFilter(y)){
        ndays = 29;
    }
    nd = d+1;nm=m;ny=y;
    if (nd > ndays){
        nd = 1;
        nm ++;
    }
    if (nm >12){
        nm = 1;
        ny++;
    }
    //printf("next days date is: %d,%d,%d\n",ny,nm,nd);
    fprintf(f,"%d,%d,%d,  next days date is: %d, %d, %d\n",y,m,d,ny,nm,nd);
}


void readfile(){
    FILE* file = fopen("/Users/liki/Desktop/Calendar/Calendar/testcase", "r");
    FILE* outfile = fopen("/Users/liki/Desktop/Calendar/Calendar/result","w");
    while (!feof (file)) {
        int year,month,day;
        fscanf(file, "%d,%d,%d",&year,&month,&day);
        printf("%d,%d,%d\n",year,month,day);
        get_next_day(outfile,year, month,day);
    }
    fclose(file);
}


int main(int argc, const char * argv[]){
    // read testcases and output test result
    readfile();
    return 0;
}


