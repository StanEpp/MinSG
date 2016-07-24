#ifdef MINSG_EXT_THESISSTANISLAW

#ifndef MINSG_EXT_THESISSTANISLAW_UNIFORMSAMPLER_H
#define MINSG_EXT_THESISSTANISLAW_UNIFORMSAMPLER_H


namespace MinSG{
namespace ThesisStanislaw{
namespace Sampler{
namespace UniformSampler{
  
struct SamplePoint{
  float x, y;
  SamplePoint () : x(0), y(0) {}
  SamplePoint(float x_, float y_) : x(x_), y(y_){}
};

std::vector<SamplePoint> generateUniformSamples(uint32_t numPoints){
  auto size = static_cast<int>(std::ceil(std::sqrt(numPoints)));
  
  float xOff = (1.f/static_cast<float>(size))/2.f;
  float yOff = xOff;
  
  float xLength = 1.f/static_cast<float>(size);
  float yLength = xLength;
  
  std::vector<SamplePoint> ret;
  
  for(int y = 0; y < size; y++){
    for(int x = 0; x < size && (y * size + x) < numPoints; x++){
      ret.push_back(SamplePoint(xOff + x * xLength, yOff + y * yLength));
    }
  }
  
  return ret;
}

}}}}



#endif // UNIFORMSAMPLER_H_INCLUDED

#endif 
