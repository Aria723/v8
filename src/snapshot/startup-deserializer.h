// Copyright 2017 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_SNAPSHOT_STARTUP_DESERIALIZER_H_
#define V8_SNAPSHOT_STARTUP_DESERIALIZER_H_

#include "src/snapshot/deserializer.h"
#include "src/snapshot/snapshot.h"

namespace v8 {
namespace internal {

// Initializes an isolate with context-independent data from a given snapshot.
class StartupDeserializer final : public Deserializer {
 public:
  explicit StartupDeserializer(const SnapshotData* data)
      : Deserializer(data, false) {}

  // Deserialize the snapshot into an empty heap.
  void Deserialize(Isolate* isolate);

 private:
  void FlushICacheForNewIsolate();
  void PrintDisassembledCodeObjects();

  // Rehash after deserializing an isolate.
  void Rehash();
};

}  // namespace internal
}  // namespace v8

#endif  // V8_SNAPSHOT_STARTUP_DESERIALIZER_H_
