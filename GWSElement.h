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

   $Date: 2007-09-24 14:19:12 +0100 (Mon, 24 Sep 2007) $ $Revision: 25500 $
   */ 

#ifndef	INCLUDED_GWSELEMENT_H
#define	INCLUDED_GWSELEMENT_H

#import <Foundation/NSObject.h>

#if     defined(__cplusplus)
extern "C" {
#endif

@class  NSDictionary;
@class  NSMutableArray;
@class  NSMutableDictionary;
@class  NSMutableString;
@class  NSString;

/** This little class encapsulates an XML element as part of a simple
 * tree of elements in a document.<br />
 * The [GWSCoder] class creates a tree of these elements
 * when it parses a document.<br />
 * This class aims to produce the most lightweight practical implementation
 * of a tree-structured representation of the subset of XML documents
 * required for web services, so that we have the ease of use advantages
 * of working with an entire document as a tree structure, while
 * minimising performance/efficiency overheads.<br />
 * You probably don't need to use this class directly yourself unless
 * you are writing a new GWSCoder subclass to handle some form of XML
 * serialisation of data (or if you want to bugfix/enhance the existing 
 * GWSCoder subclasses or GWSDocument decodiong/encooding of WSDL).
 */
@interface      GWSElement : NSObject <NSMutableCopying>
{
@private
  GWSElement            *_parent;       // not retained.
  NSString              *_name;
  NSString              *_namespace;
  NSString              *_qualified;
  NSMutableDictionary   *_attributes;
  NSMutableDictionary   *_namespaces;
  NSMutableArray        *_children;
  NSMutableString       *_content;
  NSString              *_literal;
}

/** Adds a string to the content of the receiver.  New content is appended
 * to any existing content.
 */
- (void) addContent: (NSString*)content;

/** Adds an element to the list of elements which are direct
 * children of the receiver.
 */
- (void) addChild: (GWSElement*)child;

/** Returns the attributes of the receiver, or nil if no attributes
 * dictionary exists.
 */
- (NSMutableDictionary*) attributes;

/** Returns the child of the receiver at the specified index in the list
 * of children. Raises an exception if the index does not lie in the list.
 */
- (GWSElement*) childAtIndex: (unsigned)index;

/** Returns an autoreleased array containing all the child elements of
 * the receiver.
 */
- (NSArray*) children;

/** Returns the content of the receiver.  This may be nil if no content
 * has been added to the receiver.
 */
- (NSString*) content;

/** returns the number of direct child elements.
 */
- (unsigned) countChildren;

/** Appends a string representation of the receiver's content
 * and/or child elements to the coder's mutable string.<br />
 * If the receiver is an empty element, this does nothing.<br />
 * If -setLiteralValue: has been called to set a string value for
 * this element, then this method does nothing.
 */
- (void) encodeContentWith: (GWSCoder*)coder;

/** Appends a string representation of the receiver's end tag
 * to the coder's mutable string.<br />
 * If -setLiteralValue: has been called to set a string value for
 * this element, then this method does nothing.
 */
- (void) encodeEndWith: (GWSCoder*)coder;

/** Appends a string representation of the receiver's start tag
 * (including attributes) to the coder's mutable string.<br />
 * If the receiver is an empty element and the collapse flag
 * is YES, this ends the start tag with ' /&gt;' markup.<br />
 * If -setLiteralValue: has been called to set a string value for
 * this element, then this method appends the entire literal value
 * to the coder's mutable string.<br />
 * The return value of this method is YES if either the element
 * has been collapsed into the start tage or a literal string has
 * been output to represent the whole element.  It returns NO if
 * the content and end tag of the element still need to be output.
 */
- (BOOL) encodeStartWith: (GWSCoder*)coder collapse: (BOOL)flag;

/** Appends a string representation of the receiver (and its child
 * elements) to the coder's mutable string.<br />
 * This method can be used to generate an XML document from a tree
 * of elements.  Typically it is called by a [GWSCoder] to output a
 * tree of elements that the coder has built up from the items it
 * is encoding.<br />
 * If -setLiteralValue: has been called to set a string value for
 * this element, then this method appends that literal value to
 * the document text in coder.  Otherwise, this method encodes a
 * representation of the receiver built from its name, namespace,
 * attributes, content and children.<br />
 * This method calls the other encoding methods to perform its work.
 */
- (void) encodeWith: (GWSCoder*)coder;

/** Returns the first child element or nil if there are no children.
 */
- (GWSElement*) firstChild;

/** Returns the position of this element within the list of siblings
 * which are direct children of its parent.<br />
 * Returns NSNotFound if the receiver has no parent.
 */
- (unsigned) index;

/* <init />
 * Initialises the receiver with the name, namespace URI, fully qualified
 * name, and attributes given.
 */
- (id) initWithName: (NSString*)name
          namespace: (NSString*)namespace
          qualified: (NSString*)qualified
         attributes: (NSDictionary*)attributes;

/** Perform a deep copy of the receiver.
 */
- (id) mutableCopyWithZone: (NSZone*)aZone;

/** Returns the name of the receiver (as set when it was initialised).
 */
- (NSString*) name;

/** Returns the namespace URI of the receiver (as set when it was initialised).
 */
- (NSString*) namespace;

/** Returns the namespaces mappings introduced by this element.
 */
- (NSMutableDictionary*) namespaces;

/** Returns the parent of this element.
 */
- (GWSElement*) parent;

/** Returns the fully qualified name of the receiver
 * (as set when it was initialised).
 */
- (NSString*) qualified;

/** Removes the receiver from its parent.  This may cause the receiver to
 * be deallocated.
 */
- (void) remove;

/** Sets the value for the specified key.  If attribute is nil then any
 * existing value for the key is removed.
 */
- (void) setAttribute: (NSString*)attribute forKey: (NSString*)key;

/** Sets the literal text to be used as the XML representing this element
 * and its content and children when encoding to an XML document.<br />
 * This overrides the default behavior which is to traverse the tree of
 * elements producing output to the XML document.<br />
 * Use with <em>extreme</em> care ... this method allows you to inject
 * illegal data into an XML document.
 */
- (void) setLiteralValue: (NSString*)xml;

/** Sets the namespace URI for the specified prefix key.
 */
- (void) setNamespace: (NSString*)uri forKey: (NSString*)key;

/**
 * Returns the next sibling of the receiver.  In conjunction with the
 * -firstChild method, this can be used to step through all the children
 * of an element.
 */
- (GWSElement*) sibling;

@end

#if	defined(__cplusplus)
}
#endif

#endif

