/*//Use g++ for build

#include <winsock2.h>
#include <Windows.h> //Sleep
#include <stdlib.h> //System


using namespace std;*/
#include <iostream>  //cout
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
/*
string host = "192.168.0.247";
string tst = "ping " + host;
string tst2;
int main(){
    tst2 = system(tst.c_str()); 
    Sleep(500);
    cout << tst2;
    Sleep(5000);

}*/
/*
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


//now testing sending TCP packets for Scanner()

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
int port = {1,2,3,54,89,66};
int tmp1 = size(port);
int main()
for (int i = 0; i < tmp1; i++) {
    cout << port[i] << endl;
}


/*
{
    //----------------------
    // Initialize Winsock
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        wprintf(L"WSAStartup function failed with error: %d\n", iResult);
        return 1;
    }else{
        cout << "tst";
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
        cout << "socket create";
    }
    //----------------------s
    // The sockaddr_in structure specifies the address family,
    // IP address, and port of the server to be connected to.
    sockaddr_in clientService;
    clientService.sin_family = AF_INET;
    clientService.sin_addr.s_addr = inet_addr(host.c_str());
    clientService.sin_port = htons(port);
    cout << clientService.sin_family << endl <<  clientService.sin_addr.s_addr << endl << clientService.sin_port;

    //----------------------
    // Connect to server.
    iResult = connect(ConnectSocket, (SOCKADDR *) & clientService, sizeof (clientService));
    if (iResult == SOCKET_ERROR) {
        wprintf(L"connect function failed with error: %ld\n", WSAGetLastError());
        iResult = closesocket(ConnectSocket);
        if (iResult == SOCKET_ERROR)
            wprintf(L"closesocket function failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    else{
        cout << "wtf is going on";
    }

    wprintf(L"Connected to server.\n");

    iResult = closesocket(ConnectSocket);
    if (iResult == SOCKET_ERROR) {
        wprintf(L"closesocket function failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    WSACleanup();
    return 0;
    */
}