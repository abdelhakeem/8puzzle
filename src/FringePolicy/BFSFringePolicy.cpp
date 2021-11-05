#include "FringePolicy/BFSFringePolicy.h"
#include "Fringe/BFSFringe.h"

Fringe::sptr BFSFringePolicy::makeFringe() const {
    return std::make_shared<BFSFringe>();
}
