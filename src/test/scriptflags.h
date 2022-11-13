// Copyright (c) 2017 The Blink developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BLINK_TEST_SCRIPTFLAGS_H
#define BLINK_TEST_SCRIPTFLAGS_H

#include <string>

uint32_t ParseScriptFlags(std::string strFlags);
std::string FormatScriptFlags(uint32_t flags);

#endif // BLINK_TEST_SCRIPTFLAGS_H
