#ifndef GRID_DRAWER_H
#define GRID_DRAWER_H

#include "GridGraph.h"

// STL includes
#include <memory>

// Qt includes
#include <QPainter>
#include <utility>

class CDrawer
{
public:
	inline	CDrawer();
	virtual ~CDrawer() = default;
	
	virtual void	Draw(QPainter* pPainter, QSize szWidget) = 0;

protected:
	QSize m_szOffset;
};

inline CDrawer::CDrawer() :
	m_szOffset({10, 10})
{
	
}


class CGridDrawer : public CDrawer
{
	template<class T>
	using SharedPtr = std::shared_ptr<T>;

public:
	CGridDrawer() = default;
	virtual ~CGridDrawer() = default;
	CGridDrawer(CGridDrawer const&) = default;
	CGridDrawer& operator=(CGridDrawer const&) = default;
	
	inline	CGridDrawer(SharedPtr<CGridGraph> pGraph);
	inline	CGridDrawer(CGridDrawer&& oDrawer) noexcept;
	inline	CGridDrawer&	operator=(CGridDrawer&& oDrawer) noexcept;

public:
	void			ResetGraphDimensions(int nRow, int nCol, bool bPopulate = false);
	virtual void	Draw(QPainter* pPainter, QSize szWidget) override;
	virtual void	Draw(QPainter* pPainter, QSize szWidget, bool bDrawTree);

private:
	void			DrawEdges(QPainter* pPainter, SharedPtr<const CGridGraph> pGraph, QSize szOffset, QSize szSpacing);
	void			CreateSTCache();
	void			ResetSTCache();

private:
	SharedPtr<CGridGraph>	m_pGraph; //! Pointer to the CGridGraph object that should be drawn
	SharedPtr<CGridGraph>	m_pSTCache; //! Cache for the spanning tree object
};

inline CGridDrawer::CGridDrawer(SharedPtr<CGridGraph> pGraph) 
	: m_pGraph(std::move(pGraph))
{

}

inline CGridDrawer::CGridDrawer(CGridDrawer&& oDrawer) noexcept
	: m_pGraph(std::move(oDrawer.m_pGraph))
{
	oDrawer.m_pGraph.reset();

	m_szOffset = oDrawer.m_szOffset;
}

inline CGridDrawer& CGridDrawer::operator=(CGridDrawer&& oDrawer) noexcept
{
	if (this == &oDrawer)
		return *this;

	m_pGraph = oDrawer.m_pGraph;
	m_pSTCache = oDrawer.m_pSTCache;
	m_szOffset = oDrawer.m_szOffset;
	
	oDrawer.m_pGraph.reset();
	oDrawer.m_pSTCache.reset();

	return *this;
}

#endif
