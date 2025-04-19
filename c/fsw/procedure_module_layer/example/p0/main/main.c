#include "init/init_ram.h"
#include "init/init_rom.h"
#include "interrupt/interrupt_wakeup.h"
#include "loop.h"

int main(void){
    init_ram();
    init_rom();

    interrupt_wakeup_register();

    while(true){
        loop();
    }
}