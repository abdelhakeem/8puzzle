#ifndef __FRINGE_POLICY_H__
#define __FRINGE_POLICY_H__

#include "Fringe/Fringe.h"

class FringePolicy {
public:
    typedef std::shared_ptr<FringePolicy> sptr;

    virtual Fringe::sptr makeFringe() const = 0;
};

#endif
