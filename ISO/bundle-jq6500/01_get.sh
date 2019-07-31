#!/bin/sh

set -e

. ../../common.sh

# Read the 'jq6500' download URL from '.config'.
DOWNLOAD_URL=`read_property JQ6500_SOURCE_URL`

# Grab everything after the last '/' character.
ARCHIVE_FILE=${DOWNLOAD_URL##*/}

# Download 'jq6500' source archive in the 'source/overlay' directory.
download_source $DOWNLOAD_URL $OVERLAY_SOURCE_DIR/$ARCHIVE_FILE

# Extract all 'jq6500' sources in the 'work/overlay/jq6500' directory.
extract_source $OVERLAY_SOURCE_DIR/$ARCHIVE_FILE jq6500

cd $SRC_DIR
