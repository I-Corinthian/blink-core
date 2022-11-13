// Copyright (c) 2021 Blink Association
// Distributed under the Open BSV software license, see the accompanying file LICENSE.

#ifndef BLINK_ABORTNODE_H
#define BLINK_ABORTNODE_H

#include <iostream>
#include "consensus/validation.h"

bool AbortNode(const std::string &strMessage,
               const std::string &userMessage = "");

bool AbortNode(CValidationState &state, const std::string &strMessage,
               const std::string &userMessage = "");

#endif
