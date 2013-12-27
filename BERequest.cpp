/* 
 * File:   BERequest.cpp
 * Author: rafal.olejniczak
 * 
 * Created on 27 grudzień 2013, 09:10
 */

#include "BERequest.h"
#include "Request.h"
#include <stdint.h>
#include <stdlib.h>
#include <cstring>
#include <arpa/inet.h>

BERequest::BERequest(Request &request) {
    uint16_t *tab;
    int i;
    com_olejniczak_utils::dns_header tmp;
    
    /* Copy structures */
    tmp =  request.getHeader();
    memcpy(&this->_header, &tmp, sizeof(com_olejniczak_utils::be_dns_header));
    this->_questions = request.getQuestions(&this->_header.qdcount);
    this->_q_amount = request.getHeader().qdcount;
    
    /* Convert header to Big-Endian*/
    tab = (uint16_t *) &(this->_header);
    for (i = 0 ; i < 6 ; i++) {
        tab[i] = htons(tab[i]);
    }
    
    /* Convert questions endings for BE */
    for (i = 0 ; i < this->_q_amount ; i++) {
        this->_questions[i].net_class = htons(this->_questions[i].net_class);
        this->_questions[i].type = htons(this->_questions[i].type);
    }
}

char* BERequest::marshal(int *length) {
    char* ret;
    int len, p1, i;
    
    /* Determinate message size */
    len = sizeof(this->_header);
    len += 4 * this->_q_amount;
    for (i = 0 ; i < this->_q_amount ; i++) {
        len += this->_questions[i].name.length;
    }
    
    /* Allocate memory */
    ret = (char *) calloc(len, sizeof(char));
    p1 = 0;
    
    /* Write message */
    memcpy(ret, &this->_header, sizeof(this->_header) );
    p1 += sizeof(this->_header);
    
    for (i = 0 ; i < this->_q_amount ; i++) {
//        memset(
//                ret + p1, 
//                0x0b,
//                sizeof(char)
//           );
//        p1 += 1;
        
//        com_olejniczak_utils::convert_dots(this->_questions[i].name.name);
        memcpy(
                ret + p1, 
                this->_questions[i].name.name,
                this->_questions[i].name.length
           );
        p1 += this->_questions[i].name.length;
        
        memcpy(
                ret + p1, 
                &this->_questions[i].type,
                sizeof(uint16_t)
           );
        p1 += sizeof(uint16_t);
        
        memcpy(
                ret + p1, 
                &this->_questions[i].net_class,
                sizeof(uint16_t)
           );
        p1 += sizeof(uint16_t);
    }
    *length = len;

    return ret;
}

BERequest::~BERequest() {
}

