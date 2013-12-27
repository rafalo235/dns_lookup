/* 
 * File:   utils.h
 * Author: rafal.olejniczak
 *
 * Created on 16 grudzień 2013, 13:51
 */
#include <stdint.h>

#ifndef UTILS_H
#define	UTILS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    
    
    namespace com_olejniczak_utils {
        typedef struct {
            uint16_t id;
//            uint16_t qr:1;
//            uint16_t opcode:4;
//            uint16_t aa:1;
//            uint16_t tc:1;
//            uint16_t rd:1;
//            uint16_t ra:1;
//            uint16_t z:3;
//            uint16_t r_code:4;
            uint16_t r_code:4;
            uint16_t z:3;
            uint16_t ra:1;
            uint16_t rd:1;
            uint16_t tc:1;
            uint16_t aa:1;
            uint16_t opcode:4;
            uint16_t qr:1;
//            uint16_t rd:1;
//            uint16_t tc:1;
//            uint16_t aa:1;
//            uint16_t opcode:4;
//            uint16_t qr:1;
//            uint16_t r_code:4;
//            uint16_t z:3;
//            uint16_t ra:1;
            uint16_t qdcount;
            uint16_t ancount;
            uint16_t nscount;
            uint16_t arcount;
        } dns_header;
        
        typedef struct {
            uint16_t id;
            uint16_t flags;
            uint16_t qdcount;
            uint16_t ancount;
            uint16_t nscount;
            uint16_t arcount;
        } be_dns_header;
        
        typedef struct {
            char* name;
            uint16_t length;
        } internal_name;
        
        typedef struct {
            internal_name name;
            uint16_t type;
            uint16_t net_class;
        } dns_question;
        
        typedef struct {
            uint16_t name;
            uint16_t type;
            uint16_t net_class;
            uint32_t ttl;
            uint16_t length;
            uint16_t data;
        } dns_resource_rec;
        
        int convert_addr_to_int(const char*);
        int count_dots(const char*);
        void fill_string_length(char* str, int length);
        char* convert_serv_name_to_internal(const char*, uint16_t *);
        void convert_dots(char *str);
        void print(char *, int);
    }

#ifdef	__cplusplus
}
#endif

#endif	/* UTILS_H */

