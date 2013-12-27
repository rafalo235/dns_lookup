#include "utils.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

namespace com_olejniczak_utils {

int convert_addr_to_int(const char* addr) {
    unsigned char* a;
    int r = 0;
    a = new unsigned char[4];
    sscanf(addr, "%hhu.%hhu.%hhu.%hhu", &a[0], &a[1], &a[2], &a[3]);
    
    r = 0;
    for(int i = 0 ; i < 4 ; i++) {
        r += a[i];
        if (i != 3) {
                r *= 256;
        }
    }
    return r;
}

int count_dots(const char* str) {
    int i = 0, counter = 0;
    
    while(str[i] != '\0') {
        if ( str[i] == '.' ) {
            counter++;
        }
        i += sizeof(char);
    }
    return counter;
}

void fill_string_length(char* str, int length) {
    char tmp[5];
    sprintf( tmp, "0x%02x", length);
    for ( int i = 0; i < 4 ; i++ ) {
        str[i] = tmp[i];
    }
}

char* convert_serv_name_to_internal(const char* serv_name, uint16_t *length) {
    int len, i = 0, counter = 0;
    char *int_nam = 0;
    
    /* Memory allocation */
    *length = len = strlen(serv_name) + 2;
    int_nam = (char *) calloc(len, sizeof(char));
    
    /* Prepare iterators */
    i = len - 3;
    len -= 2;
    
    /* Prepare returned value */
    while ( i >= 0 ) {
        if ( serv_name[i] == '.') {
            int_nam[len] = counter;
            len -= sizeof(char);
            i -= sizeof(char);
            counter = 0;
        } else {
            int_nam[len] = serv_name[i];
            len -= sizeof(char);
            i -= sizeof(char);
            counter++;
        }
    }
    int_nam[0] = counter;
    
    return int_nam;
}

void convert_dots(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if ( str[i] == '.') {
            str[i] = 0x02;
        }
        i += sizeof(char);
    }
}

}
