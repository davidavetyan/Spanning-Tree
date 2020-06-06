#ifndef GRID_GRAPH_H
#define GRID_GRAPH_H

// Qt includes
#include <QVector>

#include "Matrix.h"

/*
 * class CGridGraph
 * Represents a grid graph of size m x n. Is created empty by default.
 */
class CGridGraph
{
	// Type definitions
	using t_index = unsigned int;

public:
	inline CGridGraph(t_index nRow = 0, t_index nCol = 0);
	inline CGridGraph(CGridGraph&& oGraph) noexcept;
	inline CGridGraph& operator=(CGridGraph&& oGraph) noexcept;

public:
	enum class EEdgeType
	{
		eTop = 0x8,
		eRight = 0x4,
		eBottom = 0x2,
		eLeft = 0x1
	};
	Q_DECLARE_FLAGS(EEdgeFlags, EEdgeType)

	enum class ENodeState
	{
		eUnvisited = 0,
		eVisited = 1,
		eProcessed = 2
	};

public:
	// Main interface

	void			Reset(t_index nRow = 0, t_index nCol = 0);
	void			PopulateFull();
	void			GetSpanTree(CGridGraph& oSpanTree) const;
	void			AddEdge(int x, int y, EEdgeType eType);
	CMatrix<EEdgeFlags> const& GetEdges() const;

public:
	inline t_index	GetRowCount() const;
	inline t_index	GetColumnCount() const;
	bool			isEmpty() const;

private:
	CMatrix<EEdgeFlags>	m_mxEdges;
	t_index				m_nRowCount;
	t_index				m_nColCount;
};

inline CGridGraph::CGridGraph(t_index nRow, t_index nCol)
	: m_nRowCount(nRow), m_nColCount(nCol)
{
}

inline CGridGraph::CGridGraph(CGridGraph&& oGraph) noexcept
	: m_nRowCount(oGraph.m_nRowCount), m_nColCount(oGraph.m_nColCount)
{
	m_mxEdges = oGraph.m_mxEdges;

	oGraph.m_nRowCount = 0;
	oGraph.m_nColCount = 0;
	m_mxEdges.Resize(0, 0);
}

inline CGridGraph& CGridGraph::operator=(CGridGraph&& oGraph) noexcept
{
	if (this == &oGraph)
		return *this;

	m_nRowCount = oGraph.m_nRowCount;
	m_nColCount = oGraph.m_nColCount;
	m_mxEdges = oGraph.m_mxEdges;

	oGraph.m_nRowCount = 0;
	oGraph.m_nColCount = 0;
	m_mxEdges.Resize(0, 0);

	return *this;
}

inline CGridGraph::t_index CGridGraph::GetRowCount() const
{
	return m_nRowCount;
}

inline CGridGraph::t_index CGridGraph::GetColumnCount() const
{
	return m_nColCount;
}

#endif