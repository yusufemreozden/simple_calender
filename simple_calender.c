/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Simple Calendar                                                          */
/*                                                                            */
/*   By: Yusuf Emre OZDEN | <yusufemreozdenn@gmail.com>                       */
/*                                                                            */      
/*   https://GitHub.com/yusufemreozden                                        */
/*   https://linkedIn.com/in/yusufemreozden                                   */
/*   https://sites.google.com/view/yusufemreozden                             */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int Day_Calculator(int day, int month, int year)
{
    if((month != 2 && day<=29) || (month==2 && day==28 && year%4==0) || (month <= 12 && day<=28))
        day+=1;
    else if((month==2 && year%4==0 && day==29) || (month==2 && year%4!=0 && day==28))
        day=1;
    else if(((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day == 31) || ((month == 4 || month == 6 || month == 9 || month == 11) && day == 30))
        day=1;
    return(day);
}

int Month_Calculator(int day, int month, int year)
{
    if(day==31 && month==12)
        month=1;    
    else if(month !=2 && (month == 4 || month == 6 || month == 9 || month == 11) && day == 30)
        month+=1;
    else if((month==2 && year%4==0 && day==29) || (month==2 && year%4!=0 && day == 28))
        month+=1;
    else if(month !=2 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day == 31)
        month+=1;
    return(month);
}

int YearCalculator(int day, int month, int year)
{
    if(day==31 && month==12)
        year+=1;
    return(year);
}

int main()
{
    int day, month, year, day2, month2, year2;
    printf("Enter a date (0 0 0 to quit): ");
    scanf("%d %d %d",&day,&month,&year);

    if(day==0 && month==0 && year==0)
        printf("Thanks for using our calendar!\n");

    else if ((day>31 || day<1) || (month<1 || month>12) || (month==2 && day>29))
        printf("This is not valid date!\n");
    else if ((month==2 && day>=30 && year%4!=0) || (month==2 && day>=29 && year%4!=0))
        printf("This is not valid date!\n");
    else
    {
        day2 = Day_Calculator(day,month,year);
        month2 = Month_Calculator(day,month,year);
        year2 = YearCalculator(day,month,year);

        printf("The next day of %d.%d.%d is %d.%d.%d",day,month,year,day2,month2,year2);
    }
}

//made my Yusuf Emre OZDEN
