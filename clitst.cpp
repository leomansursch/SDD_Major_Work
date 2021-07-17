/*//Use g++ for build

#include <winsock2.h>
#include <Windows.h> //Sleep 
#include <stdlib.h> //System


using namespace std;
#include <Windows.h> //Sleep 
#include <iostream>  //cout
#include <fstream>
using namespace std;
//now testing host checking

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
}


//now testing sending TCP packets for Scanner() DONE 13/7/21


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


}


//now testing file outputs and how to get data from other subprograms 

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


#include <winsock2.h> // scanner()
#include <Windows.h> //Sleep

#include <ws2tcpip.h> // scanner()
#include <stdio.h>  // scanner()
#include <fstream> // fout() file creation,opening,editing,closing

#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "ws2_32.lib") // dependancy of <winsock2.h>

int main() {
    //int tmp4 = sizeof(port) / sizeof(port[ 0 ]) - 1 ;
    int tmp4;
    int port[] = {};
    int portresponce[] = {};
    string host = "realflavour.media";
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
    cout << host <<endl;
    //----------------------
    // Hostname >> IP
    cout << host;
    DWORD dw;
    struct hostent * host_info;
    struct in_addr addr;    
    // hostname for which we want the IP address
    host_info = gethostbyname (host.c_str()); // gethostbyname function retrieves host information.
    // gethostbyname returns a pointer of type struct hostent.
    //A null pointer is returned if an error occurs. The specific error number can be known by calling WSAGetLastError.
    if ( host_info == NULL ){
        dw = WSAGetLastError ();
        if ( dw != 0 ){
            if ( dw == WSAHOST_NOT_FOUND ){
                cout << "Host is not found";
                return 1;
            }
            else if ( dw == WSANO_DATA ){
                cout << "No data record is found";
                return 1;
            }
            else{
                cout << "Function failed with an error : " << dw;
                return 1;
            }
        }
    }
    else{
        cout << "Hostname : " << host_info->h_name << endl;
        addr.s_addr = *(u_long *) host_info->h_addr_list;
        host == inet_ntoa(addr); // inet_ntoa function converts IPv4 address to ASCII string in Internet standard dotted-decimal format.
        cout << endl << host << endl << "a" << endl;
        WSACleanup();
                
                
    }
            
    for (int i = 0; i <= tmp4; i++) {
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
            cout << host <<endl;
            //----------------------
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
        return 0;*/

#include <iostream>  //cout
#include <winsock2.h> // scanner()
#include <Windows.h> //Sleep
#include <stdlib.h> //System
#include <ws2tcpip.h> // scanner()
#include <stdio.h>  // scanner()
#include <fstream> // fout() file creation,opening,editing,closing
#include <string.h> // string 
#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "ws2_32.lib") // dependancy of <winsock2.h>
using namespace std;
/*
int main()
{

    //-----------------------------------------
    // Declare and initialize variables
    string host = "realflavour.media";
    WSADATA wsaData;
    int iResult;

    DWORD dwError;
    int i = 0;

    struct hostent *remoteHost;
    struct in_addr addr;

    char **pAlias;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        WSACleanup();
        return 1;
    }
    // get the stupid ip address
    remoteHost = gethostbyname(host.c_str());
    
    if (remoteHost == NULL) {
        dwError = WSAGetLastError();
        if (dwError != 0) {
            if (dwError == WSAHOST_NOT_FOUND) {
                printf("Host not found\n");
                return 1;
            } else if (dwError == WSANO_DATA) {
                printf("No data record found\n");
                return 1;
            } else {
                printf("Function failed with error: %ld\n", dwError);
                return 1;
            }
        }
    } 
    
    if (remoteHost->h_addrtype == AF_INET)
    {
        while (remoteHost->h_addr_list[i] != 0) {
            addr.s_addr = *(u_long *) remoteHost->h_addr_list[i++];
            printf("\tIP Address #%d: %s\n", i, inet_ntoa(addr));
        }
    }
    host = inet_ntoa(addr);
    WSACleanup();
    return 0;
}*/


// ensuring that file output works
string fileoutput = "C:\\Users\\leo\\Documents\\SDD_Major_Work\\test.txt", tmp1 = "did";
int tmp4 = 2;
int port[50] = {};
int presponce[50] = {};
int tmp2 = tmp4 - 1;



int main() {

    ofstream fileout;
    fileout.open (fileoutput);
    cout<<"file is opend";
    fileout << "The host " << tmp1 << " respond to pings" << endl;
    cout << "the ports scaned were ";
    for (int i = 0; i <= tmp4; i++) {
        fileout << port[i];
        if (i <= tmp2);
            fileout << ",";
    }
    fileout << "." << endl;
    fileout << "From these port/s ";
    for (int i = 0; i <= tmp4; i++){
        if (presponce[i] == 1) {
            fileout << port[i] << ",";
        }
        else{
        }
    }
    fileout << "are open. and ";
    for (int i = 0; i <= tmp4; i++){
        if (presponce[i] == 2) {
            fileout << port[i] << ",";
        }
        else{
        }
    }
    fileout << "are closed." << endl;
    cout<<"file has been writen";
    fileout.close();
    cout<<"file has been closed";
    return 0;
} 
