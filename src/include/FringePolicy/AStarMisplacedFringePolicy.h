#ifndef __ASTAR_MISPLACED_FRINGE_POLICY_H__
#define __ASTAR_MISPLACED_FRINGE_POLICY_H__

#include "FringePolicy/FringePolicy.h"

class AStarMisplacedFringePolicy : public FringePolicy {
    Fringe::sptr makeFringe() const override;
};

#endif
