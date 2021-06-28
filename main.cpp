//Use g++ for build
#include <iostream>  //cout
#include <Windows.h> //Sleep
#include <stdlib.h> //System
using namespace std;

//Variables
    //debug
bool debug = false;
    //States

bool start = true;
bool resolve = false;
bool scan = false;
bool output = false;

bool uport = false;
    //user inputs
string host, ports;
    // temp storage
string tmp1, tmp2;
    // commands for terminal
string ping;
string port;

void debugexamples(){
    if (debug == true){
    //start variables
    host = "1.1.1.1";
    ports = "80";
    //resolve variables
    //scan variables
    //output variables
    cout << "variables have been assigned for skiping" << endl;  
    }
    return;

}

int main(){
   if (debug == true){
        debugexamples(); //calling debug setting of variables
        cout << "ALERT DEBUG IS ON" << endl;
        cout << "please select subprogram to skip to" << endl;
        cout << "1 for 'start', 2 for 'resolve', 3 for 'scan', 4 for 'output'" << endl;
        cout << "For normal program please select 1" << endl;
        cin >> tmp1;
        if (tmp1 == "1"){
            cout << "proceding with normal program" << endl;
        } 
        else if (tmp1 == "2"){
            cout << "skiping to resolve" << endl;
            resolve = true;
            start = false;
        }
        else if (tmp1 == "3"){
            cout << "skiping to scan" << endl;
            scan = true;
            start = false;
        }
        else if (tmp1 == "4"){
            cout << "skiping to output" << endl;
            output = true;
            start = false;
        }
        else {
            cout << "invaid responce please select select a vaild responce";
        }
    } 
   while (start == true){
       cout << "please input hostname or IP address" << endl;
       cin >> host;
       cout << "would you like to scan ports? (y/N)" << endl;
       cin >> tmp2;
       if (tmp2 == "y") {
           uport = true;
           cout << "Please enter the ports seperated by a comma" << endl;
           cin >> ports;
           start = false;
           resolve = true;
       } else {
           start = false;
           resolve = true;
       }
    }
   
   if (resolve == true){
        ping = "ping -a -n 3 " + host;
        tmp2 = system(ping.c_str());
        cout << endl << "a" << tmp2;
        Sleep(5000);
        cout << tmp2;
   }
}
