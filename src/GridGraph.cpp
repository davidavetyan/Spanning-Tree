#include "GridGraph.h"

// STL includes
#include <random>

#include "Matrix.h"

std::random_device rand_device;
std::mt19937 mt_19937(rand_device());

void CGridGraph::Reset(t_index nRow, t_index nCol)
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

void CGridGraph::GetSpanTree(CGridGraph& oSpanTree) const
{
	if (isEmpty())
		return;

	oSpanTree.Reset(m_nRowCount, m_nColCount);

	CMatrix<ENodeState> mxVisited(m_nRowCount + 1, m_nColCount + 1);
	for (int i = 0; i < m_nRowCount + 1; ++i)
	{
		for (int j = 0; j < m_nColCount + 1; ++j)
		{
			mxVisited(i, j) = ENodeState::eUnvisited;
		}
	}

	std::uniform_int_distribution<int> uniform_row_dist(0, m_nRowCount);
	std::uniform_int_distribution<int> uniform_col_dist(0, m_nColCount);
	std::uniform_int_distribution<int> uniform_pair_dist(0, 1);


	QVector<QPoint> stVertices;
	stVertices << QPoint(uniform_row_dist(mt_19937) % (m_nRowCount + 1), uniform_col_dist(mt_19937) % (m_nColCount + 1));

	int bFront = 0;

	while (!stVertices.empty())
	{
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
				oSpanTree.AddEdge(x, y, EEdgeType::eLeft);
				stVertices << QPoint{ x, y - 1 };
				mxVisited(x, y - 1) = ENodeState::eVisited;
			}

			if (y + 1 <= m_nColCount && ENodeState::eUnvisited == mxVisited(x, y + 1))
			{
				oSpanTree.AddEdge(x, y, EEdgeType::eRight);
				stVertices << QPoint{ x, y + 1 };
				mxVisited(x, y + 1) = ENodeState::eVisited;
			}

			if (x - 1 >= 0 && ENodeState::eUnvisited == mxVisited(x - 1, y))
			{
				oSpanTree.AddEdge(x, y, EEdgeType::eTop);
				stVertices << QPoint{ x - 1, y };
				mxVisited(x - 1, y) = ENodeState::eVisited;
			}

			if (x + 1 <= m_nRowCount && ENodeState::eUnvisited == mxVisited(x + 1, y))
			{
				oSpanTree.AddEdge(x, y, EEdgeType::eBottom);
				stVertices << QPoint{ x + 1, y };
				mxVisited(x + 1, y) = ENodeState::eVisited;
			}
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

