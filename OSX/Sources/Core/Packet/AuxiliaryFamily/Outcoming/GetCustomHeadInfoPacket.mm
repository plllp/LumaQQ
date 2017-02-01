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

#import "GetCustomHeadInfoPacket.h"


@implementation GetCustomHeadInfoPacket

- (id)initWithQQUser:(QQUser*)user {
	self = [super initWithQQUser:user];
	if(self) {
		m_command = kQQCommandGetCustomHeadInfo;
	}
	return self;
}

- (void) dealloc {
	[m_friendQQs release];
	[super dealloc];
}

- (void)fillBody:(ByteBuffer*)buf {
	[buf writeUInt32:0];
	[buf writeUInt32:0];
	
	int pos = [buf position];
	[buf skip:2];
	[buf writeUInt16:0x1];
	
	[buf writeUInt16:[m_friendQQs count]];
	NSEnumerator* e = [m_friendQQs objectEnumerator];
	while(NSNumber* qq = [e nextObject]) {
		[buf writeUInt32:[qq unsignedIntValue]];
	}
	
	[buf writeUInt16:([buf position] - pos - 2) position:pos];
}

- (void)setFriends:(NSArray*)friends {
	[friends retain];
	[m_friendQQs release];
	m_friendQQs = friends;
}

@end
