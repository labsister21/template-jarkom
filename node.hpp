#ifndef node_h
#define node_h

#include "socket.hpp"

/**
 * Abstract class.
 *
 * This is the base class for Server and Client class.
 */
class Node
{
protected:
    TCPSocket *connection;

public:
    void run();
    virtual void handleMessage(Segment segment) = 0;
};

#endif