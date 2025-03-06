//Display HC05
//Display address: 0x0004

void display_HC05() {
  u8g2.clearBuffer();
  u8g2.setFontPosTop();

  u8g2.setFont(u8g2_font_boutique_bitmap_7x7_t_all);
  char hexStr[5];                          // Buffer to store the hex string (4 digits + "0x" + null terminator)
  sprintf(hexStr, "%04X", nowDisplaying);  // Format the value as a 4-digit hexadecimal string
  u8g2.drawStr(0, 0, hexStr);              // Print the hexadecimal value
  u8g2.drawStr(90, 0, "HC-05");

  u8g2.sendBuffer();
}


void display_HC05_ButtonFunctions() {
  if (!btn.isFunctionExecuted() && btn.getPressedButton() == "BACK") {
    btn.functionExecuted();
    nowDisplaying = 0x0000;
  }
}