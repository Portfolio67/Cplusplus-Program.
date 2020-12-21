
#include <iostream>
#include <iomanip>               // For setprecision
#include <ctime>     // current date/time based on current system
// just add seconds to the variable. now+1 = new variable.


using namespace std;

int currentHour24;
int currentHour12;
int currentMinute;
int currentSecond;

int cTime(int x) {
    // current date/time based on current system
    // just add seconds to the variable. now+1 = new variable.
    time_t now = time(0);   // add 3600 for an hour, 60 for a minute, 1 for a second.
    now += x;
    tm *ltm = localtime(&now);  // astrix is a mark for a pointer type. localtime() return pointertype
    cout << "Time: "<< ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;

    currentHour24 = ltm->tm_hour;
    if(currentHour24 >= 12){
        currentHour12 = currentHour24 - 12;
    }
    else{
        currentHour12 = currentHour24;
    }
    currentMinute = ltm->tm_min;
    currentSecond = ltm->tm_sec;
}

int clearScreen(){
    int i;
    for( int i=0; i<40; ++i){
        cout << endl;
    }
}

int displayClock(){
    cout << "Clock Display" << endl;
    cout << "***************************** 	 	 *****************************" << endl ;
    cout << "*       12-Hour Clock       * 	 	 *       24-Hour Clock       *" << endl ;
    cout << "*       "<<currentHour12 << ":" << currentMinute << ":" << currentSecond <<"     		* 	 	 *       "<< currentHour24 << ":" << currentMinute << ":" << currentSecond <<"  			 *" << endl ;
    cout << "***************************** 	 	 *****************************" << endl ;
    return 0;
}

int getInput(){
    cout << "Menu choice " << endl;
    cout << "***************************** " << endl ;
    cout << "* 1 - Add One Hour          * " << endl ;
    cout << "* 2 - Add One Minute        * " << endl ;
    cout << "* 3 - Add One Second        * " << endl ;
    cout << "* quit Exit Program         * " << endl ;
    cout << "***************************** " << endl ;
    return 0;
}

int main() {

    int currentTime;
    int now;
    int timeTracker = 0;
    //clearScreen(); // Outputs a screen with 8 new lines
    string userInput;

    //clearScreen();
    cTime(0);  // must pass cTime a int
    displayClock(); // after cTime has int then display clock gives current time plus 0 seconds
    getInput();
    cout << "What is your selection: ";
    cin >> userInput;
    while(userInput != "quit"){ // & != no:pos //FIXME THROW EXCEPTION
        try{
            if(userInput == "1"){
                timeTracker += 3600;  // Pluss equals keeps the change
                //timeTracker in main because calling to change in this and keep it changed
                cTime(timeTracker);
            }
            if(userInput == "2"){
                timeTracker += 60;  // Pluss equals keeps the change
                //timeTracker in main because calling to change in this and keep it changed
                cTime(timeTracker);
            }

            if(userInput == "3"){
                timeTracker += 1;  // Pluss equals keeps the change
                //timeTracker in main because calling to change in this and keep it changed
                cTime(timeTracker);
            }

            clearScreen();
            displayClock();
            getInput();
            cout << "What is your selection: ";
            cin >> userInput;;

        }
        catch (runtime_error& excpt) {
            // Prints the error message passed by throw statement
            cout << excpt.what() << endl;
            cout << "Invalid input: quit , 1, 2, or 3" << endl;
        }


    }

    return 0;
}


