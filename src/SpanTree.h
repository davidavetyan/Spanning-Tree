#ifndef SPANTREE_H
#define SPANTREE_H

#include <QtWidgets/QMainWindow>
#include "ui_SpanTree.h"

// STL includes
#include <memory>

class QSpinBox;
class CCanvasWidget;
class CGridDrawer;
class CGridGraph;

class SpanTree : public QMainWindow
{
	Q_OBJECT

	// Type definitions
	template<class T>
	using SharedPtr = std::shared_ptr<T>;

public:
	SpanTree(QWidget *parent = Q_NULLPTR);
	~SpanTree();

public slots:
	void	OnDimensionChanged();
	void	OnSTToggled(bool bChecked);
	void	OnOrderChanged(QString const& strText);

private:
	Ui::SpanTreeClass ui;
	CCanvasWidget*	m_pCanvasWidget;
	SharedPtr<CGridGraph> m_pGraph;
	SharedPtr<CGridDrawer> m_pDrawer;
};

#endif