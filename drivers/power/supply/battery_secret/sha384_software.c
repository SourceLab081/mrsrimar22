// SPDX-License-Identifier: MIT
/*
 * sha384_software.c - HMAC-SHA3-256 software implementation
 *
 * Copyright (C) 2017 Maxim Integrated Products, Inc., All Rights Reserved.
 *
 */
#include "ucl_sha3.h"
#include <linux/string.h>
#include "sha384_software.h"

/*
 * sha3_256_hmac_phase - one HMAC phase: SHA3-256(pad || data).
 *
 * IMPORTANT: ucl_sha3_finish() writes the *full* Keccak sponge state to the
 * digest pointer, which is SHA3_SPONGE_WORDS * 8 = 25 * 8 = 200 bytes,
 * regardless of the logical hash output length (32 bytes for SHA3-256).
 * Callers MUST supply an output buffer of at least SHA3_SPONGE_WORDS * 8
 * bytes; the meaningful digest occupies only the first UCL_SHA3_256_HASHSIZE
 * (32) bytes of that buffer.
 */
static int sha3_256_hmac_phase(const unsigned char *pad,
				const unsigned char *data, int data_len,
				unsigned char *out)
{
	unsigned char cat_input[1024];

	memcpy(cat_input, pad, 136);
	memcpy(&cat_input[136], data, data_len);
	return ucl_sha3_256(out, cat_input, 136 + data_len);
}

int sha3_256_hmac(const unsigned char *key, int key_len,
		  const unsigned char *message, int msg_len,
		  unsigned char *mac)
{
	unsigned char thash[SHA3_SPONGE_WORDS * 8]; /* phase-1 sponge output */
	unsigned char tmac[SHA3_SPONGE_WORDS * 8];  /* phase-2 sponge output */
	unsigned char opad[136];
	unsigned char ipad[136];
	int i;

	if (key_len > 136)
		return 0;

	if (msg_len > 512)
		return 0;

	memset(opad, 0x5C, sizeof(opad));
	memset(ipad, 0x36, sizeof(ipad));

	for (i = 0; i < key_len; i++) {
		ipad[i] ^= key[i];
		opad[i] ^= key[i];
	}

	/* thash[0..199] = SHA3-256(ipad || message); digest in [0..31] */
	sha3_256_hmac_phase(ipad, message, msg_len, thash);

	/* tmac[0..199] = SHA3-256(opad || thash[0..31]); digest in [0..31] */
	sha3_256_hmac_phase(opad, thash, UCL_SHA3_256_HASHSIZE, tmac);

	/* copy only the meaningful 32-byte digest to the caller's buffer */
	memcpy(mac, tmac, UCL_SHA3_256_HASHSIZE);

	return 1;
}
