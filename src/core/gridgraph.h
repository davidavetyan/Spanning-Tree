#ifndef GRID_GRAPH_H
#define GRID_GRAPH_H

#include "matrix.h"

////////////////////////////////////////////////////////////////////
namespace core {
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
// class CGridGraph
// Represents a grid graph of size m x n. Is created empty by default.
//
class CGridGraph
{
public:
	inline CGridGraph(size_t nRow = 0, size_t nCol = 0);
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

public:
	// Main interface

	void			Reset(size_t nRow = 0, size_t nCol = 0);
	void			PopulateFull();
	void			AddEdge(int x, int y, EEdgeType eType);
	CMatrix<EEdgeFlags> const& GetEdges() const;

public:
	inline size_t	GetRowCount() const;
	inline size_t	GetColumnCount() const;
	bool			isEmpty() const;

private:
	CMatrix<EEdgeFlags>	m_mxEdges;
	size_t				m_nRowCount;
	size_t				m_nColCount;
};
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
// Inline implementations

inline CGridGraph::CGridGraph(size_t nRow, size_t nCol)
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

inline size_t CGridGraph::GetRowCount() const
{
	return m_nRowCount;
}

inline size_t CGridGraph::GetColumnCount() const
{
	return m_nColCount;
}

////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
} // namespace core
////////////////////////////////////////////////////////////////////

#endif