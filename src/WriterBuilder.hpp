#ifndef ONEWRITER_WRITERBUILDER_HPP
#define ONEWRITER_WRITERBUILDER_HPP

#include "AbstractWriter.hpp"
#include <memory>
#include <vector>
#include <functional>

namespace OneWriter {

enum class FormatTypes {
  // class 0: raw data
  txt, // raw ASCII data
  dat, // raw binary data
  // class 1: Tecplot format data
  tec, // Tecplot ASCII data
  plt, // Tecplot binary data
  Unknown
};

class WriterBuilder {
public:
  WriterBuilder() = default;

  WriterBuilder& format(FormatTypes format);

  auto&& get() {
    return std::move(writer);
  }

private:
  std::unique_ptr<AbstractWriter> writer = nullptr;
  std::vector<std::function<void()>> stack;
};
}
#endif // ONEWRITER_WRITERBUILDER_HPP
