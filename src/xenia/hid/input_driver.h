/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2013 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#ifndef XENIA_HID_INPUT_DRIVER_H_
#define XENIA_HID_INPUT_DRIVER_H_

#include <xenia/core.h>
#include <xenia/xbox.h>


namespace xe {
namespace hid {

class InputSystem;


class InputDriver {
public:
  virtual ~InputDriver();

  virtual X_STATUS Setup() = 0;

  virtual XRESULT GetCapabilities(
      uint32_t user_index, uint32_t flags, X_INPUT_CAPABILITIES& out_caps) = 0;
  virtual XRESULT GetState(
      uint32_t user_index, X_INPUT_STATE& out_state) = 0;
  virtual XRESULT SetState(
      uint32_t user_index, X_INPUT_VIBRATION& vibration) = 0;

protected:
  InputDriver(InputSystem* input_system);

  InputSystem* input_system_;
};


}  // namespace hid
}  // namespace xe


#endif  // XENIA_HID_INPUT_DRIVER_H_