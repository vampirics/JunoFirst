#include "src/utils/Arduboy2Ext.h"

// --------------------------------------------------------------------------------------
//  Render the screen
//
void RenderScreen(Player *player, Enemy *enemies) {


  // Render the horizon ;

  const uint8_t horizon[5][7] = {
                                  { 0, 2,  6, 12, 20, 30, 42 },
                                  { 0, 2,  7, 13, 22, 32, 45 },
                                  { 0, 3,  8, 15, 24, 35, 48 },
                                  { 0, 3,  9, 16, 26, 37, 51 },
                                  { 0, 4, 10, 18, 28, 40, 54 }
                                };                        

  uint8_t row = level.getHorizon();

  for (uint8_t col = 0; col < HORIZON_COL_COUNT; col++) {

    uint8_t y = horizon[row][col] + 4;

#ifdef USE_DOTTED_LINES
    arduboy.drawHorizontalDottedLine((col + 2) / 2, WIDTH, y, col + 2);
#else
    arduboy.drawFastHLine(0, y, WIDTH);
#endif
  }


  // Render the enemies ..

  for (uint8_t x = 0; x < MAX_NUMBER_OF_ENEMIES; x++) {

    Enemy *enemy = &enemies[x];

    uint8_t const *imageName = nullptr;
    uint8_t const *maskName = nullptr;
    uint8_t frame = 0;

    if (enemy->isVisible()) {

      if (enemy->getStatus() == EnemyStatus::Active) {

        switch (enemy->getSize()) {

          case ImageSize::Horizon:

            imageName = alien_horizon;
            maskName = alien_horizon_mask;
            break;

          case ImageSize::Far:

            imageName = alien_far;
            maskName = alien_far_mask;
            break;

          case ImageSize::Medium:

            if (arduboy.getFrameCount(ENEMY_FRAME_COUNT) < ENEMY_FRAME_COUNT_HALF) {
              imageName = alien_medium_1;
              maskName = alien_medium_1_mask;
            }
            else {
              imageName = alien_medium_2;
              maskName = alien_medium_2_mask;
            }

            frame = static_cast<uint8_t>(enemy->getType());

            break;

          case ImageSize::Close:

            if (arduboy.getFrameCount(ENEMY_FRAME_COUNT) < ENEMY_FRAME_COUNT_HALF) {
              imageName = alien_close_1;
              maskName = alien_close_1_mask;
            }
            else {
              imageName = alien_close_2;
              maskName = alien_close_2_mask;
            }

            frame = static_cast<uint8_t>(enemy->getType());

            break;

        }


        // Render image ..

        Sprites::drawExternalMask(enemy->getXDisplay(), enemy->getYDisplay(), imageName, maskName, frame, frame);

      }
      else {

        switch (enemy->getStatus()) {

          case EnemyStatus::Explosion1:
            imageName = alien_close_explosion_4;
            break;

          case EnemyStatus::Explosion2:
            imageName = alien_close_explosion_3;
            break;

          case EnemyStatus::Explosion3:
            imageName = alien_close_explosion_2;
            break;

          case EnemyStatus::Explosion4:
            imageName = alien_close_explosion_1;
            break;

          default: break;
            
        }

        Sprites::drawSelfMasked(enemy->getXDisplay(), enemy->getYDisplay(), imageName, 0);

      }
 
    }
#ifdef SHOW_OUT_OF_SIGHT
    else { // Enemy is not visible ..

      if (enemy->getStatus() == EnemyStatus::Active) {

        if (enemy->getYDisplay() >= 64 && enemy->getYDisplay() <= 120) {

          if (enemy->getXDisplay() < static_cast<int16_t>(0)) {

            arduboy.drawPixel(0, 59, BLACK);
            arduboy.drawFastVLine(0, 60, 3);
            arduboy.drawFastHLine(0, 63, 3);
            arduboy.drawPixel(4, 63, BLACK);

          }
          if (enemy->getXDisplay() > static_cast<int16_t>(119)) {

            arduboy.drawPixel(119, 59, BLACK);
            arduboy.drawFastVLine(119, 60, 3);
            arduboy.drawFastHLine(116, 63, 3);
            arduboy.drawPixel(115, 63, BLACK);

          }
          else {

            arduboy.drawPixel(enemy->getXDisplay() + 2, 63, BLACK);
            arduboy.drawFastHLine(enemy->getXDisplay() + 3, 63, 6);
            arduboy.drawPixel(enemy->getXDisplay() + 9, 63, BLACK);

          }

        }
        else {

          if (enemy->getXDisplay() < static_cast<int16_t>(0)) {

            arduboy.drawPixel(0, enemy->getYDisplay() + 2, BLACK);
            arduboy.drawFastVLine(0, enemy->getYDisplay() + 3, 6, WHITE);
            arduboy.drawPixel(0, enemy->getYDisplay() + 9, BLACK);

          }

          if (enemy->getXDisplay() > static_cast<int16_t>(119)) {

            arduboy.drawPixel(119, enemy->getYDisplay() + 2, BLACK);
            arduboy.drawFastVLine(119, enemy->getYDisplay() + 3, 6, WHITE);
            arduboy.drawPixel(119, enemy->getYDisplay() + 9, BLACK);

          }

        }

      }

    }
#endif
  }


  // Render the space ship ..  

  const uint8_t frames[] = {0, 4, 3, 3, 2};
  uint8_t frameRate = frames[absT(player->getYDelta())];

  if (player->getStatus() == PlayerStatus::Active) {
      
    switch (player->getYDelta()) {

      case -4 ... -1:

        if (arduboy.getFrameCount(frameRate) % frameRate < frameRate / 2) { 
          Sprites::drawExternalMask(player->getX(), player->getY(), spaceship_backwards_1, spaceship_backwards_1_mask, 0, 0);
        }
        else {
          Sprites::drawExternalMask(player->getX(), player->getY(), spaceship_backwards_2, spaceship_backwards_2_mask, 0, 0);
        }
        break;

      case 0:

        Sprites::drawExternalMask(player->getX(), player->getY(), spaceship_neutral, spaceship_neutral_mask, 0, 0);
        break;

      case 1 ... 4:

        if (arduboy.getFrameCount(frameRate) % frameRate < frameRate / 2) { 
          Sprites::drawExternalMask(player->getX(), player->getY() + 1, spaceship_advance_1, spaceship_advance_1_mask, 0, 0);
        }
        else {
          Sprites::drawExternalMask(player->getX(), player->getY(), spaceship_advance_2, spaceship_advance_2_mask, 0, 0);
        }
        break;

    }

  }
  else {

    uint8_t const *imageName = nullptr;

    switch (player->getStatus()) {

      case PlayerStatus::Explosion1:
        imageName = alien_close_explosion_4;
        break;

      case PlayerStatus::Explosion2:
        imageName = alien_close_explosion_3;
        break;

      case PlayerStatus::Explosion3:
        imageName = alien_close_explosion_2;
        break;

      case PlayerStatus::Explosion4:
        imageName = alien_close_explosion_1;
        break;

      default: 
        imageName = alien_close_explosion_5;
        break;
        
    }

    Sprites::drawSelfMasked(player->getX(), player->getY(), imageName, 0);
    
  }


  // Render player bullet ..

  if (playerBullet.getY() > 0) {

    arduboy.drawFastVLine(playerBullet.getX(), playerBullet.getY(), 5, WHITE); 

  }


  // Render enemy bullets ..

  for (uint8_t x = 0; x < MAX_NUMBER_OF_BULLETS; x++) {

    Bullet *bullet = &bullets[x];

    if (bullet->getY() > 0) { 

      arduboy.drawRect(bullet->getX(), bullet->getY(), 2, 2, WHITE);

    }

  }


  if (gameState == GameState::GamePlay && arduboy.everyXFrames(2)) {
    
    alternate++;

  }


  // Render scoreboard ..

  Sprites::drawOverwrite(120, 0, blankScoreboard, 0);

  if (alternate < 128) {


    // Score ..

    uint8_t digits[6] = {};
    extractDigits(digits, level.getScore());
    
    for (int8_t i = 5, y = 1; i >= 0; --i, y += 5) {
      Sprites::drawOverwrite(123, y, numbers_vert, digits[i]);
    }

    if (gameState == GameState::Wave) {
    
      if (introDelay % 2 == 1) {

        for (int8_t i = player->getLives(), y = 64 - (player->getLives() * 6); i > 0; --i, y += 6) {
          Sprites::drawOverwrite(123, y, life_vert, 0);
        }

      }
      else {
        
        for (int8_t i = player->getLives() - 1, y = 64 - ((player->getLives() - 1) * 6); i > 0; --i, y += 6) {
          Sprites::drawOverwrite(123, y, life_vert, 0);
        }

      }

    }
    else {
        
      for (int8_t i = player->getLives() - 1, y = 64 - ((player->getLives() - 1) * 6); i > 0; --i, y += 6) {
        Sprites::drawOverwrite(123, y, life_vert, 0);
      }
      
    }
  
  }
  else {

    Sprites::drawOverwrite(123, 0, fuel, 0);

    uint8_t fuel = player->getFuel();
    for (uint8_t y = 5; y < fuel; y+=2) {
      arduboy.drawFastHLine(123, y, WIDTH, WHITE);
    }

    Sprites::drawOverwrite(123, 50, heart, 0);

    for (uint8_t y = 0; y < player->getHealth(); y+=2) {
      arduboy.drawFastHLine(123, 57 + y, WIDTH, WHITE);
    }

  }


  // Start of game or wave?

  if (gameState == GameState::Wave) {

    if (introDelay != 2 && introDelay != 4 && introDelay != 6) {

      if (level.getWave() == 1 && player->getLives() == MAX_NUMBER_OF_LIVES) {

        arduboy.fillRect(33, 21, 53, 13, BLACK);
        Sprites::drawSelfMasked(34, 22, getReady, 0);

      }
      else {

        arduboy.fillRect(42, 21, 39, 13, BLACK);
        Sprites::drawSelfMasked(43, 22, startOfWave, 0);
        Sprites::drawSelfMasked(69, 25, numbers, level.getWave() / 10);
        Sprites::drawSelfMasked(74, 25, numbers, level.getWave() % 10);
        
      }

    }
    else {

      if (!sound.playing()) sound.tones(blib);

    }

  }

  if (gameState == GameState::Paused) {
    
    arduboy.fillRect(44, 21, 33, 13, BLACK);
    Sprites::drawSelfMasked(44, 22, pause, 0);

  }


  // Double up score ..

  alternate2++;
  if (alternate2 > 96) alternate2 = 0;

  if (level.inDoubleUpPhase()) {

    arduboy.setRGBled(0, (alternate2 < 48 ? (alternate2 + 2) / 2 : 50 - (alternate2 / 2)), 0);
   
    if (alternate2 < 48) {

      Sprites::drawOverwrite(106, 0, x2Inverted, 0);
 
    }

  }
  else {

    arduboy.setRGBled(0, 0, 0);

  }

}
