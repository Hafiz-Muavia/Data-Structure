#include <iostream>
#include <ctime>
#include <tuple>

using namespace std;

tuple<int, int, int> getTime() {
    // Get the current time
    time_t now = time(0);

    // Convert the current time to a struct
    tm* currentTime = localtime(&now);

    // Extract the day, month, and year
    int day = currentTime->tm_mday;
    int month = currentTime->tm_mon + 1;  // tm_mon ranges from 0 to 11
    int year = currentTime->tm_year + 1900;  // tm_year counts from 1900

    return make_tuple(day, month, year);
}