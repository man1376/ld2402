#include "hlk_ld2402.h"
#include "esphome/core/log.h"

namespace esphome {
namespace hlk_ld2402 {

static const char *const TAG = "hlk_ld2402";

void HLKLD2402Component::loop() {
  while (available()) {
    char c = read();
    if (c == '\n') {
      ESP_LOGD(TAG, "Received: %s", buffer_.c_str());

      bool presence = buffer_.find("PR:1") != std::string::npos;
      bool motion = buffer_.find("MV:1") != std::string::npos;

      if (callback) {
        callback(presence, motion);
      }

      buffer_.clear();
    } else {
      buffer_ += c;
    }
  }
}

}  // namespace hlk_ld2402
}  // namespace esphome