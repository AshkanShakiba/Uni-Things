#include <MD_MAX72xx.h>

#define BUF_SIZE 20
#define MAX_DEVICES 6
#define CHAR_SIZE 6
#define MAXCHARS_ONSCREEN 6

#define CLK_PIN   13  // or SCK
#define DATA_PIN  11  // or MOSI
#define CS_PIN    10  // or SS

uint8_t alph[37][5] = 
{  {0,0,0,0,0}              // ETC
  ,{126, 9, 9, 9, 126}      // A
  ,{127, 73, 73, 73, 54}    // B
  ,{62, 65, 65, 65, 65}     // C
  ,{127, 65, 65, 65, 62}    // D
  ,{ 127, 73, 73, 73, 65}   // E
  ,{127, 9, 9, 9, 1}        // F
  ,{62, 65, 65, 73, 121}    // G
  ,{127, 8, 8, 8, 127}      // H
  ,{0, 65, 127, 65, 0}      // I 
  ,{48, 65, 65, 65, 63}     // J
  ,{127, 8, 20, 34, 65}     // K
  ,{127, 64, 64, 64, 64}    // L
  ,{127, 2, 12, 2, 127}     // M
  ,{127, 4, 8, 16, 127}     // N
  ,{62, 65, 65, 65, 62}     // O
  ,{127, 9, 9, 9, 6}        // P
  ,{62, 65, 65, 97, 126}    // Q
  ,{127, 9, 25, 41, 70}     // R
  ,{70, 73, 73, 73, 49}     // S
  ,{1, 1, 127, 1, 1}        // T
  ,{63, 64, 64, 64, 63}     // U
  ,{31, 32, 64, 32, 31}     // V
  ,{63, 64, 56, 64, 63}     // W
  ,{99, 20, 8, 20, 99}      // X
  ,{3, 4, 120, 4, 3}        // Y
  ,{97, 81, 73, 69, 67}     // Z
  ,{62, 81, 73, 69, 62,}    // 0
  ,{0, 4, 2, 127, 0}        // 1
  ,{113, 73, 73, 73, 70}    // 2
  ,{65, 73, 73, 73, 54}     // 3
  ,{15, 8, 8, 8, 127}       // 4
  ,{79, 73, 73, 73, 49}     // 5
  ,{62, 73, 73, 73, 48}     // 6
  ,{3, 1, 1, 1, 127}        // 7
  ,{54, 73, 73, 73, 54}     // 8
  ,{6, 73, 73, 73, 62}      // 9
};

class Effects {
public:
  Effects(MD_MAX72XX *mx): md(mx) {}

  void open(){
    md->setRow(0,0xff);
    md->setRow(1,0xff);
    md->setRow(2,0xff);
    md->setRow(3,0xff);
    md->setRow(4,0xff);
    md->setRow(5,0xff);
    md->setRow(6,0xff);
    md->setRow(7,0xff);
    for(int i = 0 ; i < 4 ; i++){
      delay(300);
      md->setRow(3-i,0);
      md->setRow(4+i,0);
    }
    delay(300);
  }

  void close(){
    for(int i = 0 ; i < 4 ; i++){
      delay(300);
      md->setRow(0+i,0xff);
      md->setRow(7-i,0xff);
    }
    delay(300);
  }

  void reverse(){
    uint8_t buff;
    for(int j = 0 ; j < 4 ; j++)
    for(int i = 0 ; i < 8 ; i++){
      buff = md->getColumn(j,i);
      md->setColumn(j*8 + i,~buff);
    }
  }

private:
  MD_MAX72XX *md = 0 ;
};

MD_MAX72XX mx = MD_MAX72XX(MD_MAX72XX::PAROLA_HW, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);
Effects effect = Effects(&mx);

void printChar(uint8_t col, uint8_t c)
{
  uint8_t cc;
  
  if(c >= 65 && c <= 90)
    cc = c - 64;
  else if(c >= 97 && c <= 122)
    cc = c - 96;
  else if(c >= 48 && c <= 57 )
    cc = c - 21;
  else
    cc = 0;

  mx.setBuffer(col,5,alph[cc]);
}

void showStaticText(const char *str, uint8_t len) {
  static char curr_msg[BUF_SIZE];
  int mid_col = (len % 2) ? 18 : 15 ;
  int mid_char_indx = len/2;
  int i, right_char_col, left_char_col;
  
  if(len <= 0)
    return;

  strcpy(curr_msg, str);

  for(i = 0 ; i < (len/2)+1 ; i++){
    right_char_col = mid_col - i*CHAR_SIZE;
    left_char_col = mid_col + i*CHAR_SIZE;
    if(mid_char_indx-i >= 0 && left_char_col <= 32 + CHAR_SIZE) // change to macro
      printChar(left_char_col, curr_msg[mid_char_indx-i]);
    if(mid_char_indx-+i < len && i!=0 && right_char_col >= 0)
      printChar(right_char_col,curr_msg[mid_char_indx+i]);
  }
}

void showMovingText(const char *str, uint8_t len) {
  int i, c;
  int scol =0 , ccol =0;
  static char curr_msg[BUF_SIZE];
  uint32_t animation_len;

  if(len <= 0)
    return;

  strcpy(curr_msg, str);

  animation_len = (len + MAXCHARS_ONSCREEN) * CHAR_SIZE;

  for(i=0 ; i < animation_len ; i++){
    int chars = (int)(i/CHAR_SIZE) + 1 ;
    chars = (chars > len) ? len : chars ;
    scol = ccol;
    int min_char = ((chars < MAXCHARS_ONSCREEN) ? 0 : chars-MAXCHARS_ONSCREEN);
    mx.clear();
    for(c = chars-1; c >= min_char ; c--){
      printChar(scol, (uint8_t)curr_msg[c]);
      scol += 6;
    }
    ccol += 1;
    if(ccol >= CHAR_SIZE && chars != len)
      ccol = 0;
    delay(50);
  }

}

void animation() {
  effect.open();
  showMovingText("ashkan",6);
  effect.close();
  delay(100);
  effect.open();
  showStaticText("MPAL",4);
  delay(500);
  effect.reverse();
  delay(5);
  effect.reverse();
  delay(5);
  effect.reverse();
  delay(5);
  effect.reverse();
  delay(5);
  effect.reverse();
  delay(5);
  effect.reverse();
  delay(1000);
  effect.close();
}

void setup() {
  mx.begin();
}

void loop() {
  animation();
}
