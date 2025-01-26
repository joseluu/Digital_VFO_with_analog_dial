/* 
 * File:   display.h
 * Author: JF3HZB / T.UEBO
 *
 * Created on 2019/02/10, 22:13
 */

#ifndef _display_
#define _display_


// if using the official library TFT_eSPI, you must modify the library itself
// it is usually in your configured sketch directory under libraries
// on Windows that is: "C:\Users\<name>\Documents\Arduino\libraries"
// in the library directory must modify User_Setup_Select.h to:
// comment line 27 #include <User_Setup.h>
// uncomment the line for this display: #include <User_Setups/Setup22_TTGO_T4_v1.3.h> 


#include <TFT_eSPI.h> // Graphics and font library



#define Xw 128
#define Yw 320

#define Nx Yw
#define Ny Xw

class TFT_eSPI_extended : public TFT_eSPI
{
  using TFT_eSPI::TFT_eSPI;  // inherit constructors
  public:
    void drawPixelRGB(int32_t x, int32_t y, uint8_t r, uint8_t g, uint8_t b){
      drawPixel(Nx - x, y, color24to16(r<<16|g<<8|b));
    }
    uint8_t readPixelR(int32_t x, int32_t y){
      uint16_t pixel = readPixel(Nx - x, y);
      return color16to24(pixel)>>16;
    }
    uint8_t readPixelG(int32_t x, int32_t y){
      uint16_t pixel = readPixel(Nx - x, y);
      return (color16to24(pixel) & 0xFF00) >>16;
    }
    uint8_t readPixelB(int32_t x, int32_t y){
      uint16_t pixel = readPixel(Nx - x, y);
      return color16to24(pixel) & 0xFF;
    }
};



void display_init(void);
void Transfer_Image(void);
void trans65k(void);
void d_Command(uint8_t d);

#endif
