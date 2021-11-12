#include "thread.h"
#include "socketserver.h"
#include <stdlib.h>
#include <time.h>
#include <list>
#include <vector>
#include <algorithm>
#include "socket.h"

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
        //int * p;
         // Wait for a client socket connection
        Socket* newConnection = new Socket(server.Accept());
        //Calls alternate constructor in socket.h, creates a socket link with Client
        //Client uses the other constructor that needs an IP and port

        // A reference to this pointer 
        Socket& socketReference = *newConnection;

        //ByteArray recvBuff(p, 255);
        
    	//socketReference.Read(recvBuff);
    	
    	//mangle string
    	//string mangled = recvBuff.ToString() + " yolo";
    	
    	//Writing mangled string to connection
    	//socketReference.Write(ByteArray(mangled));
    	
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
