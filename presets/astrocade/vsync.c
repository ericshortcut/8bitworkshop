 
#include <string.h>

#include "aclib.h"
//#link "aclib.c"
//#link "hdr_autostart.s"
#include "acbios.h"
//#link "acbios.s"

const byte player_bitmap[] =
{3,14,/*{w:12,h:16,bpp:2,brev:1}*/0x00,0x3C,0x00,0x00,0x18,0x00,0x00,0x3C,0x00,0x00,0x18,0x00,0x04,0x18,0x20,0x0C,0x3C,0x30,0x3C,0x3C,0x3C,0x1F,0xE7,0xF4,0x1F,0x66,0xF4,0x17,0xE7,0xE4,0x17,0xE7,0xE4,0x1C,0x7E,0x34,0x1C,0xFF,0x34,0x3C,0x18,0x3C,0x0C,0x18,0x30,0x04,0x18,0x20};

/*{pal:"astrocade",layout:"astrocade"}*/
const byte palette[8] = {
  0x06, 0x62, 0xF1, 0x04,
  0x07, 0xD4, 0x35, 0x01,
};

void setup_registers() {
  set_palette(palette);
  hw_horcb = 0;
  hw_verbl = 102*2;
}

void main() {
  byte x,y;
  x=10;
  y=10;
  setup_registers();
  clrscr();
  activate_interrupts();
  while (1) {
    render_sprite(player_bitmap, x, y, M_MOVE);
    wait_for_vsync();
    erase_sprite(player_bitmap, x, y);
    x++;
    y++;
  }
}