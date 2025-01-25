/* 
 * File:   display.cpp
 * Author: JF3HZB / T.UEBO
 *
 * Created on 2019/02/10, 22:13
 * 
 * ------------------------------------------- 
 *  Dedicated Display Interface for ESP32
 *-------------------------------------------- 
 *
 */

// if using the official library TFT_eSPI, you must modify the library itself
// it is usually in your configured sketch directory under libraries
// on Windows that is: "C:\Users\<name>\Documents\Arduino\libraries"
// in the library directory must modify User_Setup_Select.h to:
// comment line 27 #include <User_Setup.h>
// uncomment the line for this display: #include <User_Setups/Setup22_TTGO_T4_v1.3.h> 

// if using my library: git@github.com:joseluu/TFT_eSPI.git
// no need to modify it, only include below on your projet
// the file corresponding for your display copied from the library
// at location C:\Users\<name>\Documents\Arduino\libraries\TFT_eSPI\User_Setups
#include "Setup22_TTGO_T4_v1.3.h"
#define USER_SETUP_LOADED 1
#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip

#include "display.h"

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h

// because of memory used by the internal bitmap
// select "Huge App" in Arduino IDE menu Tools -> PartitionScheme
uint8_t R_GRAM[Nx][Ny];
uint8_t G_GRAM[Nx][Ny];
uint8_t B_GRAM[Nx][Ny];
uint16_t GRAM65k[Nx][Ny];

void display_init(void) {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  tft.setTextColor(TFT_YELLOW, TFT_BLACK); // Note: the new fonts do not draw the background colour
}


//-------------------------------------------------------
void Transfer_Image() {
  tft.pushImage(0,0,Nx,Ny,&GRAM65k[0][0]);
}






/*------------------------------------------
       Command write
-------------------------------------------*/ 
void d_Command(uint8_t d){

}


/*------------------------------------------
     Convert 24bit image to 16bit image
-------------------------------------------*/ 
void trans65k(void){
    int xps, yps;
    uint16_t col16;
    for(xps=0; xps<Nx; xps++){
        for(yps=0; yps<Ny; yps++){ 
          col16=(0xf800&(R_GRAM[xps][yps]<<8)) | (0x07E0&(G_GRAM[xps][yps]<<3)) | (0x001F&(B_GRAM[xps][yps]>>3));
          GRAM65k[xps][yps]=(col16 >> 8) | (col16 << 8);           
        }
    }
}
