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

int Day_Calculator(int day, int month, int year) //it'll calculate what day will happen.
{
    if((month != 2 && day<=29) || (month==2 && day==28 && year%4==0) || (month!=2 && month <= 12 && day<=28))
        day+=1;
    else if((month==2 && year%4==0 && day==29) || (month==2 && year%4!=0 && day==28))
        day=1;
    else if(((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day == 31) || ((month == 4 || month == 6 || month == 9 || month == 11) && day == 30))
        day=1;
    return(day);
}

int Month_Calculator(int day, int month, int year) //it'll calculate that the number of month will increase or won't.
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

int Year_Calculator(int day, int month, int year) //in this function, if the given day is last day of the given year, year will be changed.
{
    if(day==31 && month==12)
        year+=1;
    return(year);
}

int main()
{
    int day, month, year, day2, month2, year2;
    printf("Enter a date (0 0 0 to quit): ");

    if (scanf("%d %d %d", &day, &month, &year) != 3) 
    {
        printf("This is not valid date!\n");
        return 1;
    }
    if(day==0 && month==0 && year==0)
        printf("Thanks for using our calendar!\n");

    else if ((day>31 || day<1) || (month<1 || month>12) || (month==2 && day>29))
        printf("This is not valid date!\n");
    else if ((month==2 && day>=30 && year%4!=0) || (month==2 && day>=29 && year%4!=0))
        printf("This is not valid date!\n");
    else //if the taken date isn't invalid, program will be started here.
    {
        day2 = Day_Calculator(day,month,year);
        month2 = Month_Calculator(day,month,year);
        year2 = Year_Calculator(day,month,year);

        printf("The next day of %d.%d.%d is %d.%d.%d",day,month,year,day2,month2,year2);
    }
}

//made my Yusuf Emre OZDEN
