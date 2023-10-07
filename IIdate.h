#include <iostream>
using namespace std;
class DATE 
{
private: 
    int year;
    int month;
    int day;
   
    int norm_year[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leap_year[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

public:
    void setAge(int day, int month, int year); 
    void showAge();
    DATE operator-(DATE obj); // overloading - operator
};

void DATE::setAge(int day, int month, int year)
{
    if (year > 0 && year < 9999) 
    {
        (*this).year = year;
    }
    else
    {
        cout << "Error in years ";
        exit(1);
    }
    if (month > 0 && month <= 12) 
    {
        (*this).month = month;
    }
    else
    {
        cout << "error in months ";
        exit(1);
    }
    if (year % 4 == 0)
    { 
        if (day > 0 && day <= leap_year[month])
        {
           (*this).day = day;
        }
        else
        {
            cout << "error in days ";
            exit(1);
        }
    }
    else
    {
        
        if (day > 0 && day <= norm_year[month])
        {
            (*this).day = day;
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
        else if (temp.month > 0) 
        {
            if (obj.year % 4 == 0) 
            {
                if (temp.day < 0) 
                {
                    temp.day += leap_year[obj.month]; 
                    temp.month--;                     
                }
            }
            else
            {
                
                if (temp.day < 0)
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
             if (obj.year % 4 == 0) 
            {
                if (temp.day < 0) 
                {
                    temp.day += leap_year[obj.month]; 
                    temp.month--;                     
                }
            }
            else
            {
              
                if (temp.day < 0)
                {
                    temp.day += norm_year[obj.month];
                    temp.month--;
                }
            }

        }
        else if (temp.month == 0) 
        {
           
             temp.month += 12;
            temp.year--;
            // in case of leap year
            if (obj.year % 4 == 0)
            {
                if (temp.day < 0) 
                {
                    // converting months to days
                    temp.day += leap_year[obj.month];
                    temp.month--;
                }
            }
            else
            {
                // in case of normal year
                if (temp.day < 0)
                {
                    temp.day += norm_year[obj.month];
                    temp.month--;
                }
            }
        }
        else if (temp.month > 0) // and months are equal
        {
            if (temp.day < 0) // but days are less
            {
                // in case of leap year
                if (obj.year % 4 == 0)
                { // convert month to days
                    temp.day += leap_year[obj.month];
                    temp.month--;
                }
                else
                { // in case of normal year
                    temp.day += norm_year[obj.month];
                    temp.month--;
                }
            }
        }
    }
    return temp; // return the final output
}
