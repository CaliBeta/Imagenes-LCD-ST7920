void mensajeInicio(uint8_t x, uint8_t y) {
  u8g2.clearBuffer();
  u8g2.drawXBMP(x, y, CaliBeta_Logo_width, CaliBeta_Logo_height, CaliBeta_Logo_bits);
  u8g2.sendBuffer();
  delay(1500);
  u8g2.clearBuffer();
  u8g2.drawRFrame(0, 0, u8g2.getDisplayWidth(), u8g2.getDisplayHeight(), 10);
  u8g2.sendBuffer();
  u8g2.setFont(u8g2_font_9x18_tr);

  for (int i = -50; i < 1; i++) {
    u8g2.setDrawColor(0);
    u8g2.drawBox(1, y + 9, 126, 20);
    u8g2.setDrawColor(1);
    u8g2.setCursor(x + i, y + 20);
    u8g2.print(F("CaliBeta"));
    u8g2.sendBuffer();
    delay(1);
  }

  u8g2.setFont(u8g2_font_6x13_tr);
  u8g2.setCursor(x - 18, y + 45);
  u8g2.print(F("La Electronica a tu"));
  u8g2.setCursor(x + 20, y + 55);
  u8g2.print(F("Alcance"));
  u8g2.sendBuffer();
}
//----------------------------------------------------------------------

void animacionYoutube(uint8_t x, uint8_t y) {
  if (logo == false) {
    u8g2.clearBuffer();
    u8g2.drawXBMP(x + 2, y, YouTube_width, YouTube_height, YouTube_bits);
    u8g2.sendBuffer();
  }

  u8g2.setDrawColor(0);
  u8g2.drawBox(1, y + 49, 126, 15);
  u8g2.setDrawColor(1);
  u8g2.drawBox(x - 5, y + 50, dx, 14);
  u8g2.setDrawColor(2);
  u8g2.setFont(u8g2_font_6x13_tr);
  u8g2.setCursor(x, 62);
  u8g2.print(F("SUSCRIBETE!!"));
  u8g2.setDrawColor(1);
  u8g2.sendBuffer();

  if (dx > 80)signo = -1;
  if (dx < 2) signo = 1;

  dx += (signo * 2);
  logo = true;
}
//----------------------------------------------------------------------
