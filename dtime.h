//DISPLAY 12.6 Placing a Class in a Namespace Header File
//Header file dtime.h: This is the interface for the class DigitalTime.
//Values of this type are times of day. The values are input and output in
//24-hour notation, as in 9:30 for 9:30 AM and 14:45 for 2:45 PM.

#ifndef DTIME_H
#define DTIME_H

#include <iostream>
using namespace std;

namespace dtimesavitch
{

    class DigitalTime
    {

    public:
        friend bool operator ==(const DigitalTime& time1, const DigitalTime& time2);
        //Returns true if time1 and time2 represent the same time;
        //otherwise, returns false.

        DigitalTime(int theHour, int theMinute);
        //Precondition: 0 <= theHour <= 23 and 0 <= theMinute <= 59.
        //Initializes the time value to theHour and theMinute.

        DigitalTime( );
        //Initializes the time value to 0:00 (which is midnight).

        void advance(int minutesAdded);
        //Precondition: The object has a time value.
        //Postcondition: The time has been changed to minutesAdded minutes later.

        void advance(int hoursAdded, int minutesAdded);
        //Precondition: The object has a time value.
        //Postcondition: The time value has been advanced
        //hoursAdded hours plus minutesAdded minutes.

        friend istream& operator >>(istream& ins, DigitalTime& theObject);
        //Overloads the >> operator for input values of type DigitalTime.
        //Precondition: If ins is a file input stream, then ins has already been
        //connected to a file.

        friend ostream& operator <<(ostream& outs, const DigitalTime& theObject);
        //Overloads the << operator for output values of type DigitalTime.
        //Precondition: If outs is a file output stream, then outs has already been
        //connected to a file.
    private:
        int hour;
        int minute;
    };
    
}//end dtimesavitch

#endif //DTIME_H
