/* SPDX-License-Identifier: MIT */
/*******************************************************************************
 * Copyright (C) 2015 Maxim Integrated Products, Inc., All rights Reserved.
 *
 * ucl_hash.h - Hash function selection defines for the UCL library.
 *
 * These defines are used to select or deselect hash functions,
 * useful on platforms with limited resources.
 *******************************************************************************
 */
#ifndef _UCL_HASH_H
#define _UCL_HASH_H

#define HASH_SHA256
#define HASH_SIA256
#define HASH_SHA3

#define MAX_HASH_FUNCTIONS 3

#endif /* UCL_HASH */
