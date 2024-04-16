#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <regex>

enum Status { SUCCESS, ERROR, WARNING };

class CTime {
    int hours;
    int minutes;
    int seconds;
    Status fix();

public:
    CTime();
    CTime(int hours, int minutes, int seconds);
    CTime(const CTime& time);
    //CTime(std::string time);

    Status check() const;

    Status add_hours(int hours);
    Status add_minutes(int minutes);
    Status add_seconds(int seconds);

    std::string to_str();

    Status input();

    CTime& operator =(const CTime& ctime) {
        this->hours = ctime.hours;
        this->minutes = ctime.minutes;
        this->seconds = ctime.seconds;
        return *this;
    }

    CTime& operator +=(const CTime& ctime) {
        this->hours += ctime.hours;
        this->minutes += ctime.minutes;
        this->seconds += ctime.seconds;
        this->fix();
        return *this;
    }

    int operator ==(const CTime& ctime) {
        return this->hours == ctime.hours 
            && this->minutes == ctime.minutes 
            && this->seconds == ctime.seconds;
    }

    friend std::ostream& operator<<(std::ostream& cout, CTime& ctime);
    friend std::istream& operator>>(std::istream& cin, CTime& ctime) {
        char colon;

        return cin >> ctime.hours
            >> colon >> ctime.minutes
            >> colon >> ctime.seconds;
    }

};
