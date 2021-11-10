
#include "thread.h"
#include "socket.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace Sync;

int main(void)
{
	// Welcome the user 
	std::cout << "SE3313 Lab 3 Client" << std::endl;

	// Create our socket
	Socket socket("127.0.0.1", 3000);


	//Try to connect to server

	//Loop
	//Once connected await for string input
	//Wait for reply
	//When reply 
	//Continue loop

	//To write to socket and read from socket. You may use ByteArray 
	//socket.Write(data);
	//socket.Read(data);

	//If done entered
	//Send flag to server
	//loop
	//close all sockets
	socket.Close();
	//terminate threads.. ie. flag them
	
	return 0;
}
