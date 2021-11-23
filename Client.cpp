
#include "thread.h"
#include "socket.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
// #include <string>

using namespace Sync;

int main(void)
{	
	std::string userInput;
	int * p;

	// Welcome the user 
	std::cout << "SE3313 Lab 3 Client" << std::endl;

	// Create our socket
	Socket socket("127.0.0.1", 3000);

	//Declare recv buffer
	ByteArray recvBuff(p, 255);

	//Try to connect to server 	
	socket.Open();


	std::cout << "awaiting input.. " << std::endl;

	// Loop
	while(true) {
		
		//Once connected await for string input
		std::cin >> userInput;
		//Wait for reply
		//When reply 
		if (userInput != "done") {
			socket.Write(ByteArray(userInput));
			sleep(2);
			
			socket.Read(recvBuff);

			std::cout << "Response: " << recvBuff.ToString() << std::endl;
			
		} 
		if (userInput == "done") {
			socket.Write(ByteArray("done"));
			break;
		}
	}

	socket.Close();

	return 0;
}
