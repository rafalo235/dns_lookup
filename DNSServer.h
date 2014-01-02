/* 
 * File:   DNSServer.h
 * Author: rafal.olejniczak
 *
 * Created on 16 grudzień 2013, 13:21
 */

#include "Request.h"
#include "Response.h"
#include <netinet/in.h>

#ifndef DNSSERVER_H
#define	DNSSERVER_H

class DNSServer {
public:
    DNSServer();
    DNSServer(int address);
    DNSServer(char* address);
    DNSServer(const DNSServer& orig);
    void connect();
    void disconnect();
    void sendRequest(Request &);
    Response *receiveResponse();
    virtual ~DNSServer();
    int translate(const char* );
private:
    int _address;
    char* _dot_addr;
    int _sockfd;
    struct sockaddr_in _dest_addr;
};

#endif	/* DNSSERVER_H */

