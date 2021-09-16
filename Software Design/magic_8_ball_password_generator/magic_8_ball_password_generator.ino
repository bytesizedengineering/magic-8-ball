#include <Wire.h>
#include <ADXL345.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <Fonts/FreeSans9pt7b.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define SCREEN_ADDRESS 0x3D // run i2c address scanner to confirm
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define CHAR_H 7
#define CHAR_W 5
#define SHAKE_THRESHOLD 40.0

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//Adafruit_SSD1306 display(0);


String line1,line2,line3;
const int textSize = 1;
const int screenCenterWidth = SCREEN_WIDTH/2.0;
const int screenCenterHeight = SCREEN_HEIGHT/2.0;
const int cursor2 = screenCenterHeight - CHAR_H*textSize/2.0;
const int cursor1 = cursor2 - CHAR_H*textSize - 2 * textSize;
const int cursor3 = cursor2 + CHAR_H*textSize + 2 * textSize;
const int charOffset = CHAR_W * textSize/2.0;
sensors_event_t event, lastEvent;
long stopWatch;

void setup() {
  Serial.begin(9600);
  bool oledBegin = display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS); 
  if(!oledBegin) { 
    Serial.print(F("SSD1306 allocation failed: "));Serial.println(oledBegin);
    while(1);
  }
  else
    Serial.println("SSD1306 oled Display initialized");
    
  display.setTextColor(WHITE);
  //display.setTextSize(textSize);
  //display.setFont(&FreeSans9pt7b);
  //display.invertDisplay(true);
  display.clearDisplay();
  display.display();
  randomSeed(analogRead(0));
  
  // Initialise the accelerometer
  if(!accel.begin())
  {
    // There was a problem detecting the ADXL345 ... check your connections
    Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
    while(1);
  }
  else
    Serial.println("ADXL345 initialized");
    
  accel.setRange(ADXL345_RANGE_16_G);
  accel.getEvent(&event);  
}

void loop() {
  if(detectShake()){
    int randomNum = random(1,21);
    setMagic8BallDisplay(randomNum);
    //setPassword(randomNum);    
  }  
}

void setPassword(int reply){
  Serial.print(reply); Serial.print("\t");
  
  switch(reply){
    case 1:
      line1 = F("David subscribes to the stuff your tent into the bag strategy over nicely folding it.");
      line2 = F("");
      line3 = F("");
      break;    
    case 2:
      line1 = F("Lets all be unique together until we realise we are all the same.");
      line2 = F("");
      line3 = F("");
      break;    
    case 3:
      line1 = F("It took him a while to realize that everything he decided not to change, he was actually choosing.");
      line2 = F("");
      line3 = F("");
      break;    
    case 4:
      line1 = F("He found his art never progressed when he literally used his sweat and tears.");
      line2 = F("");
      line3 = F("");
      break;    
    case 5:
      line1 = F("You're unsure whether or not to trust him, but very thankful that you wore a turtle neck.");
      line2 = F("");
      line3 = F("");
      break;    
    case 6:
      line1 = F("At that moment he wasn't listening to music, he was living an experience.");
      line2 = F("");
      line3 = F("");
      break;
    case 7:
      line1 = F("The gloves protect my feet from excess work.");
      line2 = F("");
      line3 = F("");
      break;
    case 8:
      line1 = F("He had a wall full of masks so she could wear a different face every day.");
      line2 = F("");
      line3 = F("");
      break;
    case 9:
      line1 = F("Last Friday I saw 5 $potted striped blue worms shake h@nds with 34 legless lizards.");
      line2 = F("");
      line3 = F("");
      break;
    case 10:
      line1 = F("He strives to keep the best lawn in the neighborhood.");
      line2 = F("");
      line3 = F("");
      break;
    case 11:
      line1 = F("Charles ate the french fries knowing they would be his last meal.");
      line2 = F("");
      line3 = F("");
      break;
    case 12:
      line1 = F("If eating three-egg omelets causes weight-gain, budgie eggs are a good substitute.");
      line2 = F("");
      line3 = F("");
      break;
    case 13:
      line1 = F("He had a vague sense that trees gave birth to dinosaurs.");
      line2 = F("");
      line3 = F("");
      break;
    case 14:
      line1 = F("Jason lived his life by the motto, Anything worth doing is worth doing poorly.");
      line2 = F("");
      line3 = F("");
      break;
    case 15:
      line1 = F("The fog was so dense even a laser decided it wasn't worth the effort.");
      line2 = F("");
      line3 = F("");
      break;
    case 16:
      line1 = F("Two seats were vacant.");
      line2 = F("");
      line3 = F("");
      break;
    case 17:
      line1 = F("A glittering gem is not enough.");
      line2 = F("");
      line3 = F("");
      break;
    case 18:
      line1 = F("Everyone was curious about the large white blimp that appeared overnight.");
      line2 = F("");
      line3 = F("");
      break;
    case 19:      
      line1 = F("She can live her life however she wants as long as she listens to what I have to say.");
      line2 = F("");
      line3 = F("");
      break;
    case 20:      
      line1 = F("The efficiency we have at removing trash has made creating trash more acceptable.");
      line2 = F("");
      line3 = F("");
      break;      
  }
  Serial.print(line1); Serial.print(" "); Serial.print(line2); Serial.print(" "); Serial.println(line3);
  display.setTextSize(1);
  display.clearDisplay();
  display.setCursor(0,0); display.println(line1);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();     
}

void setMagic8BallDisplay(int reply){
  Serial.print(reply); Serial.print("\t");
  
  switch(reply){
    case 1:
      //As I seet it, yes
      line1 = F("As I");
      line2 = F("see it,");
      line3 = F("yes");
      break;    
    case 2:
      //Ask again later
      line1 = F("Ask");
      line2 = F("again");
      line3 = F("later");
      break;    
    case 3:
      //Better not tell you now
      line1 = F("Better");
      line2 = F("not tell");
      line3 = F("you now");
      break;    
    case 4:
      //Cannot predict now
      line1 = F("Cannot");
      line2 = F("predict");
      line3 = F("now");
      break;    
    case 5:
      //Focus and ask again
      line1 = F("Focus");
      line2 = F("and ask");
      line3 = F("again");
      break;    
    case 6:
      //Don’t count on it
      line1 = F("Don't");
      line2 = F("count");
      line3 = F("on it");
      break;
    case 7:
      //It is certain
      line1 = F("It");
      line2 = F("is");
      line3 = F("certain");
      break;
    case 8:
      //It is decidedly so
      line1 = F("It is");
      line2 = F("decidedly");
      line3 = F("so");
      break;
    case 9:
      //Most likely
      line1 = F("Most");
      line2 = F("likely");
      line3 = F("");
      break;
    case 10:
      //My reply is no
      line1 = F("My");
      line2 = F("reply");
      line3 = F("is no");
      break;
    case 11:
      //My sources say no
      line1 = F("My");
      line2 = F("sources");
      line3 = F("say no");
      break;
    case 12:
      //Outlook not so good
      line1 = F("Outlook");
      line2 = F("not so");
      line3 = F("good");
      break;
    case 13:
      //Outlook good
      line1 = F("Outlook");
      line2 = F("good");
      line3 = F("");
      break;
    case 14:
      //Reply hazy, try again
      line1 = F("Reply");
      line2 = F("hazy,");
      line3 = F("try again");
      break;
    case 15:
      //Signs point to yes
      line1 = F("Signs");
      line2 = F("point");
      line3 = F("to yes");
      break;
    case 16:
      //Very doubtful
      line1 = F("Very");
      line2 = F("doubtful");
      line3 = F("");
      break;
    case 17:
      //Without a doubt
      line1 = F("Without");
      line2 = F("a doubt");
      line3 = F("");
      break;
    case 18:
      //Yes
      line1 = F("");
      line2 = F("Yes");
      line3 = F("");
      break;
    case 19:
      //Yes – definitely
      line1 = F("Yes");
      line2 = F("–");
      line3 = F("surely");
      break;
    case 20:
      //You may rely on it
      line1 = F("You may");
      line2 = F("rely");
      line3 = F("on it");
      break;      
  }
  Serial.print(line1); Serial.print(" "); Serial.print(line2); Serial.print(" "); Serial.println(line3);
  display.setTextSize(2);
  display.clearDisplay();
  display.setCursor(centerText(line1),cursor1); display.println(line1); 
  display.setCursor(centerText(line2),cursor2); display.println(line2); 
  display.setCursor(centerText(line3),cursor3); display.println(line3);
  display.display();
  delay(5000);
  display.clearDisplay();
  display.display();     
}

int centerText(String subtext){
  //Serial.print(subtext); Serial.print("\t");
  //Serial.println(subtext.length()); //Serial.print("\t");
  int offset = screenCenterWidth - subtext.length() * charOffset;
  //Serial.println(offset);
  return offset;
}

bool detectShake(){ 
  accel.getEvent(&event);  
  // Display the results (acceleration is measured in m/s^2) 
  Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  ");Serial.println("m/s^2 ");
  if(abs(event.acceleration.x) > SHAKE_THRESHOLD || abs(event.acceleration.y) > SHAKE_THRESHOLD || abs(event.acceleration.z) > SHAKE_THRESHOLD)
    return 1;
  else
    return 0;
}
