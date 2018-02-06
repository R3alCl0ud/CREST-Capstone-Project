#include "headers/broadphase.hpp"

namespace physics {

  BroadPhase::BroadPhase() {
    pairs = PairList();
  }

  void BroadPhase::GeneratePairs(void) {
    pairs.clear();
  }
}
