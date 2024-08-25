#include <iostream>

class Date {
public:
    int day;
    int month;
    int year;
    Date(int inMonth, int inYear) {
        month = inMonth;
        year = inYear;
    }
    void advance() {
        month++;
        if(month > 12) {
            month = 1;
            year++;
        }
    }
    int daysInMonth() const {
        switch (month) {
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
            case 2:
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                    return 29;
                }
                return 28;
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                return 31;
            default:
                std::cout << "Invalid month.";
                return 0;

        }
    }
};


int main() {

    int firstSundays = 0;
    int dayofWeek = 2;

    Date date = Date(1, 1901);

    while (date.year < 2001) {

        std::cout << "1st of " << date.month << " " << date.year << ": " << dayofWeek << std::endl;
        dayofWeek += date.daysInMonth();
        dayofWeek %= 7;
        if(dayofWeek == 6) {
            firstSundays++;
        }
        date.advance();
    }

    std::cout << "Sundays that started the month: " << firstSundays << std::endl;



    return 0;
}

