/*
 * Copyright (C) Internet Systems Consortium, Inc. ("ISC")
 *
 * SPDX-License-Identifier: MPL-2.0
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, you can obtain one at https://mozilla.org/MPL/2.0/.
 *
 * See the COPYRIGHT file distributed with this work for additional
 * information regarding copyright ownership.
 */

#pragma once

/*****
***** Module Info
*****/

/*! \file dns/byaddr.h
 * \brief
 * The byaddr module provides reverse lookup services for IPv4 and IPv6
 * addresses.
 *
 * MP:
 *\li	The module ensures appropriate synchronization of data structures it
 *	creates and manipulates.
 *
 * Reliability:
 *\li	No anticipated impact.
 *
 * Resources:
 *\li	TBS
 *
 * Security:
 *\li	No anticipated impact.
 *
 * Standards:
 *\li	RFCs:	1034, 1035, 2181, TBS
 *\li	Drafts:	TBS
 */

#include <isc/event.h>
#include <isc/lang.h>

#include <dns/types.h>

ISC_LANG_BEGINDECLS

isc_result_t
dns_byaddr_createptrname(const isc_netaddr_t *address, unsigned int options,
			 dns_name_t *name);
/*%<
 * Creates a name that would be used in a PTR query for this address.  The
 * nibble flag indicates that the 'nibble' format is to be used if an IPv6
 * address is provided, instead of the 'bitstring' format.  Since we dropped
 * the support of the bitstring labels, it is expected that the flag is always
 * set.  'options' are the same as for dns_byaddr_create().
 *
 * Requires:
 *
 * \li	'address' is a valid address.
 * \li	'name' is a valid name with a dedicated buffer.
 */

ISC_LANG_ENDDECLS
