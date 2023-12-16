#include "stgenerator.h"

// STL includes
#include <random>

// Qt includes
#include <QPoint>

#include "matrix.h"

////////////////////////////////////////////////////////////////////
namespace core {
////////////////////////////////////////////////////////////////////

std::random_device rand_device;
std::mt19937 mt_19937(rand_device());

CSTGenerator& CSTGenerator::GetInstance()
{
    static CSTGenerator oSTGenerator;
    return oSTGenerator;
}

void CSTGenerator::SetOrder(QString const& strText)
{
    auto it = m_mapStringToOrder.find(strText);
    if (it == m_mapStringToOrder.end())
        m_eOrder = EOrder::eUndefined;
    else
        m_eOrder = it.value();
}

void CSTGenerator::GetSpanTree(CGridGraph const& oGraph, CGridGraph& oSpanTree) const
{
    if (oGraph.isEmpty())
        return;

    size_t nRowCount = oGraph.GetRowCount();
    size_t nColCount = oGraph.GetColumnCount();

    oSpanTree.Reset(nRowCount, nColCount);

    CMatrix<ENodeState> mxVisited(nRowCount + 1, nColCount + 1);
    for (int i = 0; i < nRowCount + 1; ++i)
    {
        for (int j = 0; j < nColCount + 1; ++j)
        {
            mxVisited(i, j) = ENodeState::eUnvisited;
        }
    }

    std::uniform_int_distribution<int> uniform_row_dist(0, nRowCount);
    std::uniform_int_distribution<int> uniform_col_dist(0, nColCount);
    std::uniform_int_distribution<int> uniform_pair_dist(0, 1);


    QVector<QPoint> stVertices;
    stVertices << QPoint(uniform_row_dist(mt_19937) % (nRowCount + 1),
                         uniform_col_dist(mt_19937) % (nColCount + 1));

    assert(m_eOrder != EOrder::eUndefined);

    int bFront;
    if (EOrder::eLIFO == m_eOrder)
        bFront = 0;
    else
        bFront = 1;

    while (!stVertices.empty())
    {
        if (EOrder::eRandom == m_eOrder)
            bFront = uniform_pair_dist(mt_19937);

        QPoint pntNode;
        if (bFront)
        {
            pntNode = stVertices.front();
            stVertices.pop_front();
        }
        else
        {
            pntNode = stVertices.back();
            stVertices.pop_back();
        }

        const int x = pntNode.x();
        const int y = pntNode.y();

        if (mxVisited(x, y) != ENodeState::eProcessed)
        {
            mxVisited(x, y) = ENodeState::eProcessed;

            if (y - 1 >= 0 && ENodeState::eUnvisited == mxVisited(x, y - 1))
            {
                oSpanTree.AddEdge(x, y, CGridGraph::EEdgeType::eLeft);
                stVertices << QPoint{ x, y - 1 };
                mxVisited(x, y - 1) = ENodeState::eVisited;
            }

            if (y + 1 <= nColCount && ENodeState::eUnvisited == mxVisited(x, y + 1))
            {
                oSpanTree.AddEdge(x, y, CGridGraph::EEdgeType::eRight);
                stVertices << QPoint{ x, y + 1 };
                mxVisited(x, y + 1) = ENodeState::eVisited;
            }

            if (x - 1 >= 0 && ENodeState::eUnvisited == mxVisited(x - 1, y))
            {
                oSpanTree.AddEdge(x, y, CGridGraph::EEdgeType::eTop);
                stVertices << QPoint{ x - 1, y };
                mxVisited(x - 1, y) = ENodeState::eVisited;
            }

            if (x + 1 <= nRowCount && ENodeState::eUnvisited == mxVisited(x + 1, y))
            {
                oSpanTree.AddEdge(x, y, CGridGraph::EEdgeType::eBottom);
                stVertices << QPoint{ x + 1, y };
                mxVisited(x + 1, y) = ENodeState::eVisited;
            }
        }
    }
}

//void CSTGenerator::OnOrderChanged(QString const& strText)
//{
//	QMap<QString, EOrder>::const_iterator it = s_mapStringToOrder.find(strText);
//	if (s_mapStringToOrder.cend() == it)
//		m_eOrder = EOrder::eUndefined;
//	else
//		m_eOrder = it.value();
//}

////////////////////////////////////////////////////////////////////
} // namespace core
  ////////////////////////////////////////////////////////////////////