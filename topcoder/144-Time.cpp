#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Time
{
      public:
             string whatTime( int seconds )
             {
                    stringstream cout;
                    int hours = seconds/3600;
                    int minutes = (seconds - hours*3600)/60;
                    int sec = seconds - ( minutes*60 + hours * 3600);
                    cout<<hours<<":"<<minutes<<":"<<sec;
                    return cout.str( );
                    }
                    
};
