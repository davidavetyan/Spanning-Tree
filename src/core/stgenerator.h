#ifndef ST_GENERATOR_H
#define ST_GENERATOR_H

// Qt includes
#include <QMap>
#include <QObject>
#include <QVector>

#include "gridgraph.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace core {
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
//
/// Spanning tree generator for grid graphs
//
class CSTGenerator : public QObject
{
    Q_OBJECT

    // Type definitions
    using EEdgeType = CGridGraph::EEdgeType;

public:
    enum class ENodeState
    {
        eUnvisited = 0,
        eVisited = 1,
        eProcessed = 2
    };
    enum class EOrder
    {
        eUndefined,
        eRandom,
        eLIFO,
        eFIFO
    };

private:
    inline CSTGenerator();
    CSTGenerator(CSTGenerator&) = delete;
    void operator=(const CSTGenerator&) = delete;

public:
    static CSTGenerator& GetInstance();

public:
    void SetOrder(QString const& strText);

public:
    void GetSpanTree(CGridGraph const& oGraph, CGridGraph& oSpanTree) const;

private:
    QMap<QString, EOrder> m_mapStringToOrder;
    EOrder m_eOrder;
};
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Inline implementations
//

CSTGenerator::CSTGenerator() : m_eOrder(EOrder::eRandom)
{
    m_mapStringToOrder = {
        { "Random", CSTGenerator::EOrder::eRandom },
        { "LIFO", CSTGenerator::EOrder::eLIFO },
        { "FIFO", CSTGenerator::EOrder::eFIFO },
    };
}

////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace core
////////////////////////////////////////////////////////////////////////////////////////////////////

#endif