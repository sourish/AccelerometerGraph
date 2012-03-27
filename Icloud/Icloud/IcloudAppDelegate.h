//
//  IcloudAppDelegate.h
//  Icloud
//
//  Created by Pankaj Rawat on 14/03/12.
//  Copyright 2012 Paradigm Creatives. All rights reserved.
//

#import <UIKit/UIKit.h>

@class IcloudViewController;

@interface IcloudAppDelegate : NSObject <UIApplicationDelegate> {

}

@property (nonatomic, retain) IBOutlet UIWindow *window;

@property (nonatomic, retain) IBOutlet IcloudViewController *viewController;

@end
