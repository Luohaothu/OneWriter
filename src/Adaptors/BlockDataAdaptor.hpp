#ifndef ONEWRITER_BLOCKDATAADAPTOR_HPP
#define ONEWRITER_BLOCKDATAADAPTOR_HPP

#include "AbstractAdaptor.hpp"
namespace OneWriter {

    enum class RankStyle { ColMajor, RowMajor };

    template <typename T, int d>
    class BlockDataAdaptor : virtual AbstractAdaptor {
    public:
        BlockDataAdaptor() = default;
        ~BlockDataAdaptor() override = default;

        BlockDataAdaptor(const T* data, const int dims[d])
        : data(data), dims(dims), mode(0) {}

        BlockDataAdaptor(const T* axis[d], const T* data, const int dims[d])
        : axis(axis), data(data), dims(dims), mode(1) {}

        BlockDataAdaptor(const T* axis[d], std::function<T(int[d])> generator,
                         const int dims[d])
        : axis(axis), data_gen(std::move(generator)), dims(dims), mode(2) {}

        BlockDataAdaptor(std::function<T(int)> axis_gen,
                         std::function<T(int[d])> data_gen, const int dims[d])
                         : axis_gen(std::move(axis_gen)), data_gen(std::move(data_gen)),
                         dims(dims) {}

    private:
        constexpr static int dim = d;
        int dims[dim];
        RankStyle rankStyle;
        int mode;

        T *data, *axis[dim];
        std::function<T(int[dim])> data_gen;
        std::function<T(int)> axis_gen;
    };
}

#endif //ONEWRITER_BLOCKDATAADAPTOR_HPP
