#ifndef CANVAS_WIDGET_H
#define CANVAS_WIDGET_H

// Qt includes
#include <QImage>
#include <QWidget>

#include "GridDrawer.h"

////////////////////////////////////////////////////////////////////
// class CCanvasWidget

class CCanvasWidget : public QWidget
{
	Q_OBJECT

	// Type definitions
	template<class T>
	using SharedPtr = std::shared_ptr<T>;

	template<class T>
	using UniquePtr = std::unique_ptr<T>;

	template<class T>
	using WeakPtr = std::weak_ptr<T>;

public:
	CCanvasWidget(QWidget* parent = nullptr, SharedPtr<CGridDrawer> pDrawer = nullptr);
	~CCanvasWidget() = default;

protected:
	void		paintEvent(QPaintEvent* pEvent) override;

public:
	void		SetGridDimensions(int iRowCount, int iColumnCount);

public slots:
	void		OnSTToggled(bool bChecked);

private:
	SharedPtr<CGridDrawer>	m_pDrawer;
	bool					m_bDrawSpanTree;
};
////////////////////////////////////////////////////////////////////

#endif