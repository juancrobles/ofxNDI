meta:
	ADDON_NAME = ofxNDI
	ADDON_DESCRIPTION = NewTek NDI SDK Wrapper for openFrameworks. https://www.newtek.com/ndi/
	ADDON_AUTHOR = Nariaki Iwatani
	ADDON_TAGS = "NDI" "Network" "Video"
	ADDON_URL = https://github.com/nariakiiwatani/ofxNDI

common:
	ADDON_INCLUDES = libs/NDI/include
osx:
	ADDON_SOURCES = libs/NDI/lib/osx/libndi.3.dylib
	ADDON_LIBS = libs/NDI/lib/osx/libndi.3.dylib
	ADDON_LDFLAGS = -Xlinker -rpath -Xlinker @executable_path
ios:
	ADDON_SOURCES = libs/NDI/lib/iOS/libndi_ios.a
	ADDON_LIBS = libs/NDI/lib/iOS/libndi_ios.a
vs:
	# x64
	ADDON_LIBS = libs/NDI/lib/vs/x64/Processing.NDI.Lib.x64.lib
	ADDON_DLLS_TO_COPY = windows-copy-to-bin/Processing.NDI.Lib.x64.lib
	# Win32
	# ADDON_LIBS = libs/NDI/lib/vs/Win32/Processing.NDI.Lib.x86.lib
	# ADDON_DLLS_TO_COPY = windows-copy-to-bin/Processing.NDI.Lib.x86.lib

