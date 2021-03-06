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

//////// format 1 /////////
// header
// ---- encrypt start (session key) -----
// sub command, 1 byte, 0x01, means get auth info
// sub sub command, 2 bytes
// reply code, 1 byte
// (NOTE) when reply code is kQQReplyOK, latter is auth info, if 0x01 (means need verify code), it's a url
//			from which you can get the puzzle image
// length of data, 2 bytes
// data
// ---- encrypt end ----
// tail

//////// format 1 /////////
// header
// ---- encrypt start (session key) -----
// sub command, 1 byte, 0x02, means get auth info by verify code
// sub sub command, 2 bytes
// reply code, 1 byte
// (NOTE) if reply is not kQQReplyOK, body ends here
// length of auth info, 2 bytes
// auth info
// ---- encrypt end ----
// tail

@interface AuthInfoOpReplyPacket : BasicInPacket {
	UInt16 m_subSubCommand;
	NSData* m_authInfo;
	NSString* m_url;
}

// getter and setter
- (UInt16)subSubCommand;
- (NSData*)authInfo;
- (NSString*)url;

@end
