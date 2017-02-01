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
#import "InPacket.h"

#define PROVINCE(index) L([NSString stringWithFormat:@"LQProvince.%u", index])
#define PROVINCECOUNT [L(@"LQProvinceCount") intValue]
#define CITY(province, city) L([NSString stringWithFormat:@"LQCity.%u.%u", province, city])
#define AGE(index) L([NSString stringWithFormat:@"LQAge.%u", index])
#define AGECOUNT [L(@"LQAgeCount") intValue]
#define GENDER(index) L([NSString stringWithFormat:@"LQGender.%u", index])
#define GENDERCOUNT [L(@"LQGenderCount") intValue]
#define CITYCOUNT(province) [L([NSString stringWithFormat:@"LQCityCount%u", province]) intValue]
#define LEVEL1COUNT [L(@"Level1.count") intValue]
#define LEVEL2COUNT(index) [L([NSString stringWithFormat:@"Level2.%u.count", index]) intValue]
#define LEVEL3COUNT(l1_index, l2_index) [L([NSString stringWithFormat:@"Level3.%u.%u.count", l1_index, l2_index]) intValue]
#define LEVEL1ID(index) [L([NSString stringWithFormat:@"Level1.%u.id", index]) intValue]
#define LEVEL2ID(l1_index, l2_index) [L([NSString stringWithFormat:@"Level2.%u.%u.id", l1_index, l2_index]) intValue]
#define LEVEL3ID(l1_index, l2_index, l3_index) [L([NSString stringWithFormat:@"Level3.%u.%u.%u.id", l1_index, l2_index, l3_index]) intValue]
#define LEVEL1VALUE(index) L([NSString stringWithFormat:@"Level1.%u.value", index])
#define LEVEL2VALUE(l1_index, l2_index) L([NSString stringWithFormat:@"Level2.%u.%u.value", l1_index, l2_index])
#define LEVEL3VALUE(l1_index, l2_index, l3_index) L([NSString stringWithFormat:@"Level3.%u.%u.%u.value", l1_index, l2_index, l3_index])
#define CATEGORYLEVEL(cId) [L([NSString stringWithFormat:@"category.%u.level", cId]) intValue]
#define CATEGORYLEVEL1INDEX(cId) [L([NSString stringWithFormat:@"category.%u.level1index", cId]) intValue]
#define CATEGORYLEVEL2INDEX(cId) [L([NSString stringWithFormat:@"category.%u.level2index", cId]) intValue]
#define CATEGORYLEVEL3INDEX(cId) [L([NSString stringWithFormat:@"category.%u.level3index", cId]) intValue]

NSString* L(NSString* key);
NSString* LT(NSString* key, NSString* table);

// method for packet message translate
NSString* SM(InPacket* inPacket, NSString* clusterName, UInt32 userQQ);