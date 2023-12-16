#include "griddrawer.h"

////////////////////////////////////////////////////////////////////
namespace gui {
////////////////////////////////////////////////////////////////////

void CGridDrawer::Draw(QPainter* pPainter, QSize szWidget)
{
    if (!m_pGraph || m_pGraph->isEmpty())
        return;

    const int nRowCount = m_pGraph->GetRowCount();
    const int nColumnCount = m_pGraph->GetColumnCount();

    if (nRowCount == 0 || nColumnCount == 0)
        return;

    pPainter->save();

    const int ixOffset = m_szOffset.width();
    const int iyOffset = m_szOffset.height();

    int ixSpacing = 0;
    int iySpacing = 0;

    if (nRowCount != 0 && nColumnCount != 0)
    {
        ixSpacing = (szWidget.width() - 2 * ixOffset) / nColumnCount;
        iySpacing = (szWidget.height() - 2 * iyOffset) / nRowCount;
    }

    pPainter->setPen(QPen(Qt::blue, 1, Qt::SolidLine, Qt::RoundCap));

    DrawEdges(pPainter, m_pGraph, { ixOffset, iyOffset }, { ixSpacing, iySpacing });

    pPainter->setPen(QPen(Qt::black, 6, Qt::SolidLine, Qt::RoundCap));

    for (int i = 0; i <= nRowCount; ++i)
        for (int j = 0; j <= nColumnCount; ++j)
            pPainter->drawPoint(QPoint(ixOffset + j * ixSpacing, iyOffset + i * iySpacing));

    if (m_bDrawST)
    {
        pPainter->setPen(QPen(Qt::red, 3, Qt::SolidLine, Qt::RoundCap));

        if (!m_pSTCache)
            CreateSTCache();

        DrawEdges(pPainter, m_pSTCache, { ixOffset, iyOffset }, { ixSpacing, iySpacing });
    }

    pPainter->restore();
}

void CGridDrawer::ResetGraphDimensions(int nRow, int nCol, bool bPopulate)
{
    if (m_pGraph)
    {
        m_pGraph->Reset(nRow, nCol);
        if (bPopulate)
            m_pGraph->PopulateFull();
    }

    ResetSTCache();
}

void CGridDrawer::DrawEdges(QPainter* pPainter, SharedPtr<const core::CGridGraph> pGraph,
                            QSize szOffset, QSize szSpacing) const
{
    if (!pGraph || pGraph->isEmpty())
        return;

    const int ixOffset = szOffset.width();
    const int iyOffset = szOffset.height();

    const int ixSpacing = szSpacing.width();
    const int iySpacing = szSpacing.height();

    core::CMatrix<core::CGridGraph::EEdgeFlags> const& vecEdges = pGraph->GetEdges();
    for (int i = 0; i < vecEdges.RowCount(); ++i)
    {
        for (int j = 0; j < vecEdges.ColCount(); ++j)
        {
            QPoint pntFirst;
            QPoint pntSecond;

            pntFirst.setX(ixOffset + j * ixSpacing);
            pntFirst.setY(iyOffset + i * iySpacing);

            core::CGridGraph::EEdgeFlags eEdges = vecEdges(i, j);
            if (eEdges & core::CGridGraph::EEdgeType::eTop)
            {
                pntSecond = pntFirst - QPoint{ 0, iySpacing };
                pPainter->drawLine(pntFirst, pntSecond);
            }
            if (eEdges & core::CGridGraph::EEdgeType::eRight)
            {
                pntSecond = pntFirst + QPoint{ ixSpacing, 0 };
                pPainter->drawLine(pntFirst, pntSecond);
            }
            if (eEdges & core::CGridGraph::EEdgeType::eBottom)
            {
                pntSecond = pntFirst + QPoint{ 0, iySpacing };
                pPainter->drawLine(pntFirst, pntSecond);
            }
            if (eEdges & core::CGridGraph::EEdgeType::eLeft)
            {
                pntSecond = pntFirst - QPoint{ ixSpacing, 0 };
                pPainter->drawLine(pntFirst, pntSecond);
            }
        }
    }
}

void CGridDrawer::CreateSTCache()
{
    if (m_pGraph == nullptr)
        return;

    if (m_pSTCache == nullptr)
        m_pSTCache = std::make_shared<core::CGridGraph>();
    core::CSTGenerator& oGenerator = core::CSTGenerator::GetInstance();
    oGenerator.GetSpanTree(*m_pGraph, *m_pSTCache);
}

void CGridDrawer::ResetSTCache()
{
    m_pSTCache.reset();
}

void CGridDrawer::SetDrawST(bool bDrawST)
{
    m_bDrawST = bDrawST;
}

////////////////////////////////////////////////////////////////////
} // namespace gui
  ////////////////////////////////////////////////////////////////////