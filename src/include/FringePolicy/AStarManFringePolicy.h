#ifndef __ASTAR_MAN_FRINGE_POLICY_H__
#define __ASTAR_MAN_FRINGE_POLICY_H__

#include "FringePolicy/FringePolicy.h"

class AStarManFringePolicy : public FringePolicy {
    Fringe::sptr makeFringe() const override;
};

#endif
