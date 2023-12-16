#ifndef GRID_DRAWER_H
#define GRID_DRAWER_H

#include "core_gridgraph.h"
#include "core_stgenerator.h"

// STL includes
#include <memory>

// Qt includes
#include <QPainter>

////////////////////////////////////////////////////////////////////
namespace gui {
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//
// CDrawer
//
class CDrawer : public QObject
{
public:
    inline CDrawer();
    virtual ~CDrawer() = default;

    virtual void Draw(QPainter* pPainter, QSize szWidget) = 0;

protected:
    QSize m_szOffset;
};
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//
// CGridDrawer
//
class CGridDrawer : public CDrawer
{
    Q_OBJECT

    template<class T>
    using SharedPtr = std::shared_ptr<T>;

public:
    CGridDrawer() = default;
    virtual ~CGridDrawer();

    inline CGridDrawer(SharedPtr<core::CGridGraph> pGraph);
    inline CGridDrawer(CGridDrawer&& oDrawer) noexcept;
    inline CGridDrawer& operator=(CGridDrawer&& oDrawer) noexcept;

public:
    void Draw(QPainter* pPainter, QSize szWidget) override;
    void SetDrawST(bool bDrawST);
    void ResetGraphDimensions(int nRow, int nCol, bool bPopulate = false);
    void ResetSTCache();

private:
    void DrawEdges(QPainter* pPainter, SharedPtr<const core::CGridGraph> pGraph, QSize szOffset,
                   QSize szSpacing) const;
    void CreateSTCache();

private:
    SharedPtr<core::CGridGraph> m_pGraph; //! Pointer to the CGridGraph object that should be drawn
    SharedPtr<core::CGridGraph> m_pSTCache; //! Cache for the spanning tree object
    bool m_bDrawST;                         //! Shows whether the spanning tree should be drawn
};
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
// Inline implementations

inline CDrawer::CDrawer() : m_szOffset({ 10, 10 })
{}

inline CGridDrawer::~CGridDrawer()
{}

inline CGridDrawer::CGridDrawer(SharedPtr<core::CGridGraph> pGraph)
    : m_pGraph(std::move(pGraph))
    , m_bDrawST(false)
{}

inline CGridDrawer::CGridDrawer(CGridDrawer&& oDrawer) noexcept
    : m_pGraph(std::move(oDrawer.m_pGraph))
    , m_bDrawST(false)
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
    m_bDrawST = oDrawer.m_bDrawST;
    m_szOffset = oDrawer.m_szOffset;

    oDrawer.m_pGraph.reset();
    oDrawer.m_pSTCache.reset();

    return *this;
}

////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
} // namespace gui
////////////////////////////////////////////////////////////////////

#endif