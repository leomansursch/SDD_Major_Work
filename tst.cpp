/*//Use g++ for build

#include <winsock2.h>
#include <Windows.h> //Sleep 
#include <stdlib.h> //System


using namespace std;*/
#include <Windows.h> //Sleep 
#include <iostream>  //cout
#include <fstream>
using namespace std;
//now testing host checking
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

}

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

int main() {
string host;
cout << "put in host" << endl;
cin >> host;
string tst = "ping " + host + " > NULL 2>&1";
int x = system(tst.c_str());
if (x==0){
    cout<<"success"<<endl;
    Sleep(5000);
}else{
    cout<<"failed"<<endl;
    Sleep(5000);
}
}*/


//now testing sending TCP packets for Scanner() DONE 13/7/21
/*

#ifndef UNICODE
#define UNICODE
#endif

#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

// Need to link with Ws2_32.libB
#pragma comment(lib, "ws2_32.lib")
string host = "192.168.0.247";
int port[] = {80,22,69};
int portresponce[] = {};
int sport = sizeof(port) / sizeof(port[ 0 ]) - 1 ;
int main(){

    cout << sport << endl;
    for (int i = 0; i <= sport; i++) {
        cout << portresponce[i] << endl;
        cout << port[i] << endl;
        //----------------------
        // Initialize Winsock
        WSADATA wsaData;
        int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (iResult != NO_ERROR) {
            wprintf(L"WSAStartup function failed with error: %d\n", iResult);
            return 1;
        }else{
            cout << "tst" << endl;
        }
        //----------------------
        // Create a SOCKET for connecting to server
        SOCKET ConnectSocket;
        ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (ConnectSocket == INVALID_SOCKET) {
            wprintf(L"socket function failed with error: %ld\n", WSAGetLastError());
            WSACleanup();
            return 1;
        }else{
            cout << "socket created" << endl;
        }
        //----------------------
        // The sockaddr_in structure specifies the address family,
        // IP address, and port of the server to be connected to.
        sockaddr_in clientService;
        clientService.sin_family = AF_INET;
        clientService.sin_addr.s_addr = inet_addr(host.c_str());
        clientService.sin_port = htons(port[i]);
        cout << clientService.sin_family << endl <<  clientService.sin_addr.s_addr << endl << clientService.sin_port << endl;

        //----------------------
        // Connect to server.
        iResult = connect(ConnectSocket, (SOCKADDR *) & clientService, sizeof (clientService));
        if (iResult == SOCKET_ERROR) {
            wprintf(L"connect function failed with error: %ld\n", WSAGetLastError());
            portresponce[i] = 0;
            iResult = closesocket(ConnectSocket);
            if (iResult == SOCKET_ERROR)
                wprintf(L"closesocket function failed with error: %ld\n", WSAGetLastError());
            WSACleanup();
        }
        else{
            cout << "wtf is going on" << endl;
            wprintf(L"Connected to server.\n");
            portresponce[i] = 1;
            cout << portresponce[i] << endl;
        }



        iResult = closesocket(ConnectSocket);
        if (iResult == SOCKET_ERROR) {
            wprintf(L"closesocket function failed with error: %ld\n", WSAGetLastError());
            WSACleanup();
        }
        cout << endl << endl << endl;
        WSACleanup();

    }
    for (int i = 0; i <= sport; i++) {
    cout << portresponce[i] << endl;
    }


}*/


//now testing file outputs and how to get data from other subprograms 
int main(){
    string test1 = "aiodufboadsb'b'a bs";
    string test2 = "iabfiabibfiabwidbaisbkdbasbd";
    string test3 = "C:\\Users\\leo\\Documents\\SDD_Major_Work\\test.txt";
    ofstream testfile;
    testfile.open (test3);
    cout<<"file is opend";
    testfile << test1 << endl << test2 << endl;
    cout<<"file has been writen";
    testfile.close();
    cout<<"file has been closed";
    return 0;
}