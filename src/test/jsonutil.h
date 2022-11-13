// Copyright (c) 2018 The Bitcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BLINK_TEST_JSONUTIL_H
#define BLINK_TEST_JSONUTIL_H

#include <string>
#include <univalue.h>

UniValue read_json(const std::string &jsondata);

#endif // BLINK_TEST_JSONUTIL_H
