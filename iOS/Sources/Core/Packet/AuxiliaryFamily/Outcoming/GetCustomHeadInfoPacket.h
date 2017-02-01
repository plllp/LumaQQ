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
#import "AuxiliaryOutPacket.h"

///// format 1 //////////
// header
// unknown 8 bytes
// length of following data, 2 bytes, exclusive
// unknown 2 bytes, most of time it is 0x0001
// number of friends, 2 bytes
// NOTE: max friend number is 0x14 in QQ
// a. friend qq, 4 bytes
// NOTE: repeat (a) if has more friends

@interface GetCustomHeadInfoPacket : AuxiliaryOutPacket {
	NSArray* m_friendQQs;
}

- (void)setFriends:(NSArray*)friends;

@end
