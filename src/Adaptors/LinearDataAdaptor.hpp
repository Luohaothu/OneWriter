#ifndef ONEWRITER_LINEARDATAADAPTOR_HPP
#define ONEWRITER_LINEARDATAADAPTOR_HPP

#include "AbstractAdaptor.hpp"
#include <functional>

namespace OneWriter {
    template <typename T>
    class LinearDataAdaptor : virtual AbstractAdaptor {
    public:
        LinearDataAdaptor() = default;
        virtual ~LinearDataAdaptor() = default;

        LinearDataAdaptor(const T* data, long long size) : data(data), size(size), mode(0) {}

        LinearDataAdaptor(const T* axis, const T* data, long long size)
        : axis(axis), data(data), size(size), mode(1) {}

        LinearDataAdaptor(std::function<T()> generator, long long size)
        : data_gen(std::move(generator)), size(size), mode(2) {}

        LinearDataAdaptor(const T* axis, std::function<T()> generator, long long size)
        : axis(axis), data_gen(std::move(generator)), size(size), mode(3) {}

        LinearDataAdaptor(std::function<T()> axis_gen, std::function<T()> data_gen, long long size)
        : axis_gen(std::move(axis_gen)), data_gen(std::move(data_gen)), size(size), mode(4) {}

    private:
        const T *data, *axis;
        std::function<T()> axis_gen, data_gen;
        long long size;
        int mode;
    };
}
#endif //ONEWRITER_LINEARDATAADAPTOR_HPP
