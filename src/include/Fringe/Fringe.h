#ifndef __FRINGE_H__
#define __FRINGE_H__

#include <memory>
#include <set>

#include "SearchNode.h"

class Fringe {
    // <Board::hash()>
    std::multiset<size_t> fringeSet;

protected:
    virtual bool insertInFringe(const SearchNode::sptr&) = 0;
    virtual SearchNode::sptr extractFromFringe() = 0;

public:
    typedef std::shared_ptr<Fringe> sptr;

    bool contains(const SearchNode::sptr&) const;
    void insert(const SearchNode::sptr&);
    void insertAll(const std::vector<SearchNode::sptr>&);
    SearchNode::sptr extract();
};

#endif
