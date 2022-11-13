// Copyright (c) 2011-2016 The Bitcoin Core developers
// Copyright (c) 2017 The Bitcoin developers
// Copyright (c) 2019 Blink Association
// Distributed under the Open BSV software license, see the accompanying file LICENSE.

#include "chainparams.h"
#include "config.h"
#include "consensus/consensus.h"
#include "primitives/transaction.h"
#include "test/test_blink.h"
#include "util.h"
#include "validation.h"

#include <cstdint>
#include <cstdio>
#include <vector>

#include <boost/test/unit_test.hpp>

static CBlock makeLargeDummyBlock(const size_t num_tx) {
    CBlock block;
    block.vtx.reserve(num_tx);

    CTransaction tx;
    for (size_t i = 0; i < num_tx; i++) {
        block.vtx.push_back(MakeTransactionRef(tx));
    }
    return block;
}

BOOST_FIXTURE_TEST_SUITE(validation_tests, TestingSetup)

/** Test that LoadExternalBlockFile works with the buffer size set
below the size of a large block. Currently, LoadExternalBlockFile has the
buffer size for CBufferedFile set to 2 * MAX_TX_SIZE. Test with a value
of 10 * MAX_TX_SIZE. */
BOOST_AUTO_TEST_CASE(validation_load_external_block_file) {
    fs::path tmpfile_name =
        pathTemp / strprintf("vlebf_test_%lu_%i", (unsigned long)GetTime(),
                             (int)(InsecureRandRange(100000)));

    UniqueCFile fp{ fopen(tmpfile_name.string().c_str(), "wb+") };

    BOOST_CHECK(fp != nullptr);

    const Config &config = GlobalConfig::GetConfig();
    const CChainParams &chainparams = config.GetChainParams();

    // serialization format is:
    // message start magic, size of block, block

    size_t nwritten = fwrite(chainparams.DiskMagic().data(),
                             CMessageFields::MESSAGE_START_SIZE, 1, fp.get());

    BOOST_CHECK_EQUAL(nwritten, 1UL);

    CTransaction empty_tx;
    size_t empty_tx_size = GetSerializeSize(empty_tx, SER_DISK, CLIENT_VERSION);

    size_t num_tx = (10 * MAX_TX_SIZE_CONSENSUS_BEFORE_GENESIS) / empty_tx_size;

    CBlock block = makeLargeDummyBlock(num_tx);

    BOOST_CHECK(GetSerializeSize(block, SER_DISK, CLIENT_VERSION) >
                2 * MAX_TX_SIZE_CONSENSUS_BEFORE_GENESIS);

    unsigned int size = GetSerializeSize(block, SER_DISK, CLIENT_VERSION);
    {
        CAutoFile outs(std::move(fp), SER_DISK, CLIENT_VERSION);
        outs << size;
        outs << block;
        fp = outs.release();
    }

    fseek(fp.get(), 0, SEEK_SET);
    BOOST_CHECK_NO_THROW({ LoadExternalBlockFile(config, std::move(fp), 0); });
}

BOOST_AUTO_TEST_SUITE_END()
