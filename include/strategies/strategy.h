#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>
#include <string>
#include <vector>
#include "parser.h"
#include "order.h"

enum Signal
{
    BUY,
    SELL,
    HOLD
};

class Strategy
{
protected:
    std::vector<MarketData> data;
    static int orderCount;

public:
    Strategy();
    virtual ~Strategy() = default;
    virtual Signal analyze(const MarketData &newTick) = 0;
    virtual Order generateOrder(Signal signal, const MarketData &currentTick) = 0;
};

#endif