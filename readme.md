# ofxNDI

NewTek NDI SDK Wrapper for openFrameworks.

Works on Mac, iOS, Linux, and Windows.

For Linux users, please follow this Issue.  
https://github.com/nariakiiwatani/ofxNDI/issues/27

__I stopped to provide iOS lib because it is so big that significantly consume my GitHub storage.  
please download it from NewTek.__

### Adding macOS support through xcframework
* Install NDI 5 SDK
* run on the terminal the following commands
    ``` shell
    cd of_path/addons/ofxNDI
    ./scripts/build_ndi5_xcframework
    ```
* open the xcode project
* on your project "Build Settings" remove all headers pointing to "../../../addons/ofxNDI/libs/NDI*"
* on your project "General" add the framework located on "of_path/addons/ofxNDI/libs/NDI5.xcframework"
* compile and run

## Warning
- This addon is trying to wrap all features of original SDK, but some of them are not tested.
- Receivers on mobile OS won't work because they are not supported by SDK currently.
