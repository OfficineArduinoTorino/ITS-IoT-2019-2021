// Very elegant solutions
// to display multi line content
// inspired by Peter dalmaris
// Grove for Arduino Repository and Course

void print_text(int x_position, int y_position,  String text)
{
  // u8g2_uint_t = x_position;// = 0;
  // u8g2_uint_t = y_position;// = 20;
  int font_height = 12;

  u8g2.setFont(u8g2_font_helvB12_tf);
  u8g2.setDrawColor(0);
  u8g2.drawBox(x_position, y_position - font_height, 55, 20);
  u8g2.setDrawColor(1);
  u8g2.setCursor(x_position, y_position);



  u8g2.drawStr(x_position, y_position, text.c_str()); //

  u8g2.sendBuffer();

  u8g2.print(text);
  Serial.println(text);
  u8g2.sendBuffer();                          // print the number
  u8g2.clearBuffer(); // clean the display
}


void print_name(int x_position, int y_position,  String text)
{
  // u8g2_uint_t = x_position;// = 0;
  // u8g2_uint_t = y_position;// = 20;
  int font_height = 18;

  u8g2.setFont(u8g2_font_t0_18_tn);
  u8g2.setDrawColor(0);
  u8g2.drawBox(x_position, y_position - font_height, 55, 20);
  u8g2.setDrawColor(1);
  u8g2.setCursor(x_position, y_position);
  u8g2.print(text);
  Serial.println(text);
  u8g2.sendBuffer();                          // print the number
  u8g2.clearBuffer(); // clean the display
}
