#include "CanvasWidget.h"

// Qt includes
#include <QPainter>
#include <QPaintEvent>

CCanvasWidget::CCanvasWidget(QWidget* parent, SharedPtr<CGridDrawer> pDrawer)
	: QWidget(parent), m_pDrawer(pDrawer)
{

}

void CCanvasWidget::paintEvent(QPaintEvent* pEvent)
{
	QPainter oPainter(this);

	m_pDrawer->Draw(&oPainter, size());
}