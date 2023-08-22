#!/bin/sh
BASE_DIR=`pwd`

DEST_DIR=$BASE_DIR/libs

NDI5_SDK_DIR="/Library/NDI SDK for macOS"
NDI5_LIB_DIR=lib/macOS
NDI5_LIB=libndi.dylib
NDI5_HEADERS_DIR=$BASE_DIR/libs/NDI/include
NDI5_LICENSE_FILE=libndi_licenses.txt

echo "creating the framework $DEST_DIR/NDI5.xcframework"

rm -rf $DEST_DIR/NDI5.xcframework

xcodebuild -create-xcframework -library "${NDI5_SDK_DIR}/${NDI5_LIB_DIR}/${NDI5_LIB}" -headers "${NDI5_HEADERS_DIR}" -output $DEST_DIR/NDI5.xcframework

# copy license file
cp -f "${NDI5_SDK_DIR}/${NDI5_LIB_DIR}/${NDI5_LICENSE_FILE}" $DEST_DIR/NDI5.xcframework/macos-arm64_x86_64/
