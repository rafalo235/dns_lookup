/* 
 * File:   utils.h
 * Author: rafal.olejniczak
 *
 * Created on 16 grudzień 2013, 13:51
 */

#ifndef UTILS_H
#define	UTILS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    #include <stdint.h>
    
    namespace com_olejniczak_utils {
        typedef struct {
            uint16_t id;
            uint16_t qr:1;
            uint16_t opcode:4;
            uint16_t aa:1;
            uint16_t tc:1;
            uint16_t rd:1;
            uint16_t ra:1;
            uint16_t z:3;
            uint16_t r_code:4;
            uint16_t qdcount;
            uint16_t ancount;
            uint16_t nscount;
            uint16_t arcount;
        } dns_header;
        
        typedef struct {
            char* name;
            uint16_t length;
        } internal_name;
        
        typedef struct {
            internal_name name;
            uint16_t type;
            uint16_t net_class;
        } dns_question;
        
        int convert_addr_to_int(const char*);
    }

#ifdef	__cplusplus
}
#endif

#endif	/* UTILS_H */

