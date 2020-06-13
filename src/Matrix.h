#ifndef MATRIX_H
#define MATRIX_H

// Qt includes
#include <QSize>
#include <QVector>

////////////////////////////////////////////////////////////////////////////////
//	class CMatrix
template<typename T>
class CMatrix
{
public:
	CMatrix() = default;
	CMatrix(int nRow, int nCol)
		: m_aData(nRow* nCol), m_nDim(nCol)
	{}
	CMatrix(int nRow, int nCol, T const& tDefaultVal)
		: m_aData(nRow* nCol, tDefaultVal), m_nDim(nCol)
	{}

public:

	T& operator()(int nRow, int nCol)
	{
		return m_aData[nRow * m_nDim + nCol];
	}
	T const& operator()(int nRow, int nCol) const
	{
		return m_aData[nRow * m_nDim + nCol];
	}

	void Resize(int nRow, int nCol)
	{
		m_aData.resize(nRow * nCol);
		m_nDim = nCol;
	}

	int   RowCount() const;
	int   ColCount() const;
	QSize GetDimension() const;
	bool  IsNull() const;

private:
	QVector<T> m_aData;
	int m_nDim = 0;
};
////////////////////////////////////////////////////////////////////////////////

template <typename T>
int CMatrix<T>::RowCount() const
{
	return m_nDim == 0 ? 0 : m_aData.size() / m_nDim;
}

template <typename T>
int CMatrix<T>::ColCount() const
{
	return m_nDim;
}

template <typename T>
QSize CMatrix<T>::GetDimension() const
{
	return QSize(ColCount(), RowCount());
}

template <typename T>
bool CMatrix<T>::IsNull() const
{
	return m_nDim == 0;
}

#endif