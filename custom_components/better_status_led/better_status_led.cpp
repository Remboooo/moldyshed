#include "better_status_led.h"
#include "esphome/core/log.h"
#include "esphome/core/application.h"

namespace esphome {
namespace better_status_led {

static const char *const TAG = "better_status_led";

BetterStatusLED *global_better_status_led = nullptr;  // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)

BetterStatusLED::BetterStatusLED() { global_better_status_led = this; }

void BetterStatusLED::loop() {
  if ((App.get_app_state() & STATUS_LED_ERROR) != 0u) {
    //this->pin_->digital_write(millis() % 250u < 150u);
    this->output_->set_level(millis() % 250u < 150u ? 1.0f : 0.0f);
  } else if ((App.get_app_state() & STATUS_LED_WARNING) != 0u) {
    //this->pin_->digital_write(millis() % 1500u < 250u);
    this->output_->set_level(millis() % 1500u < 250u ? 1.0f : 0.0f);
  } else {
    this->output_->set_level(0.05f);
  }
}
float BetterStatusLED::get_setup_priority() const { return setup_priority::HARDWARE; }
float BetterStatusLED::get_loop_priority() const { return 50.0f; }

}  // namespace better)status_led
}  // namespace esphome
