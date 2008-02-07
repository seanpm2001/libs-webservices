/** 
   Copyright (C) 2008 Free Software Foundation, Inc.
   
   Written by:  Richard Frith-Macdonald <rfm@gnu.org>
   Date:	January 2008
   
   This file is part of the WebServices Library.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 3 of the License, or (at your option) any later version.
   
   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.
   
   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111 USA.

   $Date: 2007-09-14 13:54:55 +0100 (Fri, 14 Sep 2007) $ $Revision: 25485 $
   */ 

#ifndef	INCLUDED_GWSBINDING_H
#define	INCLUDED_GWSBINDING_H

#import <Foundation/NSObject.h>

#if     defined(__cplusplus)
extern "C" {
#endif

@class  NSString;
@class  GWSDocument;
@class  GWSElement;
@class  GWSPortType;

/** Encapsulates a WSDL binding.
 */
@interface	GWSBinding : NSObject
{
@private
  NSString      *_name;
  NSString      *_type;
  GWSDocument   *_document;
}
/** Returns the name of the receiver.
 */
- (NSString*) name;

/** Sets the type of the binding.  This should be the name of an
 * existing [GWSPortType] instance owned by the same [GWSDocument]
 * that owns the receiver, though this methods permits any value
 * to be set (see -type).
 */
- (void) setTypeName: (NSString*)type;

/** Return a tree representation of the receiver for output as part of
 * a WSDL document.
 */
- (GWSElement*) tree;

/** Returns the port type of the receiver.
 * If no type has been set or if the value previously set using the
 * -setTypeName: method is not the name of a known [GWSPortType] instance,
 *  this method returns nil.
 */
- (GWSPortType*) type;
@end

#if	defined(__cplusplus)
}
#endif

#endif

