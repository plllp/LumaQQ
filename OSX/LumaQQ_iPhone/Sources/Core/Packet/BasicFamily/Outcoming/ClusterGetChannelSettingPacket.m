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

#import "ClusterGetChannelSettingPacket.h"


@implementation ClusterGetChannelSettingPacket

- (id)initWithQQUser:(QQUser*)user {
	self = [super initWithQQUser:user];
	if(self) {
		m_subCommand = kQQSubCommandClusterGetChannelSetting;
	}
	return self;
}

- (void)fillBody:(ByteBuffer*)buf {
	[super fillBody:buf];
	[buf writeUInt32:m_mask];
}

#pragma mark -
#pragma mark getter and setter

- (UInt32)mask {
	return m_mask;
}

- (void)setMask:(UInt32)mask {
	m_mask = mask;
}

@end
