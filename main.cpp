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
int port[] = {}; // creats an array of any length for ports
int portresponce[] = {}; // creates an array of any length for the responce from the ports either 0 for fail 1 for success


void debugexamples() {
    cout << "ALERT DEBUG IS ON" << endl;
    cout << "variables have been assigned for skiping" << endl;  
    //start variables
    host = "1.1.1.1";
    port[0] = 80;
    port[1] = 22;
    port[2] = 443;
    //resolve variables
    //scan variables
    //output variables
    cout << "please select subprogram to skip to" << endl;
    cout << "1 for 'start', 2 for 'resolve', 3 for 'scan', 4 for 'output'" << endl;
    cout << "For normal program please select 1" << endl;
    cin >> tmp1;
    if (tmp1 == "1"){
        cout << "proceding with normal program" << endl;
    }else if (tmp1 == "2"){
        cout << "skiping to resolve" << endl;
        resolve = true;
        start = false;
    }else if (tmp1 == "3"){
        cout << "skiping to scan" << endl;
        useport = true;
        start = false;
    }else if (tmp1 == "4"){
        cout << "skiping to output" << endl;
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
            
            while ((tmp3 = tmp2.find(tmp1)) != std::string::npos) {
            tmp5 = tmp2.substr(0, tmp3);
            cout << tmp5 << std::endl;
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

int resolver() { 
    string tst = "ping " + host + " > NULL 2>&1";
    int tmp3 = system(tst.c_str());
    if (tmp3==0){
        cout<<"success"<<endl;
        Sleep(5000);
    }else{
        cout<<"failed"<<endl;
        Sleep(5000);
    }
    return 0;
}

int scanner() {
    //int tmp4 = sizeof(port) / sizeof(port[ 0 ]) - 1 ;
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
            // Hostname >> IP
            /*if (i = 1) {
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
                        while ( host_info->h_addr_list[i] != 0 ){
                            addr.s_addr = *(u_long *) host_info->h_addr_list[i++];
                            host == inet_ntoa(addr); // inet_ntoa function converts IPv4 address to ASCII string in Internet standard dotted-decimal format.
                            cout << endl << host << endl << "a" << endl;
                        }
                    }
            }*/
            
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
        useport == false;
        return 0;
}

int fout() {
    ofstream fileout;
    fileout.open (fileoutput);
    cout<<"file is opend";
    fileout << /*var goes here*/"" << endl << /*var goes here*/""  << endl;
    cout<<"file has been writen";
    fileout.close();
    cout<<"file has been closed";
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