//
//  VideoPreviewerH264Parser.h
//

#import <UIKit/UIKit.h>
#import "DJIStreamCommon.h"


/**
 a pure H264 parser
 */
@interface VideoPreviewerH264Parser : NSObject

/**
 *  If the stream is encoded by DJI's encoder. It is used to workaround an issue
 *  in DJI's encoder.
 */
@property (nonatomic, assign) BOOL usingDJIAircraftEncoder;


/**
 a rough frame rate
 * 需要从视频流中获取精确帧率
 */
@property(nonatomic, readonly) int frameRate;

/**
 frame counter since last reset
 */
@property (nonatomic, readonly) uint32_t frameCounter;


/**
 video size
 */
@property(nonatomic, readonly) int outputWidth;
@property(nonatomic, readonly) int outputHeight;


@property (nonatomic, assign) BOOL shouldVerifyVideoStream;


/**
 interval detail
 */
@property(nonatomic, readonly) NSTimeInterval frameInterval;

/**
 *  the frame in block should be released by user
 *  set a pointer to used length to check if the buffer contains multi-frame
 */
-(VideoFrameH264Raw*) parseVideo:(uint8_t*)buf
                          length:(int)length
                      usedLength:(int*)usedLength;

/**
 *  get the uuid for a frame
 *
 *  @return uuid of the next frame
 */
-(uint32_t) popNextFrameUUID;


/**
 reset parser buffer
 */
-(void) reset;


@end
