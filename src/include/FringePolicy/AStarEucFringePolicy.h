#ifndef __ASTAR_EUC_FRINGE_POLICY_H__
#define __ASTAR_EUC_FRINGE_POLICY_H__

#include "FringePolicy/FringePolicy.h"

class AStarEucFringePolicy : public FringePolicy {
    Fringe::sptr makeFringe() const override;
};

#endif
