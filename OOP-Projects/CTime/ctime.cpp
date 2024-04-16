#include "ctime.hpp"


CTime::CTime() {
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
}

CTime::CTime(int hours, int minutes, int seconds) {
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

CTime::CTime(const CTime& time) {
    this->hours = time.hours;
    this->minutes = time.minutes;
    this->seconds = time.seconds;
}

Status CTime::check() const {
    if (this->hours >= 24) return ERROR;
    if (this->minutes >= 60) return ERROR;
    if (this->seconds >= 60) return ERROR;

    return SUCCESS;
}


/*
* Be at home at 21:00
* Me at 20:69:
*/
Status CTime::fix() {
    Status status = SUCCESS;

    if (0 > this->seconds || this->seconds >= 60) {
        this->minutes += this->seconds / 60;
        this->seconds %= 60;
        status = WARNING;
    }
    if (0 > this->minutes || this->minutes >= 60) {
        this->hours += this->minutes / 60;
        this->minutes %= 60;
        status = WARNING;
    }
    if (0 > this->hours || this->hours >= 24) {
        this->hours %= 24;
        status = WARNING;
    }

    return status;
}

Status CTime::add_hours(int hours) {
    this->hours += hours;
    this->fix();
    return WARNING;
}

Status CTime::add_minutes(int minutes) {
    this->minutes += minutes;
    this->fix();
    return WARNING;
}

Status CTime::add_seconds(int seconds) {
    this->seconds += seconds;
    this->fix();
    return WARNING;
}

std::string CTime::to_str() {
    return std::to_string(this->hours) + ":" + std::to_string(this->minutes) + ":" + std::to_string(this->seconds);
}

Status CTime::input() {
    Status state;

    char colon;
    std::cin     >> this->hours 
        >> colon >> this->minutes 
        >> colon >> this->seconds;

    state = this->check();

    return state;
}

std::ostream& operator<<(std::ostream& cout, CTime& ctime) {
    return cout
        << std::setfill('0') << std::setw(2) << ctime.hours << ":"
        << std::setfill('0') << std::setw(2) << ctime.minutes << ":"
        << std::setfill('0') << std::setw(2) << ctime.seconds;
}