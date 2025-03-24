//Display NRF24L01 Tester
//Display address: 0x0003

void display_NRF24L01_tester() {
  u8g2.clearBuffer();
  u8g2.setFontPosTop();

  u8g2.setFont(u8g2_font_boutique_bitmap_7x7_t_all);
  char hexStr[5];                          // Buffer to store the hex string (4 digits + "0x" + null terminator)
  sprintf(hexStr, "%04X", nowDisplaying);  // Format the value as a 4-digit hexadecimal string
  u8g2.drawStr(0, 0, hexStr);              // Print the hexadecimal value
  u8g2.drawStr(80, 0, "NRF24L01 Tester");

  u8g2.sendBuffer();
}


void display_NRF24L01_tester_ButtonFunctions() {
  if (!btn.isFunctionExecuted() && btn.getPressedButton() == "BACK") {
    btn.functionExecuted();
    nowDisplaying = 0x0000;
  }
}