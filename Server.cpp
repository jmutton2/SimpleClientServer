#include "thread.h"
#include "socketserver.h"
#include <stdlib.h>
#include <time.h>
#include <list>
#include <vector>
#include <algorithm>


using namespace Sync;
using namespace std;

// This thread handles the server operations
class ServerThread : public Thread
{
    private:
        SocketServer& server;

    public:
        ServerThread(SocketServer& server)
        : server(server)
        {}

        ~ServerThread()
        {
            // Cleanup
        //...
        }

        virtual long ThreadMain()
        {
            // Wait for a client socket connection
            Socket* newConnection = new Socket(server.Accept());

            // A reference to this pointer 
            Socket& socketReference = *newConnection;
        //You can use this to read data from socket and write data to socket. You may want to put 		this read/write somewhere else. You may use ByteArray
        // Wait for data
            //socketReference.Read(data); //Get the data
            //Scramble the data
            // Send it back
            //socketReference.Write(data); //Send it back
        return 1;
        }
    };


    int main(void)
    {
    
        cout << "I am a server." << endl;
        
        // Create our server
        SocketServer server(3000);    

        // Need a thread to perform server operations
        ServerThread serverThread(server); 
        //if flag
        //shut down



        
        // This will wait for input to shutdown the server
        FlexWait cinWaiter(1, stdin);
        cinWaiter.Wait();

        // Shut down and clean up the server
        server.Shutdown();

}
