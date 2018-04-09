#pragma once

#include "ofThread.h"
#include "DoubleBuffer.h"
#include <Processing.NDI.Lib.h>
#include "ofxNDIFrame.h"
#include "ofxNDIReceiver.h"
#include "ofxNDI.h"

namespace ofxNDI {
namespace Recv {

template<typename Frame, typename Type=ofxNDIReceiver>
class Stream : private ofThread
{
public:
	void setup(Type &type, uint32_t timeout_ms, bool threaded=true);
	void setup(typename Type::Instance instance, uint32_t timeout_ms, bool threaded=true);
	void update();
	bool isFrameNew() const { return is_frame_new_; }
	template<typename Output> void decodeTo(Output &dst);
private:
	typename Type::Instance instance_;
	DoubleBuffer<Frame> frame_;
	uint32_t timeout_ms_;
	bool is_frame_new_=false;
	bool has_new_frame_=false;
	bool is_front_allocated_=false;
	
	void threadedFunction();
	void updateFrame();
	bool captureFrame();
	void freeFrame();
};

template<typename Frame, typename Type>
void Stream<Frame, Type>::setup(Type &type, uint32_t timeout_ms, bool threaded) {
	setup(type.getInstance(), timeout_ms, threaded);
}
template<typename Frame, typename Type>
void Stream<Frame, Type>::setup(typename Type::Instance instance, uint32_t timeout_ms, bool threaded) {
	instance_ = instance;
	timeout_ms_ = timeout_ms;
	if(threaded) {
		startThread();
	}
}
template<typename Frame, typename Type>
void Stream<Frame, Type>::update() {
	if(isThreadRunning()) {
		if(lock()) {
			is_frame_new_ = has_new_frame_;
			has_new_frame_ = false;
			unlock();
		}
	}
	else {
		updateFrame();
		is_frame_new_ = has_new_frame_;
		has_new_frame_ = false;
	}
}

template<typename Frame, typename Type>
void Stream<Frame, Type>::threadedFunction() {
	while(isThreadRunning()) {
		if(lock()) {
			updateFrame();
			unlock();
			sleep(1);
		}
	}
}
template<typename Frame, typename Type>
void Stream<Frame, Type>::updateFrame() {
	if(captureFrame()) {
		frame_.swap();
		if(is_front_allocated_) {
			freeFrame();
		}
		is_front_allocated_ = true;
		has_new_frame_ = true;
	}
}
template<typename Frame, typename Type> template<typename Output>
void Stream<Frame, Type>::decodeTo(Output &dst) {
	if(is_front_allocated_) {
		if(lock()) {
			frame_.front().decode(dst);
			unlock();
		}
	}
}
}}

using ofxNDIRecvVideo = ofxNDI::Recv::Stream<ofxNDI::VideoFrame>;
using ofxNDIRecvAudio = ofxNDI::Recv::Stream<ofxNDI::AudioFrame>;
using ofxNDIRecvMetadata = ofxNDI::Recv::Stream<ofxNDI::MetadataFrame>;
