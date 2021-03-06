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

#import "ClusterMemberTreeDataSource.h"
#import "Constants.h"

@implementation ClusterMemberTreeDataSource

- (id)initWithCluster:(Cluster*)cluster {
	self = [super init];
	if(self) {
		m_cluster = [cluster retain];
		m_childParentMapping = [[NSMutableDictionary dictionary] retain];
	}
	return self;
}

- (void) dealloc {
	[m_cluster release];
	[m_childParentMapping release];
	[super dealloc];
}

#pragma mark -
#pragma mark tree selector data source

- (float)outlineView:(NSOutlineView *)outlineView heightOfRowByItem:(id)item {
	return kSizeSmall.height + 2;
}

- (int)outlineView:(NSOutlineView *)outlineView numberOfChildrenOfItem:(id)item {
	if(item == nil)
		return 1;
	else if([item isMemberOfClass:[Cluster class]])
		return [item memberCount];
	else
		return 0;
}

- (BOOL)outlineView:(NSOutlineView *)outlineView isItemExpandable:(id)item {
	if([item isMemberOfClass:[Cluster class]])
		return YES;
	else
		return NO;
}

- (id)outlineView:(NSOutlineView *)outlineView objectValueForTableColumn:(NSTableColumn *)tableColumn byItem:(id)item {
	return item;
}

- (id)outlineView:(NSOutlineView *)outlineView child:(int)index ofItem:(id)item {
	if(item == nil)
		return m_cluster;
	else if([item isMemberOfClass:[Cluster class]])
		return [item memberAtIndex:index];
	else
		return nil;
}

- (id)outlineView:(NSOutlineView*)outlineView parentOfItem:(id)item {
	return [m_childParentMapping objectForKey:item];
}

@end
