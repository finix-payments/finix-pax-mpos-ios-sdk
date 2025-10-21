//
//  MposTlvItem.h
//  MposPlugin
//
//  Created by kevintu@paxsz.com on 14-6-27.
//  Copyright (c) 2014年 pax. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @abstract a BER-TLV item
 */
@interface MposTlvItem : NSObject

/*!
 @abstract tag
 */
@property NSData *tag;
/*!
 @abstract value
 */
@property NSData *value;

/*!
 @abstract init with the tag to string mapping, mainly for debuggng purpose
 @param map [input] the tag to string mapping. the type of key is NSNumber, the type of value is NSString
 for example
 NSDictionary * map = \@{
 [NSNumber numberWithInt:0x5F30]: \@"SERVICE_CODE",
 [NSNumber numberWithInt:0x81]: \@"AMT_AUTHORIZED",
 };
 @param encoding    the string encoding of the value in the map
 @result the TLV item object
 */
- (id)initWithTagToStringMapping:(NSDictionary *)map valueEncoding:(NSStringEncoding)encoding;

/*!
 @abstract set tag with specified data
 @param data    [input] the data to set
 @param offset  the offset of the data to set
 @result    the length of tag
 */
- (int)setTagWithData:(const Byte *)data offset:(NSInteger)offset;

/*!
 @abstract set tag with specified value
 @param tag    value of tag
 */
- (void)setTagWithValue:(NSInteger)tag;

/*!
 @abstract set value with specified byte
 @param byte    the byte to set
 */
- (void)setValueToByte:(Byte)byte;

/*!
 @abstract set value with specified data
 @param data    [input] data to set
 */
- (void)setValueToData:(NSData *)data;

/*!
 @abstract integer value of the tag (big-endian)
 @result intger value of the tag
 */
- (UInt32)tag2Int;

/*!
 @abstract a description of the tag, from the tag to string mapping, if not set previously, default to "UNKNOWN_TAG"
 @result a description of the tag
 */
- (NSString *)tag2Str;

/*!
 @abstract a description of the TLV item
 @result the description string
 */
- (NSString *)description;

@end
