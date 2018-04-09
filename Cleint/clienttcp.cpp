#include "clienttcp.h"
#include "client.h"
#include "singleton.h"
#include <iostream>
#include <signal.h>
#include "../src/TCPClient.h"
#include <fstream>
#include <string>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

TCPClient tcp;
vector<string> data;
vector<string> stringLenthes;
vector<string> packetSizes;
int fileNumber = 1;

void sig_exit(int s)
{
    tcp.exit();
    exit(0);
}

void CreateLogFileInNewDir(string content){
    string outputFolderName = "output";
    outputFolderName.append(to_string(fileNumber++));
    string path = "output/";
    path.append(outputFolderName);

    if(!QDir(&path[0u]).exists())
        QDir().mkdir(&path[0u]);
    path.append("/log.txt");
    std::ofstream out(path);
    out << content;
    out.close();
}

void ClientTCP :: run()
{
    /* Waiting for connection */

    signal(SIGINT, sig_exit);
    bool connected = false;
    std::cout << "TRYING TO CONNECT.." << std::endl;
    while(!connected){
        connected = tcp.setup("127.0.0.1",8080);
        usleep(1000000);
    }
    cout << "CONNECTED!" << std::endl;

    if(!QDir("output").exists())
        QDir().mkdir("output");

    // Initializing buffer and packet string
    bool receivingBuffer = false;
    string buffer = "";
    string packetString = "";

    // Receiving thread
    while(1)
    {
        srand(time(0));
        string rec = tcp.receive();
        if(rec == "start"){
            receivingBuffer = true;
            std::cout << "Receiving new packet!" << std::endl;
            string packetSize = tcp.receive();
            string stringLengh = tcp.receive();
            std::cout << "packet size --> " << packetSize << std::endl;
            std::cout << "string length --> " << stringLengh << std::endl;
            packetSizes.push_back(packetSize);
            stringLenthes.push_back(stringLengh);
            Singleton* s = Singleton::getInstance();
            s->packetSizes.push_back(packetSize);
            s->stringLengthes.push_back(stringLengh);
        }

        buffer = "";
        while(receivingBuffer){
            packetString = tcp.receive();
            if(packetString == "end"){
                receivingBuffer = false;
                break;
            }
            else if( packetString != "" )
            {
                buffer.append(packetString);
            }
        }

        if(buffer != ""){
            data.push_back(buffer);
            cout << "buffer received: \n" << buffer << std::endl;
            CreateLogFileInNewDir(buffer);
        }
        sleep(1);
    }
}
