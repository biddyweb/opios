/*
 
 Copyright (c) 2012, SMB Phone Inc.
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 The views and conclusions contained in the software and documentation are those
 of the authors and should not be interpreted as representing official policies,
 either expressed or implied, of the FreeBSD Project.
 
 */

#import <Foundation/Foundation.h>
#import <OpenpeerSDK/HOPProtocols.h>

@class Contact;

@interface ContactsManager : NSObject<UIWebViewDelegate,HOPProvisioningAccountIdentityLookupQueryDelegate,HOPProvisioningAccountPeerFileLookupQueryDelegate>

@property (nonatomic, strong) NSMutableArray *contactArray;
@property (nonatomic, strong) NSMutableDictionary *contactsDictionaryByProvider; //This is dictionary of dictionaries. Each provider has its own dictionary with contacts whose keys are contact provider id
@property (nonatomic, strong) NSMutableDictionary *contactsDictionaryByUserId;
@property (nonatomic, strong) UIWebView *linkedinContactsWebView;

+ (id) sharedContactsManager;

- (void) loadContacts;

- (void)contactsLookupQuery:(NSArray *)contacts;
- (void)peerFileLookupQuery:(NSArray *)contacts;

- (Contact*) getContactForIdentities:(NSArray*) identities;
- (Contact*) getContactForUserId:(NSString*) userId;

- (void) checkAvailability;
- (void) onCheckAvailabilityResponseReceivedForContact:(Contact*) contact withListOfUserIds:(NSString*) userIds;
@end
