// Copyright (c) 2017 The Blink developers
// Copyright (c) 2019 Blink Association
// Distributed under the Open BSV software license, see the accompanying file LICENSE.

#include "config.h"
#include "consensus/validation.h"
#include "primitives/transaction.h"
#include "validation.h"

bool CheckFinalTx(
    const CTransaction &tx,
    int32_t nChainActiveHeight,
    int nMedianTimePast,
    int flags = -1) {

    auto &config = GlobalConfig::GetConfig();
    CValidationState state;
    return ContextualCheckTransactionForCurrentBlock(
                config,
                tx,
                nChainActiveHeight,
                nMedianTimePast,
                state,
                flags);
}
