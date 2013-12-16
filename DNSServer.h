/* 
 * File:   DNSServer.h
 * Author: rafal.olejniczak
 *
 * Created on 16 grudzień 2013, 13:21
 */

#ifndef DNSSERVER_H
#define	DNSSERVER_H

class DNSServer {
public:
    DNSServer();
    DNSServer(int address);
    DNSServer(const char* address);
    DNSServer(const DNSServer& orig);
    virtual ~DNSServer();
    int translate(const char* );
private:
    int _address;
};

#endif	/* DNSSERVER_H */

