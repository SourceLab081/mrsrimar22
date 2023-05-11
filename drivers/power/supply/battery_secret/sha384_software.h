/* SPDX-License-Identifier: MIT */
/*
 * sha384_software.h - HMAC-SHA3-256 software implementation interface
 *
 * Copyright (C) 2017 Maxim Integrated Products, Inc., All Rights Reserved.
 */
#ifndef __SHA384_SOFTWARE_H__
#define __SHA384_SOFTWARE_H__

/**
 * sha3_256_hmac - compute HMAC using SHA3-256.
 *
 * @key:  secret key buffer (not modified)
 * @key_len:  length of key in bytes (must be <= 136)
 * @message:  input message buffer (not modified)
 * @msg_len:  length of message in bytes (must be <= 512)
 * @mac:  32-byte output buffer for the resulting MAC
 *
 * Returns 1 on success, 0 if key_len or msg_len exceed supported limits.
 */
int sha3_256_hmac(const unsigned char *key, int key_len,
		  const unsigned char *message, int msg_len,
		  unsigned char *mac);

#endif /* __SHA384_SOFTWARE_H__ */
