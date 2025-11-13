//
//  MposApdu.h
//  MposProto
//
//  Created by kevintu@paxsz.com on 14-6-27.
//  Copyright (c) 2014年 pax. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @abstract Mpos APDU
 */
@interface MposApdu : NSObject

// for req
/*!
 @abstract class, default to 0
 */
@property   Byte cla;
/*!
 @abstract ins, default to 0
 */
@property   Byte ins;
/*!
 @abstract p1, default to 0
 */
@property   Byte p1;
/*!
 @abstract p2, default to 0
 */
@property   Byte p2;
/*!
 @abstract length of command, default to 0
 */
@property   ushort lc;
/*!
 @abstract length of expected data, default to 0xFFFF
 */
@property   ushort le;
/*!
 @abstract data
 */
@property   (nonatomic)NSData *data;

// for debug
/*!
 @abstract human readable string for class, default to \@"";
 */
@property   (copy, nonatomic)NSString *claStr;
/*!
 @abstract human readable string for ins, default to \@"";
 */
@property   (copy, nonatomic)NSString *insStr;

/*!
 @abstract get the status code from the response apdu
 @param resp    [input] the response APDU
 @result the status code, 0xFFFF on error
 */
+ (ushort)statusFromResp:(MposApdu *)resp;

/*!
 @abstract get the data from the response apdu
 @param resp    [input] the response APDU
 @result the data
 */
+ (NSData *)dataFromResp:(MposApdu *)resp;

/*!
 @abstract init with class and ins
 @param cla class
 @param ins ins
 @result an MposApdu instance
 */
- (id)initWithCla:(Byte)cla ins:(Byte)ins;
/*!
 @abstract init with class/ins/p1/p2/data
 @param cla class
 @param ins ins
 @param p1  p1
 @param p2  p2
 @param data    [input] data
 @result an MposApdu instance
 */
- (id)initWithCla:(Byte)cla ins:(Byte)ins p1:(Byte)p1 p2:(Byte)p2 data:(NSData *)data;
/*!
 @abstract init with class/ins/p1/p2/data/lc
 @param cla class
 @param ins ins
 @param p1  p1
 @param p2  p2
 @param data    [input] data
 @param lc  length of command
 @result an MposApdu instance
 */
- (id)initWithCla:(Byte)cla ins:(Byte)ins p1:(Byte)p1 p2:(Byte)p2 data:(NSData *)data lc:(ushort)lc;
/*!
 @abstract init with class/ins/p1/p2/data/lc/le
 @param cla class
 @param ins ins
 @param p1  p1
 @param p2  p2
 @param data    [input] data
 @param lc  length of command
 @param le  length of expected data
 @result an MposApdu instance
 */
- (id)initWithCla:(Byte)cla ins:(Byte)ins p1:(Byte)p1 p2:(Byte)p2 data:(NSData *)data lc:(ushort)lc le:(ushort)le;

/*!
 @abstract reset all properties except for the cla/ins/claStr/insStr
 @discussion when the object is for re-use with cls/ins untouched, it is useful.
 */
- (void)resetAllButClaIns;

/*!
 @abstract reset all properties to default
 */
- (void)resetAll;

/*!
 @abstract make a request package
 @result the package data
 */
- (NSData *)packReq;

/*!
 @abstract get a human-readable description
 @result the human-readable description
 */
- (NSString *)description;

@end
