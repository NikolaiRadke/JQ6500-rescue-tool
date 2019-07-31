#!/bin/sh

set -e

. ../../common.sh

# Change to the jq6500 source directory which ls finds, e.g. 'jq6500-0.42'.
cd `ls -d $OVERLAY_WORK_DIR/$BUNDLE_NAME/jq6500`

make_clean

rm -rf $DEST_DIR

echo "Building '$BUNDLE_NAME'."
make_target ARCHFLAGS=

echo "Installing '$BUNDLE_NAME' to $DEST_DIR."
make_target install DESTDIR=$DEST_DIR
install -m755 -D $SRC_DIR/99_jq6500.sh $DEST_DIR/etc/autorun/99_jq6500.sh
install -m644 -D $SRC_DIR/motd $DEST_DIR/etc/motd

echo "Reducing '$BUNDLE_NAME' size."
reduce_size $DEST_DIR/usr/bin

install_to_overlay

echo "Bundle '$BUNDLE_NAME' has been installed."

cd $SRC_DIR
