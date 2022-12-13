#pragma once

#include "esphome/core/component.h"
#include "esphome/core/hal.h"
#include "esphome/components/output/float_output.h"

namespace esphome {
namespace better_status_led {

class BetterStatusLED : public Component {
 public:
  explicit BetterStatusLED();

  void set_output(output::FloatOutput *output) { output_ = output; }
  void loop() override;
  float get_setup_priority() const override;
  float get_loop_priority() const override;

 protected:
  output::FloatOutput *output_;
};

extern BetterStatusLED *global_better_status_led;  // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)

}  // namespace better_status_led
}  // namespace esphome
