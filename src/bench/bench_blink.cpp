// Copyright (c) 2015-2016 The Bitcoin Core developers
// Copyright (c) 2019 Blink Association
// Distributed under the Open BSV software license, see the accompanying file LICENSE.

#include "bench.h"
#include "crypto/sha256.h"
#include "key.h"
#include "random.h"
#include "util.h"

int main(int argc, char** argv)
{
    SHA256AutoDetect();
    RandomInit();
    SetupEnvironment();

    // don't want to write to blinkd.log file
    GetLogger().fPrintToDebugLog = false;

    benchmark::BenchRunner::RunAll();
}
