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

int DNSServer::translate(const char* addr) {
    Request r;
    BEResponse be_response;
    char* msg;
    unsigned char buffer[1024];
    struct sockaddr_in dest_addr;
    int dst_addr_len;
    int check = 0;
    int length = 0;
    
    r.addQuestion(addr, 0x01);
    msg = r.marshal(&length);
    
    memset(buffer, 0, 1024);
    
    /* Prepare send to address */
    dest_addr.sin_family = AF_INET; // host byte order
    dest_addr.sin_port = htons( DEST_PORT ); // short, network byte order
    dest_addr.sin_addr.s_addr = inet_addr( this->_dot_addr );
    memset( &( dest_addr.sin_zero ), '\0', 8 ); // wyzeruj resztę struktury
    
    
    check = sendto( 
            this->_sockfd,
            msg, 
            length, 
            0,
            (sockaddr *) &dest_addr, 
            sizeof(dest_addr)
        );
    free(msg);
    if (check == -1) {
        return 1;
    }
    
    check = recvfrom( 
                this->_sockfd, 
                buffer, 
                1024,
                0,
                (sockaddr *) &dest_addr,
                &dst_addr_len);
    if (check == -1) {
        return 2;
    }
    
//    memcpy(be_response.getHeaderRef(),
//            buffer,
//            sizeof(com_olejniczak_utils::be_dns_header)
//         );
    
    
    
//    com_olejniczak_utils::print(buffer, 1024);
    
    
    return 0;
}

