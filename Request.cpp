/* 
 * File:   Request.cpp
 * Author: rafal.olejniczak
 * 
 * Created on 16 grudzień 2013, 16:17
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <arpa/inet.h>
#include "Request.h"
#include "BERequest.h"

Request::Request() {
    this->_header.id = 0x0000;
    this->_header.qr = 0x0;
    this->_header.opcode = 0x00;
    this->_header.aa = 0x0; // set by server
    this->_header.tc = 0x0; // set by server
    this->_header.rd = 0x1;
    this->_header.ra = 0x0; // set by server
    this->_header.z = 0x00; // reserved
    this->_header.r_code = 0x00; // response code set by server
    this->_header.qdcount = 0x0000;
    this->_header.ancount = 0x0000; // set by server
    this->_header.nscount = 0x0000; // set by server
    this->_header.arcount = 0x0000; // set by server
    this->_questions = NULL;
}

Request::Request(const Request& orig) {
    //this->_header = orig.getHeader();
}

Request::Request(const char *serv_name) {
    this->_header.id = 0x0000;
    this->_header.qr = 0x0;
    this->_header.opcode = 0x00;
    this->_header.aa = 0x0; // set by server
    this->_header.tc = 0x0; // set by server
    this->_header.rd = 0x1;
    this->_header.ra = 0x0; // set by server
    this->_header.z = 0x00; // reserved
    this->_header.r_code = 0x00; // response code set by server
    this->_header.qdcount = 0x0000;
    this->_header.ancount = 0x0000; // set by server
    this->_header.nscount = 0x0000; // set by server
    this->_header.arcount = 0x0000; // set by server
    this->_questions = NULL;
    addQuestion(serv_name, 0x01);
}

void Request::setHeaderId(uint16_t id) {
    this->_header.id = id;
}

void Request::addQuestion(const char *name, uint16_t type) {
    com_olejniczak_utils::dns_question q;
    q.name.name = 
            com_olejniczak_utils::convert_serv_name_to_internal(
                name, 
                &q.name.length
            );
    q.type = type;
    q.net_class = 0x0001; // IN - Internet
    this->_header.qdcount++;
    this->_questions = (com_olejniczak_utils::dns_question*)
        realloc(
            this->_questions,
            this->_header.qdcount * sizeof(com_olejniczak_utils::dns_question)
        );
    this->_questions[this->_header.qdcount - 1] = q;
}

com_olejniczak_utils::dns_header Request::getHeader() {
    return this->_header;
}

com_olejniczak_utils::dns_question* Request::getQuestions(uint16_t *length) {
    com_olejniczak_utils::dns_question* ret;
    ret = (com_olejniczak_utils::dns_question *) calloc(
            this->_header.qdcount,
            sizeof(com_olejniczak_utils::dns_question)
            );
    for (int i = 0 ; i < this->_header.qdcount ; i++) {
        ret[i] = this->_questions[i];
    }
    *length = this->_header.qdcount;
    return ret;
}

Request::~Request() {
    for (int i = 0; i < this->_header.qdcount; i++) {
        free( this->_questions[i].name.name );
    }
    free( this->_questions );
}

char* Request::marshal(int *length) {
//    char* ret;
//    int len, p1, i;
//    
//    /* Determinate message size */
//    len = sizeof(this->_header);
//    len += 4 * this->_header.qdcount;
//    for (i = 0 ; i < this->_header.qdcount ; i++) {
//        len += this->_questions[i].name.length;
//        len += 2;
//    }
//    
//    /* Allocate memory */
////    while (buf_len < len) {
////        buf_len += 2;
////    }
//    ret = (char *) calloc(len, sizeof(char));
//    p1 = 0;
//    
//    /* Write message */
//    this->_header.qdcount = htons(this->_header.qdcount);
//    memcpy(ret, &this->_header, sizeof(this->_header) );
//    this->_header.qdcount = ntohs(this->_header.qdcount);
//    p1 += sizeof(this->_header);
////    for (i = 0 ; i < 6 ; i++) {
////        *(ret + i * sizeof(uint16_t)) = htons(*(ret + i * sizeof(uint16_t)));
////    }
//    
//    for (i = 0 ; i < this->_header.qdcount ; i++) {
//        memset(
//                ret + p1, 
//                0x0b,
//                1
//           );
//        p1 += 1;
//        com_olejniczak_utils::convert_dots(this->_questions[i].name.name);
//        memcpy(
//                ret + p1, 
//                this->_questions[i].name.name,
//                this->_questions[i].name.length + 1
//           );
//        p1 += this->_questions[i].name.length;
//        p1 += 1;
//        this->_questions[i].type = htons(this->_questions[i].type);
//        memcpy(
//                ret + p1, 
//                &this->_questions[i].type,
//                2
////                sizeof(this->_questions[i].type)
//           );
//        p1 += sizeof(this->_questions[i].type);
//        this->_questions[i].net_class = htons(this->_questions[i].net_class);
//        memcpy(
//                ret + p1, 
//                &this->_questions[i].net_class,
//                2
////                sizeof(this->_questions[i].net_class)
//           );
//        p1 += sizeof(this->_questions[i].net_class);
//    }
//    *length = len;
//    
//    
//    return ret;
    char *ret;
    
    BERequest bereq(*this);
    ret = bereq.marshal(length);
//    free(bereq);
    
    return ret;
}

