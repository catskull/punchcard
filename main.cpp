#include <iostream>
#include <windows.h>
#include <ctime>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

string timeToDate(time_t time) {
    stringstream ss;
    int hour;
    struct tm * now = localtime(&time);

    if (now->tm_hour > 12){
            hour = now->tm_hour - 12;
            }
    else {
            hour = now->tm_hour;
            }

    ss << hour << ':'
        << now->tm_min
        << endl;
    return ss.str();
}

bool writeDate(string date) {
    ifstream fileIn("time.csv");
    string contents;
    fileIn >> contents;
    fileIn.close();
    cout << contents << endl;
    if (contents.size() > 0){
        contents += ",";
    }
    ofstream file;
    file.open("time.csv", ios_base::trunc);
    contents += date;
    cout << contents << endl;
    file << contents;
    file.close();
}

int main()
{
    time_t t = time(0);     // var to store the time at which the key was pressed
    bool flag = 0;          // var to store whether the key just checked was pressed or not
    bool time_flag = 1;     // var to store whether timeout csv has already been written

    while (true) {
        for(int i = 0; i < 255; i++) {
            flag = GetAsyncKeyState(i);
            if (flag == 1) {
                t = time(0);
                if (time_flag == 1) {
                    cout << "Time started." << endl;
                }
                time_flag = 0;
            }

        if (time(0) - t > 5 && !time_flag) {
            cout << "Time expired." << endl;
            cout << timeToDate(t) << endl;
            writeDate(timeToDate(t));

            time_flag = 1;
        }

        }
    }
}
