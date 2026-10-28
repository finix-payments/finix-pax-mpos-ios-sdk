//
//  Utils.h
//  MposApi
//
//  Created by kevintu@paxsz.com on 6/3/13.
//  Copyright (c) 2013 paxhz. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonCryptor.h>

/*!
 @abstract Utilities
 */
@interface MposUtils : NSObject

/*!
 @abstract generate random bytes
 @param bytes   [input] a pointer to a buffer where random bytes are stored
 @param len length of random bytes to generate
 */
+ (void)randomBytes:(Byte  *)bytes len:(UInt32)len ;

/*!
 @abstract dump buffer
 @discussion for debuggin purpose
 @param buf [input] a pointer to the data to dump
 @param len the length of data
 @param header  [input] a string to display, typically a description of the data
 */
+ (void)hexDump:(const Byte  *)buf len:(UInt32)len header:(const Byte  *)header;
/*!
 @abstract transform bytes into hex string, seperated with space between bytes, no '\n' inserted
 @discussion for debuggin purpose
 @param buf [input] a pointer to the data to transform
 @param offset  offset of data
 @param bufLen  length of data to transform
 @result result string
 */
+ (NSString  *)byte2HexStrUnformatted:(const Byte  *)buf bufLen:(UInt32)bufLen offset:(UInt32)offset len:(UInt32)len;
/*!
 @abstract transform bytes into hex string, seperated with space between bytes, '\n' inserted for every 16 bytes
 @discussion for debuggin purpose
 @param buf [input] a pointer to the data to transform
 @param offset  offset of data
 @param bufLen  length of data to transform
 @result result string
 */
+ (NSString  *)byte2HexStrForLog:(const Byte  *)buf bufLen:(NSUInteger)bufLen offset:(NSUInteger)offset len:(NSUInteger)len;

/*!
 @abstract transform bytes into hex string
 @param buf [input] a pointer to the data to transform
 @param offset  offset of data
 @param bufLen  length of data to transform
 @result result string
 */
+ (NSString  *)byte2HexStr:(const Byte  *)buf bufLen:(NSUInteger)bufLen offset:(NSUInteger)offset len:(NSUInteger)len;

/*!
 @abstract transform data from BCD to ASCII
 @discussion    e.g. 0x12 --> "12",  0x3A --> "3A"
 @param bcd [input] data to transform
 @result data in ASCII format
 */
+ (NSData *)bcd2Asc:(const NSData *)bcd;
/*!
 @abstract transform data from ASCII to BCD
 @discussion    e.g. "12" --> 0x12,  "3A" --> 0x3A
 @param asc [input] data to transform
 @param rightAdjust     true for right-aligned, false otherwise
 @result data in BCD format
 */
+ (NSData *) asc2Bcd:(NSData *)asc rightAdjust:(BOOL)rightAdjust;

/*!
 @abstract  transform an integer value(4 bytes) into bytes
 @param x   integer
 @param byteArray   [output] a pointer to a buffer where the data is stored
 @param offset  the offset in the buffer where to put the data
 @param flag    true for big-endian mode, false otherwise
 */
+ (void)intValue:(NSUInteger)x to:(Byte *)byteArray offset:(NSUInteger)offset bigEndian:(BOOL)flag;
/*!
 @abstract  transform an short value(2 bytes) into bytes
 @param x   short value
 @param byteArray   [output] a pointer to a buffer where the data is stored
 @param offset  the offset in the buffer where to put the data
 @param flag    true for big-endian mode, false otherwise
 */
+ (void)shortValue:(UInt16)x to:(Byte *)byteArray offset:(NSUInteger)offset bigEndian:(BOOL)flag;
/*!
 @abstract  fetch an integer value(4 bytes) from a buffer
 @param byteArray   [input] a pointer to a buffer where the data is stored
 @param offset  the offset in the buffer where to fetch the data
 @param flag    true for big-endian mode, false otherwise
 @result the integer value fetched
 */
+ (UInt32)intValueFrom:(const Byte *)byteArray offset:(NSUInteger)offset bigEndian:(BOOL)flag;
/*!
 @abstract  fetch an short value(2 bytes) from a buffer
 @param byteArray   [input] a pointer to a buffer where the data is stored
 @param offset  the offset in the buffer where to fetch the data
 @param flag    true for big-endian mode, false otherwise
 @result the short value fetched
 */
+ (UInt16)shortValueFrom:(const Byte *)byteArray offset:(NSUInteger)offset bigEndian:(BOOL)flag;

/*!
 @abstract transform a dictionary into JSON string
 @param object  [input] a dictionary
 @result    the result string
 */
+ (NSString *)dictToJsonString:(id)object;
/*!
 @abstract  transform bytes into binary string. e.g. 0x1234 --> 00010010 00110100 --> 01001000 00101100
 @param data    [input] data to transform
 @result    the result string
 */
+ (NSString *)bytes2BinaryString:(const NSData *)data;
/*!
 @abstract reverse a string
 @param str [input] a string to reverse
 @result    the reversed string
 */
+ (NSString *)reverseString:(const NSString *)str;

/*!
 @abstract left-padding a string with specified character to build a string with specified length
 @discussion if the length of the original string is greater or equal to the destination length, then do nothing
 @param str [input] the string to left-padding
 @param c   a character to padding to the string
 @param len the total length
 @result the generated string
 */
+ (NSString *)strPaddingLeftToStr:(NSString *)str WithChar:(char)c totalLen:(NSInteger)len;

/*!
 @abstract transform a charset string into NSStringEncoding type
 @param charset [input] the charset string. e.g. GBK
 @result    encoding
 */
+ (NSStringEncoding)encodingFromCharset:(const NSString *)charset;
/*!
 @abstract url encoding, per RFC 3986
 @param input   [input] the string to process
 @param encoding    the encoding of the input string
 @result the encoded string
 */
+ (NSString *)urlEncode:(NSString *)input encoding:(NSStringEncoding)encoding;

/*!
 @abstract transform certificate in pem format to DER format
 @param data    [input] the certificate data in pem format
 @result the data in DER format
 */
+ (NSData *)pem2Der:(NSData *)data;

/*!
 @abstract get current document path
 @result document path
 */
+ (NSString *)documentPath;
/*!
 @abstract get a path in current document path with the specified file name
 @result file path
 */
+ (NSString *)documentPathForFile:(NSString *)file;

/*!
 @abstract  base64 encoding
 @param data    [input] data to process
 @result base64-encoded string
 */
+ (NSString*) base64Encode:(NSData *)data;
/*!
 @abstract base64 decoding
 @param string  [input] the base64-encoded string
 @result data after process
 */
+ (NSData*) base64Decode:(NSString *)string;

///*!
// @abstract md5 of specified data
// @param data    [input] data to process
// @result    md5 value of the data
// */
//+ (NSData *)md5OfData:(NSData *)data;
/*!
 @abstract lrc of specified data. xor of all bytes
 @param data    [input] data to process
 @param offset  offset of the data to process
 @param len length of data to process
 @result lrc value
 */
+ (Byte)lrcOfData:(const Byte *)data from:(UInt32)offset withLen:(NSUInteger)len;

/*!
 @abstract des/3des encryption/decryption, ECB, NO padding
 @param key [input] key, length MUST be 8, 16 or 24 bytes
 @param data [input] data, length MUST be multiple of 8
 @param operation  either encrypt or decrypt
 @result the result. nil if any error occurred
 */
+ (NSData *)desWithKey:(NSData *)key data:(NSData *)data operation:(CCOperation)operation;

@end
