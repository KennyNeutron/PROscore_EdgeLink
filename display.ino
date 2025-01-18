void displayCenterOnly(String text_to_display) {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x10_mr);
  const char* text = text_to_display.c_str();
  int16_t text_width = u8g2.getStrWidth(text);
  int16_t text_height = u8g2.getAscent();
  int16_t x = (u8g2.getDisplayWidth() - text_width) / 2;
  int16_t y = (u8g2.getDisplayHeight() + text_height) / 2;
  u8g2.drawStr(x, y, text);
  u8g2.sendBuffer();
}

String str_menu[]{ "NRF24L01 Tester", "PSWDBS TX", "PSWDBS RX", "HC-05" };
void Display_Main() {
  u8g2.clearBuffer();

  u8g2.setFontPosTop();
  u8g2.setFont(u8g2_font_boutique_bitmap_7x7_t_all);
  u8g2.drawStr(0, 0, "01");
  u8g2.drawStr(90, 0, "Main Menu");

  u8g2.setFont(u8g2_font_7x13_tf);

  u8g2.drawStr(10, 15, str_menu[0].c_str());
  u8g2.drawStr(10, 33, str_menu[1].c_str());
  u8g2.drawStr(10, 51, str_menu[2].c_str());

  switch (selection_current) {
    case 0:
      u8g2.drawRFrame(0, 13, 125, 15, 7);
      break;
    case 1:
      u8g2.drawRFrame(0, 31, 125, 15, 7);
      break;
    case 2:
      u8g2.drawRFrame(0, 49, 125, 15, 7);
      break;
    default:
      selection_current = 0;
      break;
  }
  u8g2.sendBuffer();
}


void Display_Button_Functions() {
  switch (nowDisplaying) {
    case 0x0000:
      if (!btn.isFunctionExecuted() && btn.getPressedButton() == "DOWN") {
        btn.functionExecuted();
        selection_current++;
      }
      if (!btn.isFunctionExecuted() && btn.getPressedButton() == "UP") {
        btn.functionExecuted();
        selection_current--;
      }
      break;
  }
}