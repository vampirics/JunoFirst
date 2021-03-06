#include "src/utils/Arduboy2Ext.h"


// --------------------------------------------------------------------------------------
//  Render High Score screen ..
//

void HighScore() {

  uint8_t xOffset = 28;
  uint8_t yOffset = 23;

  Sprites::drawOverwrite(17, 0, highScoreImg, 0);

  for (uint8_t x =0; x < MAX_NUMBER_OF_SCORES; x++) {

    Slot slot;
    EEPROM_Utils::getSlot(x, &slot);

    Sprites::drawOverwrite(xOffset, yOffset, font, slot.getChar0());
    Sprites::drawOverwrite(xOffset + 5, yOffset, font, slot.getChar1());
    Sprites::drawOverwrite(xOffset + 10, yOffset, font, slot.getChar2());


    // Score ..
    {
      uint8_t digits[6] = {};
      extractDigits(digits, slot.getScore());
      
      for (uint8_t i = 0, x2 = xOffset + 49; i < 6; ++i, x2 -= 5) {
        Sprites::drawOverwrite(x2, yOffset, numbers, digits[i]);
      }
      
    }


    // Wave ..
    
    Sprites::drawOverwrite(xOffset + 65, yOffset, numbers, slot.getWave() / 10);
    Sprites::drawOverwrite(xOffset + 70, yOffset, numbers, slot.getWave() % 10);

    yOffset = yOffset + 8;

  }


  if (highScore.getSlotNumber() != DO_NOT_EDIT_SLOT) {

    yOffset = 23;
    alternate++;
  
    if (alternate < 40) {

      Sprites::drawOverwrite(xOffset - 6, yOffset + (highScore.getSlotNumber() * 8), arrowLeft, 0);
      Sprites::drawOverwrite(xOffset + 77, yOffset + (highScore.getSlotNumber() * 8), arrowRight, 0);
    
    }
    else if (alternate > 80) {

      alternate = 0;

    }

    if (highScore.getCharIndex() == 0) {
      arduboy.fillRect(xOffset - 1, yOffset + (highScore.getSlotNumber() * 8) - 1, 5, 7, WHITE);
      Sprites::drawErase(xOffset, yOffset + (highScore.getSlotNumber() * 8), font, highScore.getChar(0));
    }
    else {
      Sprites::drawOverwrite(xOffset, yOffset + (highScore.getSlotNumber() * 8), font, highScore.getChar(0));
    }

    if (highScore.getCharIndex() == 1) {
      arduboy.fillRect(xOffset + 4, yOffset + (highScore.getSlotNumber() * 8) - 1, 5, 7, WHITE);
      Sprites::drawErase(xOffset + 5, yOffset + (highScore.getSlotNumber() * 8), font, highScore.getChar(1));
    }
    else {
      Sprites::drawOverwrite(xOffset + 5, yOffset + (highScore.getSlotNumber() * 8), font, highScore.getChar(1));
    }

    if (highScore.getCharIndex() == 2) {
      arduboy.fillRect(xOffset + 9, yOffset + (highScore.getSlotNumber() * 8) - 1, 5, 7, WHITE);
      Sprites::drawErase(xOffset + 10, yOffset + (highScore.getSlotNumber() * 8), font, highScore.getChar(2));
    }
    else {
      Sprites::drawOverwrite(xOffset + 10, yOffset + (highScore.getSlotNumber() * 8), font, highScore.getChar(2));
    }


    // Handle buttons ..

    uint8_t charIndex = highScore.getCharIndex();

    if (arduboy.justPressed(UP_BUTTON))       { highScore.incChar(charIndex); }
    if (arduboy.justPressed(DOWN_BUTTON))     { highScore.decChar(charIndex); }
    if (arduboy.justPressed(LEFT_BUTTON))     { highScore.decCharIndex(); } 
    if (arduboy.justPressed(RIGHT_BUTTON))    { highScore.incCharIndex(); } 

    if (arduboy.justPressed(A_BUTTON)) { 
      
      EEPROM_Utils::writeChars(highScore.getSlotNumber(), &highScore);
      highScore.disableEditting(); 
      
    }

  }
  else {

    if (arduboy.justPressed(A_BUTTON) || arduboy.justPressed(B_BUTTON)) { gameState = GameState::Intro_Init; }
    
  }

}