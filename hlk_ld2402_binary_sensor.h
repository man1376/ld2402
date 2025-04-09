#pragma once

#include "esphome/core/component.h"
#include "esphome/components/binary_sensor/binary_sensor.h"
#include "hlk_ld2402.h"

namespace esphome {
namespace hlk_ld2402 {

class HLKLD2402BinarySensor : public binary_sensor::BinarySensor, public Component {
 public:
  void set_parent(HLKLD2402Component *parent) { parent_ = parent; }

  void setup() override {
    parent_->callback = [this](bool presence, bool motion) {
      if (this->type_ == "presence") {
        this->publish_state(presence);
      } else if (this->type_ == "motion") {
        this->publish_state(motion);
      }
    };
  }

  void set_type(const std::string &type) { type_ = type; }

 protected:
  HLKLD2402Component *parent_;
  std::string type_;
};

}  // namespace hlk_ld2402
}  // namespace esphome

// Регистрация платформы
ESPHome_REGISTER_BINARY_SENSOR(hlk_ld2402, esphome::hlk_ld2402::HLKLD2402BinarySensor);