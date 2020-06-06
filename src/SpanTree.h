#ifndef SPANTREE_H
#define SPANTREE_H

#include <QtWidgets/QMainWindow>
#include "ui_SpanTree.h"

class QSpinBox;
class CCanvasWidget;

class SpanTree : public QMainWindow
{
	Q_OBJECT

	// Type definitions
	template<class T>
	using SharedPtr = std::shared_ptr<T>;

public:
	SpanTree(QWidget *parent = Q_NULLPTR);
	~SpanTree();

public:
	void	OnDimensionChanged();

private:
	Ui::SpanTreeClass ui;
	CCanvasWidget*	m_pcCanvasWidget;
};

#endif