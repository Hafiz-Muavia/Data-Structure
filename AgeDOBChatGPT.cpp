#include <iostream>
using namespace std;

class DOB {
private:
    int year, day, month;

public:
    DOB();
    void set();
    void get();
    DOB operator-(const DOB& a);
};

DOB::DOB() {
    year = day = month = 0;
}

void DOB::set() {
    cout << "Enter the date as day/month/year: ";
    cin >> day >> month >> year;
}

void DOB::get() {
    cout << "Age: " << year << " Years, " << month << " Months, " << day << " Days." << endl;
}

DOB DOB::operator-(const DOB& a) {
    DOB temp;
    temp.year = year - a.year;
    if (a.month > month) {
        temp.year--;
    }

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    temp.month = month - a.month;
    if (day < a.day) {
        temp.month--;
        temp.day = daysInMonth[a.month - 1] - a.day + day;
    } else {
        temp.day = day - a.day;
    }

    if (temp.month < 0) {
        temp.month += 12;
    }

    return temp;
}

int main() {
    DOB cur_date, dob, age;

    cout << "Enter your date of birth" << endl;
    dob.set();

    cout << "Enter the current date" << endl;
    cur_date.set();

    cout << "Your age is: ";
    age = cur_date - dob;
    age.get();

    return 0;
}
