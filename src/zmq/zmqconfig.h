// Copyright (c) 2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BLINK_ZMQ_ZMQCONFIG_H
#define BLINK_ZMQ_ZMQCONFIG_H

#if defined(HAVE_CONFIG_H)
#include "config/blink-config.h"
#endif

#include <string>

#if ENABLE_ZMQ
#include <zmq.h>
#endif

#include "primitives/block.h"

void zmqError(const char *str);

#endif // BLINK_ZMQ_ZMQCONFIG_H
