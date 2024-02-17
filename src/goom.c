#include <stdint.h>
#include <stdbool.h>

#include "pico/stdlib.h"
#include "hardware/pwm.h"

#include "bsp/board.h"
#include "tusb.h"

#include "consts.h"

enum  {
  BLINK_NOT_MOUNTED = 250,
  BLINK_MOUNTED = 1000,
  BLINK_SUSPENDED = 2500,
};

static uint32_t blink_interval_ms = BLINK_NOT_MOUNTED;

void handleNoteOn(uint8_t channel, uint8_t note, uint8_t velocity, uint slice_num) {

    board_led_write(1);

    // One percent of 100 KHz wrap
    int one_percent_duty = 12;

    int duty_cycle = (int)(one_percent_duty * note_duty[note - 12]);

    pwm_set_chan_level(slice_num, PWM_CHAN_A, duty_cycle);

}

void handleNoteOff(uint8_t channel, uint8_t note, uint8_t velocity, uint slice_num) {

    board_led_write(0);
    pwm_set_chan_level(slice_num, PWM_CHAN_A, 0);

}

// Invoked when device is mounted
void tud_mount_cb(void)
{
  blink_interval_ms = BLINK_MOUNTED;
}

// Invoked when device is unmounted
void tud_umount_cb(void)
{
  blink_interval_ms = BLINK_NOT_MOUNTED;
}

// Invoked when usb bus is suspended
// remote_wakeup_en : if host allow us  to perform remote wakeup
// Within 7ms, device must draw an average of current less than 2.5 mA from bus
void tud_suspend_cb(bool remote_wakeup_en)
{
  (void) remote_wakeup_en;
  blink_interval_ms = BLINK_SUSPENDED;
}

// Invoked when usb bus is resumed
void tud_resume_cb(void)
{
  blink_interval_ms = tud_mounted() ? BLINK_MOUNTED : BLINK_NOT_MOUNTED;
}

// volatile bool midi_received = false;
//
// void tud_midi_rx_cb(uint8_t itf) {
//     if (tud_midi_available()) {
//
//         uint8_t midi_buf[32];
//         uint32_t count = tud_midi_stream_read(midi_buf, sizeof(midi_buf));
//
//         midi_received = true;
//
//     }
// }

void handle_midi(uint slice_num)
{
    uint8_t midi_buf[32];
    uint32_t length = tud_midi_stream_read(midi_buf, sizeof(midi_buf));

    for (uint32_t i = 0; i < length; i += 4) {

        // byte 0: Cable Number and Code Index Number
        // byte 1: MIDI note number (or first data byte)
        // byte 2: MIDI note velocity (or second data byte)

        // First 4 bits
        uint8_t status = midi_buf[i] & 0xF0;

        // Second 4 bits
        uint8_t channel = midi_buf[i] & 0x0F;

        uint8_t note = midi_buf[i + 1];
        uint8_t velocity = midi_buf[i + 2];

        switch (status) {
            case MIDI_NOTE_ON:
                if (velocity == 0) {
                    handleNoteOff(channel, note, velocity, slice_num);
                } else {
                    handleNoteOn(channel, note, velocity, slice_num);
                }
                break;
            case MIDI_NOTE_OFF:
                handleNoteOff(channel, note, velocity, slice_num);
                break;
            default:
                // Handle other MIDI messages if needed
                break;
        }
    }

}

uint pwm_out_init()
{
    // Initialize the standard library, which also configures the GPIOs.
    stdio_init_all();

    // Choose a GPIO for PWM output. For this example, let's use GPIO 2.
    const uint PWM_PIN = 2;

    // Set up the GPIO for PWM output.
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);

    // Retrieve the PWM slice for the chosen GPIO.
    uint slice_num = pwm_gpio_to_slice_num(PWM_PIN);

    // Set the PWM frequency to 100kHz.
    pwm_set_wrap(slice_num, 1248);  // For 100kHz frequency at 125MHz system clock.

    // Enable PWM.
    pwm_set_enabled(slice_num, true);

    return slice_num;

}

int main() {

    board_init();
    tusb_init();

    uint slice_num = pwm_out_init();

    while (1) {

        tud_task();

        if (tud_midi_available()) {
            handle_midi(slice_num);

        }

    }

    return 0;
}
