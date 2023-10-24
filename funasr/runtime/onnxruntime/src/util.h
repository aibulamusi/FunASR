#ifndef UTIL_H
#define UTIL_H
#include <vector>
#include <memory>
#include "tensor.h"

using namespace std;

namespace funasr {
extern float *LoadParams(const char *filename);

extern void SaveDataFile(const char *filename, void *data, uint32_t len);
extern void Relu(Tensor<float> *din);
extern void Swish(Tensor<float> *din);
extern void Sigmoid(Tensor<float> *din);
extern void DoubleSwish(Tensor<float> *din);

extern void Softmax(float *din, int mask, int len);

extern void LogSoftmax(float *din, int len);
extern int ValAlign(int val, int align);
extern void DispParams(float *din, int size);

extern void BasicNorm(Tensor<float> *&din, float norm);

extern void FindMax(float *din, int len, float &max_val, int &max_idx);

extern void Glu(Tensor<float> *din, Tensor<float> *dout);

string PathAppend(const string &p1, const string &p2);
bool is_target_file(const std::string& filename, const std::string target);

void KeepChineseCharacterAndSplit(const std::string &input_str,
                                  std::vector<std::string> &chinese_characters);

std::vector<std::string> split(const std::string &s, char delim);

template<typename T>
void PrintMat(const std::vector<std::vector<T>> &mat, const std::string &name);
void Trim(std::string *str);
size_t Utf8ToCharset(const std::string &input, std::vector<std::string> &output);
void SplitStringToVector(const std::string &full, const char *delim,
                         bool omit_empty_strings,
                         std::vector<std::string> *out);
} // namespace funasr
#endif
