#include <iostream>
using namespace std;
class DATE //class 
{
private:
    int year;
    int month;
    int day;
    int norm_year[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leap_year[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

public:
    void setAge(int d, int m, int y);
    void showAge();
    DATE operator-(DATE obj);

};
void DATE::setAge(int d, int m, int y)
{
    if (y > 0 && y < 9999)
    {
        year = y;
    }
    else
    {
        cout << "Error in years ";
        exit(1);
    }
    if (m > 0 && m <= 12)
    {
        month = m;
    }
    else
    {
        cout << "error in months ";
        exit(1);
    }
    if (y % 4 == 0)
    {
        if (d > 0 && d <= leap_year[m])
        {
            day = d;
        }
        else
        {
            cout << "error in days ";
            exit(1);
        }
    }
    else
    {
        if (d > 0 && d <= norm_year[m])
        {
            day = d;
        }
        else
        {
            cout << "error in days ";
            exit(1);
        }
    }
}
void DATE::showAge()
{
    cout << "DD : MM : YY " << endl;
    cout << day << " : " << month << " : " << year << endl
         << endl;
}
 DATE DATE::operator-(DATE obj)
    {
        DATE temp;
        temp.year = year - obj.year;
        temp.month = month - obj.month;
        temp.day = day - obj.day;
        if (temp.year < 0)
        {
            cout << "Error in year ";
            exit(1);
        }
        else if (temp.year == 0)
        {
            if (temp.month < 0)
            {
                cout << "Error in months ";
                exit(1);
            }
            else if (temp.month == 0)
            {
                if (temp.day < 0)
                {
                    cout << "Error in days ";
                    exit(1);
                }
            }
            else if(temp.month>0)
            {
                if (year % 4 == 0)
                {
                    if (temp.day < 0)
                    {
                        temp.day += leap_year[obj.month];
                        temp.month--;
                    }
                }
                else
                {
                    if(temp.day<0)
                    {
                    temp.day += norm_year[obj.month];
                    temp.month--;
                    }
                }
            }
        }
        else if (temp.year > 0)
        {
            if (temp.month < 0)
            {
                temp.month += 12;
                temp.year--;
            }
            else if (temp.month == 0)
            {
                if (year % 4 == 0)
                {
                    if (temp.day < 0)
                    {
                        temp.month += 12;
                        temp.year--;
                        temp.day += leap_year[obj.month];
                        temp.month--;
                    }
                }
                else
                {
                    temp.month += 12;
                    temp.year--;
                    temp.day += norm_year[obj.month];
                    temp.month--;
                }
            }
            else if (temp.month > 0)
            {
                if (temp.day < 0)
                {
                    if (year % 4 == 0)
                    {
                        temp.day += leap_year[obj.month];
                        temp.month--;
                    }
                    else
                    {
                        temp.day += norm_year[obj.month];
                        temp.month--;
                    }
                }
            }
        }
        return temp;
    }