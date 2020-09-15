#include "WriterBuilder.hpp"
#include "TXTWriter.hpp"

namespace OneWriter {
WriterBuilder& WriterBuilder::format(OneWriter::FormatTypes format) {
  switch (format) {
  case FormatTypes::txt:
    this->writer = std::make_unique<TXTWriter>();
  case FormatTypes::dat:
    break;
  case FormatTypes::tec:
    break;
  case FormatTypes::plt:
    break;
  case FormatTypes::Unknown:
    break;
  }
  return *this;
}
}