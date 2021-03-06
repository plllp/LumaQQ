/*
 * LumaQQ - Cross platform QQ client, special edition for iPhone
 *
 * Copyright (C) 2007 luma <stubma@163.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#import <Foundation/Foundation.h>
#import "ByteBuffer.h"
#import "FontStyle.h"

@interface NormalIM : NSObject <NSCoding> {
	UInt16 m_sessionId;
	UInt32 m_sendTime;
	UInt16 m_senderHead;
	UInt32 m_flag;
	UInt8 m_fragmentCount;
	UInt8 m_fragmentIndex;
	UInt16 m_messageId;
	char m_replyType;
	NSData* m_messageData; // don't use NSString here because it may be a fragment
	FontStyle* m_fontStyle;
	
	BOOL m_fromMobileQQ;
}

- (void)read:(ByteBuffer*)buf;
- (void)readEx:(ByteBuffer*)buf;

// helper
- (NSComparisonResult)compare:(NormalIM*)normalIM;

// getter and setter
- (BOOL)fromMobileQQ;
- (UInt16)sessionId;
- (UInt32)sendTime;
- (UInt16)senderHead;
- (UInt32)flag;
- (UInt8)fragmentCount;
- (UInt8)fragmentIndex;
- (UInt16)messageId;
- (char)replyType;
- (NSData*)messageData;
- (void)setMessageData:(NSData*)data;
- (FontStyle*)fontStyle;

@end
