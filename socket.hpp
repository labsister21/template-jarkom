#ifndef socket_h
#define socket_h

#include <sys/socket.h>
#include <string>
#include <functional>
#include "segment.hpp"
#include "segment_handler.hpp"

using namespace std;

class TCPSocket
{
private:
    /**
     * The ip address and port for the socket instance
     * Not to be confused with ip address and port of the connected connection
     */
    string ip;
    int32_t port;

    /**
     * Socket descriptor
     */
    int32_t socket;

    function<void(Segment)> handler;

    SegmentHandler *segmentHandler;

    void notify();

public:
    void send(string ip, int32_t port);
    void listen();
    void close();
    void registerHandler(function<void(Segment)> handler);
};

#endif