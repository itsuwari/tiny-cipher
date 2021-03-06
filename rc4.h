#ifndef _LibRc4_h_
#define _LibRc4_h_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  IMPORTS
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  TYPES
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Rc4Context - This must be initialised using Rc4Initialised. Do not modify the contents of this structure directly.
typedef struct
{
    uint32_t     i;
    uint32_t     j;
    uint8_t      S[256];
} Rc4Context;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  PUBLIC FUNCTIONS
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Rc4Initialise
//
//  Initialises an RC4 cipher and discards the specified number of first bytes.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void
    Rc4Initialise
    (
        Rc4Context*     Context,
        void*           Key,
        uint32_t        KeySize,
        uint32_t        DropN
    );

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Rc4Output
//
//  Outputs the requested number of bytes from the RC4 stream
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void
    Rc4Output
    (
        Rc4Context*     Context,
        void*           Buffer,
        uint32_t        Size
    );

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Rc4Xor
//
//  XORs the RC4 stream with an input buffer and puts the results in an output buffer. This is used for encrypting
//  and decrypting data. InBuffer and OutBuffer can point to the same location for inplace encrypting/decrypting
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void
    Rc4Xor
    (
        Rc4Context*     Context,
        void*           InBuffer,
        void*           OutBuffer,
        uint32_t        Size
    );

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif //_LibRc4_h_
