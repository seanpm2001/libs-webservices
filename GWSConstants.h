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

#ifndef	INCLUDED_GWSCONSTANTS_H
#define	INCLUDED_GWSCONSTANTS_H

#import	<Foundation/NSString.h>

#if     defined(__cplusplus)
extern "C" {
#endif

/** Key for a local error returned in a result dictionary.<br />
 * If an error occurred at the local end while producing the result
 * dictionary, the value for this key (and NSError, NSException, or NSString)
 * will describe the nature of the problem.
 */
NSString * const GWSErrorKey;

/** Key for a fault dictionary returned in a response dictionary.<br />
 * The value for this key is nil unless a wsdl <em>fault</em>
 * was decoded into the dictionary.
 */
NSString * const GWSFaultKey;

/** Key for the method name in a request dictionary.<br />
 * The value of this key is nil unless the dictionary was the result of
 * decoding a request, in which case it is the name of the method/operation
 * requested.
 */
NSString * const GWSMethodKey;

/** Key for an ordering array in a request or response dictionary.<br />
 * If present in a decoded object, the value of this key is an
 * NSMutableArray object containing the names of the parameters decoded.<br />
 * If present in a dictionary being encoded, this is an NSArray object
 * specifying the order in which the members of the dictionary are to be
 * encoded.
 */
NSString * const GWSOrderKey;

/** Key for a parameters dictionary in a request or response dictionary.<br />
 * If present, the value of this key is an NSMutableDictionary containing
 * the decoded parameters.
 */
NSString * const GWSParametersKey;


/** Key for the encoding style to be used for the SOAP body.
 */
NSString * const GWSSOAPBodyEncodingStyleKey;

/** SOAP body encoded in document style.  Setting this value for the
 * GWSSOAPBodyEncodingStyleKey in the parameters of a message being
 * encoded has the same effect as calling [GWSSOAPCoder-setOperationStyle:]
 * with an argument of GWSSOAPBodyEncodingStyleDocument.
 */
NSString * const GWSSOAPBodyEncodingStyleDocument;

/** SOAP body encoded in document style.  Setting this value for the
 * GWSSOAPBodyEncodingStyleKey in the parameters of a message being
 * encoded has the same effect as calling [GWSSOAPCoder-setOperationStyle:]
 * with an argument of GWSSOAPBodyEncodingStyleRPC.
 */
NSString * const GWSSOAPBodyEncodingStyleRPC;

/** SOAP body encoded in wrapped style.  Setting this value for the
 * GWSSOAPBodyEncodingStyleKey in the parameters of a message being
 * encoded has the same effect as calling [GWSSOAPCoder-setOperationStyle:]
 * with an argument of GWSSOAPBodyEncodingStyleWrapped.
 */
NSString * const GWSSOAPBodyEncodingStyleWrapped;

/** Key for the URI to be used as the default namespace for all elements
 * within the method being encoded.
 */
NSString * const GWSSOAPMethodNamespaceURIKey;

/** Key for a header element for a soap message.  The headers for
 * for the message may be provided by setting a value for this key
 * in the parameters dictionary.<br />
 * As a special case you may set an instance of [NSNull] rather than
 * an instance of [GWSElement] for this key, in which case the coder
 * will generate an empty header element which the coder's delegate
 * can then modify.
 */
NSString * const GWSSOAPMessageHeadersKey;

#if	defined(__cplusplus)
}
#endif

#endif

