#pragma once

#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"

namespace esphome {
namespace hlk_ld2402 {

class HLKLD2402Component : public uart::UARTDevice, public Component {
 public:
  HLKLD2402Component(uart::UARTComponent *parent) : UARTDevice(parent) {}
  void loop() override;

  std::function<void(bool presence, bool motion)> callback;

 protected:
  std::string buffer_;
};

}  // namespace hlk_ld2402
}  // namespace esphome