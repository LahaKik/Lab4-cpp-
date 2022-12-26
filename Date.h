#pragma once
#include "List.h"
using namespace std;

class Date
{
public:
    int Day;
    int Month;
    int Year;

    Date() {};
    Date(int day, int month, int year)
    {
        Day = day;
        Month = month;
        Year = year;
    }

    string ToString() {
        char str[14];
        itoa(Day, str, 10);
        if (Day < 10)
        {
            strcat(str + 1, "/");
            if (Month < 10) {
                itoa(Month, str + 2, 10);
                strcat(str + 3, "/");
                itoa(Year, str + 4, 10);
            }
            else {
                itoa(Month, str + 2, 10);
                strcat(str + 4, "/");
                itoa(Year, str + 5, 10);
            }
        }
        else {

            strcat(str + 2, "/");
            if (Month < 10) {
                itoa(Month, str + 3, 10);
                strcat(str + 4, "/");
                itoa(Year, str + 5, 10);
            }
            else {
                itoa(Month, str + 3, 10);
                strcat(str + 5, "/");
                itoa(Year, str + 6, 10);
            }
        }
        string rez = str;
        return rez;
    }
};

bool operator == (Date date1, Date date2) {
    if (date1.Day == date2.Day && date1.Month == date2.Month && date1.Year == date2.Year)
        return true;
    return false;
}