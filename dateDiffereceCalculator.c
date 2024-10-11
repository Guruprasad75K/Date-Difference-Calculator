#include <stdio.h>

//This function checks whether the year passed in parameter is leap yeap or not 
int isLeapYear(int year){ 
    if((year%4==0 && year%100!=0)||year%400==0){
        return 1;
    }else{
        return 0;
    }
}

//This function calculates the days between the two years without considering them 
int calculateTotalDaysinYear(int y1,int y2){
    int days=0;
    for(y1=y1+1;y1<y2;y1++){
        if(isLeapYear(y1)){
            days+=366;
        }else{
            days+=365;
        }
    }
    return days;
}

//This function calculates the days from given first date to end of the same year
int calculateTotalRemainingDays(int date,int month, int year){
    int days=0, isLeap;
    isLeap=isLeapYear(year);
        switch (month){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                days=31-date;
                break;
            case 4: case 6: case 9: case 11:
                days=30-date;
                break;
        }
        if(isLeap && month==2){
            days=29-date;
        }else if (month == 2){
            days=28-date;
        }
    for(month=month+1;month<=12;month++){
        switch (month){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                days+= 31;
                break;
            case 4: case 6: case 9: case 11:
                days+= 30;
                break;
        }
        if(isLeap && month==2){
            days+=29;
        }else if (month == 2){
            days+=28;
        }
    }
    return days;
}

//This function calculates the days from start of the given year to sencond date
int calculateTotalafterDays(int date,int month, int year){
    int days=date, isLeap;
    isLeap=isLeapYear(year);
    for(int i=1;i<month;i++){
        switch (i){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                days+= 31;
                break;
            case 4: case 6: case 9: case 11:
                days+= 30;
                break;
        }
        if(isLeap && i==2){
            days+=29;
        }else if (i == 2){
            days+=28;
        }
    }
    return days;
}

int main() {
    int date1,month1,year1,date2,month2,year2,totalDays,year,days1,days2;
    printf("Use the following format dd mm yyyy\n");
    printf("Enter the first date:");
    scanf("%d %d %d",&date1,&month1,&year1);
    printf("Enter the sencond date:");
    scanf("%d %d %d",&date2,&month2,&year2);
    //To calculate the difference between the dates if year are same 
    if (year1==year2){
        days1=calculateTotalafterDays(date1,month1,year1);
        days2=calculateTotalafterDays(date2,month2,year2);
        if (days2>days1){
            totalDays=days2-days1;
        }else{
            totalDays=days1-days2;
        }
    }
     //To calculate the difference between the dates if year1 is before year2
    if(year1<year2){
        year=calculateTotalDaysinYear(year1,year2);
        days1=calculateTotalRemainingDays(date1,month1,year1);
        days2=calculateTotalafterDays(date2,month2,year2);
        totalDays=year+days1+days2;
    }
     //To calculate the difference between the dates if year2 is before year1
    else if(year1>year2){
        year=calculateTotalDaysinYear(year2,year1);
            days1=calculateTotalRemainingDays(date2,month2,year2);
            days2=calculateTotalafterDays(date1,month1,year1);
            totalDays=year+days1+days2;
    }
    printf("The Difference between the two dates :%d",totalDays);
    return 0;
}
