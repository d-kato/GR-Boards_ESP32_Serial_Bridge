#include "mbed.h"
#include "USBSerial.h"

USBSerial pc(0x1f00, 0x2012, 0x0001, false, 20480);  // connect_blocking = false, buf_size = 20480
#if defined(TARGET_RZ_A1H)
RawSerial wifi_serial(P2_14, P2_15);
DigitalOut wifi_en(P3_10);
DigitalOut wifi_io0(P3_9);
#elif defined(TARGET_GR_LYCHEE)
RawSerial wifi_serial(P7_1, P0_1);
DigitalOut wifi_en(P5_3);
DigitalOut wifi_io0(P3_14);
#else
#error "Not supported target."
#endif

DigitalOut led1(LED1);
InterruptIn button0(USER_BUTTON0);

static uint8_t usb_send_buff[64];
static bool button_on = false;

static void settings_change(int baud, int bits, int parity, int stop) {
    wifi_serial.baud(baud);
    wifi_serial.format(bits, (SerialBase::Parity)parity, (stop == 0) ? 1 : stop);
}

static void button0_fall(void) {
    button_on = true;
}

int main() {
    pc.attach(&settings_change);

    // check mode
    if (button0 == 0) {
        wifi_io0 = 0;
        led1 = 1;
    } else {
        wifi_io0 = 1;
    }
    button_on = true;

    // button setting
    button0.fall(&button0_fall);

    while (1) {
        if (button_on) {
            button_on = false;
            wifi_en  = 0;
            Thread::wait(500);
            wifi_en  = 1;
        }
        if (wifi_serial.readable()) {
            int idx = 0;
            usb_send_buff[idx++] = wifi_serial.getc();
            while (wifi_serial.readable() && (idx < 64)) {
                usb_send_buff[idx++] = wifi_serial.getc();
            }
            pc.writeBlock(usb_send_buff, idx);
        }
        if (pc.readable()) {
            wifi_serial.putc(pc._getc());
        }
    }
}
