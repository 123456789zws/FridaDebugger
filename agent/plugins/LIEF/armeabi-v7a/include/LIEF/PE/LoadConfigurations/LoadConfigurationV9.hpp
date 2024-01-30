/* Copyright 2017 - 2023 R. Thomas
 * Copyright 2017 - 2023 Quarkslab
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef LIEF_PE_LOAD_CONFIGURATION_V9_H
#define LIEF_PE_LOAD_CONFIGURATION_V9_H
#include <ostream>

#include "LIEF/visibility.h"

#include "LIEF/PE/enums.hpp"
#include "LIEF/PE/LoadConfigurations/LoadConfigurationV8.hpp"

namespace LIEF {
namespace PE {

namespace details {
template<class T>
struct load_configuration_v9;
}

class LIEF_API LoadConfigurationV9 : public LoadConfigurationV8 {
  public:

  static constexpr WIN_VERSION VERSION = WIN_VERSION::WIN10_0_19534;
  LoadConfigurationV9();

  template<class T>
  LIEF_LOCAL LoadConfigurationV9(const details::load_configuration_v9<T>& header);

  LoadConfigurationV9& operator=(const LoadConfigurationV9&);
  LoadConfigurationV9(const LoadConfigurationV9&);

  WIN_VERSION version() const override {
    return LoadConfigurationV9::VERSION;
  }

  uint64_t guard_eh_continuation_table() const {
    return guard_eh_continuation_table_;
  }

  uint64_t guard_eh_continuation_count() const {
    return guard_eh_continuation_count_;
  }

  void guard_eh_continuation_table(uint64_t value) {
    guard_eh_continuation_table_ = value;
  }

  void guard_eh_continuation_count(uint64_t value) {
    guard_eh_continuation_count_ = value;
  }

  ~LoadConfigurationV9() override;

  void accept(Visitor& visitor) const override;

  bool operator==(const LoadConfigurationV9& rhs) const;
  bool operator!=(const LoadConfigurationV9& rhs) const;

  std::ostream& print(std::ostream& os) const override;

  protected:
  uint64_t guard_eh_continuation_table_ = 0;
  uint64_t guard_eh_continuation_count_ = 0;
};
}
}

#endif
