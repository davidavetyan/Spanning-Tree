#ifndef CANVAS_WIDGET_H
#define CANVAS_WIDGET_H

// Qt includes
#include <QImage>
#include <QWidget>

#include "GridDrawer.h"

////////////////////////////////////////////////////////////////////
//
// CCanvasWidget
//
class CCanvasWidget : public QWidget
{
	Q_OBJECT

	// Type definitions
	template<class T>
	using SharedPtr = std::shared_ptr<T>;

public:
	CCanvasWidget(QWidget* parent = nullptr, SharedPtr<CGridDrawer> pDrawer = nullptr);
	~CCanvasWidget() = default;

protected:
	void		paintEvent(QPaintEvent* pEvent) override;

private:
	SharedPtr<CGridDrawer>	m_pDrawer;
};
////////////////////////////////////////////////////////////////////

#endif