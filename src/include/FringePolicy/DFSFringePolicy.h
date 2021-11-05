#ifndef __DFS_FRINGE_POLICY_H__
#define __DFS_FRINGE_POLICY_H__

#include "FringePolicy/FringePolicy.h"

class DFSFringePolicy : public FringePolicy {
    Fringe::sptr makeFringe() const override;
};

#endif
