#ifndef ONEWRITER_ABSTRACTWRITER_HPP
#define ONEWRITER_ABSTRACTWRITER_HPP

#include <string>

namespace OneWriter {

enum class MeshType {
  MeshLess, Grid, Structured, UnStructured, Unknown
};

struct WriterProps {
  bool canAppend;
};

struct WriterFlags {
  bool toAppend;
  MeshType meshType;
  bool constMesh;
};

struct WriterStatus {
  bool inited;
  bool isAppend;
  bool meshWriten;
};

class AbstractWriter {
public:
  AbstractWriter();
  explicit AbstractWriter(const std::string& path);
  virtual ~AbstractWriter() = default;

  void setPath(const std::string& path);
  virtual void write(float* data, long long size) = 0;
  virtual void write(double* data, long long size) = 0;
  virtual void write(int* data, long long size) = 0;

private:
  WriterProps props;
  WriterFlags flags;
  WriterStatus status;

  std::string path;
};
}

#endif // ONEWRITER_ABSTRACTWRITER_HPP
