//Use g++ for build
#include <iostream>  //cout
#include <Windows.h> //Sleep
#include <stdlib.h> //System
using namespace std;

string tst1;
string host = "abcdnef.com";
string tst = "ping " + host + "";
int main(){
    system(tst.c_str());
    tst1 = system("echo %ERRORLEVEL%");
    cout << tst1;
    Sleep(5000);
}