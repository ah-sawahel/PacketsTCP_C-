First build server from terminal:

1) cd to Server dir
2) run --> g++ -Wall -o server server.cpp -I../src/ ../src/TCPServer.cpp ../src/TCPClient.cpp -std=c++11 -lpthread
3) run server --> ./server

Secondly run directly Client application in build-Cleint-Desktop-Debug folder
OR build and run main class in Client folder

PS: output folder for log files will be generated in build-Cleint-Desktop-Debug folder
