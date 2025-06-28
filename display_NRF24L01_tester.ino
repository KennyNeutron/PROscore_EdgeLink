//Display NRF24L01 Tester
//Display address: 0x1000

uint16_t txCount = 0;   // Transmitted packets
uint16_t rxCount = 0;   // Received packets
int8_t lastRSSI = -50;  // Last signal strength reading

void display_NRF24L01_tester() {
  u8g2.clearBuffer();
  u8g2.setFontPosTop();
  u8g2.setFont(u8g2_font_boutique_bitmap_7x7_t_all);

  // ── Header ───────────────────────────────
  char hexStr[5];
  sprintf(hexStr, "%04X", nowDisplaying);
  u8g2.drawStr(0, 0, hexStr);
  u8g2.drawStr(60, 0, "NRF24L01 Tester");

  // ── Status ───────────────────────────────
  u8g2.drawStr(0, 10, "Status:");
  u8g2.drawStr(60, 10, NRF.isChipConnected() ? "Connected" : "FAILED");

  // ── Channel & Data Rate ─────────────────
  char chStr[10], drStr[10];
  sprintf(chStr, "CH:%d", NRF.getChannel());
  sprintf(drStr, "DR:%s",
          NRF.getDataRate() == RF24_250KBPS ? "250K" :
          NRF.getDataRate() == RF24_1MBPS   ? "1M"   : "2M");
  u8g2.drawStr(0, 20, chStr);
  u8g2.drawStr(60, 20, drStr);

  // ── Power & CRC ─────────────────────────
  char pwrStr[10], crcStr[10];
  sprintf(pwrStr, "PWR:%s",
          NRF.getPALevel() == RF24_PA_MIN  ? "MIN" :
          NRF.getPALevel() == RF24_PA_LOW  ? "LOW" :
          NRF.getPALevel() == RF24_PA_HIGH ? "HIGH" : "MAX");
  sprintf(crcStr, "CRC:%s",
          NRF.getCRCLength() == RF24_CRC_DISABLED ? "OFF" :
          NRF.getCRCLength() == RF24_CRC_8        ? "8"   : "16");
  u8g2.drawStr(0, 30, pwrStr);
  u8g2.drawStr(60, 30, crcStr);

  // ── Packet Counters ─────────────────────
  char txStr[10], rxStr[10];
  sprintf(txStr, "TX:%d", txCount);
  sprintf(rxStr, "RX:%d", rxCount);
  u8g2.drawStr(0, 40, txStr);
  u8g2.drawStr(60, 40, rxStr);

  // ── Payload & Signal Quality ─────────────
  char plStr[10], rssiStr[15];
  sprintf(plStr, "PL:%d", NRF.getPayloadSize());
  sprintf(rssiStr, "RSSI:%ddBm", lastRSSI); // replace with actual RSSI logic if needed
  u8g2.drawStr(0, 50, plStr);
  u8g2.drawStr(60, 50, rssiStr);

  u8g2.sendBuffer();
}

void display_NRF24L01_tester_ButtonFunctions() {
  if (!btn.isFunctionExecuted() && btn.getPressedButton() == "BACK") {
    btn.functionExecuted();
    nowDisplaying = 0x0000;
  }
}