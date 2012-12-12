/*
 * A simple sketch that uses WiServer to serve a web page
 */


#include <WiServer.h>
#include <string.h>

#define WIRELESS_MODE_INFRA	1
#define WIRELESS_MODE_ADHOC	2

#define FEET_DOWN 3 // yellow
#define BED_UP 4 // green
#define BED_DOWN 5 // purple
#define HEAD_UP 6 // white
#define HEAD_DOWN 7 // brown
#define FEET_UP 8 // orange

// common pins are blue/red

const unsigned int SMALL_CLICK = 1000; // 1 second per click
const unsigned int LARGE_CLICK = 2000; // 2 seconds per click

// Wireless configuration parameters ----------------------------------------
unsigned char local_ip[] = {192,168,2,10};	// IP address of WiShield 
unsigned char gateway_ip[] = {192,168,2,1};	// router or gateway IP address
unsigned char subnet_mask[] = {255,255,255,0};	// subnet mask for the local network
const prog_char ssid[] PROGMEM = {"belkin.7a8"};		// max 32 bytes

unsigned char security_type = 3;	// 0 - open; 1 - WEP; 2 - WPA; 3 - WPA2

// WPA/WPA2 passphrase
const prog_char security_passphrase[] PROGMEM = {"7a9a36cc"};	// max 64 characters

// WEP 128-bit keys
// sample HEX keys
prog_uchar wep_keys[] PROGMEM = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d,	// Key 0
				  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	// Key 1
				  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	// Key 2
				  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00	// Key 3
				};

// setup the wireless mode
// infrastructure - connect to AP
// adhoc - connect to another WiFi device
unsigned char wireless_mode = WIRELESS_MODE_INFRA;

unsigned char ssid_len;
unsigned char security_passphrase_len;
// End of wireless configuration parameters ----------------------------------------

boolean states[6]; //holds led states
char stateCounter; //used as a temporary variable
char tmpStrCat[64]; //used in processing the web page
char stateBuff[4]; //used in text processing around boolToString()
char numAsCharBuff[2];
char ledChange;
int duration;
boolean started;

void boolToString (boolean test, char returnBuffer[4])
{
  returnBuffer[0] = '\0';
  if (test)
  {
    strcat(returnBuffer, "On");
  }
  else
  {
    strcat(returnBuffer, "Off");
  }
}

// This is our page serving function that generates web pages
boolean sendPage(char* URL) {
  
  // should read ?BED and then integers 4 - 9 that correspond to pins and then 1 or 2 that corresponds to duration
  
  if (URL[1] == '?' && URL[2] == 'B' && URL[3] == 'E' && URL[4] == 'D') //url has a leading /
  {
    if (URL[6] == '1'){
      duration = SMALL_CLICK;
      Serial.println(duration);
    }
    else if (URL[6] == '2')
    {
      duration = LARGE_CLICK;
      Serial.println(duration);
    }
    
    if (URL[5] == '4'){
      digitalWrite(4, HIGH);
      delay(duration);
      digitalWrite(4, LOW);
      Serial.println(4);
    }    
    else if (URL[5] == '5'){
      digitalWrite(5, HIGH);
      delay(duration);
      digitalWrite(5, LOW);
      Serial.println(5);
    }   
    else if (URL[5] == '6'){
      digitalWrite(6, HIGH);
      delay(duration);
      digitalWrite(6, LOW);
      Serial.println(6);
    }    
    else if (URL[5] == '7'){
      digitalWrite(7, HIGH);
      delay(duration);
      digitalWrite(7, LOW);
      Serial.println(7);
    }    
    else if (URL[5] == '8'){
      digitalWrite(8, HIGH);
      delay(duration);
      digitalWrite(8, LOW);
      Serial.println(8);
    }
    else if (URL[5] == '9'){
      digitalWrite(3, HIGH);
      delay(duration);
      digitalWrite(3, LOW);
      Serial.println(3);
    }
    
    WiServer.print("<HTML><HEAD><meta http-equiv='REFRESH' content='0;url=/'></HEAD></HTML>");
    return true;
  }
  
  //keeping this as a backup
  if (strcmp(URL, "/") == false) //why is this not true?
   {
      WiServer.print("<html><head><title>TouchUpPro</title></head><body><center>Welcome to TouchUpPro!</center></body></html>");
      return true;
   }
}

void setup() {
  // Initialize WiServer and have it use the sendMyPage function to serve pages
  pinMode(BED_UP, OUTPUT);
  pinMode(BED_DOWN, OUTPUT);
  pinMode(HEAD_UP, OUTPUT);
  pinMode(HEAD_DOWN, OUTPUT);
  pinMode(FEET_UP, OUTPUT);
  pinMode(FEET_DOWN, OUTPUT);
  
  //pinMode(TEST, OUTPUT); // for testing the relays

  Serial.begin(9600);
  WiServer.init(sendPage);
  
  started = true;
}

void loop(){ 
  //digitalWrite(TEST, HIGH); 
  //if (started){
  //  digitalWrite(2, HIGH); //for testing the relays
  //  started = false;
  //}
  
  // Run WiServer
  WiServer.server_task();

  delay(50); //change this time to accomodate for lag
}
