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


int inputValid(int d, int m, int y){
    if((0<m && m<13) && (0<d && d<32)){
        if (m ==2 ){
            if(((leapYearFilter(y) && d < 30)) || ((!leapYearFilter(y) && d<29))){
                return 1;
            }else{
                return 0;
            }
        }else{
            return 1;
        }
    }else{return 0;}
}



int main(int argc, const char * argv[]){
    int month[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    int d,m,y,nd,nm,ny,ndays;
    printf("Please enter the year,month,day\n");
    scanf("%d,%d,%d",&y,&m,&d);
    /*
    *** for real running, the user will continue input date until he gets right data frame
    int mark = 0;
    while(mark ==0){
        if(inputValid(d, m, y) == 0){
            printf("Please enter the year,month,day\n");
            scanf("%d,%d,%d",&y,&m,&d);
            printf("%d,%d,%d",y,m,d);
        }else{
            mark = 1;
        }
    }*/
    
    //for test output, I smiplify the while loop to a print sentence
    if(!inputValid(d, m, y)){
        printf("invalid date input! Please input again!\n");
        return 0;
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
    printf("Given date is: %d,%d,%d\n",y,m,d);
    printf("next days date is: %d,%d,%d\n",ny,nm,nd);
    printf("\n");
    return 0;
}


