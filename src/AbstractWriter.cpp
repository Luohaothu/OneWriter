#include "AbstractWriter.hpp"

namespace OneWriter {
AbstractWriter::AbstractWriter() {
  props.canAppend = false;

  flags.toAppend  = false;
  flags.meshType  = MeshType::Unknown;
  flags.constMesh = false;

  status.meshWriten = false;
  status.isAppend = false;
  status.inited = false;
}

AbstractWriter::AbstractWriter(const std::string &path)
: AbstractWriter() {
  this->path = path;
}

void AbstractWriter::setPath(const std::string &path) {
  this->path = path;
}
}