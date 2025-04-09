#pragma once

#include "hlk_ld2402.h"
#include "esphome/components/binary_sensor/binary_sensor.h"

namespace esphome {
namespace hlk_ld2402 {

class HLKLD2402BinarySensor : public binary_sensor::BinarySensor, public Component {
 public:
  void set_parent(HLKLD2402Component *parent) {
    this->parent_ = parent;
  }

  void setup() override {
    if (this->type_ == "presence") {
      parent_->set_presence_sensor(this);
    } else if (this->type_ == "motion") {
      parent_->set_motion_sensor(this);
    }
  }

  void set_type(const std::string &type) { this->type_ = type; }

 protected:
  HLKLD2402Component *parent_;
  std::string type_;
};

}  // namespace hlk_ld2402
}  // namespace esphome