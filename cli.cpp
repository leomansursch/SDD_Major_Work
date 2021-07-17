//Use g++ for build
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
//Each section of the program is broken down into subprograms (Starting(), resolver(), Scaner(), Outputs())
//This allows me to do further explination about each subprogram while not cluttering up main()
//Variables
    //debug
bool debug = false; //example data also verbose data about where we are
    //States

bool start = true; // gathe user input
bool resolve = false; //check if host alive
bool useport = false; // decision for scan()
bool uout = false; // decision for output()

    //user inputs
string host, fileoutput; // user input for host and file output directory
    // temp storage
string tmp1, tmp2, tmp5; // tmp1 for debug menu selection, tmp2 for starting() menu selection
int tmp3, tmp4; // tmp3 for ping() alive/dead, tmp4 for no. elemnts of arrays scanner() used for itterating the for loop the amount of times that entitys are in the array
//internal variables 
int port[20] = {}; // creats an array of any length for ports
int presponce[20] = {}; // creates an array of any length for the responce from the ports either 0 for fail 1 for success


void debugexamples() {
    cout << "ALERT DEBUG IS ON" << endl;
    cout << "variables have been assigned for skiping" << endl;  
    //start variables
    host = "realflavour.media";
    port[0] = 80;
    port[1] = 443;
    port[2] = 553;
    //resolve variables
    //scan variables
    //output variables
    cout << "please select subprogram to skip to" << endl;
    cout << "1 for 'start', 2 for 'resolve', 3 for 'scan', 4 for 'output'" << endl;
    cout << "For normal program please select 1" << endl;
    cin >> tmp1;
    if (tmp1 == "1"){
        cout << "proceding with normal program" << endl;
        debug = false;
    }else if (tmp1 == "2"){
        cout << "skiping to resolve" << endl;
        debug = false;
        resolve = true;
        start = false;
    }else if (tmp1 == "3"){
        cout << "skiping to scan" << endl;
        debug = false;
        useport = true;
        start = false;
    }else if (tmp1 == "4"){
        cout << "skiping to output" << endl;
        debug = false;
        uout = true;
        start = false;
    }else {
        cout << "invaid responce please select select a vaild responce";
    }
    return;
}

void starting() { 
    cout << "please input hostname or IP address" << endl;
        cin >> host;
        cout << "would you like to scan ports? (y/N)" << endl;
        cin >> tmp2;
        if (tmp2 == "y") {
            useport = true;
            cout << "Please enter the ports seperated by a comma" << endl;
            cin >> tmp2;
            tmp2 = tmp2 + ",";
            tmp1 = ",";
            tmp3 = 0;
            tmp4 = 0;
            
            while ((tmp3 = tmp2.find(tmp1)) != std::string::npos) {
            tmp5 = tmp2.substr(0, tmp3);
            cout << tmp5 << endl;
            port[tmp4] = stoi(tmp5);
            tmp4++;
            tmp2.erase(0, tmp3 + tmp1.length());
            }
            tmp1 = ""; //reset tmp1 to nothing
            tmp2 = ""; //reset tmp2 to nothing
            tmp3 = 0; //reset tmp3 to nothing
            tmp4 = tmp4 - 1;
            
        } else if (tmp2 == "n") { 
        } else {
        }
        cout << "would you like to output a file (y/N)" << endl;
        cin >> tmp2;
        if (tmp2 == "y") {
            uout = true;
            cout << "Please enter the directory with double \\ " << endl;
            cin >> fileoutput;
            start = false;
            resolve = true;
        } else if (tmp2 == "n") {
            start = false;
            resolve = true;
        } else {
            start = false;
            resolve = true;
        }
}

int ipresolver() { 
    //-----------------------------------------
    // Declare and initialize variables
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
        }
    }
    host = inet_ntoa(addr);
    WSACleanup();
    return 0;
}

int resolver() { 
    ipresolver();
    string tst = "ping " + host + " > NULL 2>&1";
    int tmp3 = system(tst.c_str());
    cout << tmp3 << endl;
    if (tmp3==0){
        cout<<"success"<<endl;
        tmp1 = "did";
        Sleep(5000);
    }else{
        cout<<"failed"<<endl;
        tmp1 = "did not";
        Sleep(5000);
    }
    return 0;
}


int scanner() {
    //int tmp4 = sizeof(port) / sizeof(port[ 0 ]) - 1 ;
    cout << "this is tmp4: " << tmp4;
    cout << endl << endl << endl;

    for (int i = 0; i <= tmp4; i++){
        cout << endl << endl << endl;
        cout << port[i];
        cout << endl << endl << endl;
    }

    for (int i = 0; i <= tmp4; i++) {
            //tmp2 << "port: " << port[i] << "is open";
            //tmp3 << "port: " << port[i] << "is open";
            WSACleanup();
            cout << "WSACleanup has been ran" << endl;
            cout << i << endl;
            //cout << presponce[i] << endl;
            cout <<  "port being tested:" << port[i] << endl;
            //----------------------
            // Initialize Winsock
            WSADATA wsaData;
            int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
            if (iResult != NO_ERROR) {
                wprintf(L"WSAStartup function failed with error: %d\n", iResult);
                return 1;
            }else{
                cout << "winsoc started" << endl;
            }
            cout << host <<endl;
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
            cout << port[i] <<  " why no work?" << endl;
            clientService.sin_port = htons(port[i]);
            cout << clientService.sin_family << " " <<  clientService.sin_addr.s_addr << " " << clientService.sin_port << endl;

            //----------------------
            // Connect to server.
            iResult = connect(ConnectSocket, (SOCKADDR *) & clientService, sizeof (clientService));
            if (iResult == SOCKET_ERROR) {
                wprintf(L"connect function failed with error: %ld\n", WSAGetLastError());
                //presponce[i] = 2;
                iResult = closesocket(ConnectSocket);
                WSACleanup();
                if (iResult == SOCKET_ERROR)
                    wprintf(L"closesocket function failed with error: %ld\n", WSAGetLastError());
                WSACleanup();
            }
            else{
                cout << "wtf is going on" << endl;
                cout << "Connected to server" << endl;
                //presponce[i] = 1;
                cout << "ones done" << endl;
            }
            iResult = closesocket(ConnectSocket);
            if (iResult == SOCKET_ERROR) {
                wprintf(L"closesocket function failed with error: %ld\n", WSAGetLastError());
                WSACleanup();
                cout << "WSACleanup has been ran" << endl;
            }
            cout << endl << endl << endl;
        }
        useport == false;
        
        return 0;
}

int fout() {
    tmp3 = tmp4 - 1; 
    /*ofstream fileout;
    fileout.open (fileoutput);
    cout<<"file is opend";
    fileout << "The host " << tmp1 << " respond to pings" << endl;
    fileout << "the ports scaned were ";
    for (int i = 0; i <= tmp4; i++) {
        fileout << port[i];
        for (int i = 0; i <= tmp4 - 1; i++){
            fileout << ",";
        }
    }
    fileout << "." << endl;
    fileout << "From these port/s ";
    for (int i = 0; i <= tmp4; i++){
        if (presponce[i] == 1) {
            fileout << port[i] << ",";
        }
    }
    fileout << "are open. and";
    for (int i = 0; i <= tmp4; i++){
        if (presponce[i] == 2) {
            fileout << port[i] << ",";
        }
    }
    fileout << "are closed." << endl;
    cout<<"file has been writen";
    fileout.close();
    cout<<"file has been closed";
    return 0;*/
    ofstream fileout;
    fileout.open (fileoutput);
    cout<<"file is opend" << endl;;
    fileout << "The host " << tmp1 << " respond to pings" << endl;
    if (useport = true){
        cout << "the ports scaned were ";
        for (int i = 0; i <= tmp4; i++) {
            fileout << port[i];
            if (i <= tmp3);
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
    }
    cout<<"file has been writen"<<endl;
    fileout.close();
    cout<<"file has been closed"<<endl;
    return 0;
} 

int main() {
   if (debug == true){
        debugexamples(); //calling debug setting of variable
    } 
   if (start == true){
        starting(); // gathering user input
    }   
   if (resolve == true){
        resolver(); // is the host alive
    }
   if (useport == true){
       scanner(); // are the ports open (optional)
    }
   if (uout == true){
       fout(); // output to a file (optional)
   }
   
}

