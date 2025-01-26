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


#include "display.h"

TFT_eSPI_extended tft = TFT_eSPI_extended();  // Invoke library, pins defined in User_Setup.h

// because of memory used by the internal bitmap
// select "Huge App" in Arduino IDE menu Tools -> PartitionScheme
//uint16_t GRAM65k[Nx][Ny];

void display_init(void) {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  tft.setTextColor(TFT_YELLOW, TFT_BLACK); // Note: the new fonts do not draw the background colour
}


//-------------------------------------------------------
void Transfer_Image() {
  //tft.pushImage(0,0,Nx,Ny,&GRAM65k[0][0]);
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
    // for(xps=0; xps<Nx; xps++){
    //     for(yps=0; yps<Ny; yps++){ 
    //       col16=(0xf800&(R_GRAM[xps][yps]<<8)) | (0x07E0&(G_GRAM[xps][yps]<<3)) | (0x001F&(B_GRAM[xps][yps]>>3));
    //       tft.drawPixel(xps,Ny-yps,(col16 >> 8) | (col16 << 8));           
    //     }
    // }
}
