// Copyright 2017 The Lynx Authors. All rights reserved.

#ifndef LYNX_RUNTIME_LYNX_ARRAY_H_
#define LYNX_RUNTIME_LYNX_ARRAY_H_

#include <vector>
#include "base/scoped_set.h"
#include "runtime/base/lynx_value.h"

namespace jscore {

class LynxArray : public LynxValue {
 public:
  LynxArray();
  virtual ~LynxArray();

  void Push(LynxValue* value);
  LynxValue* Pop();
  LynxValue* Get(int index);
  base::ScopedPtr<LynxValue> Release(int index);
  size_t Size();

  void Release() { ptrs_.release(); }

  virtual std::string ToString();

  LynxArray* Clone();

 private:
  void RemovePtr(LynxValue* value);
  void AddPtr(LynxValue* value);
  std::vector<LynxValue*> values_;
  base::ScopedSet<LynxValue> ptrs_;
};
}  // namespace jscore

#endif  // LYNX_RUNTIME_LYNX_ARRAY_H_
