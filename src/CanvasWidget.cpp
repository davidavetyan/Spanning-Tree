#include "CanvasWidget.h"

#include <QPainter>
#include <QPaintEvent>

CCanvasWidget::CCanvasWidget(QWidget* parent, SharedPtr<CGridDrawer> pDrawer)
	: QWidget(parent), m_pDrawer(pDrawer), m_bDrawSpanTree(false)
{

}

void CCanvasWidget::paintEvent(QPaintEvent* pEvent)
{
	QPainter oPainter(this);

	m_pDrawer->Draw(&oPainter, size(), m_bDrawSpanTree);
}

void CCanvasWidget::SetGridDimensions(int nRowCount, int nColumnCount)
{
	m_pDrawer->ResetGraphDimensions(nRowCount, nColumnCount, true);
	repaint();
}

void CCanvasWidget::OnSTToggled(bool bChecked)
{
	m_bDrawSpanTree = bChecked;
	
	repaint();
}
