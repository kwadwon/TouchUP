//
//  ViewController.h
//  TouchUpPro
//
//  Created by kwadwo nyarko on 11/26/12.
//  Copyright (c) 2012 kwadwo nyarko. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

@interface ViewController : UIViewController {

    // label to let user know which control has focus
    IBOutlet UILabel *control;
    

}

- (IBAction)smallUpControl;

- (IBAction)smallDownControl;

- (IBAction)bigUpControl;

- (IBAction)bigDownControl;

- (IBAction)changeControl;


@end
