#include "utils.h"
#include <cstdio>

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

}
