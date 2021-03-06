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
#import "BasicOutPacket.h"

/////////////// format 1 /////////////
// header
// -------- encrypt start (session key) ------
// sub command, 1 byte, 0x01, means download group name
// unknown 1 byte, 0x02
// unknown 4 bytes
// ----- encrypt end -------
// tail

////////////// format 2 ///////////
// header
// -------- encrypt start (session key) ------
// sub command, 1 byte, 0x02, means upload group name
// a. group index, 1 byte, start from 0 (reserved for "my friends"). these is no "my friends" group because it's a default group. 
// b. group name, 16 bytes, if group name is less than 16 bytes, fill zero
// (NOTE) if has more groups, repeat (a)(b)
// ----- encrypt end -------
// tail

@interface GroupDataOpPacket : BasicOutPacket {
	NSMutableArray* m_groupNames;
}

// getter and setter
- (NSArray*)groupNames;
- (void)setGroupNames:(NSArray*)groupNames;

@end
