/*
 * LumaQQ - Cross platform QQ client, special edition for Mac
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

#import <Cocoa/Cocoa.h>
#import "BasicInPacket.h"

///////////// format 1 ///////////
// header
// ---- encrypt start (session key) ------
// sub command, 1 byte
// user qq you wanna add, 4 bytes
// reply code, 1 byte
// length of reply message, 1 byte
// NOTE: only when reply code is not kQQReplyOK, you should check reply message
// reply message
// ---- encrypt end -----
// tail

@interface AuthorizeReplyPacket : BasicInPacket {
	UInt32 m_QQ;
	NSString* m_message;
}

// getter and setter
- (UInt32)QQ;
- (NSString*)message;

@end
