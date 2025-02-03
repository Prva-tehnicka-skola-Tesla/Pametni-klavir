#include <Adafruit_ILI9341.h>
#include <Adafruit_GFX.h>
#include <XPT2046_Touchscreen.h>
#include <SPI.h>
#define TFT_CS 5
#define TFT_DC 21
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
#define TS_CS 4
XPT2046_Touchscreen ts(TS_CS);
int PinZvucnik = 32;
int PinTipkalo = 39;
int pritisnut;
int min_x = 370;
int min_y = 210;
int max_x = 3900;
int max_y = 3800;
int x_piksel, y_piksel;
uint16_t boja;
void setup() {
  ledcSetup(0, 10000, 12);
ledcAttachPin(PinZvucnik, 0);
pinMode(PinTipkalo, INPUT_PULLUP);

tft.begin();
tft.fillScreen(ILI9341_BLUE);
tft.setRotation(3);
tft.fillRect(297, 2, 10, 2, ILI9341_WHITE); //BIJELI DIO TESLA ZNAKA
tft.fillRect(297, 4, 5, 1, ILI9341_WHITE);
tft.fillRect(297, 5, 3, 1, ILI9341_WHITE);
tft.fillRect(297, 6, 2, 1, ILI9341_WHITE);
tft.fillRect(297, 7, 1, 1, ILI9341_WHITE);
tft.fillRect(303, 2, 4, 20, ILI9341_WHITE);
tft.fillRect(300, 20, 3, 2, ILI9341_WHITE);
tft.fillRect(302, 19, 1, 1, ILI9341_WHITE);
tft.fillRect(307, 2, 4, 20, ILI9341_BLACK); //CRNI DIO TESLA ZNAKA
tft.fillRect(307, 2, 10, 2, ILI9341_BLACK);
tft.fillRect(313, 4, 5, 1, ILI9341_BLACK);
tft.fillRect(314, 5, 3, 1, ILI9341_BLACK);
tft.fillRect(315, 6, 2, 1, ILI9341_BLACK);
tft.fillRect(316, 7, 1, 1, ILI9341_BLACK);
tft.fillRect(311, 20, 3, 2, ILI9341_BLACK);
tft.fillRect(312, 19, 1, 1, ILI9341_BLACK);
tft.fillRect(0, 120, 26, 70, ILI9341_WHITE);        // C4 NOTA
tft.fillRect(0, 190, 38, 50, ILI9341_WHITE);        
tft.fillRect(53, 120, 13, 70, ILI9341_WHITE);       // D4 NOTA
tft.fillRect(40, 190, 38, 50, ILI9341_WHITE);
tft.fillRect(93, 120, 25, 70, ILI9341_WHITE);       // E4 NOTA
tft.fillRect(80, 190, 38, 50, ILI9341_WHITE);
tft.fillRect(120, 120, 26, 70, ILI9341_WHITE);      // F4 NOTA
tft.fillRect(120, 190, 38, 50, ILI9341_WHITE);
tft.fillRect(173, 120, 13, 70, ILI9341_WHITE);      // G4 NOTA
tft.fillRect(160, 190, 38, 50, ILI9341_WHITE);
tft.fillRect(213, 120, 13, 70, ILI9341_WHITE);      // A4 NOTA
tft.fillRect(200, 190, 38, 50, ILI9341_WHITE);
tft.fillRect(253, 120, 25, 70, ILI9341_WHITE);     // H4 NOTA
tft.fillRect(240, 190, 38, 50, ILI9341_WHITE);
tft.fillRect(280, 120, 38, 120, ILI9341_WHITE);     // C5 NOTA
tft.fillRect(27, 120, 25, 69, ILI9341_BLACK);          // CIS4 NOTA
tft.fillRect(67, 120, 25, 69, ILI9341_BLACK);          // DIS4 NOTA
tft.fillRect(147, 120, 25, 69, ILI9341_BLACK);         // FIS4 NOTA
tft.fillRect(187, 120, 25, 69, ILI9341_BLACK);         // GIS4 NOTA
tft.fillRect(227, 120, 25, 69, ILI9341_BLACK);         // AIS4 NOTA
tft.setRotation(3);
tft.setTextColor(ILI9341_BLACK); 
tft.setCursor(60,40);
tft.setTextSize(2);
tft.print("Sviranje klavira");
ts.begin();
ts.setRotation(1);
}
void loop() {
pritisnut = ts.touched();

if (pritisnut) {
TS_Point p = ts.getPoint();
x_piksel = map(p.x, min_x, max_x, 0, 319);
y_piksel = map(p.y, min_y, max_y, 0, 239);

if (x_piksel<40 && y_piksel>190) ledcWriteNote(0, NOTE_C, 4);     // C4 BIJELA TIPKA

if (x_piksel>27 && x_piksel<52 && y_piksel>120 && y_piksel<190)        // CIS4 CRNA TIPKA
ledcWriteNote(0, NOTE_Cs, 4);
     
if (x_piksel>40 && x_piksel<80 && y_piksel>190)      // D4 BIJELA TIPKA
ledcWriteNote(0, NOTE_D, 4);
  
if (x_piksel>67 && x_piksel<92)        // DIS4 CRNA TIPKA
if (y_piksel>120 && y_piksel<190) 
ledcWriteNote(0, NOTE_Eb, 4);
     
if (x_piksel>80 && x_piksel<120 && y_piksel>190)      // E4 BIJELA TIPKA
ledcWriteNote(0, NOTE_E, 4);
   
if (x_piksel>120 && x_piksel<160 && y_piksel>190)       // F4 BIJELA TIPKA
ledcWriteNote(0, NOTE_F, 4);
     
if (x_piksel>147 && x_piksel<172)        // FIS4 CRNA TIPKA
if (y_piksel>120 && y_piksel<190) 
ledcWriteNote(0, NOTE_Fs, 4);
    
if (x_piksel>160 && x_piksel<200 && y_piksel>190)        // G4 BIJELA TIPKA
ledcWriteNote(0, NOTE_G, 4);
   
if (x_piksel>187 && x_piksel<212)       // GIS4 CRNA TIPKA
if (y_piksel>120 && y_piksel<190)
ledcWriteNote(0, NOTE_Gs, 4);
    
if (x_piksel>200 && x_piksel<240 && y_piksel>190)        // A4 BIJELA TIPKA
ledcWriteNote(0, NOTE_A, 4);
    
if (x_piksel>227 && x_piksel<252)       // AIS4 CRNA TIPKA
if (y_piksel>120 && y_piksel<190)
ledcWriteNote(0, NOTE_Bb, 4);
 
if (x_piksel>240 && x_piksel<280 && y_piksel>190)        // H4 BIJELA TIPKA
ledcWriteNote(0, NOTE_B, 4);
      
if (x_piksel>280 && y_piksel>120)        //  C5 BIJELA TIPKA
ledcWriteNote(0, NOTE_C, 5);
  
}

else {
  ledcWriteTone(0, 0);
  
  
}
delay(25);
}
