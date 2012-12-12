//
//  ViewController.m
//  TouchUpPro
//
//  Created by kwadwo nyarko on 11/26/12.
//  Copyright (c) 2012 kwadwo nyarko. All rights reserved.
//

#import "ViewController.h"


@implementation ViewController

// used to represent which control has focus. 0 = head, 1 = feet, 2 = bed
int controlling = 0;



- (IBAction)changeControl{
    
    if(controlling==0){
        control.text = @"FEET";
        controlling = 1;
    }
    else if (controlling==1){
        control.text = @"BED";
        controlling = 2;
    }
    else{
        control.text=@"HEAD";
        controlling = 0;
    }
    
    
}

- (IBAction)smallUpControl{
    
    
    NSString *url;
    switch(controlling){
        case (0):{ // head up for 1 second
            url= @"http://192.168.2.10/?BED61/";
            break;
        }
        case (1):{ // bed up for 1 second
            url= @"http://192.168.2.10/?BED81/";
            break;
        }
        case(2):{ // feet up for 1 second
            url= @"http://192.168.2.10/?BED41/";
            break;
        }

    }
    
    NSURLRequest *request = [[NSURLRequest alloc] initWithURL:[NSURL URLWithString:url]];

    NSURLConnection *theConnection = [[NSURLConnection alloc] initWithRequest:request delegate:self];
   

}

- (IBAction)smallDownControl{
    
    
     NSString *url;
     switch(controlling){
        case (0):{ // head down for 1 second
            url= @"http://192.168.2.10/?BED71/";
            break;
        }
        case (1):{ // bed down for 1 second
            url= @"http://192.168.2.10/?BED91/";
            break;
        }
        case(2):{ // feet down for 1 second
            url= @"http://192.168.2.10/?BED51/";
            break;
        }
     
     }

   
    NSURLRequest *request = [[NSURLRequest alloc] initWithURL:[NSURL URLWithString:url]];

    NSURLConnection *theConnection = [[NSURLConnection alloc] initWithRequest:request delegate:self];
 

    
}

- (IBAction)bigUpControl{
   
    
     NSString *url;
     switch(controlling){
        case (0):{ // head up for 2 seconds
            url= @"http://192.168.2.10/?BED62/";
            break;
        }
        case (1):{ // bed up for 2 seconds
            url= @"http://192.168.2.10/?BED82/";
            break;
        }
        case(2):{ // feet up for 2 seconds
            url= @"http://192.168.2.10/?BED42/";
            break;
        }
     
     }
       NSURLRequest *request = [[NSURLRequest alloc] initWithURL:[NSURL URLWithString:url]];

    NSURLConnection *theConnection = [[NSURLConnection alloc] initWithRequest:request delegate:self];
   

    
}

- (IBAction)bigDownControl{
    
    
    
     NSString *url;
     switch(controlling){
        case (0):{ // head down for 2 seconds
            url= @"http://192.168.2.10/?BED72/";
            break;
        }
        case (1):{ // bed down for 2 seconds
            url= @"http://192.168.2.10/?BED92/";
            break;
        }
        case(2):{ // feet down for 2 seconds
            url= @"http://192.168.2.10/?BED52/";
            break;
        }
     
     }
        NSURLRequest *request = [[NSURLRequest alloc] initWithURL:[NSURL URLWithString:url]];

    NSURLConnection *theConnection = [[NSURLConnection alloc] initWithRequest:request delegate:self];
  

    
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
