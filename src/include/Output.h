#ifndef __OUTPUT_H__
#define __OUTPUT_H__

#include "Solver.h"

std::string summarizeResult(const Result&);

std::ostream& operator<<(std::ostream&, const Board&);
std::ostream& operator<<(std::ostream&, const Result&);

#endif
