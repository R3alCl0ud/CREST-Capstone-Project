#ifndef BROAD_PHASE
#define BROAD_PHASE 1

#include "physics.hpp"

namespace physics {
  class BroadPhase {
    public:
      BroadPhase();
      virtual ~BroadPhase(){}
      PairList pairs;
      void GeneratePairs(void);
  };
}

#endif
