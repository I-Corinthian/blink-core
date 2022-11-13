#!/bin/bash

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

BLINKD=${BLINKD:-$SRCDIR/blinkd}
BLINKCLI=${BLINKCLI:-$SRCDIR/blink-cli}
BLINKTX=${BLINKTX:-$SRCDIR/blink-tx}

[ ! -x $BLINKD ] && echo "$BLINKD not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
BTCVER=($($BLINKCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for blinkd if --version-string is not set,
# but has different outcomes for blink-cli.
echo "[COPYRIGHT]" > footer.h2m
$BLINKD --version | sed -n '1!p' >> footer.h2m

for cmd in $BLINKD $BLINKCLI $BLINKTX; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${BTCVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${BTCVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
