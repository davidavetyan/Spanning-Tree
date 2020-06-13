#include "GridGraph.h"

void CGridGraph::Reset(size_t nRow, size_t nCol)
{
	m_nRowCount = nRow;
	m_nColCount = nCol;

	m_mxEdges.Resize(nRow + 1, nCol + 1);

	if (isEmpty())
		return;

	for (int i = 0; i <= m_nRowCount; ++i)
	{
		for (int j = 0; j <= m_nColCount; ++j)
		{
			m_mxEdges(i, j) = 0;
		}
	}
}

void CGridGraph::PopulateFull()
{
	if (isEmpty())
		return;

	for (int j = 0; j < m_nColCount + 1; ++j)
	{
		if (0 == j)
		{
			m_mxEdges(0, 0) = (EEdgeFlags)EEdgeType::eRight | EEdgeType::eBottom;
			m_mxEdges(m_nRowCount, 0) = (EEdgeFlags)EEdgeType::eRight | EEdgeType::eTop;
		}
		else if (m_nColCount == j)
		{
			m_mxEdges(0, m_nColCount) = (EEdgeFlags)EEdgeType::eLeft | EEdgeType::eBottom;
			m_mxEdges(m_nRowCount, m_nColCount) = (EEdgeFlags)EEdgeType::eLeft | EEdgeType::eTop;
		}
		else
		{
			m_mxEdges(0, j) = (EEdgeFlags)EEdgeType::eRight | EEdgeType::eLeft | EEdgeType::eBottom;
			m_mxEdges(m_nRowCount, j) = (EEdgeFlags)EEdgeType::eRight | EEdgeType::eLeft | EEdgeType::eTop;
		}
	}

	for (int i = 1; i < m_nRowCount; ++i)
	{
		m_mxEdges(i, 0) = (EEdgeFlags)EEdgeType::eRight | EEdgeType::eTop | EEdgeType::eBottom;
		m_mxEdges(i, m_nColCount) = (EEdgeFlags)EEdgeType::eLeft | EEdgeType::eTop | EEdgeType::eBottom;
	}

	for (int i = 1; i < m_nRowCount; ++i)
	{
		for(int j = 1; j < m_nColCount; ++j)
		{
			m_mxEdges(i, j) = (EEdgeFlags)EEdgeType::eLeft | EEdgeType::eRight | EEdgeType::eTop | EEdgeType::eBottom;
		}
	}
}

void CGridGraph::AddEdge(int x, int y, EEdgeType eType)
{
	if (0 <= x && m_nRowCount >= x && 0 <= y && m_nColCount >= y)
		m_mxEdges(x, y) |= eType;
}

CMatrix<CGridGraph::EEdgeFlags> const& CGridGraph::GetEdges() const
{
	return m_mxEdges;
}

bool CGridGraph::isEmpty() const
{
	return 0 == m_nRowCount || 0 == m_nColCount;
}