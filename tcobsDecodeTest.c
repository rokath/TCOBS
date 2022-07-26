
#include <stdint.h>
#include <string.h>
#include "tcobs.h"
#include "tcobsInternal.h"

//! decodeDebugSet contains only representative data for debugging.
//! The more intensive testing is done from Go using CGO.
static uint8_t decodeDebugSet[] = {
  //len, data...

      3, F1,         0xaa, R0|1,
      5, 0xFF, 0xFF, 0xaa, 0xaa, 0xaa,

      4, F1,         0xaa, 0xaa, Z1|2,
      6, 0xFF, 0xFF, 0xaa, 0xaa, 0, 0,

      3, F1,         0xaa, Z1|1,
      5, 0xFF, 0xFF, 0xaa, 0, 0,

      2, F1,           Z1,
      4, 0xFF, 0xFF, 0, 0,

      4, F1,           Z1,   F1,         Z1,
      8, 0xFF, 0xFF, 0, 0, 0xFF, 0xFF, 0, 0,

      1, F0,
      1, 0xFF,
     
      1, F1,
      2, 0xFF, 0xFF,
      
      1, F2,
      3, 0xFF, 0xFF, 0xFF,
      
      1, F3,
      4, 0xFF, 0xFF, 0xFF, 0xFF,

     10,                      F3, 0x22, 0x33,       F1|2, 0x55, 0x66, 0x77, 0x88, 0x99,             F2|5,
     16,  0xFF, 0xFF, 0xFF, 0xFF, 0x22, 0x33, 0xFF, 0xFF, 0x55, 0x66, 0x77, 0x88, 0x99, 0xFF, 0xFF, 0xFF,

     10,          Z3, 0x22, 0x33, Z1|2, 0x55, 0x66, 0x77, 0x88, 0x99,    Z2|5,
     16,  0, 0, 0, 0, 0x22, 0x33, 0, 0, 0x55, 0x66, 0x77, 0x88, 0x99, 0, 0, 0,

     10, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, Z0|9,
     10, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0,
      
     10, Z0, 0x22, 0x33, Z0|2, 0x55, 0x66, 0x77, 0x88, 0x99, Z0|5,
     10,  0, 0x22, 0x33,    0, 0x55, 0x66, 0x77, 0x88, 0x99, 0,
     
      1, Z0,
      1, 0,
     
      1, Z1,
      2, 0, 0,
      
      1, Z2,
      3, 0, 0, 0,
      
      1, Z3,
      4, 0, 0, 0, 0,

      2, 0xaa, R0|1,
      3, 0xaa, 0xaa, 0xaa,
      
      2, 0xaa, R1|1,
      4, 0xaa, 0xaa, 0xaa, 0xaa,
      
      2, 0xaa, R2|(1+1),
      5, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,

      2, Z0, Z0,
      5, 0, 0, 0, 0, 0,
      
      2, 0xaa, N|1,
      1, 0xaa,
      
      3, 0xaa, 0xaa, N|2,
      2, 0xaa, 0xaa,

      3, 0xaa, R0|1, R0,
      6, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,

};

void TCOBSDecodeTest( void ){
    uint8_t* t = decodeDebugSet;
    uint8_t* limit = decodeDebugSet + sizeof(decodeDebugSet);
    unsigned ilen, olen;
    uint8_t* input;
    const int omax = 32;
    uint8_t output[omax];

    while( t < limit ){
        ilen = *t++;
        input = t;
        memset( output, 0x55, sizeof(output) );
        olen = TCOBSDecode( output, omax, input, ilen);
        t += ilen;
        if( olen != *t++ ){ 
            for(;;){} 
        } 
        for( int i = omax - olen; i < omax; i++ ){
            if( output[i] != *t++ ){ 
                for(;;){} 
            } 
        }
    }
}
