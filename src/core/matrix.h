#ifndef MATRIX_H
#define MATRIX_H

// STL includes
#include <vector>

// Qt includes
#include <QSize>

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace core {
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
/**
    \brief Class for respresenting a two-dimensional matrix.

    \tparam TVal   Type of values stored in the matrix.
    \tparam TIndex Type of the data
*/
template<typename TVal, typename TIndex = size_t,
         typename = std::enable_if_t<std::is_integral_v<TIndex>>>
class CMatrix
{
public:
    CMatrix() = default;
    CMatrix(TIndex nRow, TIndex nCol) : m_aData(nRow * nCol), m_nDim(nCol) {}
    CMatrix(TIndex nRow, TIndex nCol, TVal const& tDefaultVal)
        : m_aData(nRow * nCol, tDefaultVal)
        , m_nDim(nCol)
    {}

public:
    TVal& operator()(TIndex nRow, TIndex nCol) { return m_aData[nRow * m_nDim + nCol]; }
    TVal const& operator()(TIndex nRow, TIndex nCol) const { return m_aData[nRow * m_nDim + nCol]; }

    void Resize(TIndex nRow, TIndex nCol)
    {
        m_aData.resize(nRow * nCol);
        m_nDim = nCol;
    }

    TIndex RowCount() const { return m_nDim == 0 ? 0 : m_aData.size() / m_nDim; }
    TIndex ColCount() const { return m_nDim; }
    QSize GetDimension() const { return QSize(ColCount(), RowCount()); }
    bool IsNull() const { return m_nDim == 0; }

private:
    std::vector<TVal> m_aData;
    TIndex m_nDim = 0;
};
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace core
////////////////////////////////////////////////////////////////////////////////////////////////////

#endif