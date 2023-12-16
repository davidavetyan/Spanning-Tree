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
//	class CMatrix
template<typename T, typename Type = size_t, typename = std::enable_if_t<std::is_integral_v<Type>>>
class CMatrix
{
public:
    CMatrix() = default;
    CMatrix(Type nRow, Type nCol) : m_aData(nRow * nCol), m_nDim(nCol) {}
    CMatrix(Type nRow, Type nCol, T const& tDefaultVal)
        : m_aData(nRow * nCol, tDefaultVal)
        , m_nDim(nCol)
    {}

public:
    T& operator()(Type nRow, Type nCol) { return m_aData[nRow * m_nDim + nCol]; }
    T const& operator()(Type nRow, Type nCol) const { return m_aData[nRow * m_nDim + nCol]; }

    void Resize(Type nRow, Type nCol)
    {
        m_aData.resize(nRow * nCol);
        m_nDim = nCol;
    }

    Type RowCount() const { return m_nDim == 0 ? 0 : m_aData.size() / m_nDim; }
    Type ColCount() const { return m_nDim; }
    QSize GetDimension() const { return QSize(ColCount(), RowCount()); }
    bool IsNull() const { return m_nDim == 0; }

private:
    std::vector<T> m_aData;
    Type m_nDim = 0;
};
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace core
////////////////////////////////////////////////////////////////////////////////////////////////////

#endif