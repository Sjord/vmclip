#!/bin/sh

set -e

: ${CC:=gcc}
: ${CFLAGS="-Wall"}

$CC $CFLAGS -o vmclip-read vmclip-read.c vmware.c
$CC $CFLAGS -o vmclip-write vmclip-write.c vmware.c
