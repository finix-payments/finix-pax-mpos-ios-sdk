//
//  MposRingBuffer.h
//  BT4Central
//
//  Created by kevintu@paxsz.com on 6/23/14.
//  Copyright (c) 2014 pax. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
  @abstract Mpos Ring Buffer utility
 */
@interface MposRingBuffer : NSObject

/*!
 @abstract capacity of the ring buffer
 */
@property (readonly) int capacity;
/*!
 @abstract data storage
 */
@property (readonly) NSMutableData *data;              //data storage
/*!
 @abstract read pointer(0~capacity-1)
 */
@property (readonly) int rp;                           //read pointer
/*!
 @abstract write pointer(0~capacity-1)
 */
@property (readonly) int wp;                           //write pointer

/*!
 @abstract init with capacity
 @param len     capacity, in byte
 */
- (id)initWithCapacity:(int)len;
/*!
 @abstract read expected length of data from ring buffer to destination
 @param expLen  exepcted length of data to read
 @param buffer  [output] the destination buffer
 @result    the exact length of data read
 */
- (int)readWithExpLen:(int) expLen outBuffer:(char *)buffer;
/*!
 @abstract write data into the ring buffer
 @param data    [input] data to write
 @result    the exact length of data wrote
 */
- (int)write:(const NSData *)data;
/*!
 @abstract get data length
 @result the data length
 */
- (int)dataLen;
/*!
 @abstract reset ring buffer(clearing storage, reset read/write pointer to 0)
 */
- (void)reset;

@end
