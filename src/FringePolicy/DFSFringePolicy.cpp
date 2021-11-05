#include "FringePolicy/DFSFringePolicy.h"
#include "Fringe/DFSFringe.h"

Fringe::sptr DFSFringePolicy::makeFringe() const {
    return std::make_shared<DFSFringe>();
}
