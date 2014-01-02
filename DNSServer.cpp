/* 
 * File:   DNSServer.cpp
 * Author: rafal.olejniczak
 * 
 * Created on 16 grudzień 2013, 13:21
 */

#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <sys/unistd.h>
#include "utils.h"

#define DEST_PORT 53

#include "DNSServer.h"
#include "Request.h"
#include "BEResponse.h"
#include "Response.h"

DNSServer::DNSServer() {
    this->_address = 0;
}

DNSServer::DNSServer(int address) {
    this->_address = address;
}

DNSServer::DNSServer(char* address) {
    this->_address = com_olejniczak_utils::convert_addr_to_int(address);
    this->_dot_addr = address;
//    this->_address *= 256;
    
    /* Prepare send to address */
    this->_dest_addr.sin_family = AF_INET; // host byte order
    this->_dest_addr.sin_port = htons( DEST_PORT ); // short, network byte order
    this->_dest_addr.sin_addr.s_addr = inet_addr( this->_dot_addr );
    memset( &( this->_dest_addr.sin_zero ), '\0', 8 ); // wyzeruj resztę struktury
}

DNSServer::DNSServer(const DNSServer& orig) {
}

DNSServer::~DNSServer() {
    disconnect();
}

void DNSServer::connect() {
    struct sockaddr_in my_addr;
    this->_sockfd = socket(PF_INET, SOCK_DGRAM, 0);
    
    my_addr.sin_family = AF_INET; // host byte order
    my_addr.sin_port = htons( 0 ); // short, network byte order
    my_addr.sin_addr.s_addr =  INADDR_ANY ;
    memset( &( my_addr.sin_zero ), '\0', 8 ); // wyzeruj resztę struktury
    
    bind( this->_sockfd,
                ( struct sockaddr * ) &my_addr, 
                sizeof( struct sockaddr ) 
            );
}

void DNSServer::disconnect() {
    close( this->_sockfd );
}

void DNSServer::sendRequest(Request &req) {
    char* msg;
    int length, check;
    
    msg = req.marshal(&length);
    
    check = sendto( 
            this->_sockfd,
            msg, 
            length, 
            0,
            (sockaddr *) &this->_dest_addr, 
            sizeof(this->_dest_addr)
        );
    free(msg);
    if (check == -1) {
        return;
    }
}

Response *DNSServer::receiveResponse() {
    unsigned char buffer[1024];
    BEResponse be_response;
    Response *response;
    int check, dst_addr_len;
    struct sockaddr_in dest;
    
    memset(buffer, 0, 1024);
    response = new Response();
    
    check = recvfrom( 
                this->_sockfd, 
                buffer, 
                1024,
                0,
                (sockaddr *) &this->_dest_addr,
                &dst_addr_len);
    if (check == -1) {
        return response;
    }
    com_olejniczak_utils::print(buffer, 1024);
    
    return response;
}

int DNSServer::translate(const char* addr) {
    
    Request request;
    Response *response;
    int check = 0;
    int length = 0;
    
    request.addQuestion(addr, 0x01);
    
    sendRequest(request);
    response = receiveResponse();
    
    
//    memcpy(be_response.getHeaderRef(),
//            buffer,
//            sizeof(com_olejniczak_utils::be_dns_header)
//         );
    
//    com_olejniczak_utils::print(buffer, 1024);
    
    
    return 0;
}

