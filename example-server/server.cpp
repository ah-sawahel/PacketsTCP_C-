#include <iostream>
#include "TCPServer.h"

TCPServer tcp;

void * loop(void * m)
{
  pthread_detach(pthread_self());
	while(1)
	{
		srand(time(NULL));
    int numberOfPackets;
    int stringLength;

    cout << "Enter Number Of Packets: " << endl;
    cin >> numberOfPackets;
    cout << "Enter Packet Size: " << endl;
    cin >> stringLength;

    tcp.Send("start");
    usleep(10);
    tcp.Send(to_string(numberOfPackets));
    usleep(10);
    tcp.Send(to_string(stringLength));
    usleep(10);
    for (int i = 0; i < numberOfPackets; i++) {
      string packetString = "";
  		char ch = 'a';
      cout << i << endl;

      for (int j = 0; j < stringLength; j++) {
        ch = 'a' + rand() % 26;
        packetString += ch;
      }
      packetString += ' ';
      packetString += '#';
      packetString += to_string(i+1);
      packetString += '\n';
			cout << "Message:" << packetString << endl;
			tcp.Send(packetString);
      usleep(50);
    }
    tcp.Send("end");
    usleep(100);
  //  tcp.clean();

	}
	tcp.detach();
}

int main()
{
	pthread_t msg;
	tcp.setup(8080);
	if( pthread_create(&msg, NULL, loop, (void *)0) == 0)
	{
		tcp.receive();
	}
	return 0;
}
