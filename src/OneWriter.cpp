#include "OneWriter.hpp"

namespace OneWriter {

    // Instantiate commonly used adaptors & writers for library

    template class LinearDataAdaptor<float>;
    template class LinearDataAdaptor<double>;
    template class LinearDataAdaptor<int>;

    template class BlockDataAdaptor<float, 1>;
    template class BlockDataAdaptor<float, 2>;
    template class BlockDataAdaptor<float, 3>;
    template class BlockDataAdaptor<double, 1>;
    template class BlockDataAdaptor<double, 2>;
    template class BlockDataAdaptor<double, 3>;
    template class BlockDataAdaptor<int, 1>;
    template class BlockDataAdaptor<int, 2>;
    template class BlockDataAdaptor<int, 3>;

}