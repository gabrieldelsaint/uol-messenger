/*
 * aes.h
 *
 * header file for the AES block cipher
 *
 * David A. McGrew
 * Cisco Systems, Inc.
 */

/*
 *	
 * Copyright (c) 2001-2005, Cisco Systems, Inc.
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 *   Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * 
 *   Redistributions in binary form must reproduce the above
 *   copyright notice, this list of conditions and the following
 *   disclaimer in the documentation and/or other materials provided
 *   with the distribution.
 * 
 *   Neither the name of the Cisco Systems, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef _AES_H
#define _AES_H

#include "config.h"

#include "datatypes.h"
#include "gf2_8.h"

/* aes internals */

typedef v128_t aes_expanded_key_t[11];

void
aes_expand_encryption_key(v128_t key, 
			  aes_expanded_key_t expanded_key);

inline void
aes_expand_decryption_key(const v128_t key, 
			  aes_expanded_key_t expanded_key);

void
aes_encrypt(v128_t *plaintext, const aes_expanded_key_t exp_key);

void
aes_decrypt(v128_t *plaintext, const aes_expanded_key_t exp_key);

/*
 * gf2_8_shift(x) returns the next gf2_8 value in the cyclic
 * representation of that field
 */

gf2_8
gf2_8_shift(octet_t input);

#if 0
/*
 * internal functions 
 */

void
aes_init_sbox(void);

void
aes_compute_tables(void);
#endif 

#endif /* _AES_H */
