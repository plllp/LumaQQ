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

#import "Group.h"
#import "QQConstants.h"

// encoding key
#define _kKeyGroupName @"GroupName"
#define _kKeyGroupFlag @"GroupFlag"
#define _kKeyUserArray @"Users"
#define _kKeyClusterArray @"Clusters"
#define _kKeyExpanded @"Expanded"

@implementation Group

- (id) init {
	return [self initWithFlag:(kGroupUser | kGroupFriendly)];
}

- (id)initWithFlag:(int)flag {
	self = [super init];
	if (self != nil) {
		m_flag = flag;
		m_users = [[NSMutableArray array] retain];
		m_clusters = [[NSMutableArray array] retain];
		m_expanded = NO;
	}
	return self;
}

- (id)initWithFlag:(int)flag name:(NSString*)name {
	self = [super init];
	if (self != nil) {
		m_flag = flag;
		m_users = [[NSMutableArray array] retain];
		m_clusters = [[NSMutableArray array] retain];
		[self setName:name];
		m_expanded = NO;
	}
	return self;
}

- (id)initWithGroup:(Group*)group {
	self = [super init];
	if(self) {
		m_flag = [group flag];
		[self setUsers:[group users]];
		[self setClusters:[group clusters]];
		[self setName:[group name]];
		m_expanded = NO;
	}
	return self;
}

- (void) dealloc {
	[m_name release];
	[m_users release];
	[m_clusters release];
	[super dealloc];
}

- (id)copyWithZone:(NSZone *)zone {
	return [self retain];
}

#pragma mark -
#pragma mark NSCoding protocol

- (void)encodeWithCoder:(NSCoder *)encoder {
	[encoder encodeBool:m_expanded forKey:_kKeyExpanded];
	[encoder encodeObject:m_name forKey:_kKeyGroupName];
	[encoder encodeInt:m_flag forKey:_kKeyGroupFlag];
	if([self isUser])
		[encoder encodeObject:m_users forKey:_kKeyUserArray];
	else
		[encoder encodeObject:m_clusters forKey:_kKeyClusterArray];
}

- (id)initWithCoder:(NSCoder *)decoder {
	m_expanded = [decoder decodeBoolForKey:_kKeyExpanded];
	m_name = [[decoder decodeObjectForKey:_kKeyGroupName] retain];
	m_flag = [decoder decodeIntForKey:_kKeyGroupFlag];
	if([self isUser])
		m_users = [[decoder decodeObjectForKey:_kKeyUserArray] retain];
	else
		m_clusters = [[decoder decodeObjectForKey:_kKeyClusterArray] retain];
	if(m_users == nil)
		m_users = [[NSMutableArray array] retain];
	if(m_clusters == nil)
		m_clusters = [[NSMutableArray array] retain];
	return self;
}

#pragma mark -
#pragma mark sort

- (void)sort {
	if([self isUser])
		[m_users sortUsingSelector:@selector(compare:)];
	else
		[m_clusters sortUsingSelector:@selector(compare:)];
}

#pragma mark -
#pragma mark helper

- (BOOL)isUser {
	return (m_flag & kGroupUser) != 0;
}

- (BOOL)isCluster {
	return (m_flag & kGroupCluster) != 0;
}

- (BOOL)isFriendly {
	return (m_flag & kGroupFriendly) != 0;
}

- (BOOL)isStranger {
	return ![self isFriendly] && ![self isBlacklist];
}

- (BOOL)isBlacklist {
	return (m_flag & kGroupBlacklist) != 0;
}

- (void)clearFlag {
	m_flag = 0;
}

- (void)setUser {
	m_flag |= kGroupUser;
}

- (void)setCluster {
	m_flag |= kGroupCluster;
}

- (void)setFriendly {
	m_flag |= kGroupFriendly;
}

- (void)setBlacklist {
	m_flag |= kGroupBlacklist;
}

- (BOOL)addUser:(User*)user {
	// return YES if user is added, or NO if user does exist
	BOOL exist = [m_users containsObject:user];
	if(!exist)
		[m_users addObject:user];
	return !exist;
}

- (void)removeUser:(User*)user {
	[m_users removeObject:user];
}

- (void)removeCluster:(Cluster*)cluster {
	[m_clusters removeObject:cluster];
}

- (BOOL)addCluster:(Cluster*)cluster {
	// return YES if cluster is added, or NO if cluster does exist
	BOOL exist = [m_clusters containsObject:cluster];
	if(!exist)
		[m_clusters addObject:cluster];
	return !exist;
}

- (void)clearUsers {
	[m_users removeAllObjects];
}

#pragma mark -
#pragma mark getter and setter

- (NSString*)name {
	return m_name;
}

- (void)setName:(NSString*)name {
	[name retain];
	[m_name release];
	m_name = name;
}

- (NSEnumerator*)userEnumerator {
	if(m_users)
		return [m_users objectEnumerator];
	else
		return nil;
}

- (NSEnumerator*)clusterEnumerator {
	if(m_clusters)
		return [m_clusters objectEnumerator];
	else
		return nil;
}

- (int)userCount {
	return [m_users count];
}

- (int)onlineUserCount {
	int count = 0;
	NSEnumerator* e = [m_users objectEnumerator];
	User* u = nil;
	while(u = [e nextObject]) {
		if([u status] != kQQStatusOffline)
			count++;
	}
	return count;
}

- (int)clusterCount {
	return [m_clusters count];
}

- (User*)user:(int)index {
	return [m_users objectAtIndex:index];
}

- (Cluster*)cluster:(int)index {
	return [m_clusters objectAtIndex:index];
}

- (int)flag {
	return m_flag;
}

- (void)setUsers:(NSMutableArray*)users {
	[m_users addObjectsFromArray:users];
}

- (void)setClusters:(NSMutableArray*)clusters {
	[m_clusters addObjectsFromArray:clusters];
}

- (NSMutableArray*)users {
	return m_users;
}

- (NSMutableArray*)clusters {
	return m_clusters;
}

- (BOOL)expanded {
	return m_expanded;
}

- (void)setExpanded:(BOOL)flag {
	m_expanded = flag;
}

@end
