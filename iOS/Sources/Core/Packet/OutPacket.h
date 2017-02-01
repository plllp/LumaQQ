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
#import "Packet.h"

@interface OutPacket : Packet {
	int m_sendCount;
	BOOL m_needAck;
	int m_repeatTimeIfNoAck;
	NSDate* m_sentDate;
}

- (void)increaseSendCount;

// getter and setter
- (int)sendCount;
- (BOOL)needAck;
- (void)setNeedAck:(BOOL)needAck;
- (NSDate*)sentDate;
- (void)setSentDate:(NSDate*)date;
- (int)repeatTimeIfNoAck;
- (void)setRepeatTimeIfNoAck:(int)time;

@end
