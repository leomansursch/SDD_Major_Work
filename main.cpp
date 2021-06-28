#include <iostream>  //cout
#include <Windows.h> //Sleep
using namespace std;

//Variables
    //States
bool start = true;
bool resolve = false;
bool scan = false;
bool output = false;
bool debug = false;
bool uport = false;
    //user inputs
string host, ports;
    // temp storage
string tmp1, tmp2;
char tmp3, tmp4;



int main()
{
     while (debug == true){
        cout << "ALERT DEBUG IS ON" << endl;
        cout << "please select subprogram to skip to" << endl;
        cout << "1 for 'start', 2 for 'resolve', 3 for 'scan', 4 for 'output'" << endl;
        cout << "For normal program please select 1" << endl;
        cin >> tmp3;
        if (tmp3 == '1'){
            cout << "proceding with normal program" << endl;
        } 
        else if (tmp3 == '2'){
            cout << "skiping to resolve" << endl;
            resolve = true;
            start = false;
        }
        else if (tmp3 == '3'){
            cout << "skiping to scan" << endl;
            scan = true;
            start = false;
        }
        else if (tmp3 == '4'){
            cout << "skiping to output" << endl;
            output = true;
            start = false;
        }
        else {
            cout << "invaid responce please select select a vaild responce"
        }


        

            }
   while (start == true){
       cout << "please input hostname or IP address" << endl;
       cin >> host;
       cout << "would you like to scan ports? (y/N)" << endl;
       cin >> tmp3;
       if (tmp3 == 'y') {
           uport = true;
           cout << "Please enter the ports seperated by a comma" << endl;
           cin >> ports;
           start = false;
           resolve = true;
       } else {
           start = false;
           resolve = true;
       }
    while (resolve == true){
        system("cmd" & "ping" && host);
    }
   }

}