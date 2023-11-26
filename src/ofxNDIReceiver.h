//#pragma once
//
//#include "ofConstants.h"
//#include "ofxNDI.h"
////#include <Processing.NDI.Advanced.h>
//#include <Processing.NDI.Recv.h>
//#include <string>
//#include <vector>
//
//namespace ofxNDI {
//namespace Recv {
//		
//class Receiver
//{
//public:
//	using Instance = NDIlib_recv_instance_t;
//	~Receiver();
//
//	struct Settings {
//		Settings(){}
//#ifdef TARGET_WIN32
//		NDIlib_recv_color_format_e color_format=NDIlib_recv_color_format_BGRX_BGRA;
//#else
//		NDIlib_recv_color_format_e color_format=NDIlib_recv_color_format_RGBX_RGBA;
//#endif
//		NDIlib_recv_bandwidth_e bandwidth=NDIlib_recv_bandwidth_highest;
//		bool deinterlace=false;
//		std::string name="";
//	};
//	bool setup(std::size_t index=0, const Settings &settings=Settings());
//	bool setup(const Source &source, const Settings &settings=Settings());
//	void clear();
//	bool isSetup() const { return instance_ != nullptr; }
//
//	bool isConnected() const;
//	void changeConnection(const Source &source);
//	void disconnect();
//	
//	void addConnectionMetadata(const std::string &metadata, int64_t timecode=NDIlib_send_timecode_synthesize) const;
//	void clearConnectionMetadata() const;
//
//	bool setTally(bool on_program, bool on_preview) const;
//	
//	bool isKVMSupported() const;
//	std::string getWebControl() const;
//	
//	void getQueue(int *video, int *audio, int *metadata) const;
//	void getNumReceivedFrame(int64_t *video, int64_t *audio, int64_t *metadata) const;
//	void getNumDroppedFrame(int64_t *video, int64_t *audio, int64_t *metadata) const;
//	
//	NDIlib_recv_instance_t getInstance() const { return instance_; }
//	NDIlib_framesync_instance_t createFrameSync();
//	NDIlib_framesync_instance_t getFrameSync() const { return frame_sync_; }
//	void destroyFrameSync();
//private:
//	NDIlib_recv_instance_t instance_=nullptr;
//	NDIlib_framesync_instance_t frame_sync_=nullptr;
//};
//
//}}
//
//using ofxNDIReceiver = ofxNDI::Recv::Receiver;
