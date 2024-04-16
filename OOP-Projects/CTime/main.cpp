#include <iostream>
#include "ctime.hpp"

using std::cin;
using std::cout;
using std::endl;

int main() {
    CTime time0 = { 11, 12, 57 };
    CTime time1;
    CTime time2(12, 13, 14);
    CTime time3(time2);
    //CTime time4("13:45:23");

    cout << "Check create objects" << endl;

    cout << "Time 0 (after default constructor + \"operator =\"  + initialization): " << time0 << endl;
    cout << "Time 1 (after default constructor): " << time1 << endl;
    cout << "Time 2 (after init constructor): " << time2 << endl;
    cout << "Time 3 (after copy constructor): " << time3 << endl;

    std::string str_time0 = time0.to_str();
    cout << "Time 0 to_str(): " << str_time0 << endl;

    cout << "Check \"input\" function" << endl;
    cin >> time1;
    cout << "Time 1 (after \"input\"): ";
    cout << time1 << endl;

    cout << "Check \"assign\" function, i.e. time2 = time0" << endl;
    time0 = time2;
    cout << "Time 0: ";
    cout << time0 << endl;
    cout << "Time 2: ";
    cout << time2 << endl;

    time0.add_seconds(61);
    cout << "Time0 + 61 seconds: " << time0 << endl;

    time0.add_minutes(61);
    cout << "Time0 + 61 minutes: " << time0 << endl;

    time0.add_hours(25);
    cout << "Time0 + 25 hours:   " << time0 << endl;

    cout << time0 << " + " << time1 << " = ";
    time0 += time1;
    cout << time0 << endl;

    cout << time0 << ((time0 == time1) ? " == " : " != ") << time1 << endl;
    cout << time0 << ((time0 == time0) ? " == " : " != ") << time0 << endl;

    system("pause");
    return 0;
}
