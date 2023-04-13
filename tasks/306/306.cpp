#include <iostream>
#include <ctime>
#include <string>


using namespace std;
string getDayOfWeek(int day, int month, int year) {
    tm timeStruct = {};
    timeStruct.tm_mday = day;
    timeStruct.tm_mon = month - 1;
    timeStruct.tm_year = year - 1900;

    mktime(&timeStruct);
    int dayOfWeek = timeStruct.tm_wday;

    static const char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    return days[dayOfWeek];
}

int main() {
    int day, year;
    string month;
    while (cin >> day >> month >> year) {
        if (month == "January" || month == "February") {
            year--;
            if (month == "January") {
                month = "13";
            } else {
                month = "14";
            }
        } else if (month == "March") {
            month = "3";
        } else if (month == "April") {
            month = "4";
        } else if (month == "May") {
            month = "5";
        } else if (month == "June") {
            month = "6";
        } else if (month == "July") {
            month = "7";
        } else if (month == "August") {
            month = "8";
        } else if (month == "September") {
            month = "9";
        } else if (month == "October") {
            month = "10";
        } else if (month == "November") {
            month = "11";
        } else if (month == "December") {
            month = "12";
        }
        cout << month << endl;
        cout << getDayOfWeek(day, stoi(month), year) << endl;
    }
    return 0;
}
