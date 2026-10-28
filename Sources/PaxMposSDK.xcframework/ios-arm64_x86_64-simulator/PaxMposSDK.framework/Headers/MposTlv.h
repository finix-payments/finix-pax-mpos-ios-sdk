//
//  MposTlv.h
//  MposPlugin
//
//  Created by kevintu@paxsz.com on 14-6-27.
//  Copyright (c) 2014年 pax. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MposTlvItem.h"

/*!
 @abstract BER-TLV
 */
@interface MposTlv : NSObject

/*!
 @abstract get an shared instance
 @result the shared instance
 */
+ (id)sharedInstance;

/*!
 @abstract parse TLV itmes from data
 @param data [input] the data to parse
 @result an array of MposTlvItem objects, nil on error
 */
- (NSArray *)parseTlvItemsFromData:(const NSData *)data;
/*!
 @abstract serialze a TLV item into data
 @param item [input] a TLV item
 @result serialzed data of the TLV item
 */
- (NSData *)serializeForTlvItem:(const MposTlvItem *)item;
/*!
 @abstract serialze an array of TLV items into data
 @param items [input] an array of TLV items
 @result serialzed data of the TLV items
 */
- (NSData *)serializeForTlvItems:(const NSArray *)items;

/*!
 @abstract set the tag to string mapping, mainly for debuggng purpose
 @param map [input] the tag to string mapping. the type of key is NSNumber, the type of value is NSString
    for example
 NSDictionary * map = \@{
    [NSNumber numberWithInt:0x5F30]: \@"SERVICE_CODE",
    [NSNumber numberWithInt:0x81]: \@"AMT_AUTHORIZED",
 };
 @param encoding    the string encoding of the value in the map
 */
- (void)setDebugInfoWithTagToStringMapping:(NSDictionary *)map valueEncoding:(NSStringEncoding)encoding;

@end
