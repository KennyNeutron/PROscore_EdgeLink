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

void Display_Main(){
    
}