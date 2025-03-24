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
  char hexStr[6];                          // Buffer to store the hex string (4 digits + "0x" + null terminator)
  sprintf(hexStr, "%04X", nowDisplaying);  // Format the value as a 4-digit hexadecimal string
  u8g2.drawStr(0, 0, hexStr);              // Print the hexadecimal value
  u8g2.drawStr(90, 0, "Main Menu");

  u8g2.drawStr(50, 0, String(selection_current).c_str());

  u8g2.setFont(u8g2_font_7x13_tf);

  if (selection_current > 0 && selection_current < 4) {
    u8g2.drawStr(10, 15, str_menu[0].c_str());  //NRF24L01 Tester
    u8g2.drawStr(10, 33, str_menu[1].c_str());  //PSWDBS TX
    u8g2.drawStr(10, 51, str_menu[2].c_str());  //PSWDBS RX
  } else if (selection_current >= 4) {
    u8g2.drawStr(10, 15, str_menu[1].c_str());  //PSWDBS TX
    u8g2.drawStr(10, 33, str_menu[2].c_str());  //PSWDBS RX
    u8g2.drawStr(10, 51, str_menu[3].c_str());  //HC-05
  }

  switch (selection_current) {
    case 1:
      u8g2.drawRFrame(0, 13, 125, 15, 7);
      break;
    case 2:
      u8g2.drawRFrame(0, 31, 125, 15, 7);
      break;
    case 3:
      u8g2.drawRFrame(0, 49, 125, 15, 7);
      break;
    case 4:
      u8g2.drawRFrame(0, 49, 125, 15, 7);
      break;
    default:
      selection_current = 1;
      break;
  }
  u8g2.sendBuffer();
}


void Display_Main_ButtonFunctions() {
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
      if (!btn.isFunctionExecuted() && btn.getPressedButton() == "SELECT") {
        switch (selection_current) {
          case 1:
            nowDisplaying = 0x1000;
            break;
          case 3:
            nowDisplaying = 0x3000;
            break;
          case 4:
            nowDisplaying = 0x4000;
            break;
        }
      }
      break;
  }
}