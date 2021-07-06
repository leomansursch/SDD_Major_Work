//Use g++ for build
#include <iostream>  //cout
#include <Windows.h> //Sleep
#include <stdlib.h> //System
using namespace std;

/*
string host = "abcdnef.com";
string tst = "ping " + host + "";
int main(){
    system(tst.c_str());
    Sleep(5000);
}

string host = "1.1.1.1";
string pingc = "ping -a -n 3" + host;
int main(){
    system(pingc.c_str());
    Sleep(5000);

}*/

//system(tst.c_str())//

string host = "192.168.0.247";
string tst = "ping " + host;
string tst2;
int main(){
    tst2 = system(tst.c_str()); 
    Sleep(500);
    cout << tst2;
    Sleep(5000);

}