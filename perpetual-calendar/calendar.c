#include <stdio.h>

void years(int fday, int fmonth, int fyear)
{
    int g, i=0;
    switch(fmonth)
    {
        case 1:
            case 10:
                i=1;
                break;
        case 2:
            case 3:
            case 11:
                i=4;
                break;
        case 4:
            case 7:
                i=7;
                break;
        case 5:
                i=2;
                break;
        case 6:
                i=5;
        break;
        case 8:
                i=3;
                break;
        case 9:
            case 12:
                i=6;
                break;
    }

    for ( g=1901; g<fyear; g++)
    {
        if (g%4!=0)
        {
            i++;
        }
        else
        {
            i=i+2;
        }
        if (i==8)
            i=1;
        else if (i==9)
            i=2;
    }

    i = i + fday;

    switch(i)
    {
        case 1:
            case 8:
            case 15:
            case 22:
            case 29:
            case 36:
                printf("Monday\n");
                break;
        case 2:
            case 9:
            case 16:
            case 30:
            case 37:
            case 23:
                printf("Tuesday\n");
                break;
        case 3:
            case 10:
            case 17:
            case 24:
            case 31:
            case 38:
                printf("Wednesday\n");
                break;
        case 4:
            case 11:
            case 18:
            case 25:
            case 32:
                printf("Thursday\n");
                break;
        case 5:
            case 12:
            case 19:
            case 26:
            case 33:
                printf("Friday\n");
                break;
        case 6:
            case 13:
            case 20:
            case 27:
            case 34:
                printf("Saturday\n");
                break;
        case 7:
            case 14:
            case 21:
            case 28:
            case 35:
                printf("Sunday\n");
                break;
    }
}

int main()
{
    int day, year, month;
    printf("Enter date as day.month.year: ");
    scanf("%d", &day);
    scanf(".%d", &month);
    scanf(".%d", &year);

    if (day<=31 && month<=12)
        years(day, month, year);
    else
        printf("You are loser!!!");
    return 0;
}
